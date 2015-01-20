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

#ifndef HMMTK4J_Core_IArrayOfInteger_h
#define HMMTK4J_Core_IArrayOfInteger_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      class IArrayOfInteger: public IArray<Integer>
      {
        public:

          /** Count the number of times that the value appears in the array
           *
           * @param value the value to count
           * @return the number of times that the value appears in the array
           */
          Integer countElements(Integer value);

          /** Check if the elements of the array are in the range [minValue;maxValue]
           *
           * @param minValue the minimal value
           * @param maxValue the maximal value
           * @return true if the elements of the IArray are in the range [minValue;maxValue], false otherwise
           */
          Boolean isValid(const Integer minValue, const Integer maxValue);

          /** Apply a boolean mask on the array. If the boolean is false, the value is set to 0.
           *
           * @param y the boolean valued IArray
           */
          void applyMask(const Ref<IArray<Boolean> > & y);

      };
    }
  }
}

#endif
