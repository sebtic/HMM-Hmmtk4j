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

#ifndef HMMTK4J_IMatrixOfDouble_inlines_h
#define HMMTK4J_IMatrixOfDouble_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {

      HMMTK4J_INLINE void IMatrixOfDouble::getCol(const Integer col, const Ref<
          DynamicArrayOfDouble> & y)
      {
        HMMTK4J_CheckArgument(0 <= col && col < colCount, "Invalid col");
        y->resize(rowCount);
        for (int i = rowCount - 1; i >= 0; --i)
          y->data[i] = data[i][col];
      }

      HMMTK4J_INLINE void IMatrixOfDouble::getRow(const Integer row, const Ref<
          DynamicArrayOfDouble> & y)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        y->resize(colCount);
        for (int i = colCount - 1; i >= 0; --i)
          y->data[i] = data[row][i];
      }

      HMMTK4J_INLINE void IMatrixOfDouble::add(const Double y)
      {
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            data[i][j] += y;
      }

      HMMTK4J_INLINE void IMatrixOfDouble::add(const Ref<IMatrix<Double> >& y)
      {
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            data[i][j] += y->data[i][j];
      }

      HMMTK4J_INLINE void IMatrixOfDouble::sub(const Ref<IMatrix<Double> >& y)
      {
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            data[i][j] -= y->data[i][j];
      }

      HMMTK4J_INLINE void IMatrixOfDouble::addToRow(const Integer row,
          const Double y)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        for (Integer j = colCount - 1; j >= 0; --j)
          data[row][j] += y;
      }

      HMMTK4J_INLINE Integer IMatrixOfDouble::indexOfMaxElement(
          const Integer row)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        Integer index = -1;
        for (Integer i = colCount - 1; i >= 0; --i)
          if (index == -1 || data[row][index] < data[row][i])
            index = i;
        return index;
      }

      HMMTK4J_INLINE Double IMatrixOfDouble::maxElement(const Integer row)
      {
        Integer index = indexOfMaxElement(row);
        HMMTK4J_CheckArgument(index != -1, "The matrix is empty");
        return data[row][index];
      }

      HMMTK4J_INLINE Integer IMatrixOfDouble::indexOfMinElement(
          const Integer row)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        Integer index = -1;
        for (Integer i = colCount - 1; i >= 0; --i)
          if (index == -1 || data[row][index] > data[row][i])
            index = i;
        return index;
      }

      HMMTK4J_INLINE Double IMatrixOfDouble::minElement(const Integer row)
      {
        Integer index = indexOfMinElement(row);
        HMMTK4J_CheckArgument(index != -1, "The matrix is empty");
        return data[row][index];
      }

      HMMTK4J_INLINE Boolean IMatrixOfDouble::isValid(const Double & minValue,
          const Double & maxValue)
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

      HMMTK4J_INLINE Double IMatrixOfDouble::maxElement()
      {
        HMMTK4J_CheckArgument(rowCount != 0 && colCount != 0,
            "The matrix is empty");
        Double m = maxElement(0);
        for (Integer i = rowCount - 1; i > 0; --i)
          m = Math::max(m, maxElement(i));
        return m;
      }

      HMMTK4J_INLINE Double IMatrixOfDouble::minElement()
      {
        HMMTK4J_CheckArgument(rowCount != 0 && colCount != 0,
            "The matrix is empty");
        Double m = minElement(0);
        for (Integer i = rowCount - 1; i > 0; --i)
          m = Math::min(m, minElement(i));
        return m;
      }

      HMMTK4J_INLINE void IMatrixOfDouble::applyMask(
          const Ref<IMatrix<Boolean> >& y)
      {
        HMMTK4J_CheckArgument(rowCount == y->rowCount && colCount
            == y->colCount, "The matrices must be of same size");
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            if (!y->data[i][j])
              data[i][j] = 0.0;
      }

      HMMTK4J_INLINE Integer IMatrixOfDouble::countElementsOnRow(
          const Integer row, const Double value)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        Integer c = 0;
        for (Integer i = colCount - 1; i >= 0; --i)
        {
          if (Math::isNull(value - data[row][i]))
            c++;
        }
        return c;
      }

      HMMTK4J_INLINE void IMatrixOfDouble::mul(const Ref<IMatrix<Double> >& y)
      {
        HMMTK4J_CheckArgument(rowCount == y->rowCount && colCount
            == y->colCount, "The matrices must be of same size");
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            data[i][j] *= y->data[i][j];
      }

      HMMTK4J_INLINE void IMatrixOfDouble::mulRow(const Integer row,
          const Double y)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        for (Integer i = colCount - 1; i >= 0; --i)
          data[row][i] *= y;
      }

      HMMTK4J_INLINE void IMatrixOfDouble::mulCol(const Integer col,
          const Double y)
      {
        HMMTK4J_CheckArgument(0 <= col && col < colCount, "Invalid col");
        for (Integer i = rowCount - 1; i >= 0; --i)
          data[i][col] *= y;
      }

      HMMTK4J_INLINE void IMatrixOfDouble::mul(const Double y)
      {
        for (Integer i = rowCount - 1; i >= 0; --i)
          for (Integer j = colCount - 1; j >= 0; --j)
            data[i][j] *= y;
      }

      HMMTK4J_INLINE Double IMatrixOfDouble::makeStochasticRow(
          const Integer row)
      {
        Double sum = 0;
        for (Integer i = colCount - 1; i >= 0; --i)
          sum += data[row][i];
        if (sum > 0)
        {
          Double inv = 1.0 / sum;
          for (int i = colCount - 1; i >= 0; --i)
            data[row][i] *= inv;
        }
        return sum;
      }

      HMMTK4J_INLINE Double IMatrixOfDouble::makeStochastic()
      {
        Double min = DBL_MAX;
        for (Integer i = rowCount - 1; i >= 0; --i)
          min = Math::min(min, makeStochasticRow(i));
        return min;
      }

      HMMTK4J_INLINE void IMatrixOfDouble::pow(const Double y)
      {
        if (Math::isNull(y))
          fill(1.);
        else
        {
          for (Integer i = rowCount - 1; i >= 0; --i)
            for (Integer j = colCount - 1; j >= 0; --j)
              data[i][j] = Math::pow(data[i][j], y);
        }
      }

      HMMTK4J_INLINE void IMatrixOfDouble::powRow(const Integer row,
          const Double y)
      {
        HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
        if (Math::isNull(y))
          fillRow(row, 1.);
        else
        {
          for (Integer i = colCount - 1; i >= 0; --i)
            data[row][i] = Math::pow(data[row][i], y);
        }
      }

      HMMTK4J_INLINE void IMatrixOfDouble::addWeightedRow(const Integer row,
          const Ref<IArray<Double> >& array, const Double weight)
      {
        HMMTK4J_ASSERT(colCount == array->size);
        for (Integer i = colCount - 1; i >= 0; --i)
          data[row][i] += weight * array->data[i];
      }

      HMMTK4J_INLINE Double IMatrixOfDouble::innerProductOfCols(
          const Integer coli, const Integer colj)
      {
        Double res = 0;
        for (Integer k = rowCount - 1; k >= 0; --k)
          res += data[k][coli] * data[k][colj];
        return res;
      }

      HMMTK4J_INLINE Double IMatrixOfDouble::innerProductOfRows(
          const Integer rowi, const Integer rowj)
      {
        Double res = 0;
        for (Integer k = colCount - 1; k >= 0; --k)
          res += data[rowi][k] * data[rowj][k];
        return res;
      }

      HMMTK4J_INLINE void IMatrixOfDouble::orthogonalize()
      {
        // orthogonalization using the Gram-Schmidt method
        if (rowCount == 0 || colCount == 0)
          return;

        Double n;

        // for each column
        for (Integer i = 0; i < colCount; ++i)
        {
          // normalize the column
          n = Math::sqrt(innerProductOfCols(i, i));
          mulCol(i, 1 / n);

          // remove the component from remaining column
          for (Integer j = i + 1; j < colCount; ++j)
          {
            n = innerProductOfCols(i, j);
            for (Integer k = rowCount - 1; k >= 0; --k)
              data[k][j] -= n * data[k][i];
          }
        }
        // normalize the last column
        n = Math::sqrt(innerProductOfCols(colCount - 1, colCount - 1));
        mulCol(colCount - 1, 1 / n);
      }

      HMMTK4J_INLINE void IMatrixOfDouble::product(
          const Ref<IMatrix<Double> >& x, const Ref<IMatrix<Double> >& y)
      {
        HMMTK4J_CheckArgument(rowCount == x->rowCount,
            "Invalid size of the resulting matrix");
        HMMTK4J_CheckArgument(colCount == y->colCount,
            "Invalid size of the resulting matrix");
        HMMTK4J_CheckArgument(x->colCount == y->rowCount,
            "Invalid matrix sizes for a product");

        for (Integer i = 0; i < rowCount; ++i)
          for (Integer j = 0; j < colCount; ++j)
          {
            Double sum = 0;
            for (Integer k = 0; k < x->colCount; ++k)
              sum += x->data[i][k] * y->data[k][j];
            data[i][j] = sum;
          }
      }

      HMMTK4J_INLINE void IMatrixOfDouble::fourthpowerSquareMatrix(
          int powerLevel)
      {
        HMMTK4J_CheckArgument(powerLevel >= 0,
            "powerLevel must be positive or null");
        HMMTK4J_CheckArgument(rowCount == colCount,
            "The matrix must be a squared matrix");
        Ref<DynamicMatrixOfDouble> temp = new DynamicMatrixOfDouble();
        temp->resize(rowCount, rowCount);
        for (Integer i = 0; i < rowCount; ++i)
          for (Integer j = 0; j < colCount; ++j)
            data[i][j] = (i == j) ? 1 : 0;

        DynamicMatrixOfDouble * tempPtr = temp.getPtr();
        for (int count = powerLevel - 1; count >= 0; --count)
        {
          tempPtr->product(this, this);
          this->product(tempPtr, tempPtr);
        }
      }

    }
  }
}
#endif
