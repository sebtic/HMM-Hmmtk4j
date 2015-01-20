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
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.executors.Algorithm;

/**
 * The Viterbi algorithm.
 * 
 * @author Sébastien Aupetit
 */
public class Viterbi extends Algorithm implements Serializable {

  /** The input HMM. */
  private HMM inputHMM;

  /** The sequenceOfObservations. */
  private SequenceOfObservations sequenceOfObservations;

  /** The state sequence. */
  private SequenceOfObservations stateSequence;

  /** The log of the probability. */
  private double logOfTheProbability = RobustMath.LOG_NULL;

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
   * Gets the sequenceOfObservations.
   * 
   * @return the sequenceOfObservations
   */
  public SequenceOfObservations getObservation() {
    return sequenceOfObservations;
  }

  /**
   * Get the state sequence.
   * 
   * @return the stateSequence
   */
  public SequenceOfObservations getStateSequence() {
    return stateSequence;
  }

  /**
   * {@inheritDoc}
   * 
   * @see org.projectsforge.hmmtk4j.executors.Algorithm#implement()
   */
  @Override
  protected void implement() {
    if (inputHMM.getSymbolCount() != sequenceOfObservations.getMaxDistinctValues()) {
      throw new IllegalArgumentException(
          "The input HMM and the sequenceOfObservations do not have the same symbol scale");
    }
    if (!inputHMM.isValid()) {
      throw new IllegalArgumentException("The inputHMM is not valid");
    }
    if (!sequenceOfObservations.isValid()) {
      throw new IllegalArgumentException("The sequenceOfObservations is not valid");
    }

    stateSequence = new SequenceOfObservations(inputHMM.getStateCount());
    stateSequence.getData().resize(sequenceOfObservations.getData().getCount());
    logOfTheProbability = org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.Viterbi.viterbi(
        sequenceOfObservations, inputHMM, stateSequence);
  }

  /**
   * Sets the input HMM.
   * 
   * @param inputHMM
   *          the input HMM
   */
  public void setInputHMM(final HMM inputHMM) {
    this.inputHMM = inputHMM;
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
}
