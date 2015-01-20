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

#ifndef HMMTK4J_Core_IndexOutOfBoundsException_h
#define HMMTK4J_Core_IndexOutOfBoundsException_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** An index out of bounds exception */
      class IndexOutOfBoundsException: public Exception
      {
        private:
          Integer index;
          Integer min;
          Integer max;
        public:
          /** The constructor defining the value accessed index and the admissible range [min;max].
           * @param index the accessed index
           * @param min the minimum allowed index
           * @param max the maximum allowed index
           */
          IndexOutOfBoundsException(Integer index, Integer min, Integer max);
          /** Get the index */
          Integer getIndex() const;
          /** Get the lower bound of the admissible range */
          Integer getMin() const;
          /** Get the upper bound of the admissible range */
          Integer getMax() const;
      };
    }
  }
}

/** Check the validity of the Index and raise an IndexOutOfBoundsException if not valid
 * @warning This check is done only when HMMTK4J_DISABLE_EXPENSIVE_CHECKS is not defined
 */
#ifndef HMMTK4J_DISABLE_EXPENSIVE_CHECKS
  #define HMMTK4J_CheckBounds( Index, Min, Max ) \
    if (((Index) < (Min)) || ((Max) < (Index))) \
    { \
      org::projectsforge::hmmtk4j::IndexOutOfBoundsException __e((Index), (Min), (Max)); \
      HMMTK4J_RaiseException(__e); \
    }
#else
  #define HMMTK4J_CheckBounds( Index, Min, Max ) { }
#endif

#endif
