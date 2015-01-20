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
 * $Id: NativeImplementationTest.java 8 2010-06-01 16:56:49Z sebtic $
 */

import junit.framework.Assert;
import junit.framework.TestCase;
import org.apache.log4j.BasicConfigurator;
import org.projectsforge.hmmtk4j.ArrayOfInteger;
import org.projectsforge.hmmtk4j.executors.Algorithm;
import org.projectsforge.hmmtk4j.executors.AlgorithmInterceptor;
import org.projectsforge.hmmtk4j.executors.Algorithms;
import org.projectsforge.hmmtk4j.executors.AlgorithmsExecutor;
import org.projectsforge.hmmtk4j.executors.SequentialAlgorithmsExecutorFactory;

public class NativeImplementationTest extends TestCase {
  static {
    BasicConfigurator.resetConfiguration();
    BasicConfigurator.configure();
    AlgorithmsExecutor.setAlgorithmsExecutorFactory(new SequentialAlgorithmsExecutorFactory());
  }

  public void testBackward() throws InterruptedException {
    final HMM hmm = new HMM(10, new int[] { 5, 3 });
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        hmm.getA().set(i, j, i + j + 1);
      }
      for (int j = 0; j < 5; ++j) {
        hmm.getB(0).set(i, j, i + j + 1);
      }
      for (int j = 0; j < 3; ++j) {
        hmm.getB(1).set(i, j, i + j + 1);
      }
      hmm.getPi().set(i, i + 1);
    }
    hmm.getA().makeStochastic();
    hmm.getB(0).makeStochastic();
    hmm.getB(1).makeStochastic();
    hmm.getPi().makeStochastic();
    final SequenceOfObservations seq = new SequenceOfObservations(new int[] { 5, 3 },
        new ArrayOfInteger[] { new ArrayOfInteger(30), new ArrayOfInteger(30) });
    for (int i = 0; i < 30; ++i) {
      seq.getData(0).set(i, i % 5);
      seq.getData(1).set(i, i % 3);
    }
    final Algorithms algorithms1 = Algorithms.newInstance();
    Forward forward = new Forward();
    forward.setInputHMM(hmm);
    forward.setObservation(seq);
    algorithms1.addAlgorithm(forward);
    algorithms1.setAlgorithmInterceptor(new AlgorithmInterceptor() {
      @Override
      public boolean intercept(final int index, final Algorithm algorithm)
          throws InterruptedException {
        final Algorithms algorithms2 = Algorithms.newInstance();
        final Backward backward = new Backward();
        algorithms2.addAlgorithm(backward);
        backward.setForward((Forward) algorithm);
        AlgorithmsExecutor.newInstance().execute(algorithms2);
        return false;
      }
    });
    forward = null;
    AlgorithmsExecutor.newInstance().execute(algorithms1);
  }

  public void testBaumWelch() throws InterruptedException {
    final HMM hmm = new HMM(10, new int[] { 5, 3 });
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        hmm.getA().set(i, j, i + j + 1);
      }
      for (int j = 0; j < 5; ++j) {
        hmm.getB(0).set(i, j, i + j + 1);
      }
      for (int j = 0; j < 3; ++j) {
        hmm.getB(1).set(i, j, i + j + 1);
      }
      hmm.getPi().set(i, i + 1);
    }
    hmm.getA().makeStochastic();
    hmm.getB(0).makeStochastic();
    hmm.getB(1).makeStochastic();
    hmm.getPi().makeStochastic();
    final SequenceOfObservations seq = new SequenceOfObservations(new int[] { 5, 3 },
        new ArrayOfInteger[] { new ArrayOfInteger(30), new ArrayOfInteger(30) });
    for (int i = 0; i < 30; ++i) {
      seq.getData(0).set(i, i % 5);
      seq.getData(1).set(i, i % 3);
    }
    final Algorithms algorithms = Algorithms.newInstance();
    final double goodValues[] = { -81.135901771049, -81.077533936765, -80.996432700948,
        -80.881430515268, -80.718421899769, -80.488350040628, -80.165020874888, -79.705694131943,
        -79.002581631379, -77.758496568221 };
    for (int nb = 1; nb <= 10; ++nb) {
      final BaumWelch baumwelch = new BaumWelch();
      baumwelch.setInputHMM(hmm);
      baumwelch.setObservation(seq);
      baumwelch.setReevaluateA(true);
      baumwelch.setReevaluateB(new boolean[] { true, true });
      baumwelch.setReevaluatePi(true);
      baumwelch.setNbMaxIteration(nb);
      algorithms.addAlgorithm(baumwelch);
    }
    algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {
      @Override
      public boolean intercept(final int index, final Algorithm algorithm) {
        final BaumWelch baumwelch = (BaumWelch) algorithm;
        Assert.assertEquals(baumwelch.getLogOfTheProbability(), goodValues[index], 0.0001);
        return false;
      }
    });
    AlgorithmsExecutor.newInstance().execute(algorithms);
  }

  public void testFastForward() throws InterruptedException {
    final HMM hmm = new HMM(10, new int[] { 5, 3 });
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        hmm.getA().set(i, j, i + j + 1);
      }
      for (int j = 0; j < 5; ++j) {
        hmm.getB(0).set(i, j, i + j + 1);
      }
      for (int j = 0; j < 3; ++j) {
        hmm.getB(1).set(i, j, i + j + 1);
      }
      hmm.getPi().set(i, i + 1);
    }
    hmm.getA().makeStochastic();
    hmm.getB(0).makeStochastic();
    hmm.getB(1).makeStochastic();
    hmm.getPi().makeStochastic();

    final SequenceOfObservations seq = new SequenceOfObservations(new int[] { 5, 3 },
        new ArrayOfInteger[] { new ArrayOfInteger(30), new ArrayOfInteger(30) });
    for (int i = 0; i < 30; ++i) {
      seq.getData(0).set(i, i % 5);
      seq.getData(1).set(i, i % 3);
    }

    final Algorithms algorithms = Algorithms.newInstance();
    FastForward forward = new FastForward();
    forward.setInputHMM(hmm);
    forward.setObservation(seq);
    algorithms.addAlgorithm(forward);
    algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {
      @Override
      public boolean intercept(final int index, final Algorithm algorithm) {
        final FastForward forward = (FastForward) algorithm;
        Assert.assertEquals(forward.getLogOfTheProbability(), -82.076737213731, 0.0001);
        return false;
      }
    });
    forward = null;
    AlgorithmsExecutor.newInstance().execute(algorithms);
  }

  public void testForward() throws InterruptedException {
    final HMM hmm = new HMM(10, new int[] { 5, 3 });
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        hmm.getA().set(i, j, i + j + 1);
      }
      for (int j = 0; j < 5; ++j) {
        hmm.getB(0).set(i, j, i + j + 1);
      }
      for (int j = 0; j < 3; ++j) {
        hmm.getB(1).set(i, j, i + j + 1);
      }
      hmm.getPi().set(i, i + 1);
    }

    hmm.getA().makeStochastic();
    hmm.getB(0).makeStochastic();
    hmm.getB(1).makeStochastic();
    hmm.getPi().makeStochastic();

    final SequenceOfObservations seq = new SequenceOfObservations(new int[] { 5, 3 },
        new ArrayOfInteger[] { new ArrayOfInteger(30), new ArrayOfInteger(30) });
    for (int i = 0; i < 30; ++i) {
      seq.getData(0).set(i, i % 5);
      seq.getData(1).set(i, i % 3);
    }

    final Algorithms algorithms = Algorithms.newInstance();
    final Forward forward = new Forward();
    forward.setInputHMM(hmm);
    forward.setObservation(seq);
    algorithms.addAlgorithm(forward);
    algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {

      @Override
      public boolean intercept(final int index, final Algorithm algorithm) {
        final Forward forward = (Forward) algorithm;
        Assert.assertEquals(forward.getLogOfTheProbability(), -82.076737213731, 0.0001);
        return false;
      }
    });
    AlgorithmsExecutor.newInstance().execute(algorithms);

  }
}
