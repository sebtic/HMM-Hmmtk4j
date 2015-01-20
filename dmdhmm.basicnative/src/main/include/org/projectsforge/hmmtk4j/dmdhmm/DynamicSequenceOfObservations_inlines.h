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

#ifndef HMMTK4J_DMDHMM_DynamicSequenceOfObservations_inlines_h
#define HMMTK4J_DMDHMM_DynamicSequenceOfObservations_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {
        HMMTK4J_INLINE DynamicSequenceOfObservations::DynamicSequenceOfObservations()
        {
          dynamic_data = new ArrayOfReference<DynamicArrayOfInteger> ();
          data = new ArrayOfReference<IArrayOfInteger> ();
          dynamic_maxDistinctValues = new DynamicArrayOfInteger();
          maxDistinctValues = dynamic_maxDistinctValues.getPtr();
        }

        HMMTK4J_INLINE void DynamicSequenceOfObservations::resize(
            Integer componentSize, Integer componentLength)
        {
          int oldComponentSize = dynamic_data->size;
          dynamic_data->resize(componentSize);
          data->resize(componentSize);
          for (int index = oldComponentSize; index < componentSize; ++index)
          {
            dynamic_data->data[index] = new DynamicArrayOfInteger();
            data->data[index] = dynamic_data->data[index].getPtr();
          }
          for (int index = 0; index < componentSize; ++index)
            dynamic_data->data[index]->resize(componentLength);
          dynamic_maxDistinctValues->resize(componentSize);
        }

        HMMTK4J_INLINE void DynamicSequenceOfObservations::copy(const Ref<
            ISequenceOfObservations> & seq)
        {
          this->resize(seq->data->size,
              (seq->data->size > 0) ? seq->data->data[0]->size : 0);
          ISequenceOfObservations::copy(seq);
        }
      }
    }
  }
}

#endif
