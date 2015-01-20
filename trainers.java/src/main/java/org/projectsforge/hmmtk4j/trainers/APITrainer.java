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

import org.projectsforge.hmmtk4j.EventListenerList;
import org.projectsforge.hmmtk4j.RobustMath;

public abstract class APITrainer extends Trainer {
  protected class Ant {
    public int failCounter;

    public boolean isExploringFromNest = true;
    public int localPatience;
    public ScoredModel newPosition = new ScoredModel();
    public ScoredModel position = new ScoredModel();

    // Le nid est en cours de déplacement
    public void advertiseOnNestMoved() {
      isExploringFromNest = true;
      resetFailCounters();
    }

    // Indique que p est un echec
    //
    public void newExplorationFailure(final ScoredModel p) {
      failCounter++;
      if (failCounter >= localPatience) {
        isExploringFromNest = true;
      }
    }

    // Indique que p est un succès
    // @warning le modèle n'est pas dupliqué
    public void newExplorationSuccess(final ScoredModel p) {
      position.copy(p, false);
      resetFailCounters();
    }

    // Indique que p est le nouveau site de la fourmi
    // @warning le modèle n'est pas dupliqué
    public void newSite(final ScoredModel p) {
      position.copy(p, false);
      isExploringFromNest = false;
      resetFailCounters();
    }

    // Remet a zero les compteurs d'échecs
    public void resetFailCounters() {
      failCounter = 0;
    }
  }

  final protected static double[] getStrategy(final int nbValues, final double minValue,
      final double maxValue, final double strategy) {
    if (nbValues <= 0) {
      throw new IllegalArgumentException("nbValues must be strictly positive");
    }
    if (strategy <= 0) {
      throw new IllegalArgumentException("stategy must be strictly positive");
    }

    final double[] values = new double[nbValues];
    double a;
    double b;
    final boolean isLinear = RobustMath.isNull(strategy - 1.);

    if (isLinear) {
      b = (minValue - maxValue) / (1. - nbValues);
      a = maxValue - b * nbValues;
    } else {
      b = (maxValue - minValue) / (1. - Math.pow(strategy, 1. / nbValues - 1.));
      a = maxValue - b;
    }

    for (int i = 0; i < nbValues; ++i) {
      if (isLinear) {
        values[i] = a + b * (i + 1.);
      } else {
        values[i] = a + b * Math.pow(strategy, (i + 1.) / nbValues - 1.);
      }
      if (minValue < maxValue) {
        values[i] = Math.max(minValue, Math.min(maxValue, values[i]));
      } else {
        values[i] = Math.max(maxValue, Math.min(minValue, values[i]));
      }
    }
    return values;
  }

  final protected static int[] getStrategy(final int nbValues, final int minValue,
      final int maxValue, final double strategy) {
    if (nbValues <= 0) {
      throw new IllegalArgumentException("nbValues must be strictly positive");
    }
    if (strategy <= 0) {
      throw new IllegalArgumentException("stategy must be strictly positive");
    }

    final int[] values = new int[nbValues];
    double a;
    double b;
    final boolean isLinear = RobustMath.isNull(strategy - 1.);

    if (isLinear) {
      b = (minValue - maxValue) / (1. - nbValues);
      a = maxValue - b * nbValues;
    } else {
      b = (maxValue - minValue) / (1. - Math.pow(strategy, 1. / nbValues - 1.));
      a = maxValue - b;
    }

    for (int i = 0; i < nbValues; ++i) {
      if (isLinear) {
        values[i] = (int) (a + b * (i + 1.));
      } else {
        values[i] = (int) (a + b * Math.pow(strategy, (i + 1.) / nbValues - 1.));
      }
      if (minValue < maxValue) {
        values[i] = Math.max(minValue, Math.min(maxValue, values[i]));
      } else {
        values[i] = Math.max(maxValue, Math.min(minValue, values[i]));
      }
    }
    return values;
  }

  /** The list of event listeners */
  private final EventListenerList<APITrainerListener> apiTrainerListenerList = new EventListenerList<APITrainerListener>();

  /** The cached event */
  private final APITrainerEvent apiTrainerEvent = new APITrainerEvent(this);

  /**
   * The strategy used for the search of ants. Values greater than 1 makes ants
   * search more on near position whereas values lower than 1 makes ants search
   * on far position. Historical value is 100.
   */
  protected double amplitudeStrategy = 100;

  protected Ant[] ants;

  protected double maxAmplitude = 1;

  protected double minAmplitude = 0.01;
  /** The nb of ants. */
  protected int nbOfAnts = 20;
  private int nestPatience = 8;
  protected ScoredModel nestPosition = new ScoredModel();
  private int numberOfIterations = 100;

  /**
   * Add a listener for APITrainer events
   * 
   * @param l
   *          the listener
   */
  public void addAPITrainerListener(final APITrainerListener l) {
    apiTrainerListenerList.add(l);
  }

  protected abstract void createAndEvaluateTheInitialNestPositions() throws InterruptedException;

  // ant.newPosition.model must be usable without duplication
  protected abstract void createAnts();

  protected abstract void exploreAndEvaluate() throws InterruptedException;

  /**
   * Fire the APITrainerNestMoved event to all listeners.
   */
  protected void fireAPITrainerNestMoved() {
    for (final Object listener : apiTrainerListenerList.getListenerList()) {
      ((APITrainerListener) listener).APITrainerNestMoved(apiTrainerEvent);
    }
  }

  final public double getAmplitudeStrategy() {
    return amplitudeStrategy;
  }

  final public double getMaxAmplitude() {
    return maxAmplitude;
  }

  final public double getMinAmplitude() {
    return minAmplitude;
  }

  /**
   * Gets the nb of ants.
   * 
   * @return the nbOfAnts
   */
  final public int getNbOfAnts() {
    return nbOfAnts;
  }

  final public int getNestPatience() {
    return nestPatience;
  }

  final public int getNumberOfIterations() {
    return numberOfIterations;
  }

  @Override
  public void implement() throws InterruptedException {
    // Create the nest
    createAndEvaluateTheInitialNestPositions();
    registerBestScoredModel(nestPosition, true);

    // Create the ants
    ants = new Ant[nbOfAnts];
    createAnts();

    setCurrentIteration(0);
    while (getCurrentIteration() < numberOfIterations) {

      // shall we move the nest and reset ants ?
      if (getCurrentIteration() % nestPatience == 0) {
        // we move the nest to the best ever found model
        nestPosition.copy(getBestScoredModel(), true);
        // we reset the ants
        for (final Ant ant : ants) {
          ant.advertiseOnNestMoved();
        }
        fireAPITrainerNestMoved();
      }

      // we explore the search space from the current positions of
      // ants'memory
      exploreAndEvaluate();

      // we record the new positions
      for (final Ant ant : ants) {
        // if we explore from nest, we memorize the new position as the
        // memory
        if (ant.isExploringFromNest) {
          ant.newSite(ant.newPosition);
        } else {
          // if we explore from the memory, we keep the best position
          if (maximize) {
            if (ant.newPosition.score > ant.position.score) {
              ant.newExplorationSuccess(ant.newPosition);
            } else {
              ant.newExplorationFailure(ant.newPosition);
            }
          } else {
            if (ant.newPosition.score < ant.position.score) {
              ant.newExplorationSuccess(ant.newPosition);
            } else {
              ant.newExplorationFailure(ant.newPosition);
            }
          }
        }

        registerBestScoredModel(ant.newPosition, true);
      }
      setCurrentIteration(getCurrentIteration() + 1);
    }
  }

  // Create an ant
  public Ant newAntInstance() {
    return new Ant();
  }

  /**
   * Remove an APITrainer listener.
   * 
   * @param l
   *          the listener
   */
  public void removeAPITrainerListener(final APITrainerListener l) {
    apiTrainerListenerList.remove(l);
  }

  final public void setAmplitudeStrategy(final double strategy) {
    this.amplitudeStrategy = strategy;
  }

  final public void setMaxAmplitude(final double maxAmplitude) {
    this.maxAmplitude = maxAmplitude;
  }

  final public void setMinAmplitude(final double minAmplitude) {
    this.minAmplitude = minAmplitude;
  }

  /**
   * Sets the nb of ants.
   * 
   * @param nbOfAnts
   *          the nbOfAnts to set
   */
  final public void setNbOfAnts(final int nbOfAnts) {
    if (nbOfAnts < 1) {
      throw new IllegalArgumentException("The parameter must be positive");
    }
    this.nbOfAnts = nbOfAnts;
  }

  final public void setNestPatience(final int aNestPatience) {
    if (aNestPatience < 0) {
      throw new IllegalArgumentException("The parameter must be at least positive");
    }
    nestPatience = aNestPatience;
  }

  final public void setNumberOfIterations(final int aNumberOfIterations) {
    if (aNumberOfIterations < 0) {
      throw new IllegalArgumentException("The parameter must be at least positive");
    }
    numberOfIterations = aNumberOfIterations;
  }
}
