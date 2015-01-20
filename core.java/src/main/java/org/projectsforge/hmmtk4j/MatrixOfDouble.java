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
 * The Class managing a matrix of double.
 */
public final class MatrixOfDouble implements Cloneable, Serializable, DeepCloneable {

  private static final class BackedColumnList extends AbstractList<Double> implements RandomAccess,
      Serializable {

    private final MatrixOfDouble matrix;
    private final int column;

    public BackedColumnList(final MatrixOfDouble matrix, final int column) {
      this.matrix = matrix;
      this.column = column;
    }

    @Override
    public Double get(final int index) {
      return matrix.get(index, column);
    }

    @Override
    public Double set(final int index, final Double element) {
      final double oldValue = matrix.get(index, column);
      matrix.set(index, column, element);
      return oldValue;
    }

    @Override
    public int size() {
      return matrix.getRowCount();
    }

  }

  private static final class BackedRowList extends AbstractList<Double> implements RandomAccess,
      Serializable {

    private final MatrixOfDouble matrix;
    private final int row;

    public BackedRowList(final MatrixOfDouble matrix, final int row) {
      this.matrix = matrix;
      this.row = row;
    }

    @Override
    public Double get(final int index) {
      return matrix.get(row, index);
    }

    @Override
    public Double set(final int index, final Double element) {
      final double oldValue = matrix.get(row, index);
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
  private static final long serialVersionUID = -2469602635279372548L;

  transient long instance;

  /**
   * Instantiates a new matrix of double.
   */
  public MatrixOfDouble() {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.newInstance();
  }

  /**
   * Instantiates a new matrix of double.
   * 
   * @param rowCount
   *          the row count
   * @param colCount
   *          the col count
   */
  public MatrixOfDouble(final int rowCount, final int colCount) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble
        .resize(instance, rowCount, colCount);
  }

  /**
   * Instantiates a new matrix of double.
   * 
   * @param rowCount
   *          the row count
   * @param colCount
   *          the col count
   * @param value
   *          the value to which the element are initialized
   */
  public MatrixOfDouble(final int rowCount, final int colCount, final double value) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.newInstance();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble
        .resize(instance, rowCount, colCount);
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.fill(instance, value);
  }

  /**
   * Instantiates a new matrix of double.
   * 
   * @param matrixOfDouble
   *          the matrix of double
   */
  public MatrixOfDouble(final MatrixOfDouble matrixOfDouble) {
    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.newInstance();
    copy(matrixOfDouble);
  }

  /**
   * Adds the value to each element.
   * 
   * @param value
   *          the value
   */
  public void add(final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.add(instance, value);
  }

  public void add(final MatrixOfDouble matrix) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.add(instance, matrix.instance);
  }

  /**
   * Adds the value to each element of the row.
   * 
   * @param row
   *          the row index
   * @param value
   *          the value
   */
  public void addToRow(final int row, final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.addToRow(instance, row, value);
  }

  /**
   * Apply a mask on the matrix. The elements are nulled if the corresponding
   * value is false.
   * 
   * @param mask
   *          the matrix
   */
  public void applyMask(final MatrixOfBoolean mask) {
    if (mask != null) {
      org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble
          .applyMask(instance, mask.instance);
    }
  }

  /**
   * Clear the matrix by reducing the size to 0x0.
   */
  public void clear() {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.clear(instance);
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new MatrixOfDouble(this);
  }

  /**
   * Copy a matrix.
   * 
   * @param matrix
   *          the matrix
   */
  public void copy(final MatrixOfDouble matrix) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.copy(instance, matrix.instance);
  }

  /**
   * Count elements which have the same value as the parameter.
   * 
   * @param value
   *          the value
   * @param row
   *          the row
   * @return the number of elements equal to value
   */
  public int countElementsOnRow(final int row, final double value) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.countElementsOnRow(instance,
        row, value);
  }

  @Override
  public DeepCloneable deepClone() {
    return new MatrixOfDouble(this);
  }

  /**
   * Fill the matrix with the provided element.
   * 
   * @param value
   *          the value
   */
  public void fill(final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.fill(instance, value);
  }

  /**
   * Fill the matrix row with the provided element.
   * 
   * @param row
   *          the row index
   * @param value
   *          the value
   */
  public void fillRow(final int row, final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.fillRow(instance, row, value);
  }

  /**
   * {@inheritDoc}
   * 
   * @see java.lang.Object#finalize()
   */
  @Override
  protected void finalize() {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.deleteInstance(instance);
  }

  /**
   * Raise the square matrix to the power 4\sup{powerLevel}
   * 
   * @param powerLevel
   *          the power level base
   */
  public void fourthpowerSquareMatrix(final int powerLevel) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.fourthpowerSquareMatrix(instance,
        powerLevel);
  }

  /**
   * Generate a stochastic matrix.
   * 
   * @param allowNullProbabilities
   *          the allow null probabilities
   */
  public void generateStochasticMatrix(final boolean allowNullProbabilities) {
    Randomizer.generateAStochasticMatrix(this, allowNullProbabilities);
  }

  /**
   * Generate a stochastic row.
   * 
   * @param allowNullProbabilities
   *          the allow null probabilities
   * @param row
   *          the row
   */
  public void generateStochasticRow(final int row, final boolean allowNullProbabilities) {
    Randomizer.generateAStochasticMatrixRow(this, row, allowNullProbabilities);
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
  public final double get(final int x, final int y) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.getElement(instance, x, y);
  }

  /**
   * Gets the column.
   * 
   * @param col
   *          the column
   * @return the column
   */
  public ArrayOfDouble getCol(final int col) {
    final ArrayOfDouble array = new ArrayOfDouble();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.getCol(instance, col,
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
  public double[] getCol(final int col, final double[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.getColJava(instance, col, array);
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
  public List<Double> getColAsBackedList(final int column) {
    return new BackedColumnList(this, column);
  }

  /**
   * Gets the column count.
   * 
   * @return the colCount
   */
  public int getColCount() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.getColCount(instance);
  }

  /**
   * Gets the row.
   * 
   * @param row
   *          the row
   * @return the row
   */
  public ArrayOfDouble getRow(final int row) {
    final ArrayOfDouble array = new ArrayOfDouble();
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.getRow(instance, row,
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
  public double[] getRow(final int row, final double[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.getRowJava(instance, row, array);
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
  public List<Double> getRowAdBackedList(final int row) {
    return new BackedRowList(this, row);
  }

  /**
   * Gets the row count.
   * 
   * @return the rowCount
   */
  public int getRowCount() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.getRowCount(instance);
  }

  /**
   * Computes the index of the greatest element of the row.
   * 
   * @param row
   *          the row
   * @return the index or -1 if the array is empty
   */
  public int indexOfMaxElement(final int row) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.indexOfMaxElement(instance,
        row);
  }

  /**
   * Computes the index of the smallest element of the row.
   * 
   * @param row
   *          the row index
   * @return the index of -1 if the array is empty
   */
  public int indexOfMinElement(final int row) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.indexOfMinElement(instance,
        row);
  }

  /**
   * Compute the inner product of two columns of the matrix
   * 
   * @param coli
   *          the first column index
   * @param colj
   *          the second column index
   * @return the inner product
   */
  double innerProductOfCols(final int coli, final int colj) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.innerProductOfCols(instance,
        coli, colj);
  }

  /**
   * Compute the inner product of two rows of the matrix
   * 
   * @param rowi
   *          the first row index
   * @param rowj
   *          the second row index
   * @return the inner product
   */
  double innerProductOfRows(final int rowi, final int rowj) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.innerProductOfRows(instance,
        rowi, rowj);
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
  public boolean isValid(final double minValue, final double maxValue) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.isValid(instance, minValue,
        maxValue);
  }

  public double l2Norm() {
    double sum = 0;
    for (int i = getRowCount() - 1; i >= 0; --i) {
      sum += innerProductOfRows(i, i);
    }
    return Math.sqrt(sum);
  }

  /**
   * Makes a stochastic matrix.
   */
  public double makeStochastic() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.makeStochastic(instance);
  }

  /**
   * Makes the row a stochastic vector.
   * 
   * @param row
   *          the row index
   */
  public double makeStochasticRow(final int row) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.makeStochasticRow(instance,
        row);
  }

  /**
   * Computes the greatest element of the matrix.
   * 
   * @return the double
   */
  public double maxElement() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.maxElement(instance);
  }

  /**
   * Computes the greatest element of the row.
   * 
   * @param row
   *          the row
   * @return the double
   */
  public double maxElement(final int row) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.maxElement(instance, row);
  }

  /**
   * Computes the smallest element of the matrix.
   * 
   * @return the double
   */
  public double minElement() {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.minElement(instance);
  }

  /**
   * Computes the smallest element of the row.
   * 
   * @param row
   *          the row
   * @return the double
   */
  public double minElement(final int row) {
    return org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.minElement(instance, row);
  }

  /**
   * Multiply each element of the matrix by the corresponding element.
   * 
   * @param matrix
   *          the matrix
   */
  public void mul(final MatrixOfDouble matrix) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.mul(instance, matrix.instance);
  }

  /**
   * Multiply each element of the row by the corresponding element.
   * 
   * @param row
   *          the row index
   * @param value
   *          the value
   */
  public void mulRow(final int row, final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.mulRow(instance, row, value);
  }

  /**
   * Orthogonalize the matrix
   */
  public void orthogonalize() {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.orthogonalize(instance);
  }

  /**
   * Raise each element of the matrix to the power value
   * 
   * @param value
   *          the power value
   */
  public void pow(final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.pow(instance, value);
  }

  /**
   * Raise each element of the row to the power value
   * 
   * @param row
   *          the row index
   * @param value
   *          the value
   */
  public void powRow(final int row, final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.powRow(instance, row, value);
  }

  /**
   * Compute the matrix product x*y
   * 
   * @param x
   *          the first matrix
   * @param y
   *          the second matrix
   */
  public void product(final MatrixOfDouble x, final MatrixOfDouble y) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.product(instance, x.instance,
        y.instance);
  }

  private void readObject(final ObjectInputStream in) throws IOException, ClassNotFoundException {
    in.defaultReadObject();

    instance = org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.newInstance();
    final int row = in.readInt();
    final int col = in.readInt();
    resize(row, col);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        set(i, j, in.readDouble());
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
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.resize(instance, newRowCount,
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
  public void set(final int x, final int y, final double value) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.setElement(instance, x, y, value);
  }

  /**
   * Sets the column.
   * 
   * @param col
   *          the column
   * @param array
   *          the array
   */
  public void setCol(final int col, final ArrayOfDouble array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.setCol(instance, col,
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
  public void setCol(final int col, final double[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.setColJava(instance, col, array);
  }

  /**
   * Sets the column count.
   * 
   * @param colCount
   *          the colCount to set
   */
  public void setColCount(final int colCount) {
    resize(org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.getRowCount(instance),
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
  public void setRow(final int row, final ArrayOfDouble array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.setRow(instance, row,
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
  public void setRow(final int row, final double[] array) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.setRowJava(instance, row, array);
  }

  /**
   * Sets the row count.
   * 
   * @param rowCount
   *          the rowCount to set
   */
  public void setRowCount(final int rowCount) {
    resize(rowCount, org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble
        .getColCount(instance));
  }

  public void sub(final MatrixOfDouble matrix) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.sub(instance, matrix.instance);
  }

  /**
   * Swap tow columns.
   * 
   * @param coli
   *          the frist column
   * @param colj
   *          the second column
   */
  public void swapCol(final int coli, final int colj) {
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.swapCol(instance, coli, colj);
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
    org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble.swapRow(instance, rowi, rowj);
  }

  public double unrootedL2Norm() {
    double sum = 0;
    for (int i = getRowCount() - 1; i >= 0; --i) {
      sum += innerProductOfRows(i, i);
    }
    return sum;
  }

  private void writeObject(final ObjectOutputStream out) throws IOException {
    out.defaultWriteObject();

    final int row = getRowCount();
    final int col = getColCount();
    out.writeInt(row);
    out.writeInt(col);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        out.writeDouble(get(i, j));
      }
    }
  }
}
