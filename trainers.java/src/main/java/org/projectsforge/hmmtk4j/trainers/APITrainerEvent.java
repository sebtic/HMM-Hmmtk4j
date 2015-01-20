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

import java.util.EventObject;

/**
 * A trainer event.
 * @author Sébastien Aupetit
 */
public class APITrainerEvent extends EventObject {

  /**
   *
   */
  private static final long serialVersionUID = 7527504049156045365L;

  /**
   * The constructor
   * @param source the Algorithm which send the event
   */
  public APITrainerEvent(final APITrainer source) {
    super(source);
  }

  /**
   * Get the APITrainer which sends the event
   * @return the algorithm instance
   */
  public APITrainer getSourceAPITrainer() {
    return (APITrainer) getSource();
  }
}
