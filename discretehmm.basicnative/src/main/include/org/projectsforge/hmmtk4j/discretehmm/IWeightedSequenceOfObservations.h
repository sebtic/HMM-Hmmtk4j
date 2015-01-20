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

#ifndef HMMTK4J_DiscreteHMM_IWeightedSequenceOfObservations_h
#define HMMTK4J_DiscreteHMM_IWeightedSequenceOfObservations_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        /** A weighted sequence of discrete symbols. */
        class IWeightedSequenceOfObservations: public Referenced
        {
          public:
            Ref<ISequenceOfObservations> sequence;
            ReadOnly<Double>::TProperty weight; //< The weight of the sequence.
          protected:
            /** The constructor */
            IWeightedSequenceOfObservations();
          public:
            /** Copy a sequence */
            virtual void copy(const Ref<IWeightedSequenceOfObservations> & seq);
            /** Set the weight
             *
             * @param value the weight
             */
            virtual void setWeight(const Double value);
        };
      }
    }
  }
}

#endif

