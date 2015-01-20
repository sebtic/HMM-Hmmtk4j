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
 * $Id: Backward.java 11 2010-08-31 15:52:23Z sebtic $
 */
package org.projectsforge.hmmtk4j.discretehmm.nativeimplementors;

import org.projectsforge.alternatives.loader.Loader;
import org.projectsforge.hmmtk4j.ArrayOfDouble;
import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.discretehmm.HMM;
import org.projectsforge.hmmtk4j.discretehmm.SequenceOfObservations;

/**
 * The native implementation of the Backward algorithm.
 * 
 * @author Sébastien Aupetit
 */
public final class Backward {

  static {
    Loader.load("hmmtk4j-discretehmm-jni");
  }

  /**
   * The native implementation of the backward algorithm.
   * 
   * @param hmm
   *          the HMM
   * @param sequenceOfObservations
   *          the observation
   * @param rescalingCoefs
   *          the computed rescaling coefficients
   * @param betaTildes
   *          the computed betaTildes variables
   */
  public native static void backward(HMM hmm, SequenceOfObservations sequenceOfObservations,
      ArrayOfDouble rescalingCoefs, MatrixOfDouble betaTildes);
}
