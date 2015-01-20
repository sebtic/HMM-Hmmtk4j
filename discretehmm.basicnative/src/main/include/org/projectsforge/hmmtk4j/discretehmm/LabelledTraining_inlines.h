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

#ifndef HMMTK4J_DiscreteHMM_LabelledTraining_inlines_h
#define HMMTK4J_DiscreteHMM_LabelledTraining_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        HMMTK4J_INLINE void labelledTraining(
            const Ref<ISequenceOfObservations> & observation,
            const Ref<ISequenceOfObservations> & stateSequence, const Double smoothing,
            const Ref<IHMM> & outputHMM)
        {
          Integer length = observation->data->size;

          HMMTK4J_ASSERT((stateSequence->maxDistinctValues
              == outputHMM->Pi->size));
          HMMTK4J_ASSERT((stateSequence->maxDistinctValues
              == outputHMM->A->rowCount) && (stateSequence->maxDistinctValues
              == outputHMM->A->colCount));
          HMMTK4J_ASSERT((stateSequence->maxDistinctValues
              == outputHMM->B->rowCount) && (observation->maxDistinctValues
              == outputHMM->B->colCount));

          IMatrixOfDouble::TBuffer Adata = outputHMM->A->data;
          IMatrixOfDouble::TBuffer Bdata = outputHMM->B->data;
          IArrayOfDouble::TBuffer Pidata = outputHMM->Pi->data;
          IArrayOfInteger::TBuffer observationdata = observation->data->data;
          IArrayOfInteger::TBuffer stateSequencedata =
              stateSequence->data->data;

          outputHMM->A->fill(smoothing);
          outputHMM->B->fill(smoothing);
          outputHMM->Pi->fill(smoothing);

          Pidata[stateSequencedata[0]] = 1;

          for (Integer t = length - 1; t >= 1; --t)
          {
            Adata[stateSequencedata[t - 1]][stateSequencedata[t]]++;
          }

          for (Integer t = length - 1; t >= 0; --t)
          {
            Bdata[stateSequencedata[t]][observationdata[t]]++;
          }

          outputHMM->A->makeStochastic();
          outputHMM->B->makeStochastic();
          outputHMM->Pi->makeStochastic();
        }
      }
    }
  }
}

#endif
