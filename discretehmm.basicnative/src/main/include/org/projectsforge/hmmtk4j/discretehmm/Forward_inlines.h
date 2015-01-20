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

#ifndef HMMTK4J_DiscreteHMM_Forward_inlines_h
#define HMMTK4J_DiscreteHMM_Forward_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        HMMTK4J_INLINE Double forward(const Ref<IHMM> & hmm, const Ref<
            ISequenceOfObservations> & obs, const Ref<IMatrixOfDouble> & alphaTildes,
            const Ref<IArrayOfDouble> & rescalingCoefs)
        {
          Integer stateCount = hmm->A->rowCount;
          Integer length = obs->data->size;

          HMMTK4J_ASSERT((alphaTildes->rowCount == length)
              && (alphaTildes->colCount == stateCount));
          HMMTK4J_ASSERT(rescalingCoefs->size == length);

          if (length == 0)
            return Math::LOG_NULL;

          Boolean validProba = true;

          IArrayOfInteger::TBuffer obsdata = obs->data->data;
          IMatrixOfDouble::TBuffer Adata = hmm->A->data;
          IMatrixOfDouble::TBuffer Bdata = hmm->B->data;
          IArrayOfDouble::TBuffer Pidata = hmm->Pi->data;
          IMatrixOfDouble::TBuffer alphaTildesdata = alphaTildes->data;
          IArrayOfDouble::TBuffer rescalingCoefsdata = rescalingCoefs->data;

          // ***** Initialisation *****
          {
            Integer ot = obs->data->data[0];
            for (Integer i = stateCount - 1; i >= 0; --i)
            {
              alphaTildesdata[0][i] = Pidata[i] * Bdata[i][ot];
            }

            Double sum = alphaTildes->makeStochasticRow(0);
            if (Math::isNull(sum))
              validProba = false;
            if (!validProba)
              fprintf(stderr, "Null probability in initialization %lf\n", sum);
            rescalingCoefsdata[0] = 1.0 / sum;
          }

          // ***** Main loop *****

          for (Integer t = 1; t < length; ++t)
          {
            Integer ot = obsdata[t];
            for (Integer j = stateCount - 1; j >= 0; --j)
            {
              Double cumul = 0;
              for (Integer i = stateCount - 1; i >= 0; --i)
                cumul += alphaTildesdata[t - 1][i] * Adata[i][j];
              alphaTildesdata[t][j] = cumul * Bdata[j][ot];
            }

            Double sum = alphaTildes->makeStochasticRow(t);
            if (Math::isNull(sum))
              validProba = false;
            if (!validProba)
              fprintf(stderr, "Null probability in main loop at %d %lf\n", t,
                  sum);
            rescalingCoefsdata[t] = 1.0 / sum;
          }

          // ***** Finalization *****
          if (validProba)
          {
            Double logProba = 0;
            for (Integer t = length - 1; t >= 0; --t)
              logProba -= Math::log(rescalingCoefsdata[t]);
            return logProba;
          }
          else
            return Math::LOG_NULL;
        }
      }
    }
  }
}

#endif
