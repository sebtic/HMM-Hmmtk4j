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
 * The Class managing a matrix of double.
 */
public final class MatrixOfDouble {

  static {
    Loader.load("hmmtk4j-core-jni");
  }

  /**
   * Native add.
   * 
   * @param instance
   *          the instance
   * @param value
   *          the value
   */
  public static native void add(long instance, double value);

  public static native void add(long instance, long matrix);

  /**
   * Native add to row.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param value
   *          the value
   */
  public static native void addToRow(long instance, int row, double value);

  /**
   * Native apply mask.
   * 
   * @param instance
   *          the instance
   * @param mask
   *          the mask
   */
  public static native void applyMask(long instance, long mask);

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
   * @param instance
   *          the instance
   * @param instance2
   *          the instance2
   */
  public static native void copy(long instance, long instance2);

  /**
   * Native count elements on row.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param value
   *          the value
   * @return the int
   */
  public static native int countElementsOnRow(long instance, int row, double value);

  /**
   * Native delete instance.
   * 
   * @param instance
   *          the instance
   */
  public static native void deleteInstance(long instance);

  /**
   * Native fill.
   * 
   * @param instance
   *          the instance
   * @param value
   *          the value
   */
  public static native void fill(long instance, double value);

  /**
   * Native fill row.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param value
   *          the value
   */
  public static native void fillRow(long instance, int row, double value);

  /**
   * Raise the square matrix to the power 4\sup{powerLevel}
   * 
   * @param instance
   *          the instance
   * @param powerLevel
   *          the power level base
   */
  public static native void fourthpowerSquareMatrix(long instance, int powerLevel);

  /**
   * Native get col.
   * 
   * @param instance
   *          the instance
   * @param col
   *          the col
   * @param array
   *          the array
   */
  public static native void getCol(long instance, int col, long array);

  /**
   * Native get col count.
   * 
   * @param instance
   *          the instance
   * @return the int
   */
  public static native int getColCount(long instance);

  /**
   * Native get column
   * 
   * @param instance
   *          the instance
   * @param col
   *          the column
   * @param array
   *          the array to fill
   */
  public static native void getColJava(long instance, int col, double[] array);

  /**
   * Native get element.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param col
   *          the col
   * @return the double
   */
  public static native double getElement(long instance, int row, int col);

  /**
   * Native get row.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param array
   *          the array
   */
  public static native void getRow(long instance, int row, long array);

  /**
   * Native get row count.
   * 
   * @param instance
   *          the instance
   * @return the int
   */
  public static native int getRowCount(long instance);

  /**
   * Native get row
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param array
   *          the array to fill
   */
  public static native void getRowJava(long instance, int row, double[] array);

  /**
   * Native index of max element.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @return the int
   */
  public static native int indexOfMaxElement(long instance, int row);

  /**
   * Native index of min element.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @return the int
   */
  public static native int indexOfMinElement(long instance, int row);

  /**
   * Compute the inner product of two columns of the matrix
   * 
   * @param coli
   *          the first column index
   * @param colj
   *          the second column index
   * @return the inner product
   */
  public static native double innerProductOfCols(long instance, int coli, int colj);

  /**
   * Compute the inner product of two rows of the matrix
   * 
   * @param rowi
   *          the first row index
   * @param rowj
   *          the second row index
   * @return the inner product
   */
  public static native double innerProductOfRows(long instance, int rowi, int rowj);

  /**
   * Native is valid.
   * 
   * @param instance
   *          the instance
   * @param minValue
   *          the min value
   * @param maxValue
   *          the max value
   * @return true, if successful
   */
  public static native boolean isValid(long instance, double minValue, double maxValue);

  /**
   * Native make stochastic.
   * 
   * @param instance
   *          the instance
   */
  public static native double makeStochastic(long instance);

  /**
   * Native make stochastic row.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   */
  public static native double makeStochasticRow(long instance, int row);

  /**
   * Native max element.
   * 
   * @param instance
   *          the instance
   * @return the double
   */
  public static native double maxElement(long instance);

  /**
   * Native max element.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @return the double
   */
  public static native double maxElement(long instance, int row);

  /**
   * Native min element.
   * 
   * @param instance
   *          the instance
   * @return the double
   */
  public static native double minElement(long instance);

  /**
   * Native min element.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @return the double
   */
  public static native double minElement(long instance, int row);

  /**
   * Native mul.
   * 
   * @param instance
   *          the instance
   * @param matrix
   *          the matrix
   */
  public static native void mul(long instance, long matrix);

  /**
   * Native mul row.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param value
   *          the value
   */
  public static native void mulRow(long instance, int row, double value);

  /**
   * Native new instance.
   * 
   * @return the long
   */
  public static native long newInstance();

  /**
   * Native orthogonalize.
   * 
   * @param instance
   *          the instance
   */
  public static native void orthogonalize(long instance);

  /**
   * Native pow.
   * 
   * @param instance
   *          the instance
   * @param value
   *          the value
   */
  public static native void pow(long instance, double value);

  /**
   * Native pow row.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param value
   *          the value
   */
  public static native void powRow(long instance, int row, double value);

  /**
   * Compute the matrix product x*y
   * 
   * @param instance
   *          the instance
   * @param x
   *          the first matrix
   * @param y
   *          the second matrix
   */
  public static native void product(long instance, long x, long y);

  /**
   * Native resize.
   * 
   * @param instance
   *          the instance
   * @param rowDimension
   *          the row dimension
   * @param colDimension
   *          the col dimension
   */
  public static native void resize(long instance, int rowDimension, int colDimension);

  /**
   * Native set col.
   * 
   * @param instance
   *          the instance
   * @param col
   *          the col
   * @param array
   *          the array
   */
  public static native void setCol(long instance, int col, long array);

  /**
   * Native set column
   * 
   * @param instance
   *          the instance
   * @param col
   *          the column
   * @param array
   *          the array used to fill the column
   */
  public static native void setColJava(long instance, int col, double[] array);

  /**
   * Native set element.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param col
   *          the col
   * @param value
   *          the value
   */
  public static native void setElement(long instance, int row, int col, double value);

  /**
   * Native set row.
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param array
   *          the array
   */
  public static native void setRow(long instance, int row, long array);

  /**
   * Native set row
   * 
   * @param instance
   *          the instance
   * @param row
   *          the row
   * @param array
   *          the array used to fill the row
   */
  public static native void setRowJava(long instance, int row, double[] array);

  public static native void sub(long instance, long matrix);

  /**
   * Native swap col.
   * 
   * @param instance
   *          the instance
   * @param coli
   *          the coli
   * @param colj
   *          the colj
   */
  public static native void swapCol(long instance, int coli, int colj);

  /**
   * Native swap row.
   * 
   * @param instance
   *          the instance
   * @param rowi
   *          the rowi
   * @param rowj
   *          the rowj
   */
  public static native void swapRow(long instance, int rowi, int rowj);
}
