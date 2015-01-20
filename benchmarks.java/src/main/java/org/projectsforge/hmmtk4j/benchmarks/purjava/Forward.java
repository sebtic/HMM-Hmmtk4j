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
package org.projectsforge.hmmtk4j.benchmarks.purjava;

import org.projectsforge.hmmtk4j.Algorithm;
import org.projectsforge.hmmtk4j.RobustMath;

/**
 * The Class Forward.
 */
public class Forward extends Algorithm {
  /** The alpha tildes. */
  private final MatrixOfDouble alphaTildes = new MatrixOfDouble();

  /** The HMM. */
  private HMM hmm;

  /** The logarithm of the probability. */
  private double logOfTheProbability = RobustMath.LOG_NULL;

  /** The observation. */
  private Sequence observation;

  /** The rescaling coefficients. */
  private final ArrayOfDouble rescalingCoefs = new ArrayOfDouble();

  /*
   * (non-Javadoc)
   * 
   * @see fr.univtours.li.hmmtk4j.Algorithm#checkInputParameters()
   */
  public void checkInputParameters() {
    if (hmm.getB().getColCount() != observation.getMaxDistinctValues()) {
      throw new IllegalArgumentException(
          "The hmm field and the observation field do not have the same symbol scale");
    }
    if (!hmm.isValid()) {
      throw new IllegalArgumentException("The hmm is not valid");
    }
    if (!observation.isValid()) {
      throw new IllegalArgumentException("The observation field is not valid");
    }
  }

  /*
   * (non-Javadoc)
   * 
   * @see fr.univtours.li.hmmtk4j.Algorithm#checkOutputParameters()
   */
  public void checkOutputParameters() {
    if ((alphaTildes.getRowCount() != observation.getCount())
        || (alphaTildes.getColCount() != hmm.getStateCount())) {
      throw new IllegalArgumentException("The alphaTildes field is not valid");
    }
    if (rescalingCoefs.getCount() != observation.getCount()) {
      throw new IllegalArgumentException("The rescalingCoefs field is not valid");
    }
  }

  public double doIt() {
    final int stateCount = hmm.getA().getRowCount();
    final int length = observation.getCount();

    // HMMTK4J_ASSERT( (alphaTildes.rowCount == length) && (alphaTildes.colCount
    // == stateCount ) );
    // HMMTK4J_ASSERT( rescalingCoefs.size == length );

    if (length == 0) {
      return org.projectsforge.hmmtk4j.RobustMath.LOG_NULL;
    }

    final ArrayOfDouble Pi = hmm.getPi();
    final MatrixOfDouble A = hmm.getA();
    final MatrixOfDouble B = hmm.getB();

    boolean validProba = true;

    // ***** Initialisation *****
    {
      final int ot = observation.get(0);
      for (int i = stateCount - 1; i >= 0; --i) {
        alphaTildes.set(0, i, Pi.get(i) * B.get(i, ot));
      }

      final double sum = alphaTildes.makeStochasticRow(0);
      if (RobustMath.isNull(sum)) {
        validProba = false;
      }
      rescalingCoefs.set(0, 1.0 / sum);
    }

    // ***** Main loop *****

    for (int t = 1; t < length; ++t) {
      final int ot = observation.get(t);
      for (int j = stateCount - 1; j >= 0; --j) {
        double cumul = 0;
        for (int i = stateCount - 1; i >= 0; --i) {
          cumul += alphaTildes.get(t - 1, i) * A.get(i, j);
        }
        alphaTildes.set(t, j, cumul * B.get(j, ot));
      }

      final double sum = alphaTildes.makeStochasticRow(t);
      if (RobustMath.isNull(sum)) {
        validProba = false;
      }
      rescalingCoefs.set(t, 1.0 / sum);
    }

    // ***** Finalization *****
    if (validProba) {
      double logProba = 0;
      for (int t = length - 1; t >= 0; --t) {
        logProba -= RobustMath.log(rescalingCoefs.get(t));
      }
      return logProba;
    } else {
      return RobustMath.LOG_NULL;
    }
  }

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
   * Gets the HMM.
   * 
   * @return the HMM
   */
  public HMM getHMM() {
    return hmm;
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
  public Sequence getObservation() {
    return observation;
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

  /*
   * (non-Javadoc)
   * 
   * @see fr.univtours.li.hmmtk4j.Algorithm#implement()
   */
  @Override
  public void implement() {
    // checkInputParameters();
    alphaTildes.resize(observation.getCount(), hmm.getStateCount());
    rescalingCoefs.resize(observation.getCount(), false);
    logOfTheProbability = doIt();
    // checkOutputParameters();
  }

  /**
   * Sets the HMM.
   * 
   * @param ahmm
   *          the new HMM
   */
  public void setHMM(final HMM ahmm) {
    hmm = ahmm;
  }

  /**
   * Sets the observation.
   * 
   * @param obs
   *          the new observation
   */
  public void setObservation(final Sequence obs) {
    observation = obs;
  }

}
