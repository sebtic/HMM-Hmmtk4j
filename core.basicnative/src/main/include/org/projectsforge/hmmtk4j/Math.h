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

#ifndef HMMTK4J_Core_Math_h
#define HMMTK4J_Core_Math_h

#include <math.h>
#include <float.h>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** The Math namespace */
      namespace Math
      {
        /** The absolute value below which a real is considered to be zero */
        extern const Double NULL_VALUE;

        /** Compute the minimum of two values \a a and \a b
         * @param a The first value
         * @param b the second value
         * @return min(a,b)
         */
        Integer min(const Integer a, const Integer b);

        /** Compute the maximum of two values \a a and \a b
         * @param a The first value
         * @param b the second value
         * @return max(a,b)
         */
        Integer max(const Integer a, const Integer b);

        /** Compute the minimum of two values \a a and \a b
         * @param a The first value
         * @param b the second value
         * @return min(a,b)
         */
        Double min(const Double a, const Double b);

        /** Compute the maximum of two values \a a and \a b
         * @param a The first value
         * @param b the second value
         * @return max(a,b)
         */
        Double max(const Double a, const Double b);

        /** A constant representing null logarithm */
        extern const Double LOG_NULL;

        /** test if value can be considered as log(0) */
        Boolean isLogNull(const Double value);

        /** A method that check if a Double value is null
         * @param value The value to check
         * @return true if \a value can be considered as null
         */
        Boolean isNull(const Double value);

        /** A robust log function
         * @param value The value
         * @return log(value) : if \a value > 1.0e-15, log(1.0e-15) otherwise
         */
        Double log(Double value);

        /** A robust log10 function
         * @param value The value
         * @return log(value) : if \a value > 1.0e-15, log10(1.0e-15) otherwise
         */
        Double log10(Double value);

        /** A robust square root function
         * @param value The value
         * @return sqrt(value) : if \a value > 0, 0 otherwise
         */
        Double sqrt(Double value);

        /** A function that computes a square
         * @param value The value
         * @return \a value*value
         */
        Double square(Double value);

        /** A function that computes the absolute value of the parameter
         * @param value The value
         * @return |value|
         */
        Double abs(Double value);

        /** A function that computes the absolute value of the parameter
         * @param value The value
         * @return |value|
         */
        Integer abs(Integer value);

        using ::pow;
        using ::exp;
      }

    }
  }
}

#endif
