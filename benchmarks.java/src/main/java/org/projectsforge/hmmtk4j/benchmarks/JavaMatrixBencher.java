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

import org.projectsforge.hmmtk4j.MatrixOfDouble;

public class JavaMatrixBencher {

  final static int NBESSAI = 4000;

  public static double benchArray_PurJava(final int size) {
    final double matrix[][] = new double[size][size];
    for (int i = 0; i < matrix.length; ++i) {
      for (int j = 0; j < matrix[i].length; ++j) {
        matrix[i][j] = 1;
      }
    }

    final double start =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();

    double sum = 0;
    for (int essai = 0; essai < JavaMatrixBencher.NBESSAI; ++essai) {
      final double s = 0;
      for (int i = 0; i < matrix.length; ++i) {
        for (int j = 0; j < matrix[i].length; ++j) {
          sum += matrix[i][j];
        }
      }
      sum += s;
    }

    final double end =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();

    System.out.println(sum);
    return (end - start) / (JavaMatrixBencher.NBESSAI * size);
  }

  public static double benchArray_PurNative(final int size) {
    final MatrixOfDouble matrix = new MatrixOfDouble(size, size, 1);
    final double start =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();

    double sum = 0;
    for (int essai = 0; essai < JavaMatrixBencher.NBESSAI; ++essai) {
      sum += org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.Bencher.getSum(matrix);
    }

    final double end =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();

    System.out.println(sum);
    return (end - start) / (JavaMatrixBencher.NBESSAI * size);
  }
}
