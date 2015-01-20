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

#ifndef HMMTK4J_DMDHMM_LabelledTraining_inlines_h
#define HMMTK4J_DMDHMM_LabelledTraining_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {
        HMMTK4J_INLINE void labelledTraining(
            const Ref<ISequenceOfObservations> & obs, const Ref<
                discretehmm::ISequenceOfObservations> & stateSequence,
            const Double smoothing, const Ref<IHMM> & outputHMM)
        {
          Integer componentCount = obs->data->size;
          Integer length = (componentCount > 0) ? obs->data->data[0]->size : 0;

          HMMTK4J_ASSERT((stateSequence->maxDistinctValues
              == outputHMM->Pi->size));
          HMMTK4J_ASSERT((stateSequence->maxDistinctValues
              == outputHMM->A->rowCount) && (stateSequence->maxDistinctValues
              == outputHMM->A->colCount));
          for (Integer index = 0; index < componentCount; ++index)
          {
            HMMTK4J_ASSERT((stateSequence->maxDistinctValues
                == outputHMM->B->data[index]->rowCount)
                && (obs->maxDistinctValues->data[index]
                    == outputHMM->B->data[index]->colCount));
          }

          IMatrixOfDouble::TBuffer Adata = outputHMM->A->data;
          IMatrixOfDouble::TBuffer Bdata[componentCount];
          for (Integer index = 0; index < componentCount; ++index)
            Bdata[index] = outputHMM->B->data[index]->data;
          IArrayOfDouble::TBuffer Pidata = outputHMM->Pi->data;
          IArrayOfInteger::TBuffer obsdata[componentCount];
          for (Integer index = 0; index < componentCount; ++index)
            obsdata[index] = obs->data->data[index]->data;
          IArrayOfInteger::TBuffer stateSequencedata =
              stateSequence->data->data;

          outputHMM->A->fill(smoothing);
          for (Integer index = 0; index < componentCount; ++index)
            outputHMM->B->data[index]->fill(smoothing);
          outputHMM->Pi->fill(smoothing);

          Pidata[stateSequencedata[0]] = 1;
          outputHMM->Pi->makeStochastic();

          for (Integer t = length - 1; t >= 1; --t)
          {
            Adata[stateSequencedata[t - 1]][stateSequencedata[t]]++;
          }
          outputHMM->A->makeStochastic();

          for (Integer index = 0; index < componentCount; ++index)
          {
            for (Integer t = length - 1; t >= 0; --t)
            {
              Bdata[index][stateSequencedata[t]][obsdata[index][t]]++;
            }
            outputHMM->B->data[index]->makeStochastic();
          }
        }
      }
    }
  }
}

#endif
