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
import java.util.ArrayList;
import java.util.List;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.executors.Algorithm;

/**
 * An implementation of the maximal mutual information learning criterion.
 * 
 * @author Sébastien Aupetit
 */
public class MaximalMutualInformation extends Algorithm implements Serializable {

  /** The input HMM. */
  private HMM inputHMM;

  /** The log of the probability. */
  private double logOfTheProbability = RobustMath.LOG_NULL;

  /** The nb max iteration. */
  private int nbMaxIteration = 0;

  /** The positive observations. */
  public final List<WeightedSequenceOfObservations> positivesObservations = new ArrayList<WeightedSequenceOfObservations>();

  /** The negative observations. */
  public final List<WeightedSequenceOfObservations> negativesObservations = new ArrayList<WeightedSequenceOfObservations>();

  /** The output HMM. */
  private HMM outputHMM;

  /** The reevaluate a. */
  private boolean reevaluateA = true;

  /** The reevaluate b. */
  private boolean reevaluateB = true;

  /** The reevaluate pi. */
  private boolean reevaluatePi = true;

  /**
   * Gets the input HMM.
   * 
   * @return the input HMM
   */
  public HMM getInputHMM() {
    return inputHMM;
  }

  /**
   * Gets the log of the probability.
   * 
   * @return the log of the probability
   */
  public double getLogOfTheProbability() {
    return logOfTheProbability;
  }

  /**
   * Gets the nb max iteration.
   * 
   * @return the nb max iteration
   */
  public int getNbMaxIteration() {
    return nbMaxIteration;
  }

  /**
   * Gets the negative observations.
   * 
   * @return the observation
   */
  public List<WeightedSequenceOfObservations> getNegativeObservations() {
    return negativesObservations;
  }

  /**
   * Gets the output HMM.
   * 
   * @return the output HMM
   */
  public HMM getOutputHMM() {
    return outputHMM;
  }

  /**
   * Gets the positive observations.
   * 
   * @return the observation
   */
  public List<WeightedSequenceOfObservations> getPositiveObservations() {
    return positivesObservations;
  }

  /**
   * {@inheritDoc}
   * 
   * @see org.projectsforge.hmmtk4j.executors.Algorithm#implement()
   */
  @Override
  protected void implement() {
    for (final WeightedSequenceOfObservations observation : positivesObservations) {
      if (inputHMM.getSymbolCount() != observation.getSequence().getMaxDistinctValues()) {
        throw new IllegalArgumentException(
            "The input HMM and an observation do not have the same symbol scale");
      }
      if (!observation.getSequence().isValid()) {
        throw new IllegalArgumentException("An observation is not valid");
      }
      if (observation.getWeight() < 0) {
        throw new IllegalArgumentException("An observation has a negative weight.");
      }
    }

    for (final WeightedSequenceOfObservations observation : negativesObservations) {
      if (inputHMM.getSymbolCount() != observation.getSequence().getMaxDistinctValues()) {
        throw new IllegalArgumentException(
            "The input HMM and an observation do not have the same symbol scale");
      }
      if (!observation.getSequence().isValid()) {
        throw new IllegalArgumentException("An observation is not valid");
      }
      if (observation.getWeight() < 0) {
        throw new IllegalArgumentException("An observation has a negative weight.");
      }
    }

    if (!inputHMM.isValid()) {
      throw new IllegalArgumentException("The inputHMM is not valid");
    }

    outputHMM = new HMM(inputHMM.getStateCount(), inputHMM.getSymbolCount());
    logOfTheProbability = org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.MaximalMutualInformation
        .maximalMutualInformation(positivesObservations.toArray(new WeightedSequenceOfObservations[0]),
            negativesObservations.toArray(new WeightedSequenceOfObservations[0]), inputHMM, nbMaxIteration,
            outputHMM);
    if ((inputHMM.getStateCount() != outputHMM.getStateCount())
        || (inputHMM.getSymbolCount() != outputHMM.getSymbolCount())) {
      throw new IllegalArgumentException("The outputHMM is not valid");
    }

    if (!outputHMM.isValid()) {
      throw new IllegalArgumentException("The outputHMM is not valid");
    }
  }

  /**
   * Checks if is reevaluate a.
   * 
   * @return true, if is reevaluate a
   */
  public boolean isReevaluateA() {
    return reevaluateA;
  }

  /**
   * Checks if is reevaluate b.
   * 
   * @return true, if is reevaluate b
   */
  public boolean isReevaluateB() {
    return reevaluateB;
  }

  /**
   * Checks if is reevaluate pi.
   * 
   * @return true, if is reevaluate pi
   */
  public boolean isReevaluatePi() {
    return reevaluatePi;
  }

  /**
   * Sets the input HMM.
   * 
   * @param inputHMM
   *          the new input HMM
   */
  public void setInputHMM(final HMM inputHMM) {
    this.inputHMM = inputHMM;
  }

  /**
   * Sets the nb max iteration.
   * 
   * @param nbMaxIteration
   *          the new nb max iteration
   */
  public void setNbMaxIteration(final int nbMaxIteration) {
    if (nbMaxIteration < 0) {
      throw new IllegalArgumentException("nbMaxIteration must be positive");
    }
    this.nbMaxIteration = nbMaxIteration;
  }

  /**
   * Sets the reevaluate a.
   * 
   * @param reevaluateA
   *          the new reevaluate a
   */
  public void setReevaluateA(final boolean reevaluateA) {
    this.reevaluateA = reevaluateA;
  }

  /**
   * Sets the reevaluate b.
   * 
   * @param reevaluateB
   *          the new reevaluate b
   */
  public void setReevaluateB(final boolean reevaluateB) {
    this.reevaluateB = reevaluateB;
  }

  /**
   * Sets the reevaluate pi.
   * 
   * @param reevaluatePi
   *          the new reevaluate pi
   */
  public void setReevaluatePi(final boolean reevaluatePi) {
    this.reevaluatePi = reevaluatePi;
  }
}
