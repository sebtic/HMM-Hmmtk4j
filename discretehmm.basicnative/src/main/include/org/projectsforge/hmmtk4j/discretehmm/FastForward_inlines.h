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

#ifndef HMMTK4J_DiscreteHMM_FastForward_inlines_h
#define HMMTK4J_DiscreteHMM_FastForward_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        HMMTK4J_INLINE Double fastForward(const Ref<IHMM> & hmm, const Ref<
            ISequenceOfObservations> & obs)
        {
          Integer stateCount = hmm->A->rowCount;
          Integer length = obs->data->size;

          if (length == 0)
            return Math::LOG_NULL;

          Double logProba = 0;
          Boolean validProba = true;

          IArrayOfInteger::TBuffer obsdata = obs->data->data;
          IMatrixOfDouble::TBuffer Adata = hmm->A->data;
          IMatrixOfDouble::TBuffer Bdata = hmm->B->data;
          IArrayOfDouble::TBuffer Pidata = hmm->Pi->data;

          Ref<DynamicArrayOfDouble> alphaTildes[2] =
          { new DynamicArrayOfDouble(), new DynamicArrayOfDouble() };

          alphaTildes[0]->resize(stateCount);
          alphaTildes[1]->resize(stateCount);

          Integer lastalphatilde = 0;

          // ***** Initialisation *****
          {
            DynamicArrayOfDouble* alpha_t =
                alphaTildes[lastalphatilde].getPtr();
            Integer ot = obsdata[0];
            for (Integer i = stateCount - 1; i >= 0; --i)
              alpha_t->data[i] = Pidata[i] * Bdata[i][ot];

            Double sum = alpha_t->makeStochastic();
            if (Math::isNull(sum))
              validProba = false;
            logProba += Math::log(sum);
          }

          // ***** Main loop *****
          if (validProba)
            for (Integer t = 1; t < length; ++t)
            {
              Integer ot = obs->data->data[t];
              DynamicArrayOfDouble * alpha_tmoins1 =
                  alphaTildes[lastalphatilde].getPtr();
              lastalphatilde = (lastalphatilde + 1) % 2;
              DynamicArrayOfDouble * alpha_t =
                  alphaTildes[lastalphatilde].getPtr();

              for (Integer j = stateCount - 1; j >= 0; --j)
              {
                Double cumul = 0;
                for (Integer i = stateCount - 1; i >= 0; --i)
                  cumul += alpha_tmoins1->data[i] * Adata[i][j];
                alpha_t->data[j] = cumul * Bdata[j][ot];
              }

              Double sum = alpha_t->makeStochastic();
              if (Math::isNull(sum))
              {
                validProba = false;
                break;
              }
              logProba += Math::log(sum);
            }

          // ***** Finalization *****
          if (!validProba)
            logProba = Math::LOG_NULL;

          return logProba;

        }
      }
    }
  }
}

#endif
