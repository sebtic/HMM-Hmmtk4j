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
 * The Class managing a matrix of boolean.
 */
public final class MatrixOfBoolean implements Cloneable, Serializable, DeepCloneable {

  private static final class BackedColumnList extends AbstractList<Boolean> implements
      RandomAccess, Serializable {

    private final MatrixOfBoolean matrix;
    private final int column;

    public BackedColumnList(final MatrixOfBoolean matrix, final int column) {
      this.matrix = matrix;
      this.column = column;
    }

    @Override
    public Boolean get(final int index) {
      return matrix.get(index, column);
    }

    @Override
    public Boolean set(final int index, final Boolean element) {
      final boolean oldValue = matrix.get(index, column);
      matrix.set(index, column, element);
      return oldValue;
    }

    @Override
    public int size() {
      return matrix.getRowCount();
    }

  }

  private static final class BackedRowList extends AbstractList<Boolean> implements RandomAccess,
      Serializable {

    private final MatrixOfBoolean matrix;
    private final int row;

    public BackedRowList(final MatrixOfBoolean matrix, final int row) {
      this.matrix = matrix;
      this.row = row;
    }

    @Override
    public Boolean get(final int index) {
      return matrix.get(row, index);
    }

    @Override
    public Boolean set(final int index, final Boolean element) {
      final boolean oldValue = matrix.get(row, index);
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
  private static final long serialVersionUID = 942799334577868644L;

  transient long instance;

  /**
   * Instantiates a new matrix of boolean.
   */
  public MatrixOfBoolean() {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.newInstance();
  }

  /**
   * Instantiates a new matrix of boolean.
   * 
   * @param rowCount
   *          the row count
   * @param colCount
   *          the col count
   */
  public MatrixOfBoolean(final int rowCount, final int colCount) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.resize(instance, rowCount,
        colCount);
  }

  /**
   * Instantiates a new matrix of boolean.
   * 
   * @param rowCount
   *          the row count
   * @param colCount
   *          the col count
   * @param value
   *          the value to which the element are initialized
   */
  public MatrixOfBoolean(final int rowCount, final int colCount, final boolean value) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.resize(instance, rowCount,
        colCount);
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.fill(instance, value);
  }

  /**
   * Instantiates a new matrix of boolean.
   * 
   * @param matrixOfBoolean
   *          the matrix of boolean
   */
  public MatrixOfBoolean(final MatrixOfBoolean matrixOfBoolean) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.newInstance();
    copy(matrixOfBoolean);
  }

  /**
   * Clear the matrix by reducing the size to 0x0.
   */
  public void clear() {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.clear(instance);
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new MatrixOfBoolean(this);
  }

  /**
   * Copy a matrix.
   * 
   * @param matrix
   *          the matrix to be copied
   */
  public void copy(final MatrixOfBoolean matrix) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.copy(instance, matrix.instance);
  }

  @Override
  public DeepCloneable deepClone() {
    return new MatrixOfBoolean(this);
  }

  /**
   * Fill the matrix with the provided element.
   * 
   * @param value
   *          the value
   */
  public void fill(final boolean value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.fill(instance, value);
  }

  /**
   * Fill the matrix row with the provided element.
   * 
   * @param row
   *          the row index
   * @param value
   *          the value
   */
  public void fillRow(final int row, final boolean value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.fillRow(instance, row, value);
  }

  /**
   * {@inheritDoc}
   * 
   * @see java.lang.Object#finalize()
   */
  @Override
  protected void finalize() {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.deleteInstance(instance);
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
  public boolean get(final int x, final int y) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.getElement(instance, x, y);
  }

  /**
   * Gets the column.
   * 
   * @param col
   *          the column
   * @return the column
   */
  public ArrayOfBoolean getCol(final int col) {
    final ArrayOfBoolean array = new ArrayOfBoolean();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.getCol(instance, col,
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
  public boolean[] getCol(final int col, final boolean[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.getColJava(instance, col, array);
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
  public List<Boolean> getColAsBackedList(final int column) {
    return new BackedColumnList(this, column);
  }

  /**
   * Gets the column count.
   * 
   * @return the colCount
   */
  public int getColCount() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.getColCount(instance);
  }

  /**
   * Gets the row.
   * 
   * @param row
   *          the row
   * @return the row
   */
  public ArrayOfBoolean getRow(final int row) {
    final ArrayOfBoolean array = new ArrayOfBoolean();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.getRow(instance, row,
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
  public boolean[] getRow(final int row, final boolean[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.getRowJava(instance, row, array);
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
  public List<Boolean> getRowAsBackedList(final int row) {
    return new BackedRowList(this, row);
  }

  /**
   * Gets the row count.
   * 
   * @return the rowCount
   */
  public int getRowCount() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.getRowCount(instance);
  }

  /**
   * Checks if the rows of the matrix are valid masks.
   * 
   * @return true, if is valid mask
   */
  public boolean isValidMask() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.isValidMask(instance);

  }

  private void readObject(final ObjectInputStream in) throws IOException, ClassNotFoundException {
    in.defaultReadObject();

    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.newInstance();
    final int row = in.readInt();
    final int col = in.readInt();
    resize(row, col);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        set(i, j, in.readBoolean());
      }
    }
  }

  /**
   * Resize the matrix.
   * 
   * @param newRowCount
   *          the new row count
   * @param newColCount
   *          the new column count
   */
  public void resize(final int newRowCount, final int newColCount) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.resize(instance, newRowCount,
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
  public void set(final int x, final int y, final boolean value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.setElement(instance, x, y, value);
  }

  /**
   * Sets the column.
   * 
   * @param col
   *          the column
   * @param array
   *          the array
   */
  public void setCol(final int col, final ArrayOfBoolean array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.setCol(instance, col,
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
  public void setCol(final int col, final boolean[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.setColJava(instance, col, array);
  }

  /**
   * Sets the column count.
   * 
   * @param colCount
   *          the colCount to set
   */
  public void setColCount(final int colCount) {
    resize(org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.getRowCount(instance),
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
  public void setRow(final int row, final ArrayOfBoolean array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.setRow(instance, row,
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
  public void setRow(final int row, final boolean[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.setRowJava(instance, row, array);
  }

  /**
   * Sets the row count.
   * 
   * @param rowCount
   *          the rowCount to set
   */
  public void setRowCount(final int rowCount) {
    resize(rowCount, org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean
        .getColCount(instance));
  }

  /**
   * Swap tow columns.
   * 
   * @param coli
   *          the first column
   * @param colj
   *          the second column
   */
  public void swapCol(final int coli, final int colj) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.swapCol(instance, coli, colj);
  }

  /**
   * Swap row.
   * 
   * @param rowi
   *          the first row
   * @param rowj
   *          the second row
   */
  public void swapRow(final int rowi, final int rowj) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean.swapRow(instance, rowi, rowj);
  }

  private void writeObject(final ObjectOutputStream out) throws IOException {
    out.defaultWriteObject();

    final int row = getRowCount();
    final int col = getColCount();
    out.writeInt(row);
    out.writeInt(col);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        out.writeBoolean(get(i, j));
      }
    }
  }
}
