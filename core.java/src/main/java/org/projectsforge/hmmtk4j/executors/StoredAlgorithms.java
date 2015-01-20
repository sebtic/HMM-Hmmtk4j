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

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class StoredAlgorithms extends Algorithms {

  private static StorageManager storageManager = new StorageManager();

  private final List<Long> algorithmId = new ArrayList<Long>();

  @Override
  public void addAlgorithm(final Algorithm algorithm) {
    final long id = StoredAlgorithms.storageManager.getNewAlgorithmId();
    try {
      StoredAlgorithms.storageManager.saveAlgorithm(id, algorithm);
    } catch (final IOException e) {
      throw new IllegalStateException(e);
    }
    algorithmId.add(id);
  }

  @Override
  public void clear(final int index) {
    final long id = algorithmId.get(index);
    StoredAlgorithms.storageManager.clearAlgorithm(id);
  }

  @Override
  public Algorithm getAlgorithm(final int index) {
    try {
      return StoredAlgorithms.storageManager.loadAlgorithm(algorithmId.get(index));
    } catch (final IOException e) {
      throw new IllegalStateException(e);
    } catch (final ClassNotFoundException e) {
      throw new IllegalStateException(e);
    }
  }

  @Override
  public int getAlgorithmsCount() {
    return algorithmId.size();
  }

  @Override
  protected void saveAlgorithm(final int index, final Algorithm algorithm) {
    try {
      StoredAlgorithms.storageManager.saveAlgorithm(algorithmId.get(index), algorithm);
    } catch (final IOException e) {
      throw new IllegalStateException(e);
    }
  }

}
