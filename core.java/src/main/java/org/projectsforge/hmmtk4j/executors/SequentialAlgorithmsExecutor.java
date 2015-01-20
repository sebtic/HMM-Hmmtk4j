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

public class SequentialAlgorithmsExecutor extends AlgorithmsExecutor {

  @Override
  public void execute(final Algorithms algorithms) throws InterruptedException {
    for (int i = 0; i < algorithms.getAlgorithmsCount(); ++i) {
      final Algorithm algo = algorithms.getAlgorithm(i);
      algo.run();

      if (algo.hasFailed()) {
        algorithms.markFailed(i, algo);
        throw new IllegalStateException("At least an algorithm failed", algo.getThrowable());
      } else {
        algorithms.markDone(i, algo);
      }
    }
  }
}
