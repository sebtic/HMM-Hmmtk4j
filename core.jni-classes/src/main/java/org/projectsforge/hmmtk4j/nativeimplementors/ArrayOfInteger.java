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
package org.projectsforge.hmmtk4j.nativeimplementors;

import org.projectsforge.alternatives.loader.Loader;

// TODO: Auto-generated Javadoc
/**
 * The Class ArrayOfDouble.
 */
public class ArrayOfInteger {

  static {
    Loader.load("hmmtk4j-core-jni");
  }

  /**
   * Native clear.
   * 
   * @param instance
   *          the instance
   */
  public static native void clear(long instance);

  /**
   * Native copy.
   * 
   * @param instance1
   *          the instance1
   * @param instance2
   *          the instance2
   */
  public static native void copy(long instance1, long instance2);

  /**
   * Native delete instance.
   * 
   * @param instance
   *          the instance
   */
  public static native void deleteInstance(long instance);

  /**
   * Native erase.
   * 
   * @param instance
   *          the instance
   * @param index
   *          the index
   */
  public static native void erase(long instance, int index);

  /**
   * Native fill.
   * 
   * @param instance
   *          the instance
   * @param value
   *          the value
   */
  public static native void fill(long instance, int value);

  /**
   * Native get count.
   * 
   * @param instance
   *          the instance
   * @return the int
   */
  public static native int getCount(long instance);

  /**
   * Native get element.
   * 
   * @param instance
   *          the instance
   * @param index
   *          the index
   * @return the int
   */
  public static native int getElement(long instance, int index);

  /**
   * Native get elements.
   * 
   * @param instance
   *          the instance
   * @param values
   *          the elements
   */
  public static native void getElements(long instance, int[] values);

  /**
   * Native insert.
   * 
   * @param instance
   *          the instance
   * @param index
   *          the index
   * @param value
   *          the value
   */
  public static native void insert(long instance, int index, int value);

  /**
   * Native insert array.
   * 
   * @param instance
   *          the instance
   * @param index
   *          the index
   * @param instance2
   *          the instance2
   */
  public static native void insertArray(long instance, int index, long instance2);

  /**
   * Native new instance.
   * 
   * @return the long
   */
  public static native long newInstance();

  /**
   * Native push back.
   * 
   * @param instance
   *          the instance
   * @param value
   *          the value
   */
  public static native void pushBack(long instance, int value);

  /**
   * Native push back array.
   * 
   * @param instance
   *          the instance
   * @param instance2
   *          the instance2
   */
  public static native void pushBackArray(long instance, long instance2);

  /**
   * Native push front.
   * 
   * @param instance
   *          the instance
   * @param value
   *          the value
   */
  public static native void pushFront(long instance, int value);

  /**
   * Native push front array.
   * 
   * @param instance
   *          the instance
   * @param instance2
   *          the instance2
   */
  public static native void pushFrontArray(long instance, long instance2);

  /**
   * Native reserve.
   * 
   * @param instance
   *          the instance
   * @param reservedDimension
   *          the reserved dimension
   * @param preserveContent
   *          the preserve content
   * @param reduceMemory
   *          the reduce memory
   */
  public static native void reserve(long instance, int reservedDimension, boolean preserveContent,
      boolean reduceMemory);

  /**
   * Native resize.
   * 
   * @param instance
   *          the instance
   * @param dimension
   *          the dimension
   * @param preserveContent
   *          the preserve content
   * @param reduceMemory
   *          the reduce memory
   */
  public static native void resize(long instance, int dimension, boolean preserveContent,
      boolean reduceMemory);

  /**
   * Native set element.
   * 
   * @param instance
   *          the instance
   * @param index
   *          the index
   * @param value
   *          the value
   */
  public static native void setElement(long instance, int index, int value);

  /**
   * Native set elements
   * 
   * @param instance
   *          the instance
   * @param values
   *          the values
   */
  public static native void setElements(long instance, int[] values);

}
