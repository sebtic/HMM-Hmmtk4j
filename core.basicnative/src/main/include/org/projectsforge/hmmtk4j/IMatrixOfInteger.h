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

#ifndef HMMTK4J_Core_IMatrixOfInteger_h
#define HMMTK4J_Core_IMatrixOfInteger_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      class IMatrixOfInteger: public IMatrix<Integer>
      {
        public:

          /** Add y to the elements of the matrix
           *
           * @param y the value to add
           */
          void add(const Integer y);

          void add(const Ref<IMatrix<Integer> > & y);

          void sub(const Ref<IMatrix<Integer> > & y);

          /** Add y to the elements of the row of the matrix
           *
           * @param row the row index
           * @param y the value to add
           */
          void addToRow(const Integer row, const Integer y);

          /** Compute the matrix resulting from the application of the mask. If a boolean is false,
           * the corresponding value in the matrix is set to 0.
           *
           * @param y the mask
           */
          void applyMask(const Ref<IMatrix<Boolean> > & y);

          /** Count the number of apparition of value in the row of the matrix
           *
           * @param row the row index
           * @param value the value to search for
           * @return
           */
          Integer countElementsOnRow(const Integer row, const Integer value);

          /** Get the index of the maximal element in a row
           *
           * @param row the row index
           * @return the column index
           */
          Integer indexOfMaxElement(const Integer row);

          /** Get the maximal value in a row
           *
           * @param row the row index
           * @return the maximal value
           */
          Integer maxElement(const Integer row);

          /** Get the index of the minimal element in a row
           *
           * @param row the row index
           * @return the column index
           */
          Integer indexOfMinElement(const Integer row);

          /** Get the minimal element of a row
           *
           * @param row the row index
           * @return the minimal element
           */
          Integer minElement(const Integer row);

          /** Check if the elements the matrix are in the range [minValue;maxValue]
           *
           * @param minValue the minimal value
           * @param maxValue the maximal value
           * @return true if all the elements the matrix are in the range [minValue;maxValue]
           */
          Boolean isValid(const Integer & minValue, const Integer & maxValue);

          /** Get the maximal element of the matrix
           *
           * @return the maximal element
           */
          Integer maxElement();

          /** Get the minimal element of the matrix
           *
           * @return the minimal element
           */
          Integer minElement();

          /** Copy the content of column into a dynamic array
           *
           * @param col the column index
           * @param y the array
           */
          void getCol(const Integer col, const Ref<DynamicArrayOfInteger> & y);

          /** Copy the content of the row into a dynamic array
           *
           * @param row the row index
           * @param y the array
           */
          void getRow(const Integer row, const Ref<DynamicArrayOfInteger> & y);

      };
    }
  }
}

#endif
