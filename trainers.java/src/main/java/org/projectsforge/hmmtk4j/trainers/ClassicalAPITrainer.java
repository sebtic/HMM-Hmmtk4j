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
package org.projectsforge.hmmtk4j.trainers;

// TODO: Auto-generated Javadoc
/**
 * The Class ClassicalAPITrainer.
 */
public abstract class ClassicalAPITrainer extends APITrainer {

  /**
   * The Class ClassicalAnt.
   */
  protected class ClassicalAnt extends Ant {

    /** The local amplitude in the range [0;1]. */
    public double localAmplitude;

    /** The nest amplitude in the range [0;1]. */
    public double nestAmplitude;
  }

  /** The local patience. */
  private int localPatience = 4;

  /** The factor used to compute local amplitudes from nest amplitude */
  private double nestToLocalAmplitudeFactor = 0.1;

  /*
   * (non-Javadoc)
   * @see fr.univtours.li.hmmtk4j.trainers.BasicAPITrainer#createAnts()
   */
  @Override
  protected void createAnts() {
    double lnestAmplitude;
    double llocalAmplitude;
    final double[] values =
        APITrainer.getStrategy(nbOfAnts, minAmplitude, maxAmplitude,
            amplitudeStrategy);

    for (int i = 0; i < nbOfAnts; ++i) {
      final ClassicalAnt ant = (ClassicalAnt) newAntInstance();

      lnestAmplitude = values[i];
      llocalAmplitude = lnestAmplitude * nestToLocalAmplitudeFactor;

      ant.localAmplitude = llocalAmplitude;
      ant.nestAmplitude = lnestAmplitude;
      ant.localPatience = localPatience;
      ants[i] = ant;
    }
  }

  /**
   * Gets the local patience.
   * @return the localPatience
   */
  public int getLocalPatience() {
    return localPatience;
  }

  public double getNestToLocalAmplitudeFactor() {
    return nestToLocalAmplitudeFactor;
  }

  @Override
  public Ant newAntInstance() {
    return new ClassicalAnt();
  }

  /**
   * Sets the local patience.
   * @param localPatience the localPatience to set
   */
  public void setLocalPatience(final int localPatience) {
    if (localPatience < 0) {
      throw new IllegalArgumentException("The parameter must be positive");
    }
    this.localPatience = localPatience;
  }

  public void setNestToLocalAmplitudeFactor(
      final double nestToLocalAmplitudeFactor) {
    if ((nestToLocalAmplitudeFactor < 0) || (nestToLocalAmplitudeFactor > 1)) {
      throw new IllegalArgumentException(
          "The parameter must be in the range [0;1]");
    }
    this.nestToLocalAmplitudeFactor = nestToLocalAmplitudeFactor;
  }
}
