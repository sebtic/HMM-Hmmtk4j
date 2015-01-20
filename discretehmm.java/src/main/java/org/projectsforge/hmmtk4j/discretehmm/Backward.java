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
import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.executors.Algorithm;

/**
 * The Backward algorithm.
 * 
 * @author Sébastien Aupetit
 */
public class Backward extends Algorithm implements Serializable {

  /** The beta tildes. */
  private final MatrixOfDouble betaTildes = new MatrixOfDouble();

  /** The forward. */
  private Forward forward = null;

  /**
   * Gets the beta tilde.
   * 
   * @param timeT
   *          the time t
   * @param stateI
   *          the state i
   * @return the beta tilde
   */
  public double getBetaTilde(final int timeT, final int stateI) {
    return betaTildes.get(timeT, stateI);
  }

  /**
   * Gets the beta tildes.
   * 
   * @return the betaTildes
   */
  public MatrixOfDouble getBetaTildes() {
    return betaTildes;
  }

  /**
   * Gets the forward.
   * 
   * @return the forward
   */
  public Forward getForward() {
    return this.forward;
  }

  /**
   * {@inheritDoc}
   * 
   * @see org.projectsforge.hmmtk4j.executors.Algorithm#implement()
   */
  @Override
  protected void implement() {
    betaTildes.resize(forward.getObservation().getData().getCount(), forward.getInputHMM()
        .getStateCount());

    org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.Backward.backward(forward
        .getInputHMM(), forward.getObservation(), forward.getRescalingCoefs(), betaTildes);
  }

  /**
   * Sets the forward.
   * 
   * @param forward
   *          the forward to set
   */
  public void setForward(final Forward forward) {
    this.forward = forward;
  }

}
