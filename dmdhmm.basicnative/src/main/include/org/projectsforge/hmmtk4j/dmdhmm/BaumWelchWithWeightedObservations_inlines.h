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

#ifndef HMMTK4J_DMDHMM_BaumWelchWithWeightedObservations_inlines_h
#define HMMTK4J_DMDHMM_BaumWelchWithWeightedObservations_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {

        HMMTK4J_INLINE Double baumwelchWithWeightedObservations(const Ref<IHMM> & inputhmm,
            const Ref<ArrayOfReference<IWeightedSequenceOfObservations> >& obss,
            const Integer nbMaxIteration, const Boolean reevaluateA,
            const Ref<IArray<Boolean> > & reevaluateB, const Boolean reevaluatePi,
            const Ref<IHMM> & outputhmm)
        {
          Integer stateCount = inputhmm->A->rowCount;
          Integer nbobs = obss->size;
          Integer componentCount = (nbobs > 0) ? obss->data[0]->sequence->data->size : 0;
          Ref<DynamicArrayOfInteger> symbolCount_dynamic = new DynamicArrayOfInteger();
          symbolCount_dynamic->resize(componentCount);
          DynamicArrayOfInteger::TBuffer symbolCount = symbolCount_dynamic->data;
          for (Integer index = 0; index < componentCount; ++index)
            symbolCount[index] = inputhmm->B->data[index]->colCount;

          Double sumOfWeights = 0;

          for (Integer o = nbobs - 1; o >= 0; --o)
            sumOfWeights += obss->data[o]->weight;

          // ***** Initialization : forward & backward *****
          outputhmm->copy(inputhmm);

          if (nbMaxIteration == 0)
            return fastForwardWithWeightedObservations(inputhmm, obss);

          Double logProba = Math::LOG_NULL;

          // creation of the working arrays and matrices
          ArrayOfReference<IMatrixOfDouble> alphaTildes;
          alphaTildes.resize(nbobs);

          ArrayOfReference<IMatrixOfDouble> betaTildes;
          betaTildes.resize(nbobs);

          ArrayOfReference<IArrayOfDouble> rescalingCoefs;
          rescalingCoefs.resize(nbobs);

          for (Integer o = nbobs - 1; o >= 0; --o)
          {
            Integer length = obss->data[o]->sequence->data->size;

            DynamicMatrixOfDouble * dynamic_alphaTildes = new DynamicMatrixOfDouble();
            dynamic_alphaTildes->resize(length, stateCount);
            alphaTildes.data[o] = dynamic_alphaTildes;

            DynamicMatrixOfDouble * dynamic_betaTildes = new DynamicMatrixOfDouble();
            dynamic_betaTildes->resize(length, stateCount);
            betaTildes.data[o] = dynamic_betaTildes;

            DynamicArrayOfDouble * dynamic_rescalingCoefs = new DynamicArrayOfDouble();
            dynamic_rescalingCoefs->resize(length);
            rescalingCoefs.data[o] = dynamic_rescalingCoefs;
          }

          // creation of the working hmm and vectors


          DynamicHMM * dynamic_newhmm = new DynamicHMM();
          dynamic_newhmm->resize(stateCount, symbolCount_dynamic.getPtr());
          Ref<IHMM> newhmm = dynamic_newhmm;

          DynamicArrayOfDouble * dynamic_newA = new DynamicArrayOfDouble();
          dynamic_newA->resize(stateCount);
          Ref<IArrayOfDouble> newA = dynamic_newA;
          Ref<IArray<Double> > generic_newA = dynamic_newA;

          DynamicArrayOfDouble * dynamic_newB[componentCount];
          Ref<IArrayOfDouble> newB[componentCount];
          Ref<IArray<Double> > generic_newB[componentCount];
          for (Integer index = 0; index < componentCount; ++index)
          {
            dynamic_newB[index] = new DynamicArrayOfDouble();
            dynamic_newB[index]->resize(symbolCount[index]);
            newB[index] = dynamic_newB[index];
            generic_newB[index] = dynamic_newB[index];
          }

          DynamicArrayOfDouble * dynamic_newPi = new DynamicArrayOfDouble();
          dynamic_newPi->resize(stateCount);
          Ref<IArrayOfDouble> newPi = dynamic_newPi;
          Ref<IArray<Double> > generic_newPi = dynamic_newPi;

          // compute the forward variables
          logProba = 0;
          for (Integer o = nbobs - 1; o >= 0; --o)
          {
            Double weight = obss->data[o]->weight;
            Double proba = forward(inputhmm, obss->data[o]->sequence, alphaTildes.data[o],
                rescalingCoefs.data[o]);
            if (Math::isLogNull(proba))
            {
              logProba = Math::LOG_NULL;
              org::projectsforge::hmmtk4j::IllegalStateException
                  __e(
                      "null likelihood detected in DMDHMM::BaumWelchWithWeightedObservations-> I can't improve the model !");
              HMMTK4J_RaiseException(__e);
              return Math::LOG_NULL;
            }
            logProba += weight * proba;
          }
          logProba /= sumOfWeights;

          // ***** Main loop *****
          for (Integer iter = nbMaxIteration - 1; iter >= 0; --iter)
          {
            if (Math::isLogNull(logProba))
              break;
            newhmm->A->fill(0.);
            for (Integer index = 0; index < componentCount; ++index)
              newhmm->B->data[index]->fill(0.);
            newhmm->Pi->fill(0.);
            logProba = 0;

            for (Integer o = nbobs - 1; o >= 0; --o)
            {
              Ref<IWeightedSequenceOfObservations> obs = obss->data[o];
              Integer length = obs->sequence->data->size;
              Double weight = obs->weight;

              // computing backward
              backward(outputhmm, obs->sequence, rescalingCoefs.data[o], betaTildes.data[o]);

              IMatrixOfDouble::TBuffer Adata = outputhmm->A->data;
              IMatrixOfDouble::TBuffer Bdata[componentCount];
              for (Integer index = 0; index < componentCount; ++index)
                Bdata[index] = outputhmm->B->data[index]->data;
              IArrayOfInteger::TBuffer obsdata[componentCount];
              for (Integer index = 0; index < componentCount; ++index)
                obsdata[index] = obs->sequence->data->data[index]->data;

              IMatrixOfDouble::TBuffer alphaTildesdata = alphaTildes.data[o]->data;
              IMatrixOfDouble::TBuffer betaTildesdata = betaTildes.data[o]->data;
              IArrayOfDouble::TBuffer rescalingCoefsdata = rescalingCoefs.data[o]->data;

              if (reevaluateA)
              {
                for (Integer i = stateCount - 1; i >= 0; --i)
                {
                  for (Integer n = stateCount - 1; n >= 0; --n)
                  {
                    Double sum = 0;
                    for (Integer t = length - 1 - 1; t >= 0; --t)
                    {
                      Double bio = 1;
                      for (int index = 0; index < componentCount; ++index)
                        bio *= Bdata[index][n][obsdata[index][t + 1]];
                      sum += alphaTildesdata[t][i] * bio * betaTildesdata[t + 1][n];
                    }
                    newA->data[n] = sum * Adata[i][n];
                  }
                  if (Math::isNull(newA->makeStochastic()))
                  {
                    logProba = Math::LOG_NULL;
                    break;
                  }
                  newhmm->A->addWeightedRow(i, generic_newA, weight / sumOfWeights);
                }
              }

              for (Integer index = 0; index < componentCount; ++index)
              {
                if (reevaluateB->data[index])
                {
                  for (Integer n = stateCount - 1; n >= 0; --n)
                  {
                    for (Integer m = symbolCount[index] - 1; m >= 0; --m)
                    {
                      Double sum = 0;
                      for (Integer t = length - 1; t >= 0; --t)
                      {
                        if (obsdata[index][t] == m)
                          sum += alphaTildesdata[t][n] * betaTildesdata[t][n]
                              / rescalingCoefsdata[t];
                      }
                      newB[index]->data[m] = sum;
                    }
                    if (Math::isNull(newB[index]->makeStochastic()))
                    {
                      logProba = Math::LOG_NULL;
                      break;
                    }
                    newhmm->B->data[index]->addWeightedRow(n, generic_newB[index], weight
                        / sumOfWeights);
                  }
                }
              }

              if (reevaluatePi)
              {
                Double coef = rescalingCoefsdata[0];
                for (Integer n = stateCount - 1; n >= 0; --n)
                  newPi->data[n] = alphaTildesdata[0][n] * betaTildesdata[0][n] / coef;
                if (Math::isNull(newPi->makeStochastic()))
                {
                  logProba = Math::LOG_NULL;
                  break;
                }
                newhmm->Pi->addWeighted(generic_newPi, weight / sumOfWeights);
              }
            }

            // normalization
            newhmm->Pi->makeStochastic();
            newhmm->A->makeStochastic();
            for (Integer index = 0; index < componentCount; ++index)
              newhmm->B->data[index]->makeStochastic();

            // compute the forward variables
            Double val = 0;
            for (Integer o = nbobs - 1; o >= 0; --o)
            {
              Double weight = obss->data[o]->weight;
              Double proba = forward(inputhmm, obss->data[o]->sequence, alphaTildes.data[o],
                  rescalingCoefs.data[o]);
              if (Math::isLogNull(proba))
              {
                val = Math::LOG_NULL;
                org::projectsforge::hmmtk4j::IllegalStateException
                    __e(
                        "null likelihood detected in DiscreteHMM::BaumWelchWithWeightedObservations -> I can't improve the model !");
                HMMTK4J_RaiseException(__e);
              }
              val += weight * proba;
            }

            if (logProba < val)
            {
              outputhmm->copy(newhmm);
              logProba = val;

              if (logProba >= 0)
                break;
            }
            else
              break;;

          }

          return logProba;
        }
      }
    }
  }
}

#endif
