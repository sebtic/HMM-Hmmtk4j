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

/**
 * The classical API trainer implementation.
 * 
 * @author Sébastien Aupetit
 */
public class ClassicalAPITrainer extends org.projectsforge.hmmtk4j.trainers.ClassicalAPITrainer
    implements Serializable {

  /**
   * Define a model arithmetic for ClassicalAPITrainer.
   */
  public interface ClassicalModelArithmetic {

    /**
     * Compute a new position HMM from a site HMM.
     * 
     * @param siteHMM
     *          the model of the site
     * @param siteAmplitude
     *          the site amplitude
     * @return the position model
     */
    HMM computeClassicalPositionFromSite(HMMStructure hmmStructure, HMM siteHMM,
        double siteAmplitude);

    /**
     * Compute a new site HMM from a nest HMM.
     * 
     * @param nestHMM
     *          the model of the nest
     * @param nestAmplitude
     *          the nest amplitude
     * @return the site model
     */
    HMM computeClassicalSiteFromNest(HMMStructure hmmStructure, HMM nestHMM, double nestAmplitude);
  }

  /** The nb max iteration of Baum Welch. */
  private int nbMaxIterationOfBaumWelch = 2;

  /** The sequenceOfObservations. */
  private SequenceOfObservations sequenceOfObservations;

  /** The state count. */
  private int stateCount = 5;

  /** The model arithmetic. */
  private ClassicalModelArithmetic modelArithmetic;

  private HMMStructure hmmStructure = null;

  /**
   * The constructor.
   * 
   * @param modelArithmetic
   *          the arithmetic model to use
   */
  public ClassicalAPITrainer(final ClassicalModelArithmetic modelArithmetic) {
    if (modelArithmetic == null) {
      throw new IllegalArgumentException("The model arithmetic can not be null");
    }
    this.modelArithmetic = modelArithmetic;
  }

  /**
   * {@inheritDoc}
   * 
   * @throws InterruptedException
   * 
   * @see org.projectsforge.hmmtk4j.trainers.APITrainer#createAndEvaluateTheInitialNestPositions()
   */
  @Override
  protected void createAndEvaluateTheInitialNestPositions() throws InterruptedException {
    final HMM inputHMM = new HMM(stateCount, sequenceOfObservations.getMaxDistinctValues());

    if (hmmStructure != null) {
      inputHMM.randomGenerate(hmmStructure);
    } else {
      inputHMM.randomGenerate(true);
    }

    final Algorithms algorithms = Algorithms.newInstance();
    FastForward forward = new FastForward();
    forward.setInputHMM(inputHMM);
    forward.setObservation(sequenceOfObservations);
    algorithms.addAlgorithm(forward);
    algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {
      @Override
      public boolean intercept(final int index, final Algorithm algorithm) {
        final FastForward forward = (FastForward) algorithm;
        nestPosition.copy(inputHMM, forward.getLogOfTheProbability(), false);
        return false;
      }
    });
    forward = null;
    AlgorithmsExecutor.newInstance().execute(algorithms);
  }

  /**
   * {@inheritDoc}
   * 
   * @throws InterruptedException
   * 
   * @see org.projectsforge.hmmtk4j.trainers.APITrainer#exploreAndEvaluate()
   */
  @Override
  protected void exploreAndEvaluate() throws InterruptedException {
    final Algorithms algorithms = Algorithms.newInstance();
    for (int i = 0; i < ants.length; ++i) {
      final ClassicalAnt ant = (ClassicalAnt) ants[i];
      final BaumWelch bw = new BaumWelch();
      HMM inputHMM;

      if (ant.isExploringFromNest) {
        inputHMM = modelArithmetic.computeClassicalSiteFromNest(hmmStructure,
            (HMM) nestPosition.model, ant.nestAmplitude);
      } else {

        inputHMM = modelArithmetic.computeClassicalPositionFromSite(hmmStructure,
            (HMM) ant.position.model, ant.localAmplitude);
      }

      bw.setInputHMM(inputHMM);
      bw.setNbMaxIteration(nbMaxIterationOfBaumWelch);
      bw.setObservation(sequenceOfObservations);
      algorithms.addAlgorithm(bw);
    }
    algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {
      @Override
      public boolean intercept(final int index, final Algorithm algorithm) {
        final BaumWelch bw = (BaumWelch) algorithm;
        final ClassicalAnt ant = (ClassicalAnt) ants[index];
        ant.newPosition.copy(bw.getOutputHMM(), bw.getLogOfTheProbability(), false);
        return false;
      }
    });
    AlgorithmsExecutor.newInstance().execute(algorithms);
  }

  public HMMStructure getHmmStructure() {
    return hmmStructure;
  }

  /**
   * Gets the model arithmetic.
   * 
   * @return the modelArithmetic
   */
  public ClassicalModelArithmetic getModelArithmetic() {
    return modelArithmetic;
  }

  /**
   * Gets the number maximum of iterations of the Baum Welch algorithm.
   * 
   * @return the new number maximum of iterations
   */
  public int getNbMaxIterationOfBaumWelch() {
    return nbMaxIterationOfBaumWelch;
  }

  /**
   * Gets the sequenceOfObservations.
   * 
   * @return the sequenceOfObservations
   */
  public SequenceOfObservations getObservation() {
    return sequenceOfObservations;
  }

  /**
   * Gets the state count.
   * 
   * @return the stateCount
   */
  public int getStateCount() {
    return stateCount;
  }

  /**
   * Implement.
   * 
   * @throws InterruptedException
   *           the interrupted exception
   * @see org.projectsforge.hmmtk4j.trainers.APITrainer#implement()
   */
  @Override
  public void implement() throws InterruptedException {
    setMaximize(true);
    super.implement();
  }

  public void setHmmStructure(final HMMStructure hmmStructure) {
    this.hmmStructure = hmmStructure;
    if (hmmStructure != null && hmmStructure.getStateCount() != stateCount) {
      stateCount = hmmStructure.getStateCount();
    }
  }

  /**
   * Sets the model arithmetic.
   * 
   * @param modelArithmetic
   *          the modelArithmetic to set
   */
  public void setModelArithmetic(final ClassicalModelArithmetic modelArithmetic) {
    this.modelArithmetic = modelArithmetic;
  }

  /**
   * Sets the number maximum of iterations of the Baum Welch algorithm.
   * 
   * @param nbMaxIterationOfBaumWelch
   *          the new number maximum of iterations
   */
  public void setNbMaxIterationOfBaumWelch(final int nbMaxIterationOfBaumWelch) {
    if (nbMaxIterationOfBaumWelch < 0) {
      throw new IllegalArgumentException("The parameter must be positive or null");
    }
    this.nbMaxIterationOfBaumWelch = nbMaxIterationOfBaumWelch;
  }

  /**
   * Sets the sequenceOfObservations.
   * 
   * @param sequenceOfObservations
   *          the new sequenceOfObservations
   */
  public void setObservation(final SequenceOfObservations sequenceOfObservations) {
    this.sequenceOfObservations = sequenceOfObservations;
  }

  /**
   * Sets the state count.
   * 
   * @param stateCount
   *          the stateCount to set
   */
  public void setStateCount(final int stateCount) {
    if (stateCount < 1) {
      throw new IllegalArgumentException("The value must be greater of equal to 1.");
    }
    this.stateCount = stateCount;
  }
}
