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
import org.projectsforge.hmmtk4j.executors.Algorithm;

/**
 * The Class Trainer.
 */
public abstract class Trainer extends Algorithm {
  /** The list of event listeners */
  private final EventListenerList<TrainerListener> trainerListenerList = new EventListenerList<TrainerListener>();

  /** The cached event */
  private final TrainerEvent trainerEvent = new TrainerEvent(this);

  boolean maximize = true;

  /** The best scored model. */
  private ScoredModel bestScoredModel;

  /** The current iteration number */
  private int currentIteration;

  /**
   * Add a listener for trainer events
   * 
   * @param l
   *          the listener
   */
  public void addTrainerListener(final TrainerListener l) {
    trainerListenerList.add(l);
  }

  /**
   * Fire the TrainerBestScoredModelImproved event to all listeners.
   */
  protected void fireTrainerBestScoredModelImproved() {
    for (final Object listener : trainerListenerList.getListenerList()) {
      ((TrainerListener) listener).trainerBestScoredModelImproved(trainerEvent);
    }
  }

  /**
   * Fire the TrainerChangedCurrentIteration event to all listeners.
   */
  protected void fireTrainerChangedCurrentIteration() {
    for (final Object listener : trainerListenerList.getListenerList()) {
      ((TrainerListener) listener).trainerChangedCurrentIteration(trainerEvent);
    }
  }

  /**
   * Fire the TrainerHasProgressed event to all listeners.
   */
  protected void fireTrainerHasProgressed() {
    for (final Object listener : trainerListenerList.getListenerList()) {
      ((TrainerListener) listener).trainerHasProgressed(trainerEvent);
    }
  }

  /**
   * Gets the best scored model.
   * 
   * @return the best scored model
   */
  public final ScoredModel getBestScoredModel() {
    return bestScoredModel;
  }

  /**
   * @return the currentIteration
   */
  public final int getCurrentIteration() {
    return currentIteration;
  }

  /**
   * Indicate if we are trying to maximize or minimise
   * 
   * @return the boolean
   */
  protected final boolean getMaximize() {
    return maximize;
  }

  /**
   * Register a scored model.
   * 
   * @param sm
   *          the scored model
   * @param needToDuplicateModel
   *          a flag indicating if the data need to be deep duplicated
   * @return true if the best model has been improved with sm
   */
  public boolean registerBestScoredModel(final ScoredModel sm, final boolean needToDuplicateModel) {
    if (bestScoredModel == null) {
      if (needToDuplicateModel) {
        bestScoredModel = (ScoredModel) sm.deepClone();
      } else {
        bestScoredModel = sm;
      }
      fireTrainerBestScoredModelImproved();
      return true;
    } else {
      if (maximize) {
        if (bestScoredModel.score < sm.score) {
          bestScoredModel.copy(sm, needToDuplicateModel);
          fireTrainerBestScoredModelImproved();
          return true;
        }
      } else {
        if (bestScoredModel.score > sm.score) {
          bestScoredModel.copy(sm, needToDuplicateModel);
          fireTrainerBestScoredModelImproved();
          return true;
        }
      }
    }
    return false;
  }

  /**
   * Remove an algorithm listener.
   * 
   * @param l
   *          the listener
   */
  public void removeTrainerListener(final TrainerListener l) {
    trainerListenerList.remove(l);
  }

  /**
   * @param currentIteration
   *          the currentIteration to set
   */
  public final void setCurrentIteration(final int currentIteration) {
    this.currentIteration = currentIteration;
    fireTrainerChangedCurrentIteration();
  }

  protected final void setMaximize(final boolean maximize) {
    this.maximize = maximize;
  }
}
