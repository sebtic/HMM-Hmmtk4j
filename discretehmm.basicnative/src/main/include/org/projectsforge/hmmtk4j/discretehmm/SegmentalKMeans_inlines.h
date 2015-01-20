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

#ifndef HMMTK4J_DiscreteHMM_SegmentalKMeans_inlines_h
#define HMMTK4J_DiscreteHMM_SegmentalKMeans_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        HMMTK4J_INLINE Double segmentalKMeans(const Ref<IHMM> & inputHMM,
            const Ref<ISequenceOfObservations> & observation, const Integer nbMaxIteration,
            const Ref<IHMM> & outputHMM)
        {
          DynamicSequenceOfObservations * dynamic_stateSequence = new DynamicSequenceOfObservations();
          dynamic_stateSequence->resize(observation->data->size);
          dynamic_stateSequence->setMaxDistinctValues(inputHMM->A->rowCount);
          Ref<ISequenceOfObservations> stateSequence = dynamic_stateSequence;

          Double logProba = Math::LOG_NULL;
          outputHMM->copy(inputHMM);

          logProba = viterbi(observation, outputHMM, stateSequence);

          for (Integer iter = nbMaxIteration - 1; iter >= 0; --iter)
          {
            Double oldLogProba = logProba;
            labelledTraining(observation, stateSequence, 0.0, outputHMM);
            logProba = viterbi(observation, outputHMM, stateSequence);
            if (oldLogProba >= logProba)
              break;
          }
          return logProba;
        }
      }
    }
  }
}

#endif
