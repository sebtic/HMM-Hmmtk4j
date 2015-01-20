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

#ifndef HMMTK4J_DiscreteHMM_Gradient_inlines_h
#define HMMTK4J_DiscreteHMM_Gradient_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        HMMTK4J_INLINE Double gradient(const Ref<ISequenceOfObservations> & observation,
            const Ref<IHMM> & hmm, const Ref<IHMM> & gradient)
        {
          Integer stateCount = hmm->A->rowCount;
          Integer symbolCount = hmm->B->colCount;
          Integer length = observation->data->size;

          HMMTK4J_ASSERT(hmm->Pi->size == gradient->Pi->size);
          HMMTK4J_ASSERT(hmm->A->rowCount == gradient->A->rowCount);
          HMMTK4J_ASSERT(hmm->A->colCount == gradient->A->colCount);
          HMMTK4J_ASSERT(hmm->B->rowCount == gradient->B->rowCount);
          HMMTK4J_ASSERT(hmm->B->colCount == gradient->B->colCount);

          DynamicMatrixOfDouble * dynamic_alphaTildes =
              new DynamicMatrixOfDouble();
          dynamic_alphaTildes->resize(length, stateCount);
          Ref<IMatrixOfDouble> alphaTildes = dynamic_alphaTildes;

          DynamicMatrixOfDouble * dynamic_betaTildes =
              new DynamicMatrixOfDouble();
          dynamic_betaTildes->resize(length, stateCount);
          Ref<IMatrixOfDouble> betaTildes = dynamic_betaTildes;

          DynamicArrayOfDouble * dynamic_rescalingCoefs =
              new DynamicArrayOfDouble();
          dynamic_rescalingCoefs->resize(length);
          Ref<IArrayOfDouble> rescalingCoefs = dynamic_rescalingCoefs;

          IArrayOfInteger::TBuffer observationdata = observation->data->data;

          IMatrixOfDouble::TBuffer hmmAdata = hmm->A->data;
          IMatrixOfDouble::TBuffer hmmBdata = hmm->B->data;
          IArrayOfDouble::TBuffer hmmPidata = hmm->Pi->data;

          IMatrixOfDouble::TBuffer gradientAdata = gradient->A->data;
          IMatrixOfDouble::TBuffer gradientBdata = gradient->B->data;
          IArrayOfDouble::TBuffer gradientPidata = gradient->Pi->data;

          IMatrixOfDouble::TBuffer alphaTildesdata = alphaTildes->data;
          IMatrixOfDouble::TBuffer betaTildesdata = betaTildes->data;
          IArrayOfDouble::TBuffer rescalingCoefsdata = rescalingCoefs->data;

          // ***** Initialization : forward & backward *****
          Double logProba = forward(hmm, observation, alphaTildes,
              rescalingCoefs);
          backward(hmm, observation, rescalingCoefs, betaTildes);

          // une valeur nulle dans hmm implique forc�ment une valeur de gradient correspondante nulle
          // on est oblig� de le traiter s�paremment car sinon on a une forme ind�termin�e 0/0 ou 0/p avec p>0

          // Pi
          for (Integer i = stateCount - 1; i >= 0; --i)
          {
            if (Math::isNull(hmmPidata[i]))
              gradientPidata[i] = 0;
            else
              gradientPidata[i]
                  = hmmPidata[i] * (hmmBdata[i][observationdata[0]]
                      * betaTildesdata[0][i] - 1);
          }

          // A
          for (Integer i = stateCount - 1; i >= 0; --i)
          {
            for (Integer j = stateCount - 1; j >= 0; --j)
            {
              if (Math::isNull(hmmAdata[i][j]))
                gradientAdata[i][j] = 0;
              else
              {
                Double sum1 = 0;
                Double sum2 = 0;
                for (Integer t = 1; t < length; ++t)
                {
                  if (!Math::isNull(alphaTildesdata[t - 1][i]))
                  {
                    sum1 += alphaTildesdata[t - 1][i] * hmmAdata[i][j]
                        * hmmBdata[j][observationdata[t]]
                        * betaTildesdata[t][j];
                    sum2 += alphaTildesdata[t - 1][i]
                        * betaTildesdata[t - 1][i] / rescalingCoefsdata[t - 1];
                  }
                }
                gradientAdata[i][j] = sum1 - sum2 * hmmAdata[i][j];
              }
            }
          }

          // B
          for (Integer i = stateCount - 1; i >= 0; --i)
          {
            for (Integer j = symbolCount - 1; j >= 0; --j)
            {
              if (Math::isNull(hmmAdata[i][j]))
                gradientBdata[i][j] = 0;
              else
              {
                Double sum = 0;

                for (Integer t = length - 1; t >= 0; --t)
                {
                  if (!Math::isNull(alphaTildesdata[t][i]))
                  {
                    sum += alphaTildesdata[t][i] * betaTildesdata[t][i]
                        * ((observationdata[t] == j) - hmmBdata[i][j])
                        / rescalingCoefsdata[t];
                  }
                }
                gradientBdata[i][j] = sum;
              }
            }
          }
          return logProba;
        }
      }
    }
  }
}

#endif
