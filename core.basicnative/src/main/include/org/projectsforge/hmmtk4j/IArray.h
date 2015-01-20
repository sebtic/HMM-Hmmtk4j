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

#ifndef HMMTK4J_Core_IArray_h
#define HMMTK4J_Core_IArray_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** A fast generic array class allowing compiler to do optimization of the code using it in release mode */
      template<class TData> class IArray: public Referenced
      {
#ifdef HMMTK4J_DEBUG
          private:
          /** @internal An internal class to easy the debugging of arrays while without reducing efficiency in the release mode. */
          class ArrayDebugger
          {
            private:
            TData * buffer;
            Integer size;
            public:
            ArrayDebugger() : buffer(NULL), size(0)
            {
              ;
            }
            void update( Integer _size, TData * _buffer )
            {
              buffer = _buffer;
              size = _size;
            }
            TData & operator[]( Integer index )
            {
              HMMTK4J_CheckBounds(index, 0, size - 1);
              HMMTK4J_ASSERT( buffer != NULL );
              return buffer[index];
            }
            const TData & operator[]( Integer index ) const
            {
              HMMTK4J_CheckBounds(index, 0, size - 1);
              HMMTK4J_ASSERT( buffer != NULL );
              return buffer[index];
            }
            void copy( const ArrayDebugger & ad )
            {
              HMMTK4J_ASSERT_MSG( size == ad.size, "The two arrays must have the same number of element" );
              memCopy( ad.buffer, buffer, size);
            }
            TData * getDataPtr()
            {
              return buffer;
            }
          };
          public:
          typedef ArrayDebugger TBuffer;
          /** The buffer containing data */
          ArrayDebugger data;
          /** The number of element stored in the array */
          ReadOnly<Integer>::TProperty size;
          protected:
          /** The default constructor */
          IArray()
          {
            ReadOnly<Integer>::set(size, 0);
          }
          public:
          /** The copy method to copy element of the array
           * @warning The two array must have the same number of element */
          void copy( const Ref<IArray<TData> >& a )
          {
            data.copy(a->data);
            ReadOnly<Integer>::set(size, a->size);
          }
          /** Fill the array with elements that are equal to value
           *
           * @param value the filling value
           */
          void fill(const TData & value)
          {
            for( Integer i = size - 1; i >= 0; --i )
            data[i] = value;
          }
          protected:
          /** @internal The update method used to specify the buffer of data and the number of element */
          void update( Integer _size, TData * _buffer )
          {
            data.update(_size,_buffer);
            ReadOnly<Integer>::set(size, _size);
          }
          TData * getDataPtr()
          {
            return data.getDataPtr();
          }
#else
        public:
          typedef TData * TBuffer;
          /** The buffer containing data */
          TData * data;
          /** The number of element stored in the array */
          Integer size;
        protected:
          /** The default constructor */
          IArray() :
            data(NULL), size(0)
          {
            ;
          }
        public:
          /** The copy method to copy element of the array
           * @warning The two array must have the same number of element */
          void copy(const Ref<IArray<TData> > & a)
          {
            HMMTK4J_ASSERT_MSG(a->size == size,
                "The two arrays must have the same number of element");
            memCopy(a->data, data, size);
          }
          /** Fill the array with elements that are equal to value
           *
           * @param value the filling value
           */
          void fill(const TData & value)
          {
            for (Integer i = size - 1; i >= 0; --i)
              data[i] = value;
          }
        protected:
          /** @internal The update method used to specify the buffer of data and the number of element */
          void update(Integer _size, TData * _buffer)
          {
            size = _size;
            data = _buffer;
          }
          TData * getDataPtr()
          {
            return data;
          }
#endif
      };
    }
  }
}

#endif
