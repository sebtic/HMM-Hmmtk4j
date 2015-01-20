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

import java.util.EventListener;

/**
 * A listener interface for Trainer events
 * @author Sébastien Aupetit
 */
public interface TrainerListener extends EventListener {
  /**
   * An event sent to signal that the best scored model has changed
   * @param event the event
   */
  public void trainerBestScoredModelImproved(TrainerEvent event);

  /**
   * An event sent to signal that the current iteration number has changed
   * @param trainerEvent the event
   */
  public void trainerChangedCurrentIteration(TrainerEvent trainerEvent);

  /**
   * An event sent to signal that the trainer has progressed
   * @param event the event
   */
  public void trainerHasProgressed(TrainerEvent event);
}
