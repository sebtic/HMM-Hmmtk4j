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
package org.projectsforge.hmmtk4j.executors;

import org.projectsforge.hmmtk4j.EventListenerList;

/**
 * A interface defining the behavior of an algorithm.
 */
public abstract class Algorithm {

  /** The list of event listeners */
  private final EventListenerList<AlgorithmListener> algorithmListenerList = new EventListenerList<AlgorithmListener>();

  /** The cached event */
  private final AlgorithmEvent algorithmEvent = new AlgorithmEvent(this);

  private Throwable throwable;

  /**
   * Add a listener for algorithm events
   * 
   * @param listener
   *          the listener
   */
  public void addAlgorithmListener(final AlgorithmListener listener) {
    algorithmListenerList.add(listener);
  }

  /**
   * Fire the algorithmFinished event to all listeners.
   */
  protected void fireAlgorithmFinished() {
    for (final Object listener : algorithmListenerList.getListenerList()) {
      ((AlgorithmListener) listener).algorithmFinished(algorithmEvent);
    }
  }

  /**
   * Fire the algorithmStarted event to all listeners.
   */
  protected void fireAlgorithmStarted() {
    for (final Object listener : algorithmListenerList.getListenerList()) {
      ((AlgorithmListener) listener).algorithmStarted(algorithmEvent);
    }
  }

  public Throwable getThrowable() {
    return throwable;
  }

  public boolean hasFailed() {
    return throwable != null;
  }

  /**
   * Implement the algorithm without doing any verifications on input or output
   * parameters.
   * 
   * @throws InterruptedException
   */
  abstract protected void implement() throws InterruptedException;

  /**
   * Remove an algorithm listener.
   * 
   * @param l
   *          the listener
   */
  public void removeAlgorithmListener(final AlgorithmListener l) {
    algorithmListenerList.remove(l);
  }

  /**
   * Run the algorithm.
   * 
   * @param currentRunner
   *          the runner which execute the algorithm or null if none is
   *          specified.
   * @throws InterruptedException
   */
  public void run() throws InterruptedException {
    if (AlgorithmsExecutor.getAlgorithmsExecutionState().isRunning(this)) {
      throw new IllegalStateException("This algorithm is already running");
    } else {
      try {
        this.throwable = null;
        AlgorithmsExecutor.getAlgorithmsExecutionState().startAlgorithm(this);
        try {
          fireAlgorithmStarted();
          implement();
          fireAlgorithmFinished();
        } finally {
          AlgorithmsExecutor.getAlgorithmsExecutionState().stopAlgorithm(this);
        }
      } catch (final Throwable e) {
        this.throwable = e;
      }
    }
  }

}
