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
 * $Id: LabelledTraining.java 8 2010-06-01 16:56:49Z sebtic $
 */

import java.io.Serializable;
import org.projectsforge.hmmtk4j.executors.Algorithm;

/**
 * Estimate an HMM from a labelled sequenceOfObservations sequence.
 * 
 * @author Sébastien Aupetit
 */
public class LabelledTraining extends Algorithm implements Serializable {

  /** The sequenceOfObservations. */
  private SequenceOfObservations sequenceOfObservations;

  /** The state sequence. */
  private org.projectsforge.hmmtk4j.discretehmm.SequenceOfObservations stateSequence;

  /** The output HMM. */
  private HMM outputHMM;

  /** The smoothing coefficient. */
  private double smoothing = 0.0;

  /**
   * Gets the sequenceOfObservations.
   * 
   * @return the sequenceOfObservations
   */
  public SequenceOfObservations getObservation() {
    return sequenceOfObservations;
  }

  /**
   * Get the output HMM.
   * 
   * @return the output HMM
   */
  public HMM getOutputHMM() {
    return outputHMM;
  }

  /**
   * Get the smoothing coefficient.
   * 
   * @return the smoothing coefficient
   */
  public double getSmoothing() {
    return smoothing;
  }

  /**
   * Get the state sequence.
   * 
   * @return the stateSequence
   */
  public org.projectsforge.hmmtk4j.discretehmm.SequenceOfObservations getStateSequence() {
    return stateSequence;
  }

  /**
   * {@inheritDoc}
   * 
   * @see org.projectsforge.hmmtk4j.executors.Algorithm#implement()
   */
  @Override
  protected void implement() {
    if (stateSequence.getLength() != sequenceOfObservations.getLength()) {
      throw new IllegalArgumentException(
          "The sequenceOfObservations and the state sequence do not have the same length.");
    }

    outputHMM = new HMM(stateSequence.getMaxDistinctValues(), sequenceOfObservations
        .getMaxDistinctValues());
    org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.LabelledTraining.labelledTraining(
        sequenceOfObservations, stateSequence, smoothing, outputHMM);

    if (!outputHMM.isValid()) {
      throw new IllegalArgumentException("The outputHMM is not valid");
    }
  }

  /**
   * Set the sequenceOfObservations.
   * 
   * @param sequenceOfObservations
   *          the sequenceOfObservations to set
   */
  public void setObservation(final SequenceOfObservations sequenceOfObservations) {
    this.sequenceOfObservations = sequenceOfObservations;
  }

  /**
   * Set the smoothing coefficient.
   * 
   * @param smoothing
   *          the smoothing to set
   * @throws IllegalArgumentException
   *           if smoothing is negative.
   */
  public void setSmoothing(final double smoothing) {
    if (smoothing < 0) {
      throw new IllegalArgumentException("Smoothing must be positive or null.");
    }
    this.smoothing = smoothing;
  }

  /**
   * Set the state sequence.
   * 
   * @param stateSequence
   *          the stateSequence to set
   */
  public void setStateSequence(
      final org.projectsforge.hmmtk4j.discretehmm.SequenceOfObservations stateSequence) {
    this.stateSequence = stateSequence;
  }

}
