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

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.AbstractList;
import java.util.List;
import java.util.RandomAccess;

/**
 * The Class ArrayOfDouble which implements a resizeable array of double..
 */
public final class ArrayOfDouble implements Cloneable, Serializable, DeepCloneable {

  private static final class ArrayOfDoubleAsList extends AbstractList<Double> implements
      RandomAccess, Serializable {

    private final ArrayOfDouble array;

    public ArrayOfDoubleAsList(final ArrayOfDouble array) {
      this.array = array;
    }

    @Override
    public void add(final int index, final Double element) {
      array.insert(index, element);
    }

    @Override
    public Double get(final int index) {
      return array.get(index);
    }

    @Override
    public Double remove(final int index) {
      final double oldValue = array.get(index);
      array.erase(index);
      return oldValue;
    }

    @Override
    public Double set(final int index, final Double element) {
      final double oldValue = array.get(index);
      array.set(index, element);
      return oldValue;
    }

    @Override
    public int size() {
      return array.getCount();
    }

  }

  /**
   *
   */
  private static final long serialVersionUID = -3306308743905130969L;

  transient long instance;

  /**
   * Instantiates a new array of double.
   */
  public ArrayOfDouble() {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.newInstance();
  }

  /**
   * Instantiates a new array of double.
   * 
   * @param arrayOfDouble
   *          the array of double to copy
   */
  public ArrayOfDouble(final ArrayOfDouble arrayOfDouble) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.copy(instance,
        arrayOfDouble.instance);
  }

  /**
   * Instantiates a new array of double.
   * 
   * @param dimension
   *          the dimension of the array
   */
  public ArrayOfDouble(final int dimension) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.resize(instance, dimension, false,
        false);
  }

  /**
   * Instantiates a new array of double.
   * 
   * @param dimension
   *          the dimension of the array
   * @param value
   *          the value used to initialize the elements
   */
  public ArrayOfDouble(final int dimension, final double value) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.resize(instance, dimension, false,
        false);
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.fill(instance, value);
  }

  /**
   * Adds the elements of the array one-by-one.
   * 
   * @param array
   *          the array
   */
  public void add(final ArrayOfDouble array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.addArray(instance, array.instance);
  }

  /**
   * Adds value to each element.
   * 
   * @param value
   *          the value
   */
  public void add(final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.add(instance, value);
  }

  /**
   * Applies a mask to the array. The element if nulled if the corresponding
   * element in the mask is false.
   * 
   * @param array
   *          the mask
   */
  public void applyMask(final ArrayOfBoolean array) {
    if (array != null) {
      org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble
          .applyMask(instance, array.instance);
    }
  }

  /**
   * Get a view of the object as a standard Java list.
   * 
   * @return the list
   */
  public List<Double> asList() {
    return new ArrayOfDoubleAsList(this);
  }

  /**
   * Clear the array by removing all elements.
   */
  public void clear() {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.clear(instance);
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new ArrayOfDouble(this);
  }

  /**
   * Copy an array.
   * 
   * @param array
   *          the array to be copied
   */
  public void copy(final ArrayOfDouble array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.copy(instance, array.instance);
  }

  /**
   * Count elements which have the same value as the parameter.
   * 
   * @param value
   *          the value
   * @return the number of elements equal to value
   */
  public int countElements(final double value) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble
        .countElements(instance, value);
  }

  @Override
  public DeepCloneable deepClone() {
    return new ArrayOfDouble(this);
  }

  /**
   * Remove an element of the array.
   * 
   * @param index
   *          the index of the element
   */
  public void erase(final int index) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.erase(instance, index);
  }

  /**
   * Fill the array with the provided element.
   * 
   * @param value
   *          the value
   */
  public void fill(final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.fill(instance, value);
  }

  /**
   * {@inheritDoc}
   * 
   * @see java.lang.Object#finalize()
   */
  @Override
  protected void finalize() {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.deleteInstance(instance);
  }

  /**
   * Compute the Fisher's coefficient:.
   * 
   * @return the value of the Fisher's coefficient - Fisher < 3 : the series is
   *         flatter than a normal - Fisher = 3 : the series is as flat as a
   *         normal - Fisher > 3 : the series is sharper than a normal
   */
  public double fisherIndex() {
    return moment(4) / Math.pow(Math.sqrt(moment(2)), 4);
  }

  /**
   * Generates a stochastic vector.
   * 
   * @param allowNullProbabilities
   *          the allow null probabilities
   */
  public void generateStochasticVector(final boolean allowNullProbabilities) {
    Randomizer.generateAStochasticVector(this, allowNullProbabilities);
  }

  public double[] get(final double[] values) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.getElements(instance, values);
    return values;
  }

  /**
   * Gets the element.
   * 
   * @param index
   *          the index
   * @return the element
   */
  public double get(final int index) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.getElement(instance, index);
  }

  /**
   * Gets the count.
   * 
   * @return the count
   */
  public int getCount() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.getCount(instance);
  }

  /**
   * Computes the index of the greatest element of the array.
   * 
   * @return the index or -1 if the array is empty
   */
  public int indexOfMaxElement() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.indexOfMaxElement(instance);
  }

  /**
   * Computes the index of the greatest element of the array.
   * 
   * @return the index or -1 if the array is empty
   */
  public int indexOfMinElement() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.indexOfMinElement(instance);
  }

  /**
   * Compute the infinite norm.
   * 
   * @return the double
   */
  public double infiniteNorm() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.infiniteNorm(instance);
  }

  /**
   * Computes the inner product of the two arrays.
   * 
   * @param array
   *          the array
   * @return the double
   */
  public double innerProduct(final ArrayOfDouble array) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.innerProduct(instance,
        array.instance);
  }

  /**
   * Insert the elements of an array at a fixed position.
   * 
   * @param index
   *          the index where the element must be inserted
   * @param array
   *          the array
   */
  public void insert(final int index, final ArrayOfDouble array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.insertArray(instance, index,
        array.instance);
  }

  /**
   * Insert an element in the array.
   * 
   * @param index
   *          the index where the element must be inserted
   * @param value
   *          the value
   */
  public void insert(final int index, final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.insert(instance, index, value);
  }

  /**
   * Checks if the elements of the array are in the provided range.
   * 
   * @param minValue
   *          the min value
   * @param maxValue
   *          the max value
   * @return true, if is valid
   */
  public boolean isValid(final double minValue, final double maxValue) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.isValid(instance, minValue,
        maxValue);
  }

  /**
   * Computes the L1 norm.
   * 
   * @return the double
   */
  public double l1Norm() {
    return sumAbsoluteElements();
  }

  /**
   * Computes the L2 norm.
   * 
   * @return the double
   */
  public double l2Norm() {
    return Math.sqrt(innerProduct(this));
  }

  /**
   * Computes the L-n norm.
   * 
   * @param n
   *          the norm order
   * @return the double
   */
  public double lNNorm(final double n) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.lNNorm(instance, n);
  }

  /**
   * Computed the unrooted L-n norm.
   * 
   * @param n
   *          the norm order
   * @return the double
   */
  public double lNNormUnRooted(final double n) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.lNNormUnRooted(instance, n);
  }

  /**
   * Makes the array stochastic.
   * 
   * @return the sum of the elements before the modificaton
   */
  public double makeStochastic() {
    final double sum = sumOfElements();
    if (sum > 0) {
      mul(1. / sum);
    }
    return sum;
  }

  /**
   * Make the array unitary against the infinite norm.
   * 
   * @return the infinite norm of the array before the modification
   */
  public double makeUnitaryForInfiniteNorm() {
    final double sum = infiniteNorm();
    if (sum > 0) {
      mul(1. / sum);
    }
    return sum;
  }

  /**
   * Makes the array unitary against L1 norm.
   * 
   * @return the L1-norm of the array before the modification
   */
  public double makeUnitaryForL1Norm() {
    final double sum = l1Norm();
    if (sum > 0) {
      mul(1. / sum);
    }
    return sum;
  }

  /**
   * Make the array unitary against the L2 norm.
   * 
   * @return the L2-norm of the array before the modification
   */
  public double makeUnitaryForL2Norm() {
    final double sum = l2Norm();
    if (sum > 0) {
      mul(1. / sum);
    }
    return sum;
  }

  /**
   * Max distance.
   * 
   * @param array
   *          the array
   * @return the distance
   */
  public double maxDistance(final ArrayOfDouble array) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.maxDistance(instance,
        array.instance);
  }

  /**
   * Computes the greatest element of the array.
   * 
   * @return the double
   */
  public double maxElement() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.maxElement(instance);
  }

  /**
   * Computes the mean of the elements.
   * 
   * @return the mean
   */
  public double mean() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.sumOfElements(instance)
        / org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.getCount(instance);
  }

  /**
   * Computes the smallest element of the array.
   * 
   * @return the double
   */
  public double minElement() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.minElement(instance);
  }

  /**
   * Computes the moment of elements.
   * 
   * @param order
   *          the order of the moment
   * @return the double
   */
  public double moment(final double order) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.moment(instance, order);
  }

  /**
   * Multiplies the elements of the array one-by-one.
   * 
   * @param array
   *          the array
   */
  public void mul(final ArrayOfDouble array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.mulArray(instance, array.instance);
  }

  /**
   * Multiplies the elements of the array by a value.
   * 
   * @param value
   *          the value
   */
  public void mul(final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.mul(instance, value);
  }

  /**
   * Raise each element to the power value.
   * 
   * @param value
   *          the value
   */
  public void pow(final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.pow(instance, value);
  }

  /**
   * Push the elements of array at the back of the array.
   * 
   * @param array
   *          the array
   */
  public void pushBack(final ArrayOfDouble array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.pushBackArray(instance,
        array.instance);
  }

  /**
   * Push an element at the back of the array.
   * 
   * @param value
   *          the value
   */
  public void pushBack(final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.pushBack(instance, value);
  }

  /**
   * Push the elements of array at the front of the array.
   * 
   * @param array
   *          the array
   */
  public void pushFront(final ArrayOfDouble array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.pushFrontArray(instance,
        array.instance);
  }

  /**
   * Push an element at the front of the array.
   * 
   * @param value
   *          the value
   */
  public void pushFront(final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.pushFront(instance, value);
  }

  private void readObject(final ObjectInputStream in) throws IOException, ClassNotFoundException {
    in.defaultReadObject();

    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.newInstance();
    final int count = in.readInt();
    resize(count);
    for (int i = 0; i < count; ++i) {
      set(i, in.readDouble());
    }
  }

  /**
   * Reserve some memory to speed up the actions making the array grow.
   * 
   * @param reservedDimension
   *          the reserved dimension of the array
   * @warn The default policy for memory reduction is applied
   */
  public void reserve(final int reservedDimension) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.reserve(instance, reservedDimension,
        true, false);
  }

  /**
   * Reserve some memory to speed up the actions making the array grow.
   * 
   * @param reservedDimension
   *          the reserved dimension of the array
   * @param preserveContent
   *          a flag indicating if the content of the array must be preserved
   * @warn The default policy for memory reduction is applied
   */
  public void reserve(final int reservedDimension, final boolean preserveContent) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.reserve(instance, reservedDimension,
        preserveContent, false);
  }

  /**
   * Reserve.
   * 
   * @param reservedDimension
   *          the reserved dimension of the array
   * @param preserveContent
   *          a flag indicating if the content of the array must be preserved
   * @param reduceMemory
   *          a flag indicating if the memory must be reduced
   */
  public void reserve(final int reservedDimension, final boolean preserveContent,
      final boolean reduceMemory) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.reserve(instance, reservedDimension,
        preserveContent, reduceMemory);
  }

  /**
   * Resize.
   * 
   * @param dimension
   *          the dimension of the array
   */
  public void resize(final int dimension) {
    resize(dimension, true, false);
  }

  /**
   * Resize.
   * 
   * @param dimension
   *          the dimension of the array
   * @param preserveContent
   *          a flag indicating if the content of the array must be preserved
   */
  public void resize(final int dimension, final boolean preserveContent) {
    resize(dimension, preserveContent, false);
  }

  /**
   * Resize.
   * 
   * @param dimension
   *          the dimension of the array
   * @param preserveContent
   *          a flag indicating if the content of the array must be preserved
   * @param reduceMemory
   *          a flag indicating if the memory must be reduced
   */
  public void resize(final int dimension, final boolean preserveContent, final boolean reduceMemory) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.resize(instance, dimension,
        preserveContent, reduceMemory);
  }

  public void set(final double[] values) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.setElements(instance, values);
  }

  /**
   * Sets the element.
   * 
   * @param index
   *          the index
   * @param value
   *          the value
   */
  public void set(final int index, final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.setElement(instance, index, value);
  }

  /**
   * Computes the squared L2 norm.
   * 
   * @return the double
   */
  public double squaredL2Norm() {
    return innerProduct(this);
  }

  /**
   * Compute the standard deviation of elements of \a a using a biaised method
   * described at http://en.wikipedia.org/wiki/Standard_deviation
   * 
   * @return the double
   */
  public double stdDev() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.stdDev(instance);
  }

  /**
   * Subs the elements of the array one-by-one.
   * 
   * @param array
   *          the array
   */
  public void sub(final ArrayOfDouble array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.sub(instance, array.instance);
  }

  /**
   * Computes the sum of the absolute values of the elements.
   * 
   * @return the double
   */
  public double sumAbsoluteElements() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble
        .sumOfAbsoluteElements(instance);
  }

  /**
   * Sums the elements of the array.
   * 
   * @return the double
   */
  public double sumOfElements() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble.sumOfElements(instance);
  }

  public double unrootedL2Norm() {
    return innerProduct(this);
  }

  private void writeObject(final ObjectOutputStream out) throws IOException {
    out.defaultWriteObject();

    final int count = getCount();
    out.writeInt(count);
    for (int i = 0; i < count; ++i) {
      out.writeDouble(get(i));
    }
  }

}
