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
package org.projectsforge.hmmtk4j.dmdhmm;

/**
 * Copyright 2010 Sébastien Aupetit <sebastien.aupetit@univ-tours.fr>
 * 
 * This file is part of HMMTK4J.
 * 
 * HMMTK4J is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 * 
 * HMMTK4J is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with HMMTK4J. If not, see <http://www.gnu.org/licenses/>.
 * 
 * $Id: SerializationTest.java 8 2010-06-01 16:56:49Z sebtic $
 */

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

  public void testSerializationSequence() throws IOException, ClassNotFoundException {
    final SequenceOfObservations obj = new SequenceOfObservations(new int[] { 5, 6, 3 });
    for (int i = 0; i < 30; ++i) {
      obj.getData(0).pushBack(i % 5);
      obj.getData(1).pushBack(i % 6);
      obj.getData(2).pushBack(i % 3);
    }

    final ByteArrayOutputStream baos = new ByteArrayOutputStream();
    final ObjectOutputStream out = new ObjectOutputStream(baos);
    out.writeObject(obj);
    out.close();

    final ByteArrayInputStream bais = new ByteArrayInputStream(baos.toByteArray());
    final ObjectInputStream in = new ObjectInputStream(bais);

    final SequenceOfObservations obj2 = (SequenceOfObservations) in.readObject();

    for (int i = 0; i < 30; ++i) {
      Assert.assertEquals(obj.getData(0).get(i), obj2.getData(0).get(i));
      Assert.assertEquals(obj.getData(1).get(i), obj2.getData(1).get(i));
      Assert.assertEquals(obj.getData(2).get(i), obj2.getData(2).get(i));
    }
  }
}
