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

#ifndef HMMTK4J_Core_DynamicArray_h
#define HMMTK4J_Core_DynamicArray_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** A dynamic array wrapper */
      template<class TParentInterface, class TData>
      class DynamicArray: public TParentInterface
      {
        private:
          Integer reserved;
        public:
          /** The default constructor creating an empty dynamic array */
          DynamicArray() :
            reserved(0)
          {
            this->update(0, (TData*) NULL);
          }
          /** The destructor */
          ~DynamicArray()
          {
            clear();
          }
          /** Copy the content of an array. The size of the two arrays can be different */
          void copy(const Ref<IArray<TData> >& _array)
          {
            resize(_array->size);
            TParentInterface::copy(_array);
          }
          DynamicArray<TParentInterface, TData> & operator=(const Ref<IArray<
              TData> > & array)
          {
            copy(array);
            return *this;
          }
          /** Resize an array in order that the array has newSize elements. The content of the remaining element are preserved
           *
           * @param newSize the requested new size of the array
           * @param preserveContent a flag to true to indicate that the array content must be preserved
           * @param reduceMemory a flag to true to indicate that the reserved memory must be shrink if possible
           */
          void resize(const Integer newSize, const Boolean preserveContent =
              true, const Boolean reduceMemory = false)
          {
            HMMTK4J_EnsureNonNegative(newSize);
            reserve(newSize, preserveContent, reduceMemory);
            this->update(newSize, this->getDataPtr());
          }
          /** Modify the array such that at least newSize elements can be stored in the array without resizing te memory associeted to the array
           *
           * @param newSize the requested new size of the array
           * @param preserveContent a flag to true to indicate that the array content must be preserved
           * @param reduceMemory a flag to true to indicate that the reserved memory must be shrink if possible
           */
          void reserve(const Integer newSize, const Boolean preserveContent =
              true, const Boolean reduceMemory = false)
          {
            TData * buffer = this->getDataPtr();
            Integer theSize = this->size;
            HMMTK4J_EnsureNonNegative(newSize);

            if (newSize == theSize)
              return;

            if ((newSize > reserved) || ((newSize < reserved) && reduceMemory))
            {
              buffer = reallocMemory(buffer, theSize, newSize, preserveContent);
              reserved = newSize;
              if (theSize > newSize)
                theSize = newSize;
            }
            this->update(theSize, buffer);
          }
          /** Add an element in the first position
           *
           * @param value the value
           */
          void pushFront(const TData & value)
          {
            insert(0, value);
          }
          /** Add an element to the end of the array
           *
           * @param value the value
           */
          void pushBack(const TData & value)
          {
            if (this->size == reserved)
              reserve(reserved + 16, true);
            this->update(this->size + 1, this->getDataPtr());
            this->data[this->size - 1] = value;
          }
          /** Remove an element from the array
           *
           * @param index the index of the element
           */
          void erase(const Integer index)
          {
            HMMTK4J_CheckBounds(index, 0, this->size - 1);
            TData * buffer = this->getDataPtr();
            memCopy(buffer + index + 1, buffer + index, this->size - index - 1);
            resize(this->size - 1, true);
          }
          /** Insert an element in the array
           *
           * @param index the index of the element
           * @param value the value of the element
           */
          void insert(const Integer index, const TData & value)
          {
            HMMTK4J_CheckBounds(index, 0, this->size);
            if (this->size + 1 > reserved)
              reserve(reserved + 16, true);
            TData * buffer = this->getDataPtr();
            memCopy(buffer + index, buffer + index + 1, this->size - index);
            this->update(this->size + 1, buffer);
            buffer[index] = value;
          }
          /** Empty the array and reduce the memory used by the array to 0 */
          void clear()
          {
            reserve(0, false, true);
          }
          /** Insert an element in the array
           *
           * @param index the insert position
           * @param value the array of elements
           */
          void insert(const Integer index, const Ref<IArray<TData> >& value)
          {
            HMMTK4J_CheckBounds(index, 0, this->size);
            if (this->size + value->size > reserved)
              reserve(this->size + value->size);
            TData * buffer = this->getDataPtr();
            memCopy(buffer + index, buffer + index + value->size, this->size
                - index);
            for (Integer i = value->size - 1; i >= 0; --i)
              buffer[index + i] = value->data[i];
            this->update(this->size + value->size, buffer);
          }
          /** Add an element in the first position
           *
           * @param value the array of elements
           */
          void pushFront(const Ref<IArray<TData> >& value)
          {
            insert(0, value);
          }
          /** Add an element to the end of the array
           *
           * @param value the array of elements
           */
          void pushBack(const Ref<IArray<TData> >& value)
          {
            insert(this->size, value);
          }
      };

      typedef DynamicArray<IArrayOfInteger, Integer> DynamicArrayOfInteger;
      typedef DynamicArray<IArrayOfDouble, Double> DynamicArrayOfDouble;
      typedef DynamicArray<IArrayOfBoolean, Boolean> DynamicArrayOfBoolean;
    }
  }
}

#endif
