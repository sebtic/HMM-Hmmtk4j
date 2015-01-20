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

#ifndef HMMTK4J_Core_IMatrix_h
#define HMMTK4J_Core_IMatrix_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** A generic Matrix class */
      template<class TData>
      class IMatrix: public Referenced
      {
#ifdef HMMTK4J_DEBUG
          private:
          class MatrixOneRowDebugger
          {
            private:
            TData * data;
            Integer colCount;
            public:
            MatrixOneRowDebugger( TData * _data, Integer _colCount )
            {
              data = _data;
              colCount = _colCount;
            }
            TData & operator[]( Integer index )
            {
              HMMTK4J_CheckBounds( index, 0, colCount - 1 );
              HMMTK4J_ASSERT( data != NULL );
              return data[index];
            }
            const TData & operator[]( Integer index ) const
            {
              HMMTK4J_CheckBounds( index, 0, colCount - 1 );
              HMMTK4J_ASSERT( data != NULL );
              return data[index];
            }
            void operator=( const MatrixOneRowDebugger & source )
            {
              HMMTK4J_ASSERT( colCount == source.colCount );
              memCopy( source.data, data, colCount);
            }
          };

          class MatrixRowsDebugger
          {
            private:
            TData ** data;
            Integer rowCount;
            Integer colCount;
            public:
            MatrixRowsDebugger() : data(NULL), rowCount(0), colCount(0)
            {
              ;
            }
            void update( Integer _rowCount, Integer _colCount, TData ** _data )
            {
              data = _data;
              rowCount = _rowCount;
              colCount = _colCount;
            }
            MatrixOneRowDebugger operator[]( Integer index )
            {
              HMMTK4J_CheckBounds( index, 0, rowCount - 1 );
              return MatrixOneRowDebugger(data[index], colCount);
            }
            const MatrixOneRowDebugger operator[]( Integer index ) const
            {
              HMMTK4J_CheckBounds( index, 0, rowCount - 1 );
              return MatrixOneRowDebugger(data[index], colCount);
            }
            TData ** getDataPtr()
            {
              return data;
            }
          };
          public:
          typedef MatrixRowsDebugger TBuffer;
          MatrixRowsDebugger data;
          ReadOnly<Integer>::TProperty rowCount;
          ReadOnly<Integer>::TProperty colCount;
          public:
          IMatrix()
          {
            ReadOnly<Integer>::set(rowCount, 0);
            ReadOnly<Integer>::set(colCount, 0);
          }
          void copy( const Ref<IMatrix<TData> >& a )
          {
            HMMTK4J_ASSERT( a->rowCount == rowCount );
            HMMTK4J_ASSERT( a->colCount == colCount );
            for ( Integer i = 0; i < rowCount; ++i )
            data[i] = a->data[i];
          }
          void fill( const TData & value)
          {
            for( Integer i = rowCount - 1; i >= 0; --i )
            for( Integer j = colCount - 1; j >= 0; --j )
            data[i][j] = value;
          }
          /** Fill a row of the matrix with the given value
           *
           * @param m the matrix
           * @param row the row index
           * @param value the value to fil with
           */
          void fillRow(const Integer row, const TData & value)
          {
            for( Integer i = colCount - 1; i >= 0; --i )
            data[row][i] = value;
          }
          /** Define the content of a column from an array
           *
           * @param col the column index
           * @param y the array
           */
          void setCol(const Integer col, const Ref<IArray< TData > >& y)
          {
            HMMTK4J_CheckArgument( 0 <= col && col < colCount, "Invalid col" );
            HMMTK4J_CheckArgument( rowCount == y->size,
                "y does not have a valid size" );

            for( int i = rowCount - 1; i >= 0; --i )
            data[i][col] = y->data[i];
          }

          /** Define the content of a row from an array
           *
           * @param x the matrix
           * @param row the row index
           * @param y the array
           */
          void setRow(const Integer row, const Ref<IArray< TData > >& y)
          {
            HMMTK4J_CheckArgument( 0 <= row && row < rowCount, "Invalid row" );
            HMMTK4J_CheckArgument( colCount == y->size,
                "y does not have a valid size" );
            for( int i = colCount - 1; i >= 0; --i )
            data[row][i] = y->data[i];
          }

          /** Copy the content of column into an array
           *
           * @param col the column index
           * @param a the array
           */
          void getCol(const Integer col, const Ref<IArray<TData> >& a)
          {
            HMMTK4J_CheckArgument(rowCount == a->size,
                "a does not have a valid size");
            HMMTK4J_CheckArgument(0 <= col && col < colCount, "Invalid col");
            for (int i = rowCount - 1; i >= 0; --i)
            a->data[i] = data[i][col];
          }

          /** Copy the content of the row into an array
           *
           * @param row the row index
           * @param a the array
           */
          void getRow(const Integer row, const Ref<IArray<TData> >& a)
          {
            HMMTK4J_CheckArgument(colCount == a->size,
                "a does not have a valid size");
            HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
            for( int i = colCount - 1; i >= 0; --i )
            a->data[i] = data[row][i];
          }

          /** Exchange the content of tow columns
           *
           * @param x the matrix
           * @param coli the first column index
           * @param colj the second column index
           */
          void swapCol(const Integer coli, const Integer colj)
          {
            HMMTK4J_CheckArgument( 0 <= coli && coli < colCount, "Invalid coli" );
            HMMTK4J_CheckArgument( 0 <= colj && colj < colCount, "Invalid colj" );

            for( int i = rowCount - 1; i >= 0; --i )
            swap( data[i][coli], data[i][colj] );
          }

          /** Exchange the content of tow rows
           *
           * @param x the matrix
           * @param rowi the first row index
           * @param rowj the second row index
           */
          void swapRow(const Integer rowi, const Integer rowj)
          {
            HMMTK4J_CheckArgument( 0 <= rowi && rowi < rowCount, "Invalid rowi" );
            HMMTK4J_CheckArgument( 0 <= rowj && rowj < rowCount, "Invalid rowj" );
            for( int i = colCount - 1; i >= 0; --i )
            swap( data[rowi][i], data[rowj][i] );
          }
          protected:
          void update( Integer _rowCount, Integer _colCount, TData ** _data )
          {
            data.update(_rowCount,_colCount,_data);
            ReadOnly<Integer>::set(rowCount, _rowCount);
            ReadOnly<Integer>::set(colCount, _colCount);
          }
          TData ** getDataPtr()
          {
            return data.getDataPtr();
          }
#else
        public:
          typedef TData ** TBuffer;
          TData ** data; //< the data
          Integer rowCount; //< the row count
          Integer colCount; //< the column count
        public:
          /** The constructor */
          IMatrix() :
            data(NULL), rowCount(0), colCount(0)
          {
            ;
          }
          void copy(const Ref<IMatrix<TData> >& a)
          {
            HMMTK4J_ASSERT(a->rowCount == rowCount);
            HMMTK4J_ASSERT(a->colCount == colCount);
            for (Integer i = 0; i < rowCount; ++i)
              memCopy(a->data[i], data[i], colCount);
          }
          void fill(const TData & value)
          {
            for (Integer i = rowCount - 1; i >= 0; --i)
              for (Integer j = colCount - 1; j >= 0; --j)
                data[i][j] = value;
          }
          /** Fill a row of the matrix with the given value
           *
           * @param row the row index
           * @param value the value to fill with
           */
          void fillRow(const Integer row, const TData & value)
          {
            for (Integer i = colCount - 1; i >= 0; --i)
              data[row][i] = value;
          }
          /** Define the content of a column from an array
           *
           * @param col the column index
           * @param a the array
           */
          void setCol(const Integer col, const Ref<IArray<TData> >& a)
          {
            HMMTK4J_CheckArgument(0 <= col && col < colCount, "Invalid col");
            HMMTK4J_CheckArgument(rowCount == a->size,
                "a does not have a valid size");

            for (int i = rowCount - 1; i >= 0; --i)
              data[i][col] = a->data[i];
          }

          /** Define the content of a row from an array
           *
           * @param row the row index
           * @param a the array
           */
          void setRow(const Integer row, const Ref<IArray<TData> > & a)
          {
            HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
            HMMTK4J_CheckArgument(colCount == a->size,
                "a does not have a valid size");

            memCopy(a->data, data[row], colCount);
            /*        for( int i = colCount - 1; i >= 0; --i )
             data[row][i] = a->data[i];*/
          }

          /** Copy the content of column into an array
           *
           * @param col the column index
           * @param a the array
           */
          void getCol(const Integer col, const Ref<IArray<TData> >& a)
          {
            HMMTK4J_CheckArgument(rowCount == a->size,
                "a does not have a valid size");
            HMMTK4J_CheckArgument(0 <= col && col < colCount, "Invalid col");
            for (int i = rowCount - 1; i >= 0; --i)
              a->data[i] = data[i][col];
          }

          /** Copy the content of the row into an array
           *
           * @param row the row index
           * @param a the array
           */
          void getRow(const Integer row, const Ref<IArray<TData> >& a)
          {
            HMMTK4J_CheckArgument(colCount == a->size,
                "a does not have a valid size");
            HMMTK4J_CheckArgument(0 <= row && row < rowCount, "Invalid row");
            memCopy(data[row], a->data, colCount);
            /*        for( int i = colCount - 1; i >= 0; --i )
             a->data[i] = data[row][i];*/
          }

          /** Exchange the content of tow columns
           *
           * @param coli the first column index
           * @param colj the second column index
           */
          void swapCol(const Integer coli, const Integer colj)
          {
            HMMTK4J_CheckArgument(0 <= coli && coli < colCount, "Invalid coli");
            HMMTK4J_CheckArgument(0 <= colj && colj < colCount, "Invalid colj");

            for (int i = rowCount - 1; i >= 0; --i)
              swap(data[i][coli], data[i][colj]);
          }

          /** Exchange the content of tow rows
           *
           * @param rowi the first row index
           * @param rowj the second row index
           */
          void swapRow(const Integer rowi, const Integer rowj)
          {
            HMMTK4J_CheckArgument(0 <= rowi && rowi < rowCount, "Invalid rowi");
            HMMTK4J_CheckArgument(0 <= rowj && rowj < rowCount, "Invalid rowj");
            for (int i = colCount - 1; i >= 0; --i)
              swap(data[rowi][i], data[rowj][i]);
          }
        protected:
          void update(Integer _rowCount, Integer _colCount, TData ** _data)
          {
            rowCount = _rowCount;
            colCount = _colCount;
            data = _data;
          }
          TData ** getDataPtr()
          {
            return data;
          }
#endif
      };
    }
  }
}

#endif
