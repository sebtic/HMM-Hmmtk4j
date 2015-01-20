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

#ifndef HMMTK4J_Core_Memory_h
#define HMMTK4J_Core_Memory_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** A generic memCopy method allowing overlapping
       *
       * @param source a pointer to source data
       * @param dest a pointer to destination data
       * @param count the number of data to copy
       */
      template<class TData> inline void memCopy(const TData * source,
          TData * dest, const Integer count)
      {
        if (dest < source)
          for (Integer i = 0; i < count; ++i)
            dest[i] = source[i];
        else
          for (Integer i = count - 1; i >= 0; --i)
            dest[i] = source[i];
      }

      /** A generic buffer reallocation method
       *
       * @param origin a pointer to the data
       * @param oldSize the size of the old memory area
       * @param newSize the size of the new memory area
       * @param preserveContent a flag indicating if the content must be preserved (true)
       * @return
       */
      template<class TData> inline TData * reallocMemory(const TData * origin,
          const Integer oldSize, const Integer newSize,
          const Boolean preserveContent)
      {
        TData * nouv;
        if (newSize > 0)
        {
          nouv = new TData[newSize];

          if (nouv == NULL)
          {
            MemoryException e("Error resizing array");
            HMMTK4J_RaiseException(e);
          }

          if (preserveContent)
          {
            Integer commun = (oldSize < newSize) ? oldSize : newSize;
            memCopy<TData> (origin, nouv, commun);
          }
        }
        else
          nouv = NULL;

        if (origin != NULL)
          delete[] origin;
        return nouv;
      }

      /** Fast versions of reallocMemory and memCopy for types that do not require object oriented programming consistency
       * @param Type the data type of the managed data
       */
#define HMMTK4J_FASTBASICARRAY(Type) \
    template <> \
      inline Type * reallocMemory<Type>( const Type * origin, \
                                         const Integer, \
                                         const Integer newSize, \
                                         const Boolean ) \
      { \
        Type * newp; \
        if (newSize == 0) \
        { \
          if (origin != NULL) \
            free( (Type*) origin ); \
          newp = NULL; \
        } \
        else \
        { \
          newp = (Type*) realloc( (Type*) origin, newSize*sizeof(Type) ); \
          \
          if (newp == NULL) \
          { \
           MemoryException e ("Error resizing array"); \
           HMMTK4J_RaiseException(e); \
          } \
        } \
        return newp; \
      } \
    template <> \
     inline void memCopy<Type>( const Type * source, Type * dest, const Integer count ) \
     { \
      memmove( dest, source, count*sizeof(Type)); \
     }

      /** Enable fast memory management for Integer */
      HMMTK4J_FASTBASICARRAY(Integer)

      /** Enable fast memory management for Long */
      HMMTK4J_FASTBASICARRAY(Long)

      /** Enable fast memory management for Double */
      HMMTK4J_FASTBASICARRAY(Double)

      /** Enable fast memory management for Boolean */
      HMMTK4J_FASTBASICARRAY(Boolean)

      /** A template to swap the content of two variables
       * @param x the first variable
       * @param y the second variable
       */
      template<class TData> void swap(TData & x, TData & y)
      {
        TData tmp = x;
        x = y;
        y = tmp;
      }

    }
  }
}

#endif
