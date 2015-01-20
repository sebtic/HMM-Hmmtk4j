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

import java.io.Serializable;
import org.projectsforge.hmmtk4j.executors.Algorithm;
import org.projectsforge.hmmtk4j.executors.AlgorithmInterceptor;
import org.projectsforge.hmmtk4j.executors.Algorithms;
import org.projectsforge.hmmtk4j.executors.AlgorithmsExecutor;
import org.projectsforge.hmmtk4j.trainers.ScoredModel;

/**
 * A default class to train a model. The algorithm used can vary with the
 * version of the library. The aim is to define a simple algorithm with minimal
 * settings.
 * 
 * @author Sébastien Aupetit
 */
public class DefaultTrainer extends Algorithm implements Serializable {

  /**
   * Maximal number of iterations of the Baum Welch algorithm to apply on model.
   */
  private int nbMaxIterationOfBaumWelch;
  /** The sequenceOfObservations sequence. */
  private SequenceOfObservations sequenceOfObservations;
  /** The number of iteration of the algorithm. */
  private int numberOfIterations;
  /** The number of hidden states of the models. */
  private int stateCount;
  /** The best scored model. */
  private ScoredModel bestScoredModel;

  /**
   * Gets the best scored model.
   * 
   * @return the best scored model
   */
  public final ScoredModel getBestScoredModel() {
    return bestScoredModel;
  }

  /**
   * Get the maximal number of iterations of the Baum Welch algorithm.
   * 
   * @return the nbMaxIterationOfBaumWelch
   */
  public int getNbMaxIterationOfBaumWelch() {
    return nbMaxIterationOfBaumWelch;
  }

  /**
   * Get the number of iteration of the algorithm.
   * 
   * @return the numberOfIterations
   */
  public int getNumberOfIterations() {
    return numberOfIterations;
  }

  /**
   * Get the sequenceOfObservations sequence.
   * 
   * @return the sequenceOfObservations
   */
  public SequenceOfObservations getObservation() {
    return sequenceOfObservations;
  }

  /**
   * Get the number of state of the models.
   * 
   * @return the stateCount
   */
  public int getStateCount() {
    return stateCount;
  }

  @Override
  protected void implement() throws InterruptedException {
    bestScoredModel = null;
    final Algorithms algorithms = Algorithms.newInstance();

    ClassicalAPITrainer trainer = new ClassicalAPITrainer(new LambdaModelArithmetic());
    trainer.setAmplitudeStrategy(100);
    trainer.setLocalPatience(4);
    trainer.setMaxAmplitude(1);
    trainer.setMinAmplitude(0);
    trainer.setNbMaxIterationOfBaumWelch(nbMaxIterationOfBaumWelch);
    trainer.setNbOfAnts(20);
    trainer.setNestPatience(20);
    trainer.setObservation(sequenceOfObservations);
    trainer.setNestToLocalAmplitudeFactor(0.1);
    trainer.setNumberOfIterations(numberOfIterations);
    trainer.setStateCount(stateCount);
    algorithms.addAlgorithm(trainer);
    algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {
      @Override
      public boolean intercept(final int index, final Algorithm algorithm) {
        bestScoredModel = ((ClassicalAPITrainer) algorithm).getBestScoredModel();
        return false;
      }
    });
    trainer = null;
    AlgorithmsExecutor.newInstance().execute(algorithms);
  }

  /**
   * Set the maximal number of iterations of the Baum Welch algorithm.
   * 
   * @param nbMaxIterationOfBaumWelch
   *          the nbMaxIterationOfBaumWelch to set
   */
  public void setNbMaxIterationOfBaumWelch(final int nbMaxIterationOfBaumWelch) {
    this.nbMaxIterationOfBaumWelch = nbMaxIterationOfBaumWelch;
  }

  /**
   * Set the number of iteration of the algorithm.
   * 
   * @param numberOfIterations
   *          the numberOfIterations to set
   */
  public void setNumberOfIterations(final int numberOfIterations) {
    this.numberOfIterations = numberOfIterations;
  }

  /**
   * Set the sequenceOfObservations sequence.
   * 
   * @param sequenceOfObservations
   *          the sequenceOfObservations to set
   */
  public void setObservation(final SequenceOfObservations sequenceOfObservations) {
    this.sequenceOfObservations = sequenceOfObservations;
  }

  /**
   * Set the state count of the models.
   * 
   * @param stateCount
   *          the stateCount to set
   */
  public void setStateCount(final int stateCount) {
    this.stateCount = stateCount;
  }
}
