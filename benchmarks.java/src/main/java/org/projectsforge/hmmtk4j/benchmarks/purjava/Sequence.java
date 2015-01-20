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
package org.projectsforge.hmmtk4j.benchmarks.purjava;

import org.projectsforge.hmmtk4j.Duplicable;

public class Sequence implements Duplicable {

  int data[];
  private int maxDistinctValues = 0;

  /**
   * Instantiates a new array of double.
   */
  public Sequence() {
    data = new int[0];
  }

  public Sequence(final int maxDistinctValues) {
    data = new int[0];
    setMaxDistinctValues(maxDistinctValues);
  }

  /**
   * Instantiates a new array of double.
   * @param arrayOfDouble the array of double to copy
   */
  public Sequence(final Sequence arrayOfDouble) {
    data = new int[0];
    copy(arrayOfDouble);
  }

  /**
   * Clear the array by removing all elements.
   */
  public void clear() {
    data = new int[0];
  }

  /**
   * Copy an array.
   * @param array the array to be copied
   */
  public void copy(final Sequence array) {
    data = new int[array.data.length];
    for (int i = 0; i < array.data.length; ++i) {
      data[i] = array.data[i];
    }
    maxDistinctValues = array.maxDistinctValues;
  }

  public Duplicable duplicate() {
    return new Sequence(this);
  }

  public void fill(final int value) {
    for (int i = 0; i < data.length; ++i) {
      data[i] = value;
    }
  }

  /**
   * Gets the element.
   * @param index the index
   * @return the element
   */
  public int get(final int index) {
    return data[index];
  }

  /**
   * Gets the count.
   * @return the count
   */
  public int getCount() {
    return data.length;
  }

  public int getMaxDistinctValues() {
    return this.maxDistinctValues;
  }

  public boolean isValid() {
    for (int i = 0; i < getCount(); ++i) {
      final int e = get(i);
      if ((e < 0) || (e >= this.maxDistinctValues)) {
        System.out
            .println("Sequence: The element " + e + " is not in the valid range [0;" + (this.maxDistinctValues - 1) + "]"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
        return false;
      }
    }
    return true;
  }

  /**
   * Push an element at the back of the array.
   * @param value the value
   */
  public void pushBack(final int value) {
    final int tmp[] = new int[data.length + 1];
    for (int i = 0; i < data.length; ++i) {
      tmp[i] = data[i];
    }
    tmp[data.length] = value;
    data = tmp;
  }

  /**
   * Resize.
   * @param dimension the dimension of the array
   */
  public void resize(final int dimension) {
    resize(dimension, true, false);
  }

  /**
   * Resize.
   * @param dimension the dimension of the array
   * @param preserveContent a flag indicating if the content of the array must
   *          be preserved
   */
  public void resize(final int dimension, final boolean preserveContent) {
    resize(dimension, preserveContent, false);
  }

  /**
   * Resize.
   * @param dimension the dimension of the array
   * @param preserveContent a flag indicating if the content of the array must
   *          be preserved
   * @param reduceMemory a flag indicating if the memory must be reduced
   */
  public void resize(final int dimension, final boolean preserveContent,
      final boolean reduceMemory) {
    data = new int[dimension];
  }

  /**
   * Sets the element.
   * @param index the index
   * @param value the value
   */
  public void set(final int index, final int value) {
    data[index] = value;
  }

  public void setMaxDistinctValues(final int maxDistinctValues) {
    if (maxDistinctValues < 0) {
      throw new IllegalArgumentException("maxDistinctValues must be positive");
    }
    this.maxDistinctValues = maxDistinctValues;
  }

}
