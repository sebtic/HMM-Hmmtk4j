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

/**
 * The Class NewAPITrainer.
 */
public abstract class NewAPITrainer extends APITrainer {

  /**
   * The Class NewAnt.
   */
  protected class NewAnt extends Ant {

    public double minAmplitude;
    public double maxAmplitude;
  }

  /** The patience on the inner ring. */
  private int innerPatience = 1;

  /** The patience on the outer ring. */
  private int outerPatience = 1;

  /** The fusiness to apply on ring widths. */
  private double ringFusiness = 1;

  private double patienceStrategy = 100;

  protected double amplitudesLimits[];

  /*
   * (non-Javadoc)
   * @see fr.univtours.li.hmmtk4j.trainers.BasicAPITrainer#createAnts()
   */
  @Override
  protected void createAnts() {
    final int patienceValues[] =
        APITrainer.getStrategy(nbOfAnts, innerPatience, outerPatience,
            patienceStrategy);
    amplitudesLimits =
        APITrainer.getStrategy(nbOfAnts, minAmplitude, maxAmplitude,
            amplitudeStrategy);

    for (int i = 0; i < nbOfAnts; ++i) {
      final NewAnt ant = (NewAnt) newAntInstance();
      ant.localPatience = patienceValues[i];
      ant.maxAmplitude = amplitudesLimits[i];
      if (i == 0) {
        ant.minAmplitude = 0;
      } else {
        ant.minAmplitude = amplitudesLimits[i - 1];
      }
      ants[i] = ant;
    }
  }

  /**
   * Gets the inner ring patience.
   * @return the inner ring patience
   */
  public int getInnerPatience() {
    return innerPatience;
  }

  /**
   * Gets the outer patience.
   * @return the outer ring patience
   */
  public int getOuterPatience() {
    return outerPatience;
  }

  public double getPatienceStrategy() {
    return patienceStrategy;
  }

  /**
   * @return the ringFusiness
   */
  public double getRingFusiness() {
    return ringFusiness;
  }

  // Create an ant
  @Override
  public Ant newAntInstance() {
    return new NewAnt();
  }

  /**
   * Sets the inner ring patience.
   * @param innerPatience the inner ring patience to set
   */
  public void setInnerPatience(final int innerPatience) {
    if (innerPatience < 1) {
      throw new IllegalArgumentException(
          "The value must be greater or equal to 1.");
    }
    this.innerPatience = innerPatience;
  }

  /**
   * Sets the outer patience.
   * @param outerPatience the outer ring patience to set
   */
  public void setOuterPatience(final int outerPatience) {
    if (outerPatience < 1) {
      throw new IllegalArgumentException(
          "The value must be greater or equal to 1.");
    }
    this.outerPatience = outerPatience;
  }

  public void setPatienceStrategy(final double patienceStrategy) {
    this.patienceStrategy = patienceStrategy;
  }

  /**
   * @param ringFusiness the ringFusiness to set
   */
  public void setRingFusiness(final double ringFusiness) {
    this.ringFusiness = ringFusiness;
  }

}
