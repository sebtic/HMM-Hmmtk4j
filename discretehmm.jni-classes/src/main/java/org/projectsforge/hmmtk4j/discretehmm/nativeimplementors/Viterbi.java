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
 * $Id: Viterbi.java 11 2010-08-31 15:52:23Z sebtic $
 */
package org.projectsforge.hmmtk4j.discretehmm.nativeimplementors;

import org.projectsforge.alternatives.loader.Loader;
import org.projectsforge.hmmtk4j.discretehmm.HMM;
import org.projectsforge.hmmtk4j.discretehmm.SequenceOfObservations;

/**
 * The native implementation of the Viterbi algorithm.
 * 
 * @author Sébastien Aupetit
 */
public final class Viterbi {

  static {
    Loader.load("hmmtk4j-discretehmm-jni");
  }

  /**
   * Compute the Viterbi algorithm.
   * 
   * @param sequenceOfObservations
   *          the observation
   * @param hmm
   *          the HMM
   * @param stateSequence
   *          the state sequence
   * @return the logarithm of the probability
   */
  public static native double viterbi(SequenceOfObservations sequenceOfObservations, HMM hmm, SequenceOfObservations stateSequence);

}
