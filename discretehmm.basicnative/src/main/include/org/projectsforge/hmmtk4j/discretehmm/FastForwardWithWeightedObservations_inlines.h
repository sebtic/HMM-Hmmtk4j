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

#ifndef HMMTK4J_DiscreteHMM_FastForwardWithWeightedObservations_inlines_h
#define HMMTK4J_DiscreteHMM_FastForwardithWeightedObservations_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        HMMTK4J_INLINE Double fastForwardWithWeightedObservations(const Ref<
            IHMM> & hmm, const Ref<ArrayOfReference<IWeightedSequenceOfObservations> >& obss)
        {
          Integer nbobs = obss->size;
          Double sumOfWeights = 0;
          Double logProba = 0;
          for (Integer o = nbobs - 1; o >= 0; --o)
          {
            Double weight = obss->data[o]->weight;
            sumOfWeights += weight;
            Double proba = fastForward(hmm, obss->data[o]->sequence);
            if (Math::isLogNull(proba))
            {
              logProba = Math::LOG_NULL;
              return Math::LOG_NULL;
            }
            logProba += weight * proba;
          }
          return logProba / sumOfWeights;
        }
      }
    }
  }
}

#endif
