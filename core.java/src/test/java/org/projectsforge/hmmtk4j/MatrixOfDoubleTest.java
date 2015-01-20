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

import junit.framework.Assert;
import junit.framework.TestCase;
import org.apache.log4j.BasicConfigurator;

/**
 * A test class for a matrix of double
 * 
 * @author Sébastien Aupetit
 */
public class MatrixOfDoubleTest extends TestCase {

  static {
    BasicConfigurator.resetConfiguration();
    BasicConfigurator.configure();
  }

  /**
   * A matrix of double
   */
  public MatrixOfDouble matrixtotest = new MatrixOfDouble(10, 17);

  /**
   * An empty constructor
   */
  public MatrixOfDoubleTest() {
    BasicConfigurator.configure();
  }

  /**
   * {@inheritDoc}
   * 
   * @see junit.framework.TestCase#setUp()
   */
  @Override
  protected void setUp() {
    BasicConfigurator.configure();
  }

  /**
   * Test method for
   * {@link org.projectsforge.hmmtk4j.MatrixOfDouble#fill(double)} .
   */
  public void testFill() {
    final MatrixOfDouble obj = new MatrixOfDouble();

    for (int i = 0; i < 100; ++i) {
      obj.resize(i, i);
      obj.fill(i);
      for (int k1 = 0; k1 < i; ++k1) {
        for (int k2 = 0; k2 < i; ++k2) {
          Assert.assertEquals(obj.get(k1, k2), i, 0.01);
        }
      }
    }

  }

  public void testFourthpowerSquareMatrix() {
    final MatrixOfDouble m = new MatrixOfDouble(10, 10, 1);
    m.fourthpowerSquareMatrix(10);
  }

  public void testGetSetCol() {
    final MatrixOfDouble obj = new MatrixOfDouble(10, 5);
    final double[] array = new double[obj.getRowCount()];
    for (int col = 0; col < obj.getColCount(); ++col) {
      for (int i = 0; i < array.length; ++i) {
        array[i] = col + i;
      }
      obj.setCol(col, array);
    }

    for (int row = 0; row < obj.getRowCount(); ++row) {
      for (int col = 0; col < obj.getColCount(); ++col) {
        Assert.assertEquals(row + col, obj.get(row, col), 0.1);
      }
    }

    for (int col = 0; col < obj.getColCount(); ++col) {
      obj.getCol(col, array);
      for (int i = 0; i < array.length; ++i) {
        Assert.assertEquals(col + i, array[i], 0.1);
      }
    }
  }

  /**
   * Test method for
   * {@link org.projectsforge.hmmtk4j.MatrixOfDouble#MatrixOfDouble()}.
   */
  public void testMatrixOfDouble() {
    final MatrixOfDouble obj = new MatrixOfDouble();
    Assert.assertNotNull(obj);
  }

  /**
   * Test method for
   * {@link org.projectsforge.hmmtk4j.MatrixOfDouble#MatrixOfDouble(int, int)}.
   */
  public void testMatrixOfDoubleIntInt() {
    final MatrixOfDouble obj = new MatrixOfDouble(10, 5);
    Assert.assertNotNull(obj);
    Assert.assertEquals(obj.getRowCount(), 10);
    Assert.assertEquals(obj.getColCount(), 5);

    final MatrixOfDouble obj2 = new MatrixOfDouble(5, 10);
    Assert.assertNotNull(obj2);
    Assert.assertEquals(obj2.getRowCount(), 5);
    Assert.assertEquals(obj2.getColCount(), 10);
  }

  public void testProduct() {
    final MatrixOfDouble m1 = new MatrixOfDouble(10, 5, 1);
    final MatrixOfDouble m2 = new MatrixOfDouble(5, 4, 2);
    final MatrixOfDouble m = new MatrixOfDouble();
    m.product(m1, m2);
  }

  /**
   * Test method for
   * {@link org.projectsforge.hmmtk4j.MatrixOfDouble#resize(int, int)} .
   */
  public void testResize() {
    final MatrixOfDouble obj = new MatrixOfDouble();

    for (int i = 0; i < 100; ++i) {
      obj.resize(i * 2, i * 3);
      obj.resize(i * 3, i * 2);
    }
  }

  public void testSetRow() {
    final MatrixOfDouble obj = new MatrixOfDouble(10, 5);
    final double[] array = new double[obj.getColCount()];
    for (int row = 0; row < obj.getRowCount(); ++row) {
      for (int i = 0; i < array.length; ++i) {
        array[i] = row + i;
      }
      obj.setRow(row, array);
    }

    for (int row = 0; row < obj.getRowCount(); ++row) {
      for (int col = 0; col < obj.getColCount(); ++col) {
        Assert.assertEquals(row + col, obj.get(row, col), 0.1);
      }
    }

    for (int row = 0; row < obj.getRowCount(); ++row) {
      obj.getRow(row, array);
      for (int i = 0; i < array.length; ++i) {
        Assert.assertEquals(row + i, array[i], 0.1);
      }
    }
  }

}
