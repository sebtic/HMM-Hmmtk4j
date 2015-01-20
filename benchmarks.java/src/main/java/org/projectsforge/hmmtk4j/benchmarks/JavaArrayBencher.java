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
package org.projectsforge.hmmtk4j.benchmarks;

import org.projectsforge.hmmtk4j.ArrayOfDouble;

public class JavaArrayBencher {
  static class Array {
    private final double data[];

    public Array(final int size) {
      data = new double[size];
    }

    public double get(final int index) {
      return data[index];
    }

    public int getSize() {
      return data.length;
    }

    public void set(final int index, final double val) {
      data[index] = val;
    }
  }

  final static int NBESSAI = 10000;

  public static double benchArray_PurJava(final int size) {
    final Array array = new Array(size);
    for (int i = 0; i < array.getSize(); ++i) {
      array.set(i, 1);
    }

    final double start =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();

    for (int essai = 0; essai < JavaArrayBencher.NBESSAI; ++essai) {
      double sum = 0;
      for (int i = 0; i < array.getSize(); ++i) {
        sum += array.get(i);
      }
    }

    final double end =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();
    return (end - start) / (JavaArrayBencher.NBESSAI * size);
  }

  public static double benchArray_PurNative(final int size) {
    final ArrayOfDouble array = new ArrayOfDouble(size, 1);
    final double start =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();

    for (int essai = 0; essai < JavaArrayBencher.NBESSAI; ++essai) {
      final double sum =
          org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.Bencher.getSum(array);
    }

    final double end =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();
    return (end - start) / (JavaArrayBencher.NBESSAI * size);
  }
}
