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
 * $Id: BaumWelchWithWeightedObservations.java 8 2010-06-01 16:56:49Z sebtic $
 */

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.executors.Algorithm;

/**
 * The Baum Welch algorithm with weighted observation sequences.
 * 
 * @author Sébastien Aupetit
 */
public class BaumWelchWithWeightedObservations extends Algorithm implements Serializable {

  /** The input HMM. */
  private HMM inputHMM;

  /** The log of the probability. */
  private double logOfTheProbability = RobustMath.LOG_NULL;

  /** The nb max iteration. */
  private int nbMaxIteration = 0;

  /** The observations. */
  private final List<WeightedSequenceOfObservations> observations = new ArrayList<WeightedSequenceOfObservations>();

  /** The output HMM. */
  private HMM outputHMM;

  /** The reevaluate a. */
  private boolean reevaluateA = true;

  /** The reevaluate b. */
  private boolean[] reevaluateB = new boolean[0];

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
   * Gets the observations.
   * 
   * @return the observation
   */
  public List<WeightedSequenceOfObservations> getObservations() {
    return observations;
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
    for (final WeightedSequenceOfObservations observation : observations) {
      if (!Arrays.equals(inputHMM.getSymbolCounts(), observation.getSequence()
          .getMaxDistinctValues())) {
        throw new IllegalArgumentException(
            "The input HMM and an observation do not have the same symbol range");
      }
      if (!observation.getSequence().isValid()) {
        throw new IllegalArgumentException("An observation is not valid");
      }
    }
    if (!inputHMM.isValid()) {
      throw new IllegalArgumentException("The input HMM is not valid");
    }

    outputHMM = new HMM(inputHMM.getStateCount(), inputHMM.getSymbolCounts());
    logOfTheProbability = org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.BaumWelchWithWeightedObservations
        .baumWelchWithWeightedObservations(inputHMM, observations
            .toArray(new WeightedSequenceOfObservations[0]), nbMaxIteration, reevaluateA,
            reevaluateB, reevaluatePi, outputHMM);

    if ((inputHMM.getStateCount() != outputHMM.getStateCount())
        || (!Arrays.equals(inputHMM.getSymbolCounts(), outputHMM.getSymbolCounts()))) {
      throw new IllegalArgumentException("The computed output HMM is not valid");
    }

    if (!outputHMM.isValid()) {
      throw new IllegalArgumentException("The output HMM is not valid");
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
  public boolean[] isReevaluateB() {
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
   * 
   *          <p>
   *          Warning: the reevaluateA, reevaluateB and reevaluatePi properties
   *          are resetted
   */
  public void setInputHMM(final HMM inputHMM) {
    this.inputHMM = inputHMM;
    reevaluateA = true;
    reevaluateB = new boolean[inputHMM.getSymbolComponentCount()];
    for (int i = 0; i < reevaluateB.length; ++i) {
      reevaluateB[i] = true;
    }
    reevaluatePi = true;
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
  public void setReevaluateB(final boolean[] reevaluateB) {
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
