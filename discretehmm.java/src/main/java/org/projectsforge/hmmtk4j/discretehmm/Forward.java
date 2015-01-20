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
import org.projectsforge.hmmtk4j.ArrayOfDouble;
import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.executors.Algorithm;

/**
 * The Forward algorithm.
 * 
 * @author Sébastien Aupetit
 */
public class Forward extends Algorithm implements Serializable {

  /** The alpha tildes. */
  private final MatrixOfDouble alphaTildes = new MatrixOfDouble();

  /** The input HMM. */
  private HMM inputHMM;

  /** The logarithm of the probability. */
  private double logOfTheProbability = RobustMath.LOG_NULL;

  /** The sequenceOfObservations. */
  private SequenceOfObservations sequenceOfObservations;

  /** The rescaling coefficients. */
  private final ArrayOfDouble rescalingCoefs = new ArrayOfDouble();

  /**
   * Gets the alpha tilde.
   * 
   * @param timeT
   *          the time t
   * @param stateI
   *          the state i
   * @return the alpha tilde
   */
  public double getAlphaTilde(final int timeT, final int stateI) {
    return alphaTildes.get(timeT, stateI);
  }

  /**
   * Gets the alpha tildes.
   * 
   * @return the alpha tildes
   */
  public MatrixOfDouble getAlphaTildes() {
    return alphaTildes;
  }

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
   * Gets the rescaling coefficients.
   * 
   * @return the rescaling coefficients
   */
  public ArrayOfDouble getRescalingCoefs() {
    return rescalingCoefs;
  }

  /**
   * Gets the rescaling coefficients.
   * 
   * @param timeT
   *          the time t
   * @return the rescaling coefficients
   */
  public double getRescalingCoefs(final int timeT) {
    return rescalingCoefs.get(timeT);
  }

  /**
   * {@inheritDoc}
   * 
   * @see org.projectsforge.hmmtk4j.executors.Algorithm#implement()
   */
  @Override
  protected void implement() {

    if (inputHMM.getB().getColCount() != sequenceOfObservations.getMaxDistinctValues()) {
      throw new IllegalArgumentException(
          "The hmm field and the sequenceOfObservations field do not have the same symbol range");
    }

    if (!inputHMM.isValid()) {
      throw new IllegalArgumentException("The hmm is not valid");
    }

    if (!sequenceOfObservations.isValid()) {
      throw new IllegalArgumentException("The sequenceOfObservations field is not valid");
    }

    alphaTildes.resize(sequenceOfObservations.getData().getCount(), inputHMM.getStateCount());
    rescalingCoefs.resize(sequenceOfObservations.getData().getCount(), false);
    logOfTheProbability = org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.Forward.forward(
        inputHMM, sequenceOfObservations, alphaTildes, rescalingCoefs);
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
