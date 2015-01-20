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

#ifndef HMMTK4J_Core_IArrayOfBoolean_h
#define HMMTK4J_Core_IArrayOfBoolean_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      class IArrayOfBoolean: public IArray<Boolean>
      {
        public:
          /** Count the number of times that the value appears in the array
           *
           * @param value the value to count
           * @return the number of times that the value appears in the array
           */
          Integer countElements(const Boolean value);

          /** Check if the provided boolean mask has at least one true value
           *
           * @return true if the provided boolean mask has at least one true value, false otherwise
           */
          Boolean isValidMask();
      };
    }
  }
}

#endif
