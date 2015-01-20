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
 * $Id: SegmentalKMeans.java 8 2010-06-01 16:56:49Z sebtic $
 */

import java.io.Serializable;
import java.util.Arrays;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.executors.Algorithm;

/**
 * An implementation of the segmental K-means algorithm.
 * 
 * @author Sébastien Aupetit
 */
public class SegmentalKMeans extends Algorithm implements Serializable {

  /** The input HMM. */
  private HMM inputHMM;

  /** The log of the probability. */
  private double logOfTheProbability = RobustMath.LOG_NULL;

  /** The nb max iteration. */
  private int nbMaxIteration = 0;

  /** The sequenceOfObservations. */
  private SequenceOfObservations sequenceOfObservations;

  /** The output HMM. */
  private HMM outputHMM;

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
   * Gets the sequenceOfObservations.
   * 
   * @return the sequenceOfObservations
   */
  public SequenceOfObservations getObservation() {
    return sequenceOfObservations;
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
   * {@inheritDoc}
   * 
   * @see org.projectsforge.hmmtk4j.executors.Algorithm#implement()
   */
  @Override
  protected void implement() {
    if (!Arrays.equals(inputHMM.getSymbolCounts(), sequenceOfObservations.getMaxDistinctValues())) {
      throw new IllegalArgumentException(
          "The input HMM and the sequenceOfObservations do not have the same symbol scale");
    }
    if (!inputHMM.isValid()) {
      throw new IllegalArgumentException("The inputHMM is not valid");
    }
    if (!sequenceOfObservations.isValid()) {
      throw new IllegalArgumentException("The sequenceOfObservations is not valid");
    }
    outputHMM = new HMM(inputHMM.getStateCount(), inputHMM.getSymbolCounts());
    logOfTheProbability = org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.SegmentalKMeans
        .segmentalKMeans(inputHMM, sequenceOfObservations, nbMaxIteration, outputHMM);

    if (!outputHMM.isValid()) {
      throw new IllegalArgumentException("The outputHMM is not valid");
    }
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
   * Sets the sequenceOfObservations.
   * 
   * @param sequenceOfObservations
   *          the new sequenceOfObservations
   */
  public void setObservation(final SequenceOfObservations sequenceOfObservations) {
    this.sequenceOfObservations = sequenceOfObservations;
  }
}
