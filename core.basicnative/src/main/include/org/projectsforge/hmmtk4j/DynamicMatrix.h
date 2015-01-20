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

#ifndef HMMTK4J_Core_DynamicMatrix_h
#define HMMTK4J_Core_DynamicMatrix_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** A dynamic matrix wrapper
       * @warning For efficiency, the content of the matrix is not preserved between resize
       */
      template<class TParentInterface, class TData>
      class DynamicMatrix: public TParentInterface
      {
        public:
          /** The default constructor */
          DynamicMatrix()
          {
            this->update(0, 0, (TData**) NULL);
          }
          /** The destructor */
          ~DynamicMatrix()
          {
            clear();
          }
          /** Empty the matrix and free memory */
          void clear()
          {
            resize(0, 0);
          }
          /** Resize the matrix */
          void resize(Integer _rowCount, Integer _colCount)
          {
            TData ** tmpdata = this->getDataPtr();
            if (this->rowCount < _rowCount)
            {
              tmpdata = reallocMemory(tmpdata, this->rowCount, _rowCount, true);
              if (this->colCount != _colCount)
                for (Integer i = 0; i < this->rowCount; ++i)
                  tmpdata[i] = reallocMemory(tmpdata[i], this->colCount,
                      _colCount, true);
              for (Integer i = this->rowCount; i < _rowCount; ++i)
                tmpdata[i] = reallocMemory((TData*) NULL, 0, _colCount, false);
            }
            else
            { // rowCount > _rowCount
              for (Integer i = _rowCount; i < this->rowCount; ++i)
                tmpdata[i]
                    = reallocMemory(tmpdata[i], this->colCount, 0, false);
              tmpdata = reallocMemory(tmpdata, this->rowCount, _rowCount, true);
              if (this->colCount != _colCount)
                for (Integer i = 0; i < _rowCount; ++i)
                  tmpdata[i] = reallocMemory(tmpdata[i], this->colCount,
                      _colCount, true);
            }
            this->update(_rowCount, _colCount, tmpdata);
          }
          void copy(const Ref<IMatrix<TData> >& _matrix)
          {
            resize(_matrix->rowCount, _matrix->colCount);
            TParentInterface::copy(_matrix);
          }
          DynamicMatrix<TParentInterface, TData> & operator=(const IMatrix<
              TData> & m)
          {
            copy(m);
            return *this;
          }
      };

      typedef DynamicMatrix<IMatrixOfInteger, Integer> DynamicMatrixOfInteger;
      typedef DynamicMatrix<IMatrixOfBoolean, Boolean> DynamicMatrixOfBoolean;

      class DynamicMatrixOfDouble: public DynamicMatrix<IMatrixOfDouble, Double>
      {
        public:
          /** Compute the matrix product x*y
           *
           * @param x the first matrix
           * @param y the second matrix
           */
          void product(const Ref<IMatrix<Double> >& x,
              const Ref<IMatrix<Double> >& y)
          {
            resize(x->rowCount, y->colCount);
            IMatrixOfDouble::product(x,y);
          }
      };
    }
  }
}

#endif
