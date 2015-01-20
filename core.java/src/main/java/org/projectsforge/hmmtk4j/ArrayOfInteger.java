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

// TODO: Auto-generated Javadoc
/**
 * The Class ArrayOfInteger which implements a resizeable array of integer..
 */
public final class ArrayOfInteger implements Cloneable, Serializable, DeepCloneable {

  private static final class ArrayOfIntegerAsList extends AbstractList<Integer> implements
      RandomAccess, Serializable {

    private final ArrayOfInteger array;

    public ArrayOfIntegerAsList(final ArrayOfInteger array) {
      this.array = array;
    }

    @Override
    public void add(final int index, final Integer element) {
      array.insert(index, element);
    }

    @Override
    public Integer get(final int index) {
      return array.get(index);
    }

    @Override
    public Integer remove(final int index) {
      final int oldValue = array.get(index);
      array.erase(index);
      return oldValue;
    }

    @Override
    public Integer set(final int index, final Integer element) {
      final int oldValue = array.get(index);
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
  private static final long serialVersionUID = 859612302768804240L;

  transient long instance;

  /**
   * Instantiates a new array of integer.
   */
  public ArrayOfInteger() {
    instance = newInstance();
  }

  /**
   * Instantiates a new array of integer.
   * 
   * @param arrayOfInteger
   *          the array of integer to copy
   */
  public ArrayOfInteger(final ArrayOfInteger arrayOfInteger) {
    instance = newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.copy(instance,
        arrayOfInteger.instance);
  }

  /**
   * Instantiates a new array of integer.
   * 
   * @param dimension
   *          the dimension of the array
   */
  public ArrayOfInteger(final int dimension) {
    instance = newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.resize(instance, dimension, false,
        false);
  }

  /**
   * Instantiates a new array of integer.
   * 
   * @param dimension
   *          the dimension of the array
   * @param value
   *          the value used to initialize the elements
   */
  public ArrayOfInteger(final int dimension, final int value) {
    instance = newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.resize(instance, dimension, false,
        false);
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.fill(instance, value);
  }

  /**
   * Get a view of the object as a standard Java list.
   * 
   * @return the list
   */
  public List<Integer> asList() {
    return new ArrayOfIntegerAsList(this);
  }

  /**
   * Clear the array by removing all elements.
   */
  public void clear() {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.clear(instance);
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new ArrayOfInteger(this);
  }

  /**
   * Copy an array.
   * 
   * @param array
   *          the array to be copied
   */
  public void copy(final ArrayOfInteger array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.copy(instance, array.instance);
  }

  @Override
  public DeepCloneable deepClone() {
    return new ArrayOfInteger(this);
  }

  protected void deleteInstance() {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.deleteInstance(instance);
  }

  /**
   * Remove an element of the array.
   * 
   * @param index
   *          the index of the element
   */
  public void erase(final int index) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.erase(instance, index);
  }

  /**
   * Fill the array with the provided element.
   * 
   * @param value
   *          the value
   */
  public void fill(final int value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.fill(instance, value);
  }

  /**
   * {@inheritDoc}
   * 
   * @see java.lang.Object#finalize()
   */
  @Override
  protected void finalize() {
    deleteInstance();
  }

  /**
   * Gets the element.
   * 
   * @param index
   *          the index
   * @return the element
   */
  public int get(final int index) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.getElement(instance, index);
  }

  public int[] get(final int[] values) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.getElements(instance, values);
    return values;
  }

  /**
   * Gets the number of elements of the array.
   * 
   * @return the count
   */
  public int getCount() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.getCount(instance);
  }

  /**
   * Insert the elements of an array at a fixed position.
   * 
   * @param index
   *          the index where the element must be inserted
   * @param array
   *          the array
   */
  public void insert(final int index, final ArrayOfInteger array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.insertArray(instance, index,
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
  public void insert(final int index, final int value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.insert(instance, index, value);
  }

  protected long newInstance() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.newInstance();
  }

  /**
   * Push the elements of array at the back of the array.
   * 
   * @param array
   *          the array
   */
  public void pushBack(final ArrayOfInteger array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.pushBackArray(instance,
        array.instance);
  }

  /**
   * Push an element at the back of the array.
   * 
   * @param value
   *          the value
   */
  public void pushBack(final int value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.pushBack(instance, value);
  }

  /**
   * Push the elements of array at the front of the array.
   * 
   * @param array
   *          the array
   */
  public void pushFront(final ArrayOfInteger array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.pushFrontArray(instance,
        array.instance);
  }

  /**
   * Push an element at the front of the array.
   * 
   * @param value
   *          the value
   */
  public void pushFront(final int value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.pushFront(instance, value);
  }

  private void readObject(final ObjectInputStream in) throws IOException, ClassNotFoundException {
    in.defaultReadObject();

    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.newInstance();
    final int count = in.readInt();
    resize(count);
    for (int i = 0; i < count; ++i) {
      set(i, in.readInt());
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
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.reserve(instance,
        reservedDimension, true, false);
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
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.reserve(instance,
        reservedDimension, preserveContent, false);
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
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.reserve(instance,
        reservedDimension, preserveContent, reduceMemory);
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
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.resize(instance, dimension,
        preserveContent, reduceMemory);
  }

  /**
   * Sets the element.
   * 
   * @param index
   *          the index
   * @param value
   *          the value
   */
  public void set(final int index, final int value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.setElement(instance, index, value);
  }

  public void set(final int[] values) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger.setElements(instance, values);
  }

  private void writeObject(final ObjectOutputStream out) throws IOException {
    out.defaultWriteObject();

    final int count = getCount();
    out.writeInt(count);
    for (int i = 0; i < count; ++i) {
      out.writeInt(get(i));
    }
  }
}
