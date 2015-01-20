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
 * A fast Forward implementation with multiple weighted observations.
 *
 * @author Sébastien Aupetit
 */
public class FastForwardWithWeightedObservations extends Algorithm implements Serializable {

  /** The input HMM. */
  private HMM inputHMM;

  /** The logarithm of the probability. */
  private double logOfTheProbability = RobustMath.LOG_NULL;

  /** The observations. */
  private final List<WeightedSequenceOfObservations> observations = new ArrayList<WeightedSequenceOfObservations>();

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
   * Gets the observation.
   *
   * @return the observation
   */
  public List<WeightedSequenceOfObservations> getObservations() {
    return observations;
  }

  /**
   * {@inheritDoc}
   *
   * @see org.projectsforge.hmmtk4j.executors.Algorithm#implement()
   */
  @Override
  protected void implement() {
    for (final WeightedSequenceOfObservations observation : observations) {
      if (inputHMM.getSymbolCount() != observation.getSequence().getMaxDistinctValues()) {
        throw new IllegalArgumentException(
            "The input HMM and an observation do not have the same symbol scale");
      }
      if (!observation.getSequence().isValid()) {
        throw new IllegalArgumentException("An observation is not valid");
      }
    }
    if (!inputHMM.isValid()) {
      throw new IllegalArgumentException("The input HMM is not valid");
    }

    logOfTheProbability = org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.FastForwardWithWeightedObservations
        .fastForwardWithWeightedObservations(inputHMM, observations
            .toArray(new WeightedSequenceOfObservations[0]));
  }

  /**
   * Sets the input HMM.
   *
   * @param inputHMM
   *          the input HMM
   */
  public void setHMM(final HMM inputHMM) {
    this.inputHMM = inputHMM;
  }
}
