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

public abstract class Algorithms {

  private static AlgorithmsFactory algorithmsFactory = new InMemoryAlgorithmsFactory();

  public static AlgorithmsFactory getAlgorithmsFactory() {
    return Algorithms.algorithmsFactory;
  }

  public static Algorithms newInstance() {
    return Algorithms.getAlgorithmsFactory().newinstance();
  }

  public static void setAlgorithmsFactory(final AlgorithmsFactory algorithmsFactory) {
    if (algorithmsFactory == null) {
      throw new IllegalArgumentException("The factory can not be null");
    }
    Algorithms.algorithmsFactory = algorithmsFactory;
  }

  private AlgorithmInterceptor algorithmInterceptor = new DiscardAlgorithmInterceptor();

  /**
   * Adds the algorithm in the list of the runner.
   * 
   * @param algorithm
   *          the algorithm
   */
  public abstract void addAlgorithm(final Algorithm algorithm);

  public void clear() {
    for (int i = 0; i < getAlgorithmsCount(); ++i) {
      clear(i);
    }
  }

  public abstract void clear(final int index);

  @Override
  protected void finalize() throws Throwable {
    clear();
  }

  public abstract Algorithm getAlgorithm(int index);

  public AlgorithmInterceptor getAlgorithmInterceptor() {
    return algorithmInterceptor;
  }

  public abstract int getAlgorithmsCount();

  public synchronized void markDone(final int index, final Algorithm algorithm)
      throws InterruptedException {
    if (algorithmInterceptor.intercept(index, algorithm)) {
      saveAlgorithm(index, algorithm);
    } else {
      clear(index);
    }
  }

  public synchronized void markFailed(final int index, final Algorithm algorithm) {
    clear(index);
  }

  protected abstract void saveAlgorithm(int index, Algorithm algorithm);

  public void setAlgorithmInterceptor(final AlgorithmInterceptor algorithmInterceptor) {
    if (algorithmInterceptor == null) {
      throw new IllegalArgumentException("The interceptor can not be null");
    }
    this.algorithmInterceptor = algorithmInterceptor;
  }
}
