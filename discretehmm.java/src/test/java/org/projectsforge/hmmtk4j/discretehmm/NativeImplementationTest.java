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
package org.projectsforge.hmmtk4j.discretehmm;

import junit.framework.Assert;
import junit.framework.TestCase;
import org.apache.log4j.BasicConfigurator;
import org.projectsforge.hmmtk4j.ArrayOfInteger;
import org.projectsforge.hmmtk4j.executors.Algorithm;
import org.projectsforge.hmmtk4j.executors.AlgorithmInterceptor;
import org.projectsforge.hmmtk4j.executors.Algorithms;
import org.projectsforge.hmmtk4j.executors.AlgorithmsExecutor;

public class NativeImplementationTest extends TestCase {
  static {
    BasicConfigurator.resetConfiguration();
    BasicConfigurator.configure();
  }

  public void testBackward() throws InterruptedException {
    final HMM hmm = new HMM(10, 5);
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        hmm.getA().set(i, j, i + j + 1);
      }
      for (int j = 0; j < 5; ++j) {
        hmm.getB().set(i, j, i + j + 1);
      }
      hmm.getPi().set(i, i + 1);
    }
    hmm.getA().makeStochastic();
    hmm.getB().makeStochastic();
    hmm.getPi().makeStochastic();

    final SequenceOfObservations seq = new SequenceOfObservations(5, new ArrayOfInteger(30));
    for (int i = 0; i < 30; ++i) {
      seq.getData().set(i, i % 5);
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
    final HMM hmm = new HMM(10, 5);
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        hmm.getA().set(i, j, i + j + 1);
      }
      for (int j = 0; j < 5; ++j) {
        hmm.getB().set(i, j, i + j + 1);
      }
      hmm.getPi().set(i, i + 1);
    }
    hmm.getA().makeStochastic();
    hmm.getB().makeStochastic();
    hmm.getPi().makeStochastic();

    final SequenceOfObservations seq = new SequenceOfObservations(5, new ArrayOfInteger(30));
    for (int i = 0; i < 30; ++i) {
      seq.getData().set(i, i % 5);
    }

    final Algorithms algorithms = Algorithms.newInstance();

    final double goodValues[] = { -48.21779377925154364, -48.17846684636410259,
        -48.12232887599249409, -48.04040938344959244, -47.91661762097253785, -47.71771933197934601,
        -47.36788282290679319, -46.69331860257293698, -45.38149439201943380, -43.25480413764215371 };

    for (int nb = 1; nb <= 10; ++nb) {
      final BaumWelch baumwelch = new BaumWelch();
      baumwelch.setInputHMM(hmm);
      baumwelch.setObservation(seq);
      baumwelch.setReevaluateA(true);
      baumwelch.setReevaluateB(true);
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
    final HMM hmm = new HMM(10, 5);
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        hmm.getA().set(i, j, i + j + 1);
      }
      for (int j = 0; j < 5; ++j) {
        hmm.getB().set(i, j, i + j + 1);
      }
      hmm.getPi().set(i, i + 1);
    }
    hmm.getA().makeStochastic();
    hmm.getB().makeStochastic();
    hmm.getPi().makeStochastic();

    final SequenceOfObservations seq = new SequenceOfObservations(5, new ArrayOfInteger(30));
    for (int i = 0; i < 30; ++i) {
      seq.getData().set(i, i % 5);
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
        Assert.assertEquals(forward.getLogOfTheProbability(), -48.852186362466, 0.0001);
        return false;
      }
    });
    forward = null;
    AlgorithmsExecutor.newInstance().execute(algorithms);
  }

  public void testForward() throws InterruptedException {
    final HMM hmm = new HMM(10, 5);
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        hmm.getA().set(i, j, i + j + 1);
      }
      for (int j = 0; j < 5; ++j) {
        hmm.getB().set(i, j, i + j + 1);
      }
      hmm.getPi().set(i, i + 1);
    }
    hmm.getA().makeStochastic();
    hmm.getB().makeStochastic();
    hmm.getPi().makeStochastic();

    final SequenceOfObservations seq = new SequenceOfObservations(5, new ArrayOfInteger(30));
    for (int i = 0; i < 30; ++i) {
      seq.getData().set(i, i % 5);
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
        Assert.assertEquals(forward.getLogOfTheProbability(), -48.852186362466, 0.0001);
        return false;
      }
    });
    AlgorithmsExecutor.newInstance().execute(algorithms);

  }
}
