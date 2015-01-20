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
package org.projectsforge.hmmtk4j;

import org.projectsforge.hmmtk4j.nativeimplementors.Bridge;

/**
 * The Class that provides robust mathematical functions.
 * 
 * @author seb
 */
public final class RobustMath {

  /** The value used to represent log(0). */
  public static final double LOG_NULL = Bridge.getLOG_NULL();

  /** The level for which a value is considered as 0. */
  public static final double NULL_VALUE = Bridge.getNULL_VALUE();

  /**
   * Checks if value can be considered as being equal to log(0).
   * 
   * @param value
   *          the value
   * @return true if value < LOG_NULL
   */
  public static final boolean isLogNull(final double value) {
    return value <= RobustMath.LOG_NULL;
  }

  /**
   * Checks if value is nearly equal to 0.
   * 
   * @param value
   *          the value
   * @return true if abs(value) <= NULL_VALUE
   */
  public static final boolean isNull(final double value) {
    return Math.abs(value) <= RobustMath.NULL_VALUE;
  }

  /**
   * A robust log function.
   * 
   * @param value
   *          the value
   * @return log(value) if value > NULL_VALUE, LOG_NULL otherwise
   */
  public static final double log(final double value) {
    if (value <= RobustMath.NULL_VALUE) {
      return RobustMath.LOG_NULL;
    }
    return Math.log(value);
  }

  /**
   * A robust square root function.
   * 
   * @param value
   *          the value
   * @return sqrt(value) if value > 0, 0 otherwise
   */
  public static final double sqrt(final double value) {
    if (value <= 0.0) {
      return 0;
    }
    return Math.sqrt(value);
  }

  /**
   * A function that computes the square of value.
   * 
   * @param value
   *          the value
   * @return value*value
   */
  public static final double square(final double value) {
    return value * value;
  }
}
