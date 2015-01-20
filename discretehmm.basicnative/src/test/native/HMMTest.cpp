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

#include <cppunit/extensions/HelperMacros.h>
#include <org/projectsforge/hmmtk4j/discretehmm/IncludeAll.h>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        class HMMTest: public CppUnit::TestFixture
        {
          public:
            CPPUNIT_TEST_SUITE( HMMTest);
            CPPUNIT_TEST( testConstructor);
            CPPUNIT_TEST( testForward);
            CPPUNIT_TEST( testFastForward);
            CPPUNIT_TEST( testBackward);
            CPPUNIT_TEST( testBaumWelch);
            CPPUNIT_TEST( testViterbi);
            CPPUNIT_TEST( testLabelledTraining);
            CPPUNIT_TEST( testSegmentalKMeans);
            CPPUNIT_TEST( testMaximalMutualInformation);CPPUNIT_TEST_SUITE_END();

            void testViterbi()
            {
              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, 10);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 10; ++j)
                  hmm->B->data[i][j] = (i == j);
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->setMaxDistinctValues(10);
              seq->resize(30);
              for (Integer i = 0; i < 30; ++i)
                seq->data->data[i] = i % 10;

              Ref<DynamicSequenceOfObservations> stateSeq = new DynamicSequenceOfObservations();
              stateSeq->resize(seq->data->size);
              stateSeq->setMaxDistinctValues(10);

              viterbi(seq.getPtr(), hmm.getPtr(), stateSeq.getPtr());

              for (Integer i = 0; i < stateSeq->data->size; ++i)
                CPPUNIT_ASSERT_EQUAL(i % 10, stateSeq->data->data[i]);
            }

            void testLabelledTraining()
            {
              Ref<DynamicSequenceOfObservations> obs = new DynamicSequenceOfObservations();
              ;
              obs->setMaxDistinctValues(10);
              obs->resize(30);
              for (Integer i = 0; i < 30; ++i)
                obs->data->data[i] = i % 10;

              Ref<DynamicSequenceOfObservations> stateSeq = new DynamicSequenceOfObservations();
              stateSeq->resize(obs->data->size);
              stateSeq->setMaxDistinctValues(10);

              for (Integer i = 0; i < obs->data->size; ++i)
              {
                obs->data->data[i] = i % 10;
                stateSeq->data->data[i] = i % 10;
              }

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, 10);

              labelledTraining(obs.getPtr(), stateSeq.getPtr(), 0, hmm.getPtr());

              const double A[10][10] =
              {
              { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
              { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
              { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
              { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
              { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
              { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
              { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
              { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };

              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                {
                  CPPUNIT_ASSERT_DOUBLES_EQUAL(A[i][j], hmm->A->data[i][j],
                      0.01);
                  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0 * (i == j),
                      hmm->B->data[i][j], 0.01);
                }
                CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0 * (i == 0), hmm->Pi->data[i],
                    0.01);
              }
            }

            void testSegmentalKMeans()
            {
              for (int essai = 0; essai < 10; ++essai)
              {

                Ref<DynamicHMM> hmm = new DynamicHMM();
                hmm->resize(10, 5);
                for (Integer i = 0; i < 10; ++i)
                {
                  for (Integer j = 0; j < 10; ++j)
                    hmm->A->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  for (Integer j = 0; j < 5; ++j)
                    hmm->B->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  hmm->Pi->data[i] = randomGenerator->nextInt() + 1; //i + 1;
                }
                hmm->A->makeStochastic();
                hmm->B->makeStochastic();
                hmm->Pi->makeStochastic();

                Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
                seq->setMaxDistinctValues(5);
                seq->resize(300);
                for (Integer i = 0; i < seq->data->size; ++i)
                  seq->data->data[i] = randomGenerator->nextInt(5);

                Ref<DynamicHMM> newhmm = new DynamicHMM();
                newhmm->resize(10, 5);
                Double old = Math::LOG_NULL;
                for (Integer nb = 1; nb <= 10; ++nb)
                {
                  Double logProba = segmentalKMeans(hmm.getPtr(), seq.getPtr(),
                      nb, newhmm.getPtr());
                  CPPUNIT_ASSERT(old <= logProba);
                  old = logProba;
                }
              }
            }

            void testMaximalMutualInformation()
            {
              hmmtk4j::Exception::activateDebugHelper();
              for (int essai = 0; essai < 10; ++essai)
              {

                Ref<DynamicHMM> hmm = new DynamicHMM();
                hmm->resize(10, 5);
                for (Integer i = 0; i < 10; ++i)
                {
                  for (Integer j = 0; j < 10; ++j)
                    hmm->A->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  for (Integer j = 0; j < 5; ++j)
                    hmm->B->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  hmm->Pi->data[i] = randomGenerator->nextInt() + 1; //i + 1;
                }
                hmm->A->makeStochastic();
                hmm->B->makeStochastic();
                hmm->Pi->makeStochastic();

                Ref<ArrayOfReference<IWeightedSequenceOfObservations> > positiveObservations =
                    new ArrayOfReference<IWeightedSequenceOfObservations> ();
                Ref<DynamicWeightedSequenceOfObservations> positiveObs;

                positiveObs = new DynamicWeightedSequenceOfObservations();
                positiveObs->sequence->setMaxDistinctValues(5);
                positiveObs->dynamic_sequence->resize(300);
                positiveObs->setWeight(2);
                for (Integer i = 0; i < positiveObs->sequence->data->size; ++i)
                  positiveObs->sequence->data->data[i]
                      = randomGenerator->nextInt(3);
                positiveObservations->pushBack(positiveObs.getPtr());

                positiveObs = new DynamicWeightedSequenceOfObservations();
                positiveObs->sequence->setMaxDistinctValues(5);
                positiveObs->dynamic_sequence->resize(300);
                positiveObs->setWeight(2);
                for (Integer i = 0; i < positiveObs->sequence->data->size; ++i)
                  positiveObs->sequence->data->data[i]
                      = randomGenerator->nextInt(3);
                positiveObservations->pushBack(positiveObs.getPtr());

                Ref<ArrayOfReference<IWeightedSequenceOfObservations> > negativeObservations =
                    new ArrayOfReference<IWeightedSequenceOfObservations> ();

                Ref<DynamicWeightedSequenceOfObservations> negativeObs;

                negativeObs = new DynamicWeightedSequenceOfObservations();
                negativeObs->sequence->setMaxDistinctValues(5);
                negativeObs->dynamic_sequence->resize(300);
                negativeObs->setWeight(0.1);
                for (Integer i = 0; i < negativeObs->sequence->data->size; ++i)
                  negativeObs->sequence->data->data[i]
                      = randomGenerator->nextInt(5);
                negativeObservations->pushBack(negativeObs.getPtr());

                negativeObs = new DynamicWeightedSequenceOfObservations();
                negativeObs->sequence->setMaxDistinctValues(5);
                negativeObs->dynamic_sequence->resize(300);
                negativeObs->setWeight(0.1);
                for (Integer i = 0; i < negativeObs->sequence->data->size; ++i)
                  negativeObs->sequence->data->data[i]
                      = randomGenerator->nextInt(5);
                negativeObservations->pushBack(negativeObs.getPtr());

                negativeObs = new DynamicWeightedSequenceOfObservations();
                negativeObs->sequence->setMaxDistinctValues(5);
                negativeObs->dynamic_sequence->resize(300);
                negativeObs->setWeight(0.1);
                for (Integer i = 0; i < negativeObs->sequence->data->size; ++i)
                  negativeObs->sequence->data->data[i]
                      = randomGenerator->nextInt(5);
                negativeObservations->pushBack(negativeObs.getPtr());

                Ref<DynamicHMM> newhmm = new DynamicHMM();
                newhmm->resize(10, 5);
                Double old = Math::LOG_NULL;
                for (Integer nb = 0; nb <= 10; ++nb)
                {
                  Double logProba = maximalMutualInformation(
                      positiveObservations.getPtr(),
                      negativeObservations.getPtr(), hmm.getPtr(), nb,
                      newhmm.getPtr());
                  CPPUNIT_ASSERT(old <= logProba);
                  old = logProba;
                }
              }
            }

            void testConstructor()
            {
              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, 5);

              CPPUNIT_ASSERT(hmm->A->rowCount == 10);
              CPPUNIT_ASSERT(hmm->A->colCount == 10);
              CPPUNIT_ASSERT(hmm->B->rowCount == 10);
              CPPUNIT_ASSERT(hmm->B->colCount == 5);
              CPPUNIT_ASSERT(hmm->Pi->size == 10);
            }

            void testForward()
            {
              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, 5);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[i][j] = i + j + 1;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->setMaxDistinctValues(5);
              seq->resize(30);
              for (Integer i = 0; i < 30; ++i)
                seq->data->data[i] = i % 5;

              Ref<DynamicMatrixOfDouble> alphaTildes =
                  new DynamicMatrixOfDouble();
              alphaTildes->resize(30, 10);
              Ref<DynamicArrayOfDouble> rescalingCoefs =
                  new DynamicArrayOfDouble();
              rescalingCoefs->resize(30);

              Double logp = forward(hmm.getPtr(), seq.getPtr(),
                  alphaTildes.getPtr(), rescalingCoefs.getPtr());
              CPPUNIT_ASSERT_DOUBLES_EQUAL(-48.852186362466, logp, 0.0001);
            }

            void testFastForward()
            {
              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, 5);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[i][j] = i + j + 1;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->setMaxDistinctValues(5);
              seq->resize(30);
              for (Integer i = 0; i < 30; ++i)
                seq->data->data[i] = i % 5;

              Double logp = fastForward(hmm.getPtr(), seq.getPtr());
              CPPUNIT_ASSERT_DOUBLES_EQUAL(-48.852186362466, logp, 0.0001);
            }

            void testBackward()
            {
              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, 5);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[i][j] = i + j + 1;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->setMaxDistinctValues(5);
              seq->resize(30);
              for (Integer i = 0; i < 30; ++i)
                seq->data->data[i] = i % 5;

              Ref<DynamicMatrixOfDouble> alphaTildes =
                  new DynamicMatrixOfDouble();
              alphaTildes->resize(30, 10);
              Ref<DynamicArrayOfDouble> rescalingCoefs =
                  new DynamicArrayOfDouble();
              rescalingCoefs->resize(30);

              Double logp = forward(hmm.getPtr(), seq.getPtr(),
                  alphaTildes.getPtr(), rescalingCoefs.getPtr());

              Ref<DynamicMatrixOfDouble> betaTildes =
                  new DynamicMatrixOfDouble();
              betaTildes->resize(30, 10);
              backward(hmm.getPtr(), seq.getPtr(), rescalingCoefs.getPtr(),
                  betaTildes.getPtr());

              CPPUNIT_ASSERT_DOUBLES_EQUAL(-48.852186362466, logp, 0.0001);
            }

            void testBaumWelch()
            {
              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, 5);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[i][j] = i + j + 1;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->setMaxDistinctValues(5);
              seq->resize(30);
              for (Integer i = 0; i < 30; ++i)
                seq->data->data[i] = i % 5;

              fastForward(hmm.getPtr(), seq.getPtr());

              Ref<DynamicHMM> newhmm = new DynamicHMM();
              newhmm->resize(10, 5);
              Double goodValues[10] =
              { -48.21779377925154364, -48.17846684636410259,
                  -48.12232887599249409, -48.04040938344959244,
                  -47.91661762097253785, -47.71771933197934601,
                  -47.36788282290679319, -46.69331860257293698,
                  -45.38149439201943380, -43.25480413764215371 };
              for (Integer nb = 1; nb <= 10; ++nb)
              {
                Double logbw = baumwelch(hmm.getPtr(), seq.getPtr(), nb, true,
                    true, true, newhmm.getPtr());
                CPPUNIT_ASSERT_DOUBLES_EQUAL(goodValues[nb - 1], logbw, 0.0001);
              }

            }

        };

        CPPUNIT_TEST_SUITE_REGISTRATION( HMMTest);
      }
    }
  }
}
