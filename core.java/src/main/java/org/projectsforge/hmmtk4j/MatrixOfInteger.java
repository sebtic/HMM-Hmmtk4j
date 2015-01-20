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
 * The Class managing a matrix of integer.
 */
public final class MatrixOfInteger implements Cloneable, Serializable, DeepCloneable {

  private static final class BackedColumnList extends AbstractList<Integer> implements
      RandomAccess, Serializable {

    private final MatrixOfInteger matrix;
    private final int column;

    public BackedColumnList(final MatrixOfInteger matrix, final int column) {
      this.matrix = matrix;
      this.column = column;
    }

    @Override
    public Integer get(final int index) {
      return matrix.get(index, column);
    }

    @Override
    public Integer set(final int index, final Integer element) {
      final int oldValue = matrix.get(index, column);
      matrix.set(index, column, element);
      return oldValue;
    }

    @Override
    public int size() {
      return matrix.getRowCount();
    }

  }

  private static final class BackedRowList extends AbstractList<Integer> implements RandomAccess,
      Serializable {

    private final MatrixOfInteger matrix;
    private final int row;

    public BackedRowList(final MatrixOfInteger matrix, final int row) {
      this.matrix = matrix;
      this.row = row;
    }

    @Override
    public Integer get(final int index) {
      return matrix.get(row, index);
    }

    @Override
    public Integer set(final int index, final Integer element) {
      final int oldValue = matrix.get(row, index);
      matrix.set(row, index, element);
      return oldValue;
    }

    @Override
    public int size() {
      return matrix.getColCount();
    }

  }

  /**
 *
 */
  private static final long serialVersionUID = 2351634991256585745L;

  transient long instance;

  /**
   * Instantiates a new matrix of integer.
   */
  public MatrixOfInteger() {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.newInstance();
  }

  /**
   * Instantiates a new matrix of integer.
   * 
   * @param rowCount
   *          the row count
   * @param colCount
   *          the col count
   */
  public MatrixOfInteger(final int rowCount, final int colCount) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.resize(instance, rowCount,
        colCount);
  }

  /**
   * Instantiates a new matrix of integer.
   * 
   * @param rowCount
   *          the row count
   * @param colCount
   *          the col count
   * @param value
   *          the value to which the element are initialized
   */
  public MatrixOfInteger(final int rowCount, final int colCount, final int value) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.resize(instance, rowCount,
        colCount);
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.fill(instance, value);
  }

  /**
   * Instantiates a new matrix of integer.
   * 
   * @param matrixOfInteger
   *          the matrix of integer
   */
  public MatrixOfInteger(final MatrixOfInteger matrixOfInteger) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.newInstance();
    copy(matrixOfInteger);
  }

  /**
   * Clear the matrix by reducing the size to 0x0.
   */
  public void clear() {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.clear(instance);
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new MatrixOfInteger(this);
  }

  /**
   * Copy a matrix.
   * 
   * @param matrix
   *          the matrix
   */
  public void copy(final MatrixOfInteger matrix) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.copy(instance, matrix.instance);
  }

  @Override
  public DeepCloneable deepClone() {
    return new MatrixOfInteger(this);
  }

  /**
   * Fill the matrix with the provided element.
   * 
   * @param value
   *          the value
   */
  public void fill(final int value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.fill(instance, value);
  }

  /**
   * Fill the row with the provided element.
   * 
   * @param row
   *          the row index
   * @param value
   *          the value
   */
  public void fillRow(final int row, final int value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.fillRow(instance, row, value);
  }

  /**
   * {@inheritDoc}
   * 
   * @see java.lang.Object#finalize()
   */
  @Override
  protected void finalize() {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.deleteInstance(instance);
  }

  /**
   * Gets the element.
   * 
   * @param x
   *          the row
   * @param y
   *          the column
   * @return the element
   */
  public int get(final int x, final int y) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.getElement(instance, x, y);
  }

  /**
   * Gets the column.
   * 
   * @param col
   *          the column
   * @return the column
   */
  public ArrayOfInteger getCol(final int col) {
    final ArrayOfInteger array = new ArrayOfInteger();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.getCol(instance, col,
        array.instance);
    return array;
  }

  /**
   * Gets the column.
   * 
   * @param col
   *          the column
   * @return the column
   */
  public int[] getCol(final int col, final int[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.getColJava(instance, col, array);
    return array;
  }

  /**
   * Get a view of a column as a standard backed Java list. The modification on
   * the returned list are done on the matrix.
   * 
   *@param column
   *          the column index
   * @return the list
   */
  public List<Integer> getColAsBackedList(final int column) {
    return new BackedColumnList(this, column);
  }

  /**
   * Gets the column count.
   * 
   * @return the colCount
   */
  public int getColCount() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.getColCount(instance);
  }

  /**
   * Gets the row.
   * 
   * @param row
   *          the row
   * @return the row
   */
  public ArrayOfInteger getRow(final int row) {
    final ArrayOfInteger array = new ArrayOfInteger();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.getRow(instance, row,
        array.instance);
    return array;
  }

  /**
   * Gets the row.
   * 
   * @param row
   *          the row
   * @return the row
   */
  public int[] getRow(final int row, final int[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.getRowJava(instance, row, array);
    return array;
  }

  /**
   * Get a view of a row as a standard backed Java list. The modification on the
   * returned list are done on the matrix.
   * 
   *@param row
   *          the row index
   * @return the list
   */
  public List<Integer> getRowAdBackedList(final int row) {
    return new BackedRowList(this, row);
  }

  /**
   * Gets the row count.
   * 
   * @return the rowCount
   */
  public int getRowCount() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.getRowCount(instance);
  }

  /**
   * Computes the index of the greatest element of the row.
   * 
   * @param row
   *          the row index
   * @return the index or -1 if the array is empty
   */
  public int indexOfMaxElement(final int row) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.indexOfMaxElement(instance,
        row);
  }

  /**
   * Computes the index of the smallest element of the row.
   * 
   * @param row
   *          the row index
   * @return the index or -1 if the array is empty
   */
  public int indexOfMinElement(final int row) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.indexOfMinElement(instance,
        row);
  }

  /**
   * Checks if the elements of the matrix are in the provided range.
   * 
   * @param minValue
   *          the min value
   * @param maxValue
   *          the max value
   * @return true, if is valid
   */
  public boolean isValid(final int minValue, final int maxValue) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.isValid(instance, minValue,
        maxValue);
  }

  /**
   * Computes the greatest element of the matrix.
   * 
   * @return the double
   */
  public double maxElement() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.maxElement(instance);
  }

  /**
   * Computes the greatest element of the row.
   * 
   * @param row
   *          the row
   * @return the double
   */
  public double maxElement(final int row) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.maxElement(instance, row);
  }

  /**
   * Computes the smallest element of the matrix.
   * 
   * @return the double
   */
  public double minElement() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.minElement(instance);
  }

  /**
   * Computes the smallest element of the row.
   * 
   * @param row
   *          the row
   * @return the double
   */
  public double minElement(final int row) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.minElement(instance, row);
  }

  private void readObject(final ObjectInputStream in) throws IOException, ClassNotFoundException {
    in.defaultReadObject();

    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.newInstance();
    final int row = in.readInt();
    final int col = in.readInt();
    resize(row, col);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        set(i, j, in.readInt());
      }
    }
  }

  /**
   * Resize the matrix
   * 
   * @param newRowCount
   *          the row count
   * @param newColCount
   *          the column count
   * @warnings the content of the matrix is not preserved
   */
  public void resize(final int newRowCount, final int newColCount) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.resize(instance, newRowCount,
        newColCount);
  }

  /**
   * Sets the element.
   * 
   * @param x
   *          the row
   * @param y
   *          the column
   * @param value
   *          the value
   */
  public void set(final int x, final int y, final int value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.setElement(instance, x, y, value);
  }

  /**
   * Sets the column.
   * 
   * @param col
   *          the column
   * @param array
   *          the array
   */
  public void setCol(final int col, final ArrayOfInteger array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.setCol(instance, col,
        array.instance);
  }

  /**
   * Sets the column.
   * 
   * @param col
   *          the column
   * @param array
   *          the array
   */
  public void setCol(final int col, final int[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.setColJava(instance, col, array);
  }

  /**
   * Sets the column count.
   * 
   * @param colCount
   *          the colCount to set
   */
  public void setColCount(final int colCount) {
    resize(org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.getRowCount(instance),
        colCount);
  }

  /**
   * Sets the row.
   * 
   * @param row
   *          the row
   * @param array
   *          the array
   */
  public void setRow(final int row, final ArrayOfInteger array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.setRow(instance, row,
        array.instance);
  }

  /**
   * Sets the row.
   * 
   * @param row
   *          the row
   * @param array
   *          the array
   */
  public void setRow(final int row, final int[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.setRowJava(instance, row, array);
  }

  /**
   * Sets the row count.
   * 
   * @param rowCount
   *          the rowCount to set
   */
  public void setRowCount(final int rowCount) {
    resize(rowCount, org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger
        .getColCount(instance));
  }

  /**
   * Swap two columns.
   * 
   * @param coli
   *          the first column
   * @param colj
   *          the second column
   */
  public void swapCol(final int coli, final int colj) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.swapCol(instance, coli, colj);
  }

  /**
   * Swap two rows.
   * 
   * @param rowi
   *          the first row
   * @param rowj
   *          the second row
   */
  public void swapRow(final int rowi, final int rowj) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger.swapRow(instance, rowi, rowj);
  }

  private void writeObject(final ObjectOutputStream out) throws IOException {
    out.defaultWriteObject();

    final int row = getRowCount();
    final int col = getColCount();
    out.writeInt(row);
    out.writeInt(col);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        out.writeInt(get(i, j));
      }
    }
  }

}
