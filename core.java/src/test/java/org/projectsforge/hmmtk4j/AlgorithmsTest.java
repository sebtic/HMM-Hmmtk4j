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
package org.projectsforge.hmmtk4j;

import java.io.Serializable;
import junit.framework.Assert;
import junit.framework.TestCase;
import org.apache.log4j.BasicConfigurator;
import org.projectsforge.hmmtk4j.executors.Algorithm;
import org.projectsforge.hmmtk4j.executors.AlgorithmInterceptor;
import org.projectsforge.hmmtk4j.executors.Algorithms;
import org.projectsforge.hmmtk4j.executors.AlgorithmsExecutor;
import org.projectsforge.hmmtk4j.executors.InMemoryAlgorithms;
import org.projectsforge.hmmtk4j.executors.SequentialAlgorithmsExecutor;
import org.projectsforge.hmmtk4j.executors.StoredAlgorithms;
import org.projectsforge.hmmtk4j.executors.ThreadedAlgorithmsExecutor;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class AlgorithmsTest extends TestCase {
  private static class DummyAlgorithm extends Algorithm implements Serializable {
    Logger logger = LoggerFactory.getLogger(DummyAlgorithm.class);
    int index;

    public DummyAlgorithm(final int index) {
      this.index = index;
    }

    @Override
    protected void implement() {
      logger.debug("Algorithm {} started", this);
      try {
        Thread.sleep(1 * 1000);
      } catch (final InterruptedException e) {
        // TODO Auto-generated catch block
        e.printStackTrace();
      }
      logger.debug("Algorithm {} stopped", this);
    }
  }

  private static class DummyAlgorithmInterceptor implements AlgorithmInterceptor {
    int total = 0;

    @Override
    public boolean intercept(final int index, final Algorithm algorithm) {
      total += ((DummyAlgorithm) algorithm).index;
      return false;
    }

  }

  Logger logger = LoggerFactory.getLogger(AlgorithmsTest.class);

  static {
    BasicConfigurator.resetConfiguration();
    BasicConfigurator.configure();
  }

  public void testSequentialAlgorithmsExecutor() throws InterruptedException {
    final AlgorithmsExecutor executor = new SequentialAlgorithmsExecutor();
    final Algorithms algorithms = new InMemoryAlgorithms();

    for (int i = 0; i < 5; ++i) {
      algorithms.addAlgorithm(new DummyAlgorithm(i));
    }

    final DummyAlgorithmInterceptor interceptor = new DummyAlgorithmInterceptor();
    algorithms.setAlgorithmInterceptor(interceptor);

    logger.debug("Sequential execution");
    executor.execute(algorithms);
    logger.debug("Sequential execution done");

    Assert.assertEquals(4 + 3 + 2 + 1, interceptor.total);
  }

  public void testStoredAlgorithms() throws InterruptedException {
    final ThreadedAlgorithmsExecutor executor = new ThreadedAlgorithmsExecutor();
    final Algorithms algorithms = new StoredAlgorithms();

    for (int i = 0; i < 10; ++i) {
      algorithms.addAlgorithm(new DummyAlgorithm(i));
    }

    final DummyAlgorithmInterceptor interceptor = new DummyAlgorithmInterceptor();
    algorithms.setAlgorithmInterceptor(interceptor);

    executor.setExecutorThreadCount(10);
    logger.debug("Threaded execution. {} Threads", executor.getExecutorThreadCount());
    executor.execute(algorithms);
    logger.debug("Threaded execution done");

    Assert.assertEquals(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1, interceptor.total);
  }

  public void testThreadedAlgorithmsExecutor() throws InterruptedException {
    final ThreadedAlgorithmsExecutor executor = new ThreadedAlgorithmsExecutor();
    final Algorithms algorithms = new InMemoryAlgorithms();

    for (int i = 0; i < 10; ++i) {
      algorithms.addAlgorithm(new DummyAlgorithm(i));
    }

    final DummyAlgorithmInterceptor interceptor = new DummyAlgorithmInterceptor();
    algorithms.setAlgorithmInterceptor(interceptor);

    executor.setExecutorThreadCount(10);
    logger.debug("Threaded execution. {} Threads", executor.getExecutorThreadCount());
    executor.execute(algorithms);
    logger.debug("Threaded execution done");

    Assert.assertEquals(9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1, interceptor.total);
  }
}
