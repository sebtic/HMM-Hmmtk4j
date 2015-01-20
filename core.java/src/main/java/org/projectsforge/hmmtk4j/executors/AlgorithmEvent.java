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
 * An algorithm event.
 * 
 * @author Sébastien Aupetit
 */
public class AlgorithmEvent {

  /**
   * The serial UID
   */
  private static final long serialVersionUID = -6730745072352513293L;
  private final Algorithm source;

  /**
   * The constructor
   * 
   * @param source
   *          the Algorithm which send the event
   */
  public AlgorithmEvent(final Algorithm source) {
    if (source == null) {
      throw new IllegalArgumentException("null source");
    }
    this.source = source;
  }

  /**
   * Get the algorithm which sends the event
   * 
   * @return the algorithm instance
   */
  public Algorithm getSource() {
    return source;
  }
}
