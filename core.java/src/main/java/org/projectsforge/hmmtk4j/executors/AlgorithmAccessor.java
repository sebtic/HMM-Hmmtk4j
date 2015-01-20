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

import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReference;

public class AlgorithmAccessor implements Comparable<AlgorithmAccessor> {
  private final Algorithms algorithms;
  private final int index;
  private final AtomicInteger done;
  private final int numberOfAlgorithmsToRoot;
  private Algorithm algorithm;
  private final AtomicInteger failed;
  private final AtomicReference<Throwable> throwable;

  public AlgorithmAccessor(final Algorithms algorithms, final int index,
      final int numberOfAlgorithmsToRoot, final AtomicInteger done, final AtomicInteger failed,
      final AtomicReference<Throwable> throwable) {
    this.algorithms = algorithms;
    this.index = index;
    this.done = done;
    this.failed = failed;
    this.throwable = throwable;
    this.numberOfAlgorithmsToRoot = numberOfAlgorithmsToRoot;
  }

  @Override
  public int compareTo(final AlgorithmAccessor o) {
    if (numberOfAlgorithmsToRoot == o.numberOfAlgorithmsToRoot) {
      return 0;
    } else if (numberOfAlgorithmsToRoot > o.numberOfAlgorithmsToRoot) {
      return -1;
    } else {
      return 1;
    }
  }

  public Algorithm getAlgorithm() {
    algorithm = algorithms.getAlgorithm(index);
    return algorithm;
  }

  public void markDone() throws InterruptedException {
    algorithms.markDone(index, algorithm);
    algorithm = null;
    done.incrementAndGet();
  }

  public void markFailed() {
    throwable.getAndSet(algorithm.getThrowable());
    algorithms.markFailed(index, algorithm);
    algorithm = null;
    failed.incrementAndGet();
  }
}
