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
package org.projectsforge.hmmtk4j.executors;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;
import org.projectsforge.hmmtk4j.Randomizer;

public class StorageManager {

  private final File dbDir = new File(System.getProperty("java.io.tmpdir"),
      "hmmtk4j-algorithmsstore-" + System.nanoTime() + "-"
          + Randomizer.getRandomGenerator().nextLong());

  private final AtomicInteger algorithmId = new AtomicInteger(0);
  private final List<File> deleteOnExit = Collections.synchronizedList(new ArrayList<File>());

  public StorageManager() {
    dbDir.mkdirs();
    dbDir.deleteOnExit();
    Runtime.getRuntime().addShutdownHook(new Thread() {
      @Override
      public void run() {
        synchronized (deleteOnExit) {
          for (final File file : deleteOnExit) {
            file.delete();
          }
        }
      }
    });
  }

  public void clearAlgorithm(final long id) {
    final File file = new File(dbDir, Long.toString(id));
    deleteOnExit.remove(file);
    file.delete();
  }

  public long getNewAlgorithmId() {
    return algorithmId.incrementAndGet();
  }

  public Algorithm loadAlgorithm(final long id) throws IOException, ClassNotFoundException {
    final File file = new File(dbDir, Long.toString(id));
    final ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(
        new FileInputStream(file)));
    try {
      return (Algorithm) ois.readObject();
    } finally {
      ois.close();
    }
  }

  public void saveAlgorithm(final long id, final Algorithm algorithm) throws IOException {
    final File file = new File(dbDir, Long.toString(id));
    final ObjectOutputStream oos = new ObjectOutputStream(new BufferedOutputStream(
        new FileOutputStream(file)));
    try {
      oos.writeObject(algorithm);
    } finally {
      oos.close();
      deleteOnExit.add(file);
    }
  }
}
