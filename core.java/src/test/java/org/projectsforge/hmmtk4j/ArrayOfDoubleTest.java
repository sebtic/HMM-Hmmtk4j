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

import java.util.Random;
import junit.framework.Assert;
import junit.framework.TestCase;
import org.apache.log4j.BasicConfigurator;

// TODO: Auto-generated Javadoc
/**
 * Test class for ArrayOfDouble.
 * 
 * @author Sébastien Aupetit
 */
public class ArrayOfDoubleTest extends TestCase {

  static {
    BasicConfigurator.resetConfiguration();
    BasicConfigurator.configure();
  }

  /**
   * An array of double.
   */
  // public ArrayOfDouble arraytotest = new ArrayOfDouble(10);
  /**
   * An empty constructor
   */
  public ArrayOfDoubleTest() {
    // nothing to do
  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#ArrayOfDouble()}.
   */
  public void testArrayOfDouble() {

    final ArrayOfDouble obj = new ArrayOfDouble(10);
    Assert.assertNotNull(obj);
  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#ArrayOfDouble(int)}.
   */
  public void testArrayOfDoubleInt() {
    final ArrayOfDouble obj = new ArrayOfDouble(10);
    Assert.assertNotNull(obj);
    Assert.assertEquals(10, obj.getCount());
  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#ArrayOfDouble(int, double)}.
   */
  public void testArrayOfDoubleIntDouble() {
    final ArrayOfDouble obj = new ArrayOfDouble(10, 1.);
    Assert.assertNotNull(obj);
    Assert.assertEquals(10, obj.getCount());
    for (int i = 0; i < 10; ++i) {
      Assert.assertEquals(obj.get(i), 1., 0.01);
    }
  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#copy(org.projectsforge.hmmtk4j.ArrayOfDouble)}
   * .
   */
  public void testCopy() {
    final ArrayOfDouble obj = new ArrayOfDouble(10, 1.);
    final ArrayOfDouble obj2 = new ArrayOfDouble();
    final Random r = new Random();

    obj2.copy(obj);
    for (int i = 0; i < obj.getCount(); ++i) {
      Assert.assertEquals(obj.get(i), obj2.get(i), 0.01);
    }

    for (int k = 0; k < 100; ++k) {
      final int dim = Randomizer.getRandomGenerator().nextInt(5000);
      final boolean preserve = Randomizer.getRandomGenerator().nextBoolean();
      final double val = r.nextDouble() * 20;
      obj.resize(dim, preserve);
      obj.fill(val);

      obj2.copy(obj);
      for (int i = 0; i < obj.getCount(); ++i) {
        Assert.assertEquals(obj.get(i), obj2.get(i), 0.01);
        Assert.assertEquals(obj.get(i), val, 0.01);
      }
    }

  }

  /**
   * Test method for {@link org.projectsforge.hmmtk4j.ArrayOfDouble#erase(int)}.
   */
  public void testErase() {
    final ArrayOfDouble obj = new ArrayOfDouble();

    for (int i = 0; i < 10; ++i) {
      obj.pushBack(i);
    }

    for (int i = 9; i >= 0; i -= 2) {
      obj.erase(i);
    }

    for (int i = 0; i < 5; ++i) {
      Assert.assertEquals(obj.get(i), 2 * i, 0.01);
    }

    final Random r = new Random();
    for (int i = 0; i < 500; ++i) {
      obj.erase(r.nextInt(obj.getCount()));
      obj.pushBack(i);
    }
  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#fill(double)}.
   */
  public void testFill() {
    final ArrayOfDouble obj = new ArrayOfDouble(10, 1.);

    for (int i = 0; i < 1000; ++i) {
      final int dim = Randomizer.getRandomGenerator().nextInt(5000);
      final boolean preserve = Randomizer.getRandomGenerator().nextBoolean();
      final double val = Randomizer.getRandomGenerator().nextDouble() * 20;
      obj.resize(dim, preserve);
      obj.fill(val);
      for (int j = 0; j < dim; ++j) {
        Assert.assertEquals(obj.get(j), val, 0.01);
      }
    }
  }

  /**
   * Test get/set of java array.
   */
  public void testGetSetJavaArray() {
    for (int essai = 1; essai < 1000; ++essai) {
      final ArrayOfDouble obj = new ArrayOfDouble(essai, 1.);
      final double[] values = new double[obj.getCount()];

      Assert.assertEquals(essai, obj.getCount());
      obj.get(values);
      for (int i = 0; i < obj.getCount(); ++i) {
        Assert.assertEquals(values[i], 1., 0.01);
      }

      final double[] values2 = new double[1 + obj.getCount() / 2];
      for (int i = 0; i < values2.length; ++i) {
        values2[i] = i;
      }
      obj.set(values2);
      Assert.assertEquals(values2.length, obj.getCount());
      for (int i = 0; i < obj.getCount(); ++i) {
        Assert.assertEquals(values2[i], i, 0.01);
      }

    }
  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#insert(int, double)}.
   */
  public void testInsertIntDouble() {
    final ArrayOfDouble obj = new ArrayOfDouble();

    for (int i = 1; i < 10; ++i) {
      obj.insert(i - 1, i);
    }

    for (int i = 0; i < 10; ++i) {
      obj.insert(0, -i);
    }

    for (int i = 0; i < 19; ++i) {
      Assert.assertEquals(obj.get(i), i - 9, 0.01);
    }

  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#pushBack(org.projectsforge.hmmtk4j.ArrayOfDouble)}
   * .
   */
  public void testPushBackArrayOfDouble() {
    final ArrayOfDouble obj = new ArrayOfDouble();
    final ArrayOfDouble obj2 = new ArrayOfDouble();

    for (int i = 0; i < 10; ++i) {
      obj.pushBack(i);
    }
    for (int i = 0; i < 10; ++i) {
      obj2.pushBack(i + 10);
    }

    obj.pushBack(obj2);
    obj.pushBack(obj);
    Assert.assertEquals(obj2.getCount(), 10);
    Assert.assertEquals(obj.getCount(), 40);
    for (int i = 0; i < 40; ++i) {
      Assert.assertEquals(obj.get(i), i % 20, 0.01);
    }
  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#pushBack(double)}.
   */
  public void testPushBackDouble() {
    final ArrayOfDouble obj = new ArrayOfDouble();
    final Random r = new Random();

    for (int k = 0; k < 100; ++k) {
      obj.clear();
      final int dim = r.nextInt(5000);
      for (int i = 0; i < dim; ++i) {
        obj.pushBack(i);
      }

      Assert.assertEquals(obj.getCount(), dim);
      for (int i = 0; i < dim; ++i) {
        Assert.assertEquals(obj.get(i), i, 0.01);
      }
    }
  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#resize(int, boolean)} .
   */
  public void testResizeIntBoolean() {
    final ArrayOfDouble obj = new ArrayOfDouble(10, 1.);

    for (int i = 0; i < 100; ++i) {
      final int dim = Randomizer.getRandomGenerator().nextInt(5000);
      final boolean preserve = Randomizer.getRandomGenerator().nextBoolean();
      obj.resize(dim, preserve);
      Assert.assertEquals(dim, obj.getCount());
    }
  }

  /**
   * Test method for.
   * 
   * {@link org.projectsforge.hmmtk4j.ArrayOfDouble#resize(int, boolean, boolean)}
   * .
   */
  public void testResizeIntBooleanBoolean() {
    final ArrayOfDouble obj = new ArrayOfDouble(10, 1.);

    for (int i = 0; i < 100; ++i) {
      final int dim = Randomizer.getRandomGenerator().nextInt(5000);
      final boolean preserve = Randomizer.getRandomGenerator().nextBoolean();
      final boolean reduce = Randomizer.getRandomGenerator().nextBoolean();
      obj.resize(dim, preserve, reduce);
      Assert.assertEquals(dim, obj.getCount());
    }
  }

}
