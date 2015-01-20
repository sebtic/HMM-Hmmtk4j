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

#ifndef HMMTK4J_DMDHMM_Backward_inlines_h
#define HMMTK4J_DMDHMM_Backward_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {
        HMMTK4J_INLINE void backward(const Ref<IHMM> & hmm, const Ref<
            ISequenceOfObservations> & obs,
            const Ref<IArrayOfDouble> & rescalingCoefs, const Ref<
                IMatrixOfDouble> & betaTildes)
        {
          Integer stateCount = hmm->A->rowCount;
          Integer componentCount = obs->data->size;
          Integer length = (componentCount > 0) ? obs->data->data[0]->size : 0;

          HMMTK4J_ASSERT((betaTildes->rowCount == length)
              && (betaTildes->colCount == stateCount));
          HMMTK4J_ASSERT(rescalingCoefs->size == length);

          if (length == 0)
            return;

          IArrayOfInteger::TBuffer obsdata[componentCount];
          for (Integer index = 0; index < componentCount; ++index)
            obsdata[index] = obs->data->data[index]->data;
          IMatrixOfDouble::TBuffer Adata = hmm->A->data;
          IMatrixOfDouble::TBuffer Bdata[componentCount];
          for (Integer index = 0; index < componentCount; ++index)
            Bdata[index] = hmm->B->data[index]->data;
          IArrayOfDouble::TBuffer rescalingCoefsdata = rescalingCoefs->data;
          IMatrixOfDouble::TBuffer betaTildesdata = betaTildes->data;

          // ***** Initialisation *****
          {
            betaTildes->fillRow(length - 1, rescalingCoefsdata[length - 1]);
          }

          // ***** BOUCLE PRINCIPALE : INDUCTION *****
          for (Integer t = length - 2; t >= 0; --t)
          {
            Double coef = rescalingCoefsdata[t];

            for (Integer i = stateCount - 1; i >= 0; --i)
            {
              Double cumul = 0;
              for (Integer j = stateCount - 1; j >= 0; --j)
              {
                Double bio = 1;
                for (int index = 0; index < componentCount; ++index)
                  bio *= Bdata[index][j][obsdata[index][t + 1]];
                cumul += Adata[i][j] * betaTildesdata[t + 1][j] * bio;
              }

              betaTildesdata[t][i] = cumul * coef;
            }
          }
        }
      }
    }
  }
}

#endif
