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

public final class MatrixOfDouble implements Duplicable {
  double data[][];

  /**
   * Instantiates a new matrix of double.
   */
  public MatrixOfDouble() {
    data = new double[0][0];
  }

  /**
   * Instantiates a new matrix of double.
   * @param rowCount the row count
   * @param colCount the col count
   */
  public MatrixOfDouble(final int rowCount, final int colCount) {
    data = new double[0][0];
    resize(rowCount, colCount);
  }

  /**
   * Instantiates a new matrix of double.
   * @param rowCount the row count
   * @param colCount the col count
   * @param value the value to which the element are initialized
   */
  public MatrixOfDouble(final int rowCount, final int colCount,
      final double value) {
    data = new double[0][0];
    resize(rowCount, colCount);
    fill(value);
  }

  /**
   * Instantiates a new matrix of double.
   * @param matrixOfDouble the matrix of double
   */
  public MatrixOfDouble(final MatrixOfDouble matrixOfDouble) {
    data = new double[0][0];
    copy(matrixOfDouble);
  }

  /**
   * Clear the matrix by reducing the size to 0x0.
   */
  public void clear() {
    data = new double[0][0];
  }

  /**
   * Copy a matrix.
   * @param matrix the matrix
   */
  public void copy(final MatrixOfDouble matrix) {
    if (matrix.data.length != 0) {
      data = new double[matrix.data.length][matrix.data[0].length];
    } else {
      data = new double[0][0];
    }
  }

  public Duplicable duplicate() {
    return new MatrixOfDouble(this);
  }

  /**
   * Fill the matrix with the provided element.
   * @param value the value
   */
  public void fill(final double value) {
    for (int i = 0; i < data.length; ++i) {
      for (int j = 0; j < data[i].length; ++j) {
        data[i][j] = value;
      }
    }
  }

  public final double get(final int x, final int y) {
    return data[x][y];
  }

  public int getColCount() {
    if (data.length != 0) {
      return data[0].length;
    } else {
      return 0;
    }
  }

  public int getRowCount() {
    return data.length;
  }

  public boolean isValid(final double minValue, final double maxValue) {
    for (int i = 0; i < data.length; ++i) {
      for (int j = 0; j < data[i].length; ++j) {
        if ((data[i][j] < minValue) || (data[i][j] > maxValue)) {
          return false;
        }
      }
    }
    return true;
  }

  public void makeStochastic() {
    for (int i = 0; i < data.length; ++i) {
      makeStochasticRow(i);
    }
  }

  public double makeStochasticRow(final int row) {
    double sum = 0;
    for (int i = 0; i < data[row].length; ++i) {
      sum += data[row][i];
    }
    final double coef = 1 / sum;
    for (int i = 0; i < data[row].length; ++i) {
      data[row][i] *= coef;
    }
    return sum;
  }

  public void resize(final int newRowCount, final int newColCount) {
    data = new double[newRowCount][newColCount];
  }

  public void set(final int x, final int y, final double value) {
    data[x][y] = value;
  }
}
