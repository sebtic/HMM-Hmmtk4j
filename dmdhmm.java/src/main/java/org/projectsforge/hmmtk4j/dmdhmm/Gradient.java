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
 * $Id: Gradient.java 8 2010-06-01 16:56:49Z sebtic $
 */

import java.io.Serializable;
import org.projectsforge.hmmtk4j.executors.Algorithm;

/**
 * Compute the gradient of the log likelihood probability. The constraints are
 * removed by considering the exponential representation of the parameters.
 * 
 * @author Sébastien Aupetit
 */
public class Gradient extends Algorithm implements Serializable {

  private SequenceOfObservations sequenceOfObservations;
  private HMM inputHMM;
  private HMM gradient;
  private double logOfTheProbability;

  /**
   * Get the gradient.
   * 
   * @return the gradient
   */
  public HMM getGradient() {
    return gradient;
  }

  /**
   * Get the input HMM.
   * 
   * @return the input HMM
   */
  public HMM getInputHmm() {
    return inputHMM;
  }

  /**
   * Get the likelihood of the input HMM.
   * 
   * @return the logOfTheProbability
   */
  public double getLogOfTheProbability() {
    return logOfTheProbability;
  }

  /**
   * Get the sequenceOfObservations.
   * 
   * @return the sequenceOfObservations
   */
  public SequenceOfObservations getObservation() {
    return sequenceOfObservations;
  }

  /**
   * {@inheritDoc}
   * 
   * @see org.projectsforge.hmmtk4j.executors.Algorithm#implement()
   */
  @Override
  protected void implement() {
    gradient = new HMM(inputHMM.getStateCount(), inputHMM.getSymbolCounts());
    logOfTheProbability = org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.Gradient.gradient(
        sequenceOfObservations, inputHMM, gradient);
  }

  /**
   * Sets the input HMM.
   * 
   * @param inputHMM
   *          the inputHMM to set
   */
  public void setInputHmm(final HMM inputHMM) {
    this.inputHMM = inputHMM;
  }

  /**
   * @param sequenceOfObservations
   *          the sequenceOfObservations to set
   */
  public void setObservation(final SequenceOfObservations sequenceOfObservations) {
    this.sequenceOfObservations = sequenceOfObservations;
  }

}
