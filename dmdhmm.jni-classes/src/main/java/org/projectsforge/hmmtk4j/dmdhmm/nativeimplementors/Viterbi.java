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
package org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors;

import org.projectsforge.alternatives.loader.Loader;
import org.projectsforge.hmmtk4j.dmdhmm.HMM;
import org.projectsforge.hmmtk4j.dmdhmm.SequenceOfObservations;

public final class Viterbi {

  static {
    Loader.load("hmmtk4j-dmdhmm-jni");
  }

  public static native double viterbi(final SequenceOfObservations sequenceOfObservations,
      final HMM inputHMM,
      final org.projectsforge.hmmtk4j.discretehmm.SequenceOfObservations stateSequence);

}
