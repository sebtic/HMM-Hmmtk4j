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

#ifndef HMMTK4J_DiscreteHMM_MaximalMutualInformation_inlines_h
#define HMMTK4J_DiscreteHMM_MaximalMutualInformation_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {

        HMMTK4J_INLINE Double maximalMutualInformation(
            const Ref<ArrayOfReference<IWeightedSequenceOfObservations> > & positiveObservations,
            const Ref<ArrayOfReference<IWeightedSequenceOfObservations> > & negativeObservations,
            const Ref<IHMM> & inputHMM, const Integer nbMaxIteration,
            const Ref<IHMM> & outputHMM)
        {
          Integer stateCount = inputHMM->A->rowCount;
          Integer symbolCount = inputHMM->B->colCount;

          HMMTK4J_ASSERT(nbMaxIteration >= 0);
          HMMTK4J_ASSERT(inputHMM->Pi->size == outputHMM->Pi->size);
          HMMTK4J_ASSERT(inputHMM->A->rowCount == outputHMM->A->rowCount);
          HMMTK4J_ASSERT(inputHMM->A->colCount == outputHMM->A->colCount);
          HMMTK4J_ASSERT(inputHMM->B->rowCount == outputHMM->B->rowCount);
          HMMTK4J_ASSERT(inputHMM->B->colCount == outputHMM->B->colCount);

          Ref<IHMM> positiveGradients[(int) positiveObservations->size];
          Ref<IHMM> negativeGradients[(int) negativeObservations->size];

          for (Integer i = 0; i < positiveObservations->size; ++i)
          {
            DynamicHMM * dynamic_positiveGradients = new DynamicHMM();
            dynamic_positiveGradients->resize(stateCount, symbolCount);
            positiveGradients[i] = dynamic_positiveGradients;
          }
          for (Integer i = 0; i < negativeObservations->size; ++i)
          {
            DynamicHMM * dynamic_negativeGradients = new DynamicHMM();
            dynamic_negativeGradients->resize(stateCount, symbolCount);
            negativeGradients[i] = dynamic_negativeGradients;
          }

          DynamicHMM * dynamic_gradient = new DynamicHMM();
          dynamic_gradient->resize(stateCount, symbolCount);
          Ref<IHMM> gradient = dynamic_gradient;

          DynamicHMM * dynamic_current = new DynamicHMM();
          dynamic_current->resize(stateCount, symbolCount);
          Ref<IHMM> current = dynamic_current;

          current->copy(inputHMM);

          Double step;
          Double stepMin = 1.0e-10;

          outputHMM->copy(inputHMM);

          Double outputLogProba = 0;
          Double outputLogProbaPositive = 0;
          Double outputLogProbaNegative = 0;
          bool hasNullPositive = false;
          for (Integer i = 0; i < positiveObservations->size; ++i)
          {
            Double lp = fastForward(outputHMM,
                positiveObservations->data[i]->sequence);
            hasNullPositive = hasNullPositive || (Math::isLogNull(lp));
            outputLogProbaPositive += positiveObservations->data[i]->weight
                * lp;
          }

          for (Integer i = 0; i < negativeObservations->size; ++i)
          {
            outputLogProbaNegative = fastForward(outputHMM,
                negativeObservations->data[i]->sequence)
                * negativeObservations->data[i]->weight;
          }

          outputLogProba = outputLogProbaPositive - outputLogProbaNegative;

          if (hasNullPositive)
          {
            // on ne reconnait m�me pas les observations positives => on arr�te, on peut rien faire de mieux
            return Math::LOG_NULL;
          }

          for (Integer iter = 0; iter < nbMaxIteration; ++iter)
          {

            // Step 1: compute the gradient
            gradient->A->fill(0.0);
            gradient->B->fill(0.0);
            gradient->Pi->fill(0.0);

            for (Integer i = 0; i < positiveObservations->size; ++i)
            {
              hmmtk4j::discretehmm::gradient(
                  positiveObservations->data[i]->sequence, outputHMM,
                  positiveGradients[i]);
              positiveGradients[i]->A->mul(
                  positiveObservations->data[i]->weight);
              positiveGradients[i]->B->mul(
                  positiveObservations->data[i]->weight);
              positiveGradients[i]->Pi->mul(
                  positiveObservations->data[i]->weight);
              gradient->A->add(positiveGradients[i]->A.getPtr());
              gradient->B->add(positiveGradients[i]->B.getPtr());
              gradient->Pi->add(positiveGradients[i]->Pi.getPtr());
            }

            for (Integer i = 0; i < negativeObservations->size; ++i)
            {
              hmmtk4j::discretehmm::gradient(
                  negativeObservations->data[i]->sequence, outputHMM,
                  negativeGradients[i]);
              negativeGradients[i]->A->mul(
                  negativeObservations->data[i]->weight);
              negativeGradients[i]->B->mul(
                  negativeObservations->data[i]->weight);
              negativeGradients[i]->Pi->mul(
                  negativeObservations->data[i]->weight);
              gradient->A->sub(negativeGradients[i]->A.getPtr());
              gradient->B->sub(negativeGradients[i]->B.getPtr());
              gradient->Pi->sub(negativeGradients[i]->Pi.getPtr());
            }

            // Step 2: apply the gradient ascent


            Boolean finished = false;
            step = 0.1;
            do
            {
              IMatrixOfDouble::TBuffer outputHMMAdata = outputHMM->A->data;
              IMatrixOfDouble::TBuffer outputHMMBdata = outputHMM->B->data;
              IArrayOfDouble::TBuffer outputHMMPidata = outputHMM->Pi->data;
              IMatrixOfDouble::TBuffer currentAdata = current->A->data;
              IMatrixOfDouble::TBuffer currentBdata = current->B->data;
              IArrayOfDouble::TBuffer currentPidata = current->Pi->data;
              IMatrixOfDouble::TBuffer gradientAdata = gradient->A->data;
              IMatrixOfDouble::TBuffer gradientBdata = gradient->B->data;
              IArrayOfDouble::TBuffer gradientPidata = gradient->Pi->data;

              // Step 2a: compute the new model
              // A
              for (Integer i = stateCount - 1; i >= 0; --i)
              {
                for (Integer j = stateCount - 1; j >= 0; --j)
                  currentAdata[i][j] = Math::log(outputHMMAdata[i][j]) + step
                      * gradientAdata[i][j];

                Double max = current->A->maxElement(i);

                for (Integer j = stateCount - 1; j >= 0; --j)
                  currentAdata[i][j] = Math::exp(currentAdata[i][j] - max);
              }
              // B
              for (Integer i = stateCount - 1; i >= 0; --i)
              {
                for (Integer j = symbolCount - 1; j >= 0; --j)
                  currentBdata[i][j] = Math::log(outputHMMBdata[i][j]) + step
                      * gradientBdata[i][j];
                Double max = current->B->maxElement(i);
                for (Integer j = symbolCount - 1; j >= 0; --j)
                  currentBdata[i][j] = Math::exp(currentBdata[i][j] - max);
              }
              // Pi
              for (Integer i = stateCount - 1; i >= 0; --i)
                currentPidata[i] = Math::log(outputHMMPidata[i]) + step
                    * gradientPidata[i];
              {
                Double max = current->Pi->maxElement();
                for (Integer i = stateCount - 1; i >= 0; --i)
                  currentPidata[i] = Math::exp(currentPidata[i] - max);
              }
              // normalization
              current->A->makeStochastic();
              current->B->makeStochastic();
              current->Pi->makeStochastic();

              // Step 2b: compute the score
              Double currentLogProba;

              Double currentLogProbaPositive = 0;
              hasNullPositive = false;
              for (Integer i = 0; i < positiveObservations->size; ++i)
              {
                Double lp = fastForward(current,
                    positiveObservations->data[i]->sequence);
                hasNullPositive = hasNullPositive || Math::isLogNull(lp);
                currentLogProbaPositive
                    += positiveObservations->data[i]->weight * lp;
              }

              Double currentLogProbaNegative = 0;
              for (Integer i = 0; i < negativeObservations->size; ++i)
              {
                currentLogProbaNegative
                    += negativeObservations->data[i]->weight * fastForward(
                        current, negativeObservations->data[i]->sequence);
              }

              currentLogProba = currentLogProbaPositive
                  - currentLogProbaNegative;

              // Step 2c: does we find an improved solution ?
              if (currentLogProba > outputLogProba && !hasNullPositive)
              { // A solution has a better score and the score is >0
                outputLogProba = currentLogProba;
                outputHMM->copy(current);
                finished = true;
              }
              else
                step *= 0.5;
            }
            while ((step >= stepMin) && (!finished));

            if (!finished)
              break;
          }
          return outputLogProba;
        }
      }
    }
  }
}

#endif
