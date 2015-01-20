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

#ifndef HMMTK4J_Core_Math_inlines_h
#define HMMTK4J_Core_Math_inlines_h

#include <math.h>
#include <float.h>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace Math
      {
        HMMTK4J_INLINE Integer min(const Integer a, const Integer b)
        {
          return (a < b) ? a : b;
        }

        HMMTK4J_INLINE Integer max(const Integer a, const Integer b)
        {
          return (a > b) ? a : b;
        }

        HMMTK4J_INLINE Double min(const Double a, const Double b)
        {
          return (a < b) ? a : b;
        }

        HMMTK4J_INLINE Double max(const Double a, const Double b)
        {
          return (a > b) ? a : b;
        }

        HMMTK4J_INLINE Boolean isLogNull(const Double value)
        {
          return (value <= LOG_NULL);
        }

        HMMTK4J_INLINE Boolean isNull(const Double value)
        {
          return (fabs(value) < NULL_VALUE);
        }

        HMMTK4J_INLINE Double log(Double value)
        {
          if (value < NULL_VALUE)
            return LOG_NULL;
          else
            return ::log(value);
        }

        HMMTK4J_INLINE Double log10(Double value)
        {
          if (value < NULL_VALUE)
            return LOG_NULL;
          else
            return ::log10(value);
        }

        HMMTK4J_INLINE Double sqrt(Double value)
        {
          return ::sqrt(max(0.0, value));
        }

        HMMTK4J_INLINE Double square(Double value)
        {
          return value * value;
        }

        HMMTK4J_INLINE Double abs(Double value)
        {
          return (value > 0) ? value : -value;
        }

        HMMTK4J_INLINE Integer abs(Integer value)
        {
          return (value > 0) ? value : -value;
        }
      }
    }
  }
}

#endif
