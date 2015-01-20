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

public final class ArrayOfDouble implements Duplicable {

  double data[];

  /**
   * Instantiates a new array of double.
   */
  public ArrayOfDouble() {
    data = new double[0];
  }

  /**
   * Instantiates a new array of double.
   * @param arrayOfDouble the array of double to copy
   */
  public ArrayOfDouble(final ArrayOfDouble arrayOfDouble) {
    data = new double[0];
    copy(arrayOfDouble);
  }

  /**
   * Instantiates a new array of double.
   * @param dimension the dimension of the array
   */
  public ArrayOfDouble(final int dimension) {
    data = new double[0];
    resize(dimension, false, false);
  }

  /**
   * Instantiates a new array of double.
   * @param dimension the dimension of the array
   * @param value the value used to initialize the elements
   */
  public ArrayOfDouble(final int dimension, final double value) {
    data = new double[0];
    resize(dimension, false, false);
    fill(value);
  }

  /**
   * Clear the array by removing all elements.
   */
  public void clear() {
    data = new double[0];
  }

  /**
   * Copy an array.
   * @param array the array to be copied
   */
  public void copy(final ArrayOfDouble array) {
    data = new double[array.data.length];
    for (int i = 0; i < array.data.length; ++i) {
      data[i] = array.data[i];
    }
  }

  public Duplicable duplicate() {
    return new ArrayOfDouble(this);
  }

  public void fill(final double value) {
    for (int i = 0; i < data.length; ++i) {
      data[i] = value;
    }
  }

  /**
   * Gets the element.
   * @param index the index
   * @return the element
   */
  public double get(final int index) {
    return data[index];
  }

  /**
   * Gets the count.
   * @return the count
   */
  public int getCount() {
    return data.length;
  }

  public boolean isValid(final double minValue, final double maxValue) {
    for (int i = 0; i < data.length; ++i) {
      if ((data[i] < minValue) || (data[i] > maxValue)) {
        return false;
      }
    }
    return true;
  }

  public void makeStochastic() {
    double sum = 0;
    for (int i = 0; i < data.length; ++i) {
      sum += data[i];
    }
    sum = 1 / sum;
    for (int i = 0; i < data.length; ++i) {
      data[i] *= sum;
    }
  }

  /**
   * Push an element at the back of the array.
   * @param value the value
   */
  public void pushBack(final double value) {
    final double tmp[] = new double[data.length + 1];
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
    data = new double[dimension];
  }

  /**
   * Sets the element.
   * @param index the index
   * @param value the value
   */
  public void set(final int index, final double value) {
    data[index] = value;
  }
}
