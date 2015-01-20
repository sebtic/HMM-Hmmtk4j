/*
 * Copyright 2010 Sébastien Aupetit <sebtic@projectforge.org>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package org.projectsforge.hmmtk4j.executors;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.PriorityBlockingQueue;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReference;

public class ThreadedAlgorithmsExecutor extends AlgorithmsExecutor {

  private class ExecutorThread extends Thread {
    public ExecutorThread() {
      super(threadGroup, "Executor-" + threadId.incrementAndGet());
    }

    @Override
    public void run() {
      while (!Thread.interrupted()) {
        if (executorThreads.size() > executorThreadCount) {
          executorThreads.remove(this);
          return;
        }

        try {
          final AlgorithmAccessor accessor = taskList.take();
          if (accessor != null) {
            final Algorithm algo = accessor.getAlgorithm();
            algo.run();
            if (algo.hasFailed()) {
              accessor.markFailed();
            } else {
              accessor.markDone();
            }
          }
        } catch (final InterruptedException e) {
          return;
        }
      }
    }
  }

  private final List<ExecutorThread> executorThreads = new ArrayList<ExecutorThread>();
  private final ThreadGroup threadGroup = new ThreadGroup("HMMTK4J Executor Threads");
  private final AtomicInteger threadId = new AtomicInteger(0);

  private final PriorityBlockingQueue<AlgorithmAccessor> taskList = new PriorityBlockingQueue<AlgorithmAccessor>();

  private int executorThreadCount = 0;

  public ThreadedAlgorithmsExecutor() {
    setExecutorThreadCount(Math.max(0, Integer.parseInt(System.getProperty(
        "org.projectsforge.hmmtk4j.executors.executorThreadCount", Integer.toString(Runtime
            .getRuntime().availableProcessors())))));
  }

  @Override
  public void execute(final Algorithms algorithms) throws InterruptedException {
    final AtomicInteger done = new AtomicInteger(0);
    final AtomicInteger failed = new AtomicInteger(0);
    final AtomicReference<Throwable> throwable = new AtomicReference<Throwable>(null);

    final int numberOfAlgorithmsToRoot = AlgorithmsExecutor.getAlgorithmsExecutionState()
        .getNumberOfAlgorithmsToRoot(
            AlgorithmsExecutor.getAlgorithmsExecutionState().getCurrentAlgorithm()) + 1;

    // ajout des tâches
    for (int i = 0; i < algorithms.getAlgorithmsCount(); ++i) {
      taskList.add(new AlgorithmAccessor(algorithms, i, numberOfAlgorithmsToRoot, done, failed,
          throwable));
    }

    while (done.intValue() + failed.intValue() != algorithms.getAlgorithmsCount()) {
      final AlgorithmAccessor accessor = taskList.poll();
      if (accessor != null) {
        final Algorithm algo = accessor.getAlgorithm();
        algo.run();
        if (algo.hasFailed()) {
          throwable.getAndSet(algo.getThrowable());
          accessor.markFailed();
        } else {
          accessor.markDone();
        }
      } else {
        Thread.yield();
      }
    }
    if (failed.intValue() != 0) {
      throw new IllegalStateException("At least an algorithm failed", throwable.get());
    }
  }

  public synchronized int getExecutorThreadCount() {
    return executorThreadCount;
  }

  public synchronized void setExecutorThreadCount(final int executorThreadCount) {
    this.executorThreadCount = executorThreadCount;
    while (executorThreads.size() < executorThreadCount) {
      final ExecutorThread executor = new ExecutorThread();
      executorThreads.add(executor);
      executor.start();
    }
  }
}
