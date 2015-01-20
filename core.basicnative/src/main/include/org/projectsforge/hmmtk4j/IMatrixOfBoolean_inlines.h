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

#ifndef HMMTK4J_IMatrixOfBoolean_inlines_h
#define HMMTK4J_IMatrixOfBoolean_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {

      HMMTK4J_INLINE void IMatrixOfBoolean::getCol(const Integer col,
          const Ref<DynamicArrayOfBoolean>& y)
      {
        HMMTK4J_CheckArgument(0 <= col && col < colCount, "Invalid col");
        y->resize(rowCount);
        for (int i = rowCount - 1; i >= 0; --i)
          y->data[i] = data[i][col];
      }

      HMMTK4J_INLINE void IMatrixOfBoolean::getRow(const Integer row,
          const Ref<DynamicArrayOfBoolean> & y)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        y->resize(colCount);
        for (int i = colCount - 1; i >= 0; --i)
          y->data[i] = data[row][i];
      }

      HMMTK4J_INLINE Boolean IMatrixOfBoolean::isValidMask()
      {
        for (Integer i = rowCount - 1; i >= 0; --i)
        {
          Integer sum = 0;
          for (Integer j = colCount - 1; j >= 0; --j)
            if (!data[i][j])
              sum++;
          if (sum == colCount)
            return false;
        }
        return true;
      }

      HMMTK4J_INLINE Integer IMatrixOfBoolean::countElementsOnRow(
          const Integer row, const Boolean value)
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
    }
  }
}

#endif
