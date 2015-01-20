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

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import junit.framework.Assert;
import junit.framework.TestCase;
import org.apache.log4j.BasicConfigurator;

public class SerializationTest extends TestCase {
  static {
    BasicConfigurator.resetConfiguration();
    BasicConfigurator.configure();
  }

  public void testSerializationArrayOfBoolean() throws IOException, ClassNotFoundException {
    final ArrayOfBoolean obj = new ArrayOfBoolean();
    for (int i = 0; i < 30; ++i) {
      obj.pushBack(i % 2 == 0);
    }

    final ByteArrayOutputStream baos = new ByteArrayOutputStream();
    final ObjectOutputStream out = new ObjectOutputStream(baos);
    out.writeObject(obj);
    out.close();

    final ByteArrayInputStream bais = new ByteArrayInputStream(baos.toByteArray());
    final ObjectInputStream in = new ObjectInputStream(bais);

    final ArrayOfBoolean obj2 = (ArrayOfBoolean) in.readObject();

    for (int i = 0; i < 30; ++i) {
      Assert.assertEquals(obj.get(i), obj2.get(i));
    }
  }

  public void testSerializationArrayOfDouble() throws IOException, ClassNotFoundException {
    final ArrayOfDouble obj = new ArrayOfDouble();
    for (int i = 0; i < 30; ++i) {
      obj.pushBack(i);
    }

    final ByteArrayOutputStream baos = new ByteArrayOutputStream();
    final ObjectOutputStream out = new ObjectOutputStream(baos);
    out.writeObject(obj);
    out.close();

    final ByteArrayInputStream bais = new ByteArrayInputStream(baos.toByteArray());
    final ObjectInputStream in = new ObjectInputStream(bais);

    final ArrayOfDouble obj2 = (ArrayOfDouble) in.readObject();

    for (int i = 0; i < 30; ++i) {
      Assert.assertEquals(obj.get(i), obj2.get(i), 0.001);
    }
  }

  public void testSerializationArrayOfInteger() throws IOException, ClassNotFoundException {
    final ArrayOfInteger obj = new ArrayOfInteger();
    for (int i = 0; i < 30; ++i) {
      obj.pushBack(i);
    }

    final ByteArrayOutputStream baos = new ByteArrayOutputStream();
    final ObjectOutputStream out = new ObjectOutputStream(baos);
    out.writeObject(obj);
    out.close();

    final ByteArrayInputStream bais = new ByteArrayInputStream(baos.toByteArray());
    final ObjectInputStream in = new ObjectInputStream(bais);

    final ArrayOfInteger obj2 = (ArrayOfInteger) in.readObject();

    for (int i = 0; i < 30; ++i) {
      Assert.assertEquals(obj.get(i), obj2.get(i));
    }
  }

  public void testSerializationMatrixOfBoolean() throws IOException, ClassNotFoundException {
    final MatrixOfBoolean obj = new MatrixOfBoolean();
    obj.resize(30, 30);
    for (int i = 0; i < 30; ++i) {
      for (int j = 0; j < 30; ++j) {
        obj.set(i, j, i % 2 == 0);
      }
    }

    final ByteArrayOutputStream baos = new ByteArrayOutputStream();
    final ObjectOutputStream out = new ObjectOutputStream(baos);
    out.writeObject(obj);
    out.close();

    final ByteArrayInputStream bais = new ByteArrayInputStream(baos.toByteArray());
    final ObjectInputStream in = new ObjectInputStream(bais);

    final MatrixOfBoolean obj2 = (MatrixOfBoolean) in.readObject();

    for (int i = 0; i < 30; ++i) {
      for (int j = 0; j < 30; ++j) {
        Assert.assertEquals(obj.get(i, j), obj2.get(i, j));
      }
    }
  }

  public void testSerializationMatrixOfDouble() throws IOException, ClassNotFoundException {
    final MatrixOfDouble obj = new MatrixOfDouble();
    obj.resize(30, 30);
    for (int i = 0; i < 30; ++i) {
      for (int j = 0; j < 30; ++j) {
        obj.set(i, j, i);
      }
    }

    final ByteArrayOutputStream baos = new ByteArrayOutputStream();
    final ObjectOutputStream out = new ObjectOutputStream(baos);
    out.writeObject(obj);
    out.close();

    final ByteArrayInputStream bais = new ByteArrayInputStream(baos.toByteArray());
    final ObjectInputStream in = new ObjectInputStream(bais);

    final MatrixOfDouble obj2 = (MatrixOfDouble) in.readObject();

    for (int i = 0; i < 30; ++i) {
      for (int j = 0; j < 30; ++j) {
        Assert.assertEquals(obj.get(i, j), obj2.get(i, j), 0.001);
      }
    }
  }

  public void testSerializationMatrixOfInteger() throws IOException, ClassNotFoundException {
    final MatrixOfInteger obj = new MatrixOfInteger();
    obj.resize(30, 30);
    for (int i = 0; i < 30; ++i) {
      for (int j = 0; j < 30; ++j) {
        obj.set(i, j, i);
      }
    }

    final ByteArrayOutputStream baos = new ByteArrayOutputStream();
    final ObjectOutputStream out = new ObjectOutputStream(baos);
    out.writeObject(obj);
    out.close();

    final ByteArrayInputStream bais = new ByteArrayInputStream(baos.toByteArray());
    final ObjectInputStream in = new ObjectInputStream(bais);

    final MatrixOfInteger obj2 = (MatrixOfInteger) in.readObject();

    for (int i = 0; i < 30; ++i) {
      for (int j = 0; j < 30; ++j) {
        Assert.assertEquals(obj.get(i, j), obj2.get(i, j));
      }
    }
  }
}
