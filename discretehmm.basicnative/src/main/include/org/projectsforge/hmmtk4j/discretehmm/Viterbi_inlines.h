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

#ifndef HMMTK4J_DiscreteHMM_Viterbi_inlines_h
#define HMMTK4J_DiscreteHMM_Viterbi_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        HMMTK4J_INLINE Double viterbi(const Ref<ISequenceOfObservations> & observation,
            const Ref<IHMM> & hmm, const Ref<ISequenceOfObservations> & stateSequence)
        {
          Integer stateCount = hmm->A->rowCount;
          Integer length = observation->data->size;

          Ref<DynamicMatrixOfDouble> delta = new DynamicMatrixOfDouble();
          Ref<DynamicMatrixOfInteger> psy = new DynamicMatrixOfInteger();

          HMMTK4J_ASSERT(stateCount > 0);
          HMMTK4J_ASSERT(length > 0);

          delta->resize(length, stateCount);
          psy->resize(length, stateCount);

          IArrayOfInteger::TBuffer observationdata = observation->data->data;
          IMatrixOfDouble::TBuffer Adata = hmm->A->data;
          IMatrixOfDouble::TBuffer Bdata = hmm->B->data;
          IArrayOfDouble::TBuffer Pidata = hmm->Pi->data;
          IMatrixOfDouble::TBuffer deltadata = delta->data;
          IMatrixOfInteger::TBuffer psydata = psy->data;
          IArrayOfInteger::TBuffer stateSequencedata =
              stateSequence->data->data;

          // ***** INITIALISATION *****
          {
            for (Integer n = stateCount - 1; n >= 0; --n)
            {
              deltadata[0][n] = Math::log(Pidata[n]
                  * Bdata[n][observationdata[0]]);
              psydata[0][n] = 0;
            }
          }

          // ***** INDUCTION *****
          for (Integer t = 1; t < length; ++t)
          {
            for (Integer n = stateCount - 1; n >= 0; --n)
            {
              Double result = Math::LOG_NULL;
              Integer arg = 0;
              for (Integer i = 0; i < stateCount; ++i)
              {
                Double v;
                if (Math::isNull(Adata[i][n]))
                  v = Math::LOG_NULL;
                else
                  v = deltadata[t - 1][i] + Math::log(Adata[i][n]);
                if (result < v)
                { // on a un chemin plus probable
                  result = v;
                  arg = i;
                }
              }
              if (Math::isNull(Bdata[n][observationdata[t]]))
                deltadata[t][n] = Math::LOG_NULL;
              else
                deltadata[t][n] = result + Math::log(
                    Bdata[n][observationdata[t]]);
              psydata[t][n] = arg;
            }
          }

          // ***** TERMINAISON *****
          {
            Integer arg = 0;

            Double result = Math::LOG_NULL;
            for (Integer i = stateCount - 1; i >= 0; --i)
            {
              if (result < deltadata[length - 1][i])
              {
                result = deltadata[length - 1][i];
                arg = i;
              }
            }

            Double logProba = result;

            stateSequencedata[length - 1] = arg;
            for (Integer t = length - 2; t >= 0; --t)
            {
              arg = psydata[t + 1][arg];
              stateSequencedata[t] = arg;
            }
            return logProba;
          }
        }
      }
    }
  }
}

#endif
