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
 * The Class ArrayOfBoolean which implements a resizeable array of boolean.
 */
public final class ArrayOfBoolean implements Cloneable, DeepCloneable, Serializable {

  /**
   * The Class ArrayOfBooleanAsList.
   */
  private static final class ArrayOfBooleanAsList extends AbstractList<Boolean> implements
      RandomAccess, Serializable {

    /** The Constant serialVersionUID. */
    private static final long serialVersionUID = 1560934635110067912L;

    /** The array. */
    private final ArrayOfBoolean array;

    /**
     * Instantiates a new array of boolean as list.
     * 
     * @param array
     *          the array
     */
    public ArrayOfBooleanAsList(final ArrayOfBoolean array) {
      this.array = array;
    }

    /*
     * (non-Javadoc)
     * @see java.util.AbstractList#add(int, java.lang.Object)
     */
    @Override
    public void add(final int index, final Boolean element) {
      array.insert(index, element);
    }

    /*
     * (non-Javadoc)
     * @see java.util.AbstractList#get(int)
     */
    @Override
    public Boolean get(final int index) {
      return array.get(index);
    }

    /*
     * (non-Javadoc)
     * @see java.util.AbstractList#remove(int)
     */
    @Override
    public Boolean remove(final int index) {
      final boolean oldValue = array.get(index);
      array.erase(index);
      return oldValue;
    }

    /*
     * (non-Javadoc)
     * @see java.util.AbstractList#set(int, java.lang.Object)
     */
    @Override
    public Boolean set(final int index, final Boolean element) {
      final boolean oldValue = array.get(index);
      array.set(index, element);
      return oldValue;
    }

    /*
     * (non-Javadoc)
     * @see java.util.AbstractCollection#size()
     */
    @Override
    public int size() {
      return array.getCount();
    }

  }

  /** serialVersionUID. */
  private static final long serialVersionUID = 3709258879754680279L;

  /** The instance. */
  transient long instance;

  /**
   * Instantiates a new array of boolean.
   */
  public ArrayOfBoolean() {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.newInstance();
  }

  /**
   * Instantiates a new array of boolean.
   * 
   * @param arrayOfBoolean
   *          the array of boolean to copy
   */
  public ArrayOfBoolean(final ArrayOfBoolean arrayOfBoolean) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.copy(instance,
        arrayOfBoolean.instance);
  }

  /**
   * Instantiates a new array of boolean.
   * 
   * @param dimension
   *          the dimension of the array
   */
  public ArrayOfBoolean(final int dimension) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.resize(instance, dimension, false,
        false);
  }

  /**
   * Instantiates a new array of boolean.
   * 
   * @param dimension
   *          the dimension of the array
   * @param value
   *          the value used to initialize the elements
   */
  public ArrayOfBoolean(final int dimension, final boolean value) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.resize(instance, dimension, false,
        false);
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.fill(instance, value);
  }

  /**
   * Get a view of the object as a standard Java list.
   * 
   * @return the list
   */
  public List<Boolean> asList() {
    return new ArrayOfBooleanAsList(this);
  }

  /**
   * Clear the array by removing all elements.
   */
  public void clear() {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.clear(instance);
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new ArrayOfBoolean(this);
  }

  /**
   * Copy an array.
   * 
   * @param array
   *          the array to be copied
   */
  public void copy(final ArrayOfBoolean array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.copy(instance, array.instance);
  }

  @Override
  public DeepCloneable deepClone() {
    return new ArrayOfBoolean(this);
  }

  /**
   * Remove an element of the array.
   * 
   * @param index
   *          the index
   */
  public void erase(final int index) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.erase(instance, index);
  }

  /**
   * Fill the array with the provided element.
   * 
   * @param value
   *          the value
   */
  public void fill(final boolean value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.fill(instance, value);
  }

  /**
   * Finalize.
   * 
   * {@inheritDoc}
   * 
   * @see java.lang.Object#finalize()
   */
  @Override
  protected void finalize() {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.deleteInstance(instance);
  }

  public boolean[] get(final boolean[] values) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.getElements(instance, values);
    return values;
  }

  /**
   * Gets the element.
   * 
   * @param index
   *          the index
   * @return the element
   */
  public boolean get(final int index) {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.getElement(instance, index);
  }

  /**
   * Gets the number of elements of the array.
   * 
   * @return the count
   */
  public int getCount() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.getCount(instance);
  }

  /**
   * Insert the elements of an array at a fixed position.
   * 
   * @param index
   *          the index
   * @param array
   *          the array to be inserted
   */
  public void insert(final int index, final ArrayOfBoolean array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.insertArray(instance, index,
        array.instance);
  }

  /**
   * Insert an element in the array.
   * 
   * @param index
   *          the index
   * @param value
   *          the value
   */
  public void insert(final int index, final boolean value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.insert(instance, index, value);
  }

  /**
   * Checks if the array is valid mask i.e. if at least one element is true.
   * 
   * @return true, if is valid mask
   */
  public boolean isValidMask() {
    return org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.isValidMask(instance);
  }

  /**
   * Push the elements of array at the back of the array.
   * 
   * @param array
   *          the array
   */
  public void pushBack(final ArrayOfBoolean array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.pushBackArray(instance,
        array.instance);
  }

  /**
   * Push an element at the back of the array.
   * 
   * @param value
   *          the value
   */
  public void pushBack(final boolean value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.pushBack(instance, value);
  }

  /**
   * Push the elements of array at the front of the array.
   * 
   * @param array
   *          the array
   */
  public void pushFront(final ArrayOfBoolean array) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.pushFrontArray(instance,
        array.instance);
  }

  /**
   * Push an element at the front of the array.
   * 
   * @param value
   *          the value
   */
  public void pushFront(final boolean value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.pushFront(instance, value);
  }

  /**
   * Read object.
   * 
   * @param in
   *          the in
   * @throws IOException
   *           Signals that an I/O exception has occurred.
   * @throws ClassNotFoundException
   *           the class not found exception
   */
  private void readObject(final ObjectInputStream in) throws IOException, ClassNotFoundException {
    in.defaultReadObject();

    instance = org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.newInstance();
    final int count = in.readInt();
    resize(count);
    for (int i = 0; i < count; ++i) {
      set(i, in.readBoolean());
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
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.reserve(instance,
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
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.reserve(instance,
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
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.reserve(instance,
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
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.resize(instance, dimension,
        preserveContent, reduceMemory);
  }

  public void set(final boolean[] values) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.setElements(instance, values);
  }

  /**
   * Sets the element.
   * 
   * @param index
   *          the index
   * @param value
   *          the value
   */
  public void set(final int index, final boolean value) {
    org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean.setElement(instance, index, value);
  }

  /**
   * Write object.
   * 
   * @param out
   *          the out
   * @throws IOException
   *           Signals that an I/O exception has occurred.
   */
  private void writeObject(final ObjectOutputStream out) throws IOException {
    out.defaultWriteObject();

    final int count = getCount();
    out.writeInt(count);
    for (int i = 0; i < count; ++i) {
      out.writeBoolean(get(i));
    }
  }
}
