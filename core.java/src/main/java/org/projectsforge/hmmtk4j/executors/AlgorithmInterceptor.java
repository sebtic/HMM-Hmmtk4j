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

public interface AlgorithmInterceptor {

  /**
   * Apply the reduction on the algorithm. Called only once for an algoithm.
   * 
   * @param index
   *          the index of the algorithm in the list of managed algorithms
   * @param algorithm
   *          the algorithm instance
   * @return true if the modified algorithm instance must be saved for latter
   *         retreival ({@link StoredAlgorithms#clear(int)} or
   *         {@link StoredAlgorithms#clear()} should be called when
   *         appropriate), false if the algorithm can be discarded
   * @throws InterruptedException
   */
  public boolean intercept(int index, Algorithm algorithm) throws InterruptedException;
}
