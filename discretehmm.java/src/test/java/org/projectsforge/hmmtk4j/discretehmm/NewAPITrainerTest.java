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

import junit.framework.TestCase;
import org.apache.log4j.BasicConfigurator;
import org.projectsforge.hmmtk4j.executors.Algorithm;
import org.projectsforge.hmmtk4j.executors.AlgorithmInterceptor;
import org.projectsforge.hmmtk4j.executors.Algorithms;
import org.projectsforge.hmmtk4j.executors.AlgorithmsExecutor;
import org.projectsforge.hmmtk4j.executors.InMemoryAlgorithmsFactory;
import org.projectsforge.hmmtk4j.trainers.TrainerEvent;
import org.projectsforge.hmmtk4j.trainers.TrainerListener;

public class NewAPITrainerTest extends TestCase {
  static {
    BasicConfigurator.resetConfiguration();
    BasicConfigurator.configure();
  }

  public void testClass1() throws InterruptedException {

    Algorithms.setAlgorithmsFactory(new InMemoryAlgorithmsFactory());

    final SequenceOfObservations seq = new SequenceOfObservations(12);
    for (int i = 0; i < 3000; ++i) {
      seq.getData().pushBack(i % 10);
    }

    for (int j = 0; j < 1; ++j) {
      NewAPITrainer trainer = new NewAPITrainer(new LambdaModelArithmetic());

      trainer.setImprovedMode(false);
      trainer.setInnerPatience(4);
      trainer.setOuterPatience(4);
      trainer.setRingFusiness(1); // 1
      trainer.setMinAmplitude(0.01);
      trainer.setMaxAmplitude(0.99);
      trainer.setAmplitudeStrategy(1);
      trainer.setPatienceStrategy(1000);
      trainer.setNbMaxIterationOfBaumWelch(1);
      trainer.setNbOfAnts(20);
      trainer.setNestPatience(8);
      trainer.setNumberOfIterations(100);
      trainer.setObservation(seq);
      trainer.setStateCount(5);
      trainer.addTrainerListener(new TrainerListener() {

        public void trainerBestScoredModelImproved(final TrainerEvent event) {
          System.err.println("Best model improved: "
              + event.getSourceTrainer().getBestScoredModel().score);
        }

        public void trainerChangedCurrentIteration(final TrainerEvent trainerEvent) {
          System.err.println("Current iteration: "
              + trainerEvent.getSourceTrainer().getCurrentIteration());
        }

        public void trainerHasProgressed(final TrainerEvent event) {
          // TODO Auto-generated method stub

        }

      });
      final Algorithms algorithms = Algorithms.newInstance();
      algorithms.addAlgorithm(trainer);
      algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {

        @Override
        public boolean intercept(final int index, final Algorithm algorithm) {
          final NewAPITrainer trainer = (NewAPITrainer) algorithm;
          System.err.println("Result of the optimization : " + trainer.getBestScoredModel().score);
          return false;
        }
      });
      trainer = null;
      AlgorithmsExecutor.newInstance().execute(algorithms);
    }
  }

  public void testClass2() throws InterruptedException {

    Algorithms.setAlgorithmsFactory(new InMemoryAlgorithmsFactory());

    final SequenceOfObservations seq = new SequenceOfObservations(12);
    for (int i = 0; i < 3000; ++i) {
      seq.getData().pushBack(i % 10);
    }

    final HMMStructure structure = new HMMStructure(5, 12);
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        structure.getA().set(i, j, i <= j);
      }
      for (int j = 0; j < 12; ++j) {
        structure.getB().set(i, j, true);
      }
      structure.getPi().set(i, i == 2);
    }

    for (int j = 0; j < 1; ++j) {
      NewAPITrainer trainer = new NewAPITrainer(new LambdaModelArithmetic());

      trainer.setImprovedMode(false);
      trainer.setInnerPatience(4);
      trainer.setOuterPatience(4);
      trainer.setRingFusiness(1); // 1
      trainer.setMinAmplitude(0.01);
      trainer.setMaxAmplitude(0.99);
      trainer.setAmplitudeStrategy(1);
      trainer.setPatienceStrategy(1000);
      trainer.setNbMaxIterationOfBaumWelch(1);
      trainer.setNbOfAnts(20);
      trainer.setNestPatience(8);
      trainer.setNumberOfIterations(100);
      trainer.setObservation(seq);
      trainer.setStateCount(5);
      trainer.setHmmStructure(structure);

      trainer.addTrainerListener(new TrainerListener() {

        public void trainerBestScoredModelImproved(final TrainerEvent event) {
          System.err.println("Best model improved: "
              + event.getSourceTrainer().getBestScoredModel().score);
        }

        public void trainerChangedCurrentIteration(final TrainerEvent trainerEvent) {
          System.err.println("Current iteration: "
              + trainerEvent.getSourceTrainer().getCurrentIteration());
        }

        public void trainerHasProgressed(final TrainerEvent event) {
          // TODO Auto-generated method stub

        }

      });
      final Algorithms algorithms = Algorithms.newInstance();
      algorithms.addAlgorithm(trainer);
      algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {

        @Override
        public boolean intercept(final int index, final Algorithm algorithm) {
          final NewAPITrainer trainer = (NewAPITrainer) algorithm;
          System.err.println("Result of the optimization : " + trainer.getBestScoredModel().score);
          return false;
        }
      });
      trainer = null;
      AlgorithmsExecutor.newInstance().execute(algorithms);
    }
  }
}
