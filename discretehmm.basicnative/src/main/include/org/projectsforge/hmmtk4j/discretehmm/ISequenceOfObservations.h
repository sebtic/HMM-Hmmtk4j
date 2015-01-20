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

#ifndef HMMTK4J_DiscreteHMM_ISequenceOfObservations_h
#define HMMTK4J_DiscreteHMM_ISequenceOfObservations_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        /** A sequence of discrete symbols. All symbols are numbered in range [O;maxDistinctValues[ */
        class ISequenceOfObservations: public Referenced
        {
          public:
            ReadOnly<Integer>::TProperty maxDistinctValues; //< The number of different symbols that can be managed.
            Ref<IArrayOfInteger> data;
          protected:
            /** The constructor */
            ISequenceOfObservations();
          public:
            /** Copy a sequence */
            virtual void copy(const Ref<ISequenceOfObservations> & seq);
            /** A setter to define the maximal value of the element of the sequence
             *
             * @param value the maximal value
             */
            virtual void setMaxDistinctValues(const Integer value);
        };
      }
    }
  }
}

#endif
