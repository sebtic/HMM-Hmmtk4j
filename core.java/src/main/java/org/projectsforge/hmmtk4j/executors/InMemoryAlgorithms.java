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

public class InMemoryAlgorithms extends Algorithms {
  private final List<Algorithm> algorithms = new ArrayList<Algorithm>();

  @Override
  public void addAlgorithm(final Algorithm algorithm) {
    algorithms.add(algorithm);
  }

  @Override
  public void clear(final int index) {
    algorithms.set(index, null);
  }

  @Override
  public Algorithm getAlgorithm(final int index) {
    return algorithms.get(index);
  }

  @Override
  public int getAlgorithmsCount() {
    return algorithms.size();
  }

  @Override
  protected void saveAlgorithm(final int index, final Algorithm algorithm) {
    // nothing to do
  }
}
