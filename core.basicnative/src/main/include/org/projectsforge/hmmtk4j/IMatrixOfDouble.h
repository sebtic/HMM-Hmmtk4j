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

#ifndef HMMTK4J_Core_IMatrixOfDouble_h
#define HMMTK4J_Core_IMatrixOfDouble_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      class IMatrixOfDouble: public IMatrix<Double>
      {
        public:
          /** Add y to the elements of the matrix
           *
           * @param y the value to add
           */
          void add(const Double y);

          void add(const Ref<IMatrix<Double> > & y);

          void sub(const Ref<IMatrix<Double> >& y);

          /** Add y to the elements of the row of the matrix
           *
           * @param row the row index
           * @param y the value to add
           */
          void addToRow(const Integer row, const Double y);

          /** Compute the matrix resulting from the application of the mask. If a boolean is false,
           * the corresponding value in the matrix is set to 0.
           *
           * @param y the mask
           */
          void applyMask(const Ref<IMatrix<Boolean> >& y);

          /** Count the number of apparition of value in the row of the matrix
           *
           * @param row the row index
           * @param value the value to search for
           * @return
           */
          Integer countElementsOnRow(const Integer row, const Double value);

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
          Double maxElement(const Integer row);

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
          Double minElement(const Integer row);

          /** Check if the elements the matrix are in the range [minValue;maxValue]
           *
           * @param minValue the minimal value
           * @param maxValue the maximal value
           * @return true if all the elements the matrix are in the range [minValue;maxValue]
           */
          Boolean isValid(const Double & minValue, const Double & maxValue);

          /** Get the maximal element of the matrix
           *
           * @return the maximal element
           */
          Double maxElement();

          /** Get the minimal element of the matrix
           *
           * @return the minimal element
           */
          Double minElement();

          /** Multiply the elements of the first matrix by the elements of the second matrix
           *
           * @param y the second matrix
           */
          void mul(const Ref<IMatrix<Double> > & y);

          /** Multiply the elements of the row by y
           *
           * @param row the row index
           * @param y the value to multiply by
           */
          void mulRow(const Integer row, const Double y);

          /** Multiply the elements of the column by y
           *
           * @param col the column index
           * @param y the value to multiply by
           */
          void mulCol(const Integer col, const Double y);

          /** Multiply the elements of the matrix by a constant
           *
           * @param y the constant
           */
          void mul(const Double y);

          /** Transform a row of the matrix to make it stochastic
           *
           * @param row the row index
           * @return the sum of the elements of the row before the normalization
           */
          Double makeStochasticRow(const Integer row);

          /** Transform the matrix to make it stochastic
           * @return the minimal sum of the elements of the row before normalization
           */
          Double makeStochastic();

          /** Raise the elements of the matrix to the power y
           *
           * @param y the power
           */
          void pow(const Double y);

          /** Raise the elements of a row to the power y
           *
           * @param row the row index
           * @param y  the power
           */
          void powRow(const Integer row, const Double y);

          /** Compute the weighted sum m.data[row][j] += array.data[j] * weight
           *
           * @param row the row index
           * @param array the array
           * @param weight the weight
           */
          void addWeightedRow(const Integer row,
              const Ref<IArray<Double> > & array, const Double weight);

          /** Compute the inner product of two columns of the matrix
           *
           * @param coli the first column index
           * @param colj the second column index
           * @return the inner product
           */
          Double innerProductOfCols(const Integer coli, const Integer colj);

          /** Compute the inner product of two rows of the matrix
           *
           * @param rowi the first row index
           * @param rowj the second row index
           * @return the inner product
           */
          Double innerProductOfRows(const Integer rowi, const Integer rowj);

          /** Orthogonalize the matrix using the Gram-Schmidt method
           */
          void orthogonalize();

          /** Copy the content of column into a dynamic array
           *
           * @param col the column index
           * @param y the array
           */
          void getCol(const Integer col, const Ref<DynamicArrayOfDouble> & y);

          /** Copy the content of the row into a dynamic array
           *
           * @param row the row index
           * @param y the array
           */
          void getRow(const Integer row, const Ref<DynamicArrayOfDouble> & y);

          /** Compute the matrix product x*y
           *
           * @param x the first matrix
           * @param y the second matrix
           */
          void product(const Ref<IMatrix<Double> >& x, const Ref<
              IMatrix<Double> >& y);

          /** Raise the square matrix to the power 4<sup>powerLevel</sup>
           *
           * @param powerLevel the power level base
           */
          void fourthpowerSquareMatrix(int powerLevel);

      };
    }
  }
}

#endif
