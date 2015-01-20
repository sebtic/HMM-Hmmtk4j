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

#ifndef HMMTK4J_Core_IMatrixOfBoolean_h
#define HMMTK4J_Core_IMatrixOfBoolean_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      class IMatrixOfBoolean: public IMatrix<Boolean>
      {
        public:

          /** Count the number of apparition of value in the row of the matrix
           *
           * @param row the row index
           * @param value the value to search for
           * @return
           */
          Integer countElementsOnRow(const Integer row, const Boolean value);

          /** Copy the content of column into a dynamic array
           *
           * @param col the column index
           * @param y the array
           */
          void getCol(const Integer col, const Ref<DynamicArrayOfBoolean> & y);

          /** Copy the content of the row into a dynamic array
           *
           * @param row the row index
           * @param y the array
           */
          void getRow(const Integer row, const Ref<DynamicArrayOfBoolean> & y);

          /** Check if the matrix is a valid mask that is to say there exists at least one true value on each row
           *
           * @return true if the matrix is a valid mask
           */
          Boolean isValidMask();
      };
    }
  }
}

#endif
