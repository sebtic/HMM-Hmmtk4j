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

#ifndef HMMTK4J_IMatrixOfInteger_inlines_h
#define HMMTK4J_IMatrixOfInteger_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {

      HMMTK4J_INLINE void IMatrixOfInteger::getCol(const Integer col,
          const Ref<DynamicArrayOfInteger> & y)
      {
        HMMTK4J_CheckArgument(0 <= col && col < colCount, "Invalid col");
        y->resize(rowCount);
        for (int i = rowCount - 1; i >= 0; --i)
          y->data[i] = data[i][col];
      }

      HMMTK4J_INLINE void IMatrixOfInteger::getRow(const Integer row,
          const Ref<DynamicArrayOfInteger> & y)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        y->resize(colCount);
        for (int i = colCount - 1; i >= 0; --i)
          y->data[i] = data[row][i];
      }

      HMMTK4J_INLINE void IMatrixOfInteger::add(const Integer y)
      {
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            data[i][j] += y;
      }

      HMMTK4J_INLINE void IMatrixOfInteger::add(
          const Ref<IMatrix<Integer> > & y)
      {
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            data[i][j] += y->data[i][j];
      }

      HMMTK4J_INLINE void IMatrixOfInteger::sub(const Ref<IMatrix<Integer> >& y)
      {
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            data[i][j] -= y->data[i][j];
      }

      HMMTK4J_INLINE void IMatrixOfInteger::addToRow(const Integer row,
          const Integer y)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        for (Integer j = colCount - 1; j >= 0; --j)
          data[row][j] += y;
      }

      HMMTK4J_INLINE void IMatrixOfInteger::applyMask(const Ref<
          IMatrix<Boolean> >& y)
      {
        HMMTK4J_CheckArgument(rowCount == y->rowCount && colCount
            == y->colCount, "The matrices must be of same size");
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            if (!y->data[i][j])
              data[i][j] = 0.0;
      }

      HMMTK4J_INLINE Integer IMatrixOfInteger::countElementsOnRow(
          const Integer row, const Integer value)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        Integer c = 0;
        for (Integer i = colCount - 1; i >= 0; --i)
        {
          if (value == data[row][i])
            c++;
        }
        return c;
      }

      HMMTK4J_INLINE Integer IMatrixOfInteger::indexOfMaxElement(
          const Integer row)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        Integer index = -1;
        for (Integer i = colCount - 1; i >= 0; --i)
          if (index == -1 || data[row][index] < data[row][i])
            index = i;
        return index;
      }

      HMMTK4J_INLINE Integer IMatrixOfInteger::maxElement(const Integer row)
      {
        Integer index = indexOfMaxElement(row);
        HMMTK4J_CheckArgument(index != -1, "The matrix is empty");
        return data[row][index];
      }

      HMMTK4J_INLINE Integer IMatrixOfInteger::indexOfMinElement(
          const Integer row)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        Integer index = -1;
        for (Integer i = colCount - 1; i >= 0; --i)
          if (index == -1 || data[row][index] > data[row][i])
            index = i;
        return index;
      }

      HMMTK4J_INLINE Integer IMatrixOfInteger::minElement(const Integer row)
      {
        Integer index = indexOfMinElement(row);
        HMMTK4J_CheckArgument(index != -1, "The matrix is empty");
        return data[row][index];
      }

      HMMTK4J_INLINE Boolean IMatrixOfInteger::isValid(
          const Integer & minValue, const Integer & maxValue)
      {
        for (int i = rowCount - 1; i >= 0; --i)
          for (int j = colCount - 1; j >= 0; --j)
          {
            if ((data[i][j] < minValue) || (data[i][j] > maxValue))
            {
              std::cerr << "Erreur Matrix : " << data[i][j] << " not in "
                  << minValue << " " << maxValue << "\n";
              return false;
            }
          }
        return true;
      }

      HMMTK4J_INLINE Integer IMatrixOfInteger::maxElement()
      {
        HMMTK4J_CheckArgument(rowCount != 0 && colCount != 0,
            "The matrix is empty");
        Integer m = maxElement(0);
        for (Integer i = rowCount - 1; i > 0; --i)
          m = Math::max(m, maxElement(i));
        return m;
      }

      HMMTK4J_INLINE Integer IMatrixOfInteger::minElement()
      {
        HMMTK4J_CheckArgument(rowCount != 0 && colCount != 0,
            "The matrix is empty");
        Integer m = minElement(0);
        for (Integer i = rowCount - 1; i > 0; --i)
          m = Math::min(m, minElement(i));
        return m;
      }

    }
  }
}

#endif
