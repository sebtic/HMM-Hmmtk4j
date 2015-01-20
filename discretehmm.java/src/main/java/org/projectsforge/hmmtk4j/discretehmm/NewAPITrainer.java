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

public class NewAPITrainer extends org.projectsforge.hmmtk4j.trainers.NewAPITrainer implements
    Serializable {

  /**
   * Define a model arithmetic.
   */
  public interface NewModelArithmetic {
    /**
     * Compute a new position HMM from a site HMM.
     * 
     * @param siteHMM
     *          the model of the site
     * @param amplitudes
     *          the ring amplitudes
     * @param ringIndex
     *          the index of the ring in which the position must be created
     * @param ringFusiness
     *          the fusiness of the ring: 1 means all the ring, >1 means larger
     *          than the ring, <1 means smaller than the ring
     * @return the position model
     */
    HMM computeNewPositionFromSite(HMMStructure hmmStructure, HMM siteHMM, double[] amplitudes,
        int ringIndex, double ringFusiness);

    /**
     * Compute a new site HMM from a nest HMM.
     * 
     * @param nestHMM
     *          the model of the nest
     * @param amplitudes
     *          the ring amplitudes
     * @param ringIndex
     *          the index of the ring in chich the position must be created
     * @return the site model
     */
    HMM computeNewSiteFromNest(HMMStructure hmmStructure, HMM nestHMM, double[] amplitudes,
        int ringIndex);

  }

  private HMMStructure hmmStructure = null;

  private final NewModelArithmetic modelArithmetic;

  private boolean improvedMode = true;

  /** The nb max iteration of baum welch. */
  private int nbMaxIterationOfBaumWelch = 2;

  /** The observation. */
  private SequenceOfObservations obs;

  /** The state count. */
  private int stateCount = 5;

  /** The symbol count. */
  private int symbolCount;

  public NewAPITrainer(final NewModelArithmetic modelArithmetic) {
    if (modelArithmetic == null) {
      throw new IllegalArgumentException("The model arithmetic can not be null");
    }
    this.modelArithmetic = modelArithmetic;
  }

  public void checkInputParameters() {
    // TODO Auto-generated method stub

  }

  public void checkOutputParameters() {
    // TODO Auto-generated method stub

  }

  /*
   * (non-Javadoc)
   * @seefr.univtours.li.hmmtk4j.trainers.BasicAPITrainer#
   * createAndEvaluateTheInitialNestPositions()
   */
  @Override
  protected void createAndEvaluateTheInitialNestPositions() throws InterruptedException {
    final HMM hmm = new HMM(stateCount, symbolCount);
    if (hmmStructure != null) {
      hmm.randomGenerate(hmmStructure);
    } else {
      hmm.randomGenerate(true);
    }

    final Algorithms algorithms = Algorithms.newInstance();
    FastForward forward = new FastForward();
    forward.setInputHMM(hmm);
    forward.setObservation(obs);
    algorithms.addAlgorithm(forward);
    algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {

      @Override
      public boolean intercept(final int index, final Algorithm algorithm) {
        final FastForward forward = (FastForward) algorithm;
        nestPosition.copy(hmm, forward.getLogOfTheProbability(), false);
        return false;
      }
    });
    forward = null;
    AlgorithmsExecutor.newInstance().execute(algorithms);
  }

  @Override
  protected void exploreAndEvaluate() throws InterruptedException {
    final Algorithms algorithms = Algorithms.newInstance();
    for (int i = 0; i < ants.length; ++i) {
      final NewAnt ant = (NewAnt) ants[i];
      final BaumWelch bw = new BaumWelch();
      final HMM inputHMM;

      if (ant.isExploringFromNest) {
        inputHMM = modelArithmetic.computeNewSiteFromNest(hmmStructure, (HMM) nestPosition.model,
            amplitudesLimits, i);
      } else {
        inputHMM = modelArithmetic.computeNewPositionFromSite(hmmStructure,
            (HMM) ant.position.model, amplitudesLimits, i, getRingFusiness());
      }

      bw.setInputHMM(inputHMM);
      bw.setNbMaxIteration(nbMaxIterationOfBaumWelch);
      bw.setObservation(obs);
      algorithms.addAlgorithm(bw);
    }
    algorithms.setAlgorithmInterceptor(new AlgorithmInterceptor() {

      @Override
      public boolean intercept(final int index, final Algorithm algorithm) {
        final BaumWelch bw = (BaumWelch) algorithm;
        final NewAnt ant = (NewAnt) ants[index];
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
   * Gets the number maximum of iterations of the Baum Welch algorithm.
   * 
   * @return the new number maximum of iterations
   */
  public int getNbMaxIterationOfBaumWelch() {
    return nbMaxIterationOfBaumWelch;
  }

  /**
   * Gets the observation.
   * 
   * @return the observation
   */
  public SequenceOfObservations getObservation() {
    return obs;
  }

  /**
   * Gets the state count.
   * 
   * @return the stateCount
   */
  public int getStateCount() {
    return stateCount;
  }

  /*
   * (non-Javadoc)
   * @see fr.univtours.li.hmmtk4j.trainers.BasicAPITrainer#implement()
   */
  @Override
  public void implement() throws InterruptedException {
    checkInputParameters();
    setMaximize(true);
    symbolCount = obs.getMaxDistinctValues();
    super.implement();
    checkOutputParameters();
  }

  public boolean isImprovedMode() {
    return improvedMode;
  }

  public void setHmmStructure(final HMMStructure hmmStructure) {
    this.hmmStructure = hmmStructure;
    if (hmmStructure != null && hmmStructure.getStateCount() != stateCount) {
      stateCount = hmmStructure.getStateCount();
    }
  }

  public void setImprovedMode(final boolean improvedMode) {
    this.improvedMode = improvedMode;
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
   * Sets the observation.
   * 
   * @param obs
   *          the new observation
   */
  public void setObservation(final SequenceOfObservations obs) {
    this.obs = obs;
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
