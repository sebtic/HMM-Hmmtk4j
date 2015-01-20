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

import org.projectsforge.hmmtk4j.benchmarks.purjava.HMM;

public class JavaForwardBencher {
  final static int NBESSAI = 200;

  public static double benchForward_PurJava(final int size) {
    final org.projectsforge.hmmtk4j.benchmarks.purjava.Sequence seq =
        new org.projectsforge.hmmtk4j.benchmarks.purjava.Sequence(30);
    final HMM hmm = new HMM(20, 30);
    final org.projectsforge.hmmtk4j.benchmarks.purjava.Forward forward =
        new org.projectsforge.hmmtk4j.benchmarks.purjava.Forward();

    hmm.getA().fill(1);
    hmm.getA().makeStochastic();
    hmm.getB().fill(1);
    hmm.getB().makeStochastic();
    hmm.getPi().fill(1);
    hmm.getPi().makeStochastic();

    seq.resize(size);
    for (int i = 0; i < size; ++i) {
      seq.set(i, i % 30);
    }

    forward.setHMM(hmm);
    forward.setObservation(seq);

    final double start =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();

    for (int essai = 0; essai < JavaArrayBencher.NBESSAI; ++essai) {
      forward.run(null);
    }

    final double end =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();
    return (end - start) / (JavaArrayBencher.NBESSAI * size);
  }

  public static double benchForward_PurNative(final int size) {
    final org.projectsforge.hmmtk4j.Sequence seq = new org.projectsforge.hmmtk4j.Sequence(30);
    final org.projectsforge.hmmtk4j.discretehmm.HMM hmm = new org.projectsforge.hmmtk4j.discretehmm.HMM(20, 30);
    final org.projectsforge.hmmtk4j.discretehmm.Forward forward =
        new org.projectsforge.hmmtk4j.discretehmm.Forward();

    hmm.getA().fill(1);
    hmm.getA().makeStochastic();
    hmm.getB().fill(1);
    hmm.getB().makeStochastic();
    hmm.getPi().fill(1);
    hmm.getPi().makeStochastic();

    seq.getData().resize(size);
    for (int i = 0; i < size; ++i) {
      seq.getData().set(i, i % 30);
    }

    forward.setInputHMM(hmm);
    forward.setObservation(seq);

    final double start =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();

    for (int essai = 0; essai < JavaArrayBencher.NBESSAI; ++essai) {
      forward.run(null);
    }

    final double end =
        org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer.getClock();
    return (end - start) / (JavaArrayBencher.NBESSAI * size);
  }
}
