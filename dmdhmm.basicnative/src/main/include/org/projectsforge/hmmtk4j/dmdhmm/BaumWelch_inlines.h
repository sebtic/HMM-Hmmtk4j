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

#ifndef HMMTK4J_DMDHMM_BaumWelch_inlines_h
#define HMMTK4J_DMDHMM_BaumWelch_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {

        HMMTK4J_INLINE Double baumwelch(const Ref<IHMM> & inputhmm, const Ref<
            ISequenceOfObservations> & obs, const Integer nbMaxIteration,
            const Boolean reevaluateA, const Ref<IArray<Boolean> > & reevaluateB,
            const Boolean reevaluatePi, const Ref<IHMM> & outputhmm)
        {
          Integer stateCount = inputhmm->A->rowCount;
          Integer componentCount = obs->data->size;
          Integer length = (componentCount > 0) ? obs->data->data[0]->size : 0;
          Ref<DynamicArrayOfInteger> symbolCount_dynamic = new DynamicArrayOfInteger();
          symbolCount_dynamic->resize(componentCount);
          DynamicArrayOfInteger::TBuffer symbolCount = symbolCount_dynamic->data;
          for (Integer index = 0; index < componentCount; ++index)
            symbolCount[index] = inputhmm->B->data[index]->colCount;

          if (nbMaxIteration == 0)
          { // shortcut to speed up computation
            outputhmm->copy(inputhmm);
            return fastForward(inputhmm, obs);
          }

          DynamicMatrixOfDouble * dynamic_alphaTildes = new DynamicMatrixOfDouble();
          dynamic_alphaTildes->resize(length, stateCount);
          Ref<IMatrixOfDouble> alphaTildes = dynamic_alphaTildes;

          DynamicMatrixOfDouble * dynamic_betaTildes = new DynamicMatrixOfDouble();
          dynamic_betaTildes->resize(length, stateCount);
          Ref<IMatrixOfDouble> betaTildes = dynamic_betaTildes;

          DynamicArrayOfDouble * dynamic_rescalingCoefs = new DynamicArrayOfDouble();
          dynamic_rescalingCoefs->resize(length);
          Ref<IArrayOfDouble> rescalingCoefs = dynamic_rescalingCoefs;

          // ***** Initialization : forward & backward *****
          outputhmm->copy(inputhmm);
          Double logProba = forward(inputhmm, obs, alphaTildes, rescalingCoefs);

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

          IArrayOfInteger::TBuffer obsdata[componentCount];
          for (Integer index = 0; index < componentCount; ++index)
            obsdata[index] = obs->data->data[index]->data;

          // ***** Main loop *****

          for (Integer iter = nbMaxIteration - 1; iter >= 0; --iter)
          {
            if (Math::isLogNull(logProba))
            {
              org::projectsforge::hmmtk4j::IllegalStateException __e(
                  "null likelihood detected in DMDHMM::BaumWelch-> I can't improve the model !");
              HMMTK4J_RaiseException(__e);
            }

            backward(outputhmm, obs, rescalingCoefs, betaTildes);

            IMatrixOfDouble::TBuffer Adata = outputhmm->A->data;
            IMatrixOfDouble::TBuffer Bdata[componentCount];
            for (Integer index = 0; index < componentCount; ++index)
              Bdata[index] = outputhmm->B->data[index]->data;
            IMatrixOfDouble::TBuffer alphaTildesdata = alphaTildes->data;
            IMatrixOfDouble::TBuffer betaTildesdata = betaTildes->data;
            IArrayOfDouble::TBuffer rescalingCoefsdata = rescalingCoefs->data;

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
                { // a_{i,n} = 0/0
                  newA->fill(1. / stateCount);
                  //logProba = Math::LOG_NULL;
                  //break;
                }
                newhmm->A->setRow(i, generic_newA);
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
                        sum += alphaTildesdata[t][n] * betaTildesdata[t][n] / rescalingCoefsdata[t];
                    }
                    newB[index]->data[m] = sum;
                  }
                  if (Math::isNull(newB[index]->makeStochastic()))
                  {
                    newB[index]->fill(1. / symbolCount[index]);
                    //logProba = Math::LOG_NULL;
                    //break;
                  }
                  newhmm->B->data[index]->setRow(n, generic_newB[index]);
                }
              }
            }

            if (reevaluatePi)
            {
              Double coef = rescalingCoefs->data[0];
              for (Integer n = stateCount - 1; n >= 0; --n)
                newPi->data[n] = alphaTildesdata[0][n] * betaTildesdata[0][n] / coef;
              if (Math::isNull(newPi->makeStochastic()))
              {
                newPi->fill(1. / stateCount);
                //logProba = Math::LOG_NULL;
                //break;
              }
              newhmm->Pi->copy(generic_newPi);
            }

            Double val = forward(newhmm, obs, alphaTildes, rescalingCoefs);
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
