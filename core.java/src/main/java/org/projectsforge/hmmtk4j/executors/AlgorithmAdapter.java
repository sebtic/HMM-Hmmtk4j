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

/**
 * An adapter class for AlgorithmListener.
 * @author Sébastien Aupetit
 */
public class AlgorithmAdapter implements AlgorithmListener {

  /**
   * The method is called when an algorithm is finished.
   * @param event the event
   */
  public void algorithmFinished(final AlgorithmEvent event) {
    // nothing to do
  }

  /**
   * The method is called when an algorithm is starting.
   * @param event the event
   */
  public void algorithmStarted(final AlgorithmEvent event) {
    // nothing to do
  }

}
