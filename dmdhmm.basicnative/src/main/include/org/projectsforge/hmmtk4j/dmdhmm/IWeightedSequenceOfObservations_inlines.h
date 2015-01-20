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

#ifndef HMMTK4J_DMDHMM_IWeightedSequenceOfObservations_inlines_h
#define HMMTK4J_DMDHMM_IWeightedSequenceOfObservations_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {
        HMMTK4J_INLINE IWeightedSequenceOfObservations::IWeightedSequenceOfObservations()
        {
          sequence = NULL;
          ReadOnly<Double>::set(weight, 1.0);
        }
        HMMTK4J_INLINE void IWeightedSequenceOfObservations::copy(const Ref<
            IWeightedSequenceOfObservations> & seq)
        {
          sequence->copy(seq->sequence);
          setWeight(seq->weight);
        }

        HMMTK4J_INLINE void IWeightedSequenceOfObservations::setWeight(
            const Double value)
        {
          ReadOnly<Double>::set(weight, value);
        }
      }
    }
  }
}

#endif
