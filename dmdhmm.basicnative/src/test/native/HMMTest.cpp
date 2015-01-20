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
#include <org/projectsforge/hmmtk4j/dmdhmm/IncludeAll.h>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {
        class HMMTest: public CppUnit::TestFixture
        {
          public:
            CPPUNIT_TEST_SUITE( HMMTest);
            CPPUNIT_TEST( testConstructor);
            CPPUNIT_TEST( testForward);
            CPPUNIT_TEST( testForward2);
            CPPUNIT_TEST( testFastForward);
            CPPUNIT_TEST( testBackward);
            CPPUNIT_TEST( testBaumWelch);
            CPPUNIT_TEST( testBaumWelch2);
            CPPUNIT_TEST( testViterbi);
            CPPUNIT_TEST( testViterbi2);
            CPPUNIT_TEST( testLabelledTraining);
            CPPUNIT_TEST( testSegmentalKMeans);
            CPPUNIT_TEST( testMaximalMutualInformation);CPPUNIT_TEST_SUITE_END();

            void testViterbi()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 5;
              components->data[1] = 2;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, components);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[0]->data[i][j] = (i % 5) == j;
                for (Integer j = 0; j < 2; ++j)
                  hmm->B->data[1]->data[i][j] = ((i % 10) / 5) == j;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->data[0]->makeStochastic();
              hmm->B->data[1]->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->resize(2, 30);
              seq->setMaxDistinctValues(dai);
              for (Integer i = 0; i < 30; ++i)
              {
                seq->data->data[0]->data[i] = i % 5;
                seq->data->data[1]->data[i] = (i % 10) / 5;
              }

              Ref<discretehmm::DynamicSequenceOfObservations> stateSeq =
                  new discretehmm::DynamicSequenceOfObservations();
              stateSeq->resize(30);
              stateSeq->setMaxDistinctValues(10);

              Exception::activateDebugHelper();

              viterbi(seq.getPtr(), hmm.getPtr(), stateSeq.getPtr());

              for (Integer i = 0; i < stateSeq->data->size; ++i)
              {
                CPPUNIT_ASSERT_EQUAL(i % 10, stateSeq->data->data[i]);
              }

            }

            void testViterbi2()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 10;
              components->data[1] = 2;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, components);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = 1;
                for (Integer j = 0; j < 10; ++j)
                  hmm->B->data[0]->data[i][j] = i == j;
                for (Integer j = 0; j < 2; ++j)
                  hmm->B->data[1]->data[i][j] = 1;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->data[0]->makeStochastic();
              hmm->B->data[1]->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->resize(2, 30);
              seq->setMaxDistinctValues(dai);
              for (Integer i = 0; i < 30; ++i)
              {
                seq->data->data[0]->data[i] = i % 10;
                seq->data->data[1]->data[i] = i % 2;
              }

              Ref<discretehmm::DynamicSequenceOfObservations> stateSeq =
                  new discretehmm::DynamicSequenceOfObservations();
              stateSeq->resize(30);
              stateSeq->setMaxDistinctValues(10);

              viterbi(seq.getPtr(), hmm.getPtr(), stateSeq.getPtr());

              for (Integer i = 0; i < stateSeq->data->size; ++i)
              {
                CPPUNIT_ASSERT_EQUAL(i % 10, stateSeq->data->data[i]);
              }
            }

            void testLabelledTraining()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 5;
              components->data[1] = 2;

              Ref<DynamicSequenceOfObservations> obs = new DynamicSequenceOfObservations();
              obs->resize(2, 30);
              obs->setMaxDistinctValues(dai);
              for (Integer i = 0; i < 30; ++i)
              {
                obs->data->data[0]->data[i] = i % 5;
                obs->data->data[1]->data[i] = (i % 10) / 5;
              }

              Ref<discretehmm::DynamicSequenceOfObservations> stateSeq =
                  new discretehmm::DynamicSequenceOfObservations();
              stateSeq->resize(30);
              stateSeq->setMaxDistinctValues(10);

              for (Integer i = 0; i < obs->data->size; ++i)
                stateSeq->data->data[i] = i % 10;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, dai);

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
              { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

              const double B0[10][5] =
              {
              { 1, 0, 0, 0, 0 },
              { 0, 1, 0, 0, 0 },
              { 0, 0, 1, 0, 0 },
              { 0, 0, 0, 1, 0 },
              { 0, 0, 0, 0, 1 },
              { 1, 0, 0, 0, 0 },
              { 0, 1, 0, 0, 0 },
              { 0, 0, 1, 0, 0 },
              { 0, 0, 0, 1, 0 },
              { 0, 0, 0, 0, 1 } };

              const double B1[10][2] =
              {
              { 1, 0 },
              { 1, 0 },
              { 1, 0 },
              { 1, 0 },
              { 1, 0 },
              { 0, 1 },
              { 0, 1 },
              { 0, 1 },
              { 0, 1 },
              { 0, 1 } };

              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  CPPUNIT_ASSERT_DOUBLES_EQUAL(A[i][j], hmm->A->data[i][j], 0.01);
                for (Integer j = 0; j < 5; ++j)
                  CPPUNIT_ASSERT_DOUBLES_EQUAL(B0[i][j], hmm->B->data[0]->data[i][j], 0.01);
                for (Integer j = 0; j < 2; ++j)
                  CPPUNIT_ASSERT_DOUBLES_EQUAL(B1[i][j], hmm->B->data[1]->data[i][j], 0.01);
                CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0 * (i == 0), hmm->Pi->data[i], 0.01);
              }
            }

            void testSegmentalKMeans()
            {
              for (int essai = 0; essai < 10; ++essai)
              {
                DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
                dai->resize(2);
                Ref<IArray<Integer> > components = dai;
                components->data[0] = 10;
                components->data[1] = 2;

                Ref<DynamicHMM> hmm = new DynamicHMM();
                hmm->resize(10, dai);
                for (Integer i = 0; i < 10; ++i)
                {
                  for (Integer j = 0; j < 10; ++j)
                    hmm->A->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  for (Integer j = 0; j < 5; ++j)
                    hmm->B->data[0]->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  for (Integer j = 0; j < 2; ++j)
                    hmm->B->data[1]->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  hmm->Pi->data[i] = randomGenerator->nextInt() + 1; //i + 1;
                }
                hmm->A->makeStochastic();
                hmm->B->data[0]->makeStochastic();
                hmm->B->data[1]->makeStochastic();
                hmm->Pi->makeStochastic();

                Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
                seq->resize(2, 300);
                seq->setMaxDistinctValues(dai);
                for (Integer i = 0; i < 300; ++i)
                {
                  seq->data->data[0]->data[i] = randomGenerator->nextInt(5);
                  seq->data->data[1]->data[i] = randomGenerator->nextInt(2);
                }

                Ref<DynamicHMM> newhmm = new DynamicHMM();
                newhmm->resize(10, dai);
                Double old = Math::LOG_NULL;
                for (Integer nb = 1; nb <= 10; ++nb)
                {
                  Double logProba =
                      segmentalKMeans(hmm.getPtr(), seq.getPtr(), nb, newhmm.getPtr());
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
                DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
                dai->resize(2);
                Ref<IArray<Integer> > components = dai;
                components->data[0] = 5;
                components->data[1] = 2;

                Ref<DynamicHMM> hmm = new DynamicHMM();
                hmm->resize(10, components);
                for (Integer i = 0; i < 10; ++i)
                {
                  for (Integer j = 0; j < 10; ++j)
                    hmm->A->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  for (Integer j = 0; j < 5; ++j)
                    hmm->B->data[0]->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  for (Integer j = 0; j < 2; ++j)
                    hmm->B->data[1]->data[i][j] = randomGenerator->nextInt() + 1; //i + j + 1;
                  hmm->Pi->data[i] = randomGenerator->nextInt() + 1; //i + 1;
                }
                hmm->A->makeStochastic();
                hmm->B->data[0]->makeStochastic();
                hmm->B->data[1]->makeStochastic();
                hmm->Pi->makeStochastic();

                Ref<ArrayOfReference<IWeightedSequenceOfObservations> > positiveObservations =
                    new ArrayOfReference<IWeightedSequenceOfObservations> ();
                Ref<DynamicWeightedSequenceOfObservations> positiveObs;

                positiveObs = new DynamicWeightedSequenceOfObservations();
                positiveObs->dynamic_sequence->resize(2, 300);
                positiveObs->sequence->setMaxDistinctValues(dai);
                positiveObs->setWeight(2);
                for (Integer i = 0; i < 300; ++i)
                {
                  positiveObs->sequence->data->data[0]->data[i] = randomGenerator->nextInt(5);
                  positiveObs->sequence->data->data[1]->data[i] = randomGenerator->nextInt(2);
                }
                positiveObservations->pushBack(positiveObs.getPtr());

                positiveObs = new DynamicWeightedSequenceOfObservations();
                positiveObs->dynamic_sequence->resize(2, 300);
                positiveObs->sequence->setMaxDistinctValues(dai);
                positiveObs->setWeight(2);
                for (Integer i = 0; i < 300; ++i)
                {
                  positiveObs->sequence->data->data[0]->data[i] = randomGenerator->nextInt(5);
                  positiveObs->sequence->data->data[1]->data[i] = randomGenerator->nextInt(2);
                }
                positiveObservations->pushBack(positiveObs.getPtr());

                Ref<ArrayOfReference<IWeightedSequenceOfObservations> > negativeObservations =
                    new ArrayOfReference<IWeightedSequenceOfObservations> ();

                Ref<DynamicWeightedSequenceOfObservations> negativeObs;

                negativeObs = new DynamicWeightedSequenceOfObservations();
                negativeObs->dynamic_sequence->resize(2, 300);
                negativeObs->sequence->setMaxDistinctValues(dai);
                negativeObs->setWeight(0.1);
                for (Integer i = 0; i < 300; ++i)
                {
                  negativeObs->sequence->data->data[0]->data[i] = randomGenerator->nextInt(5);
                  negativeObs->sequence->data->data[1]->data[i] = randomGenerator->nextInt(2);
                }
                negativeObservations->pushBack(negativeObs.getPtr());

                negativeObs = new DynamicWeightedSequenceOfObservations();
                negativeObs->dynamic_sequence->resize(2, 300);
                negativeObs->sequence->setMaxDistinctValues(dai);
                negativeObs->setWeight(0.1);
                for (Integer i = 0; i < 300; ++i)
                {
                  negativeObs->sequence->data->data[0]->data[i] = randomGenerator->nextInt(5);
                  negativeObs->sequence->data->data[1]->data[i] = randomGenerator->nextInt(2);
                }
                negativeObservations->pushBack(negativeObs.getPtr());

                negativeObs = new DynamicWeightedSequenceOfObservations();
                negativeObs->dynamic_sequence->resize(2, 300);
                negativeObs->sequence->setMaxDistinctValues(dai);
                negativeObs->setWeight(0.1);
                for (Integer i = 0; i < 300; ++i)
                {
                  negativeObs->sequence->data->data[0]->data[i] = randomGenerator->nextInt(5);
                  negativeObs->sequence->data->data[1]->data[i] = randomGenerator->nextInt(2);
                }
                negativeObservations->pushBack(negativeObs.getPtr());

                Ref<DynamicHMM> newhmm = new DynamicHMM();
                newhmm->resize(10, dai);
                Double old = Math::LOG_NULL;
                for (Integer nb = 0; nb <= 10; ++nb)
                {
                  Double logProba = maximalMutualInformation(positiveObservations.getPtr(),
                      negativeObservations.getPtr(), hmm.getPtr(), nb, newhmm.getPtr());
                  CPPUNIT_ASSERT(old <= logProba);
                  old = logProba;
                }
              }
            }

            void testConstructor()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 5;
              components->data[1] = 3;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, components);

              CPPUNIT_ASSERT(hmm->A->rowCount == 10);
              CPPUNIT_ASSERT(hmm->A->colCount == 10);
              CPPUNIT_ASSERT(hmm->B->size == 2);
              CPPUNIT_ASSERT(hmm->B->data[0]->rowCount == 10);
              CPPUNIT_ASSERT(hmm->B->data[0]->colCount == 5);
              CPPUNIT_ASSERT(hmm->B->data[1]->rowCount == 10);
              CPPUNIT_ASSERT(hmm->B->data[1]->colCount == 3);
              CPPUNIT_ASSERT(hmm->Pi->size == 10);
            }

            void testForward()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 5;
              components->data[1] = 3;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, components);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[0]->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 3; ++j)
                  hmm->B->data[1]->data[i][j] = i + j + 1;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->data[0]->makeStochastic();
              hmm->B->data[1]->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->resize(2, 30);
              seq->setMaxDistinctValues(dai);
              for (Integer i = 0; i < 30; ++i)
              {
                seq->data->data[0]->data[i] = i % 5;
                seq->data->data[1]->data[i] = i % 3;
              }

              Ref<DynamicMatrixOfDouble> alphaTildes = new DynamicMatrixOfDouble();
              alphaTildes->resize(30, 10);
              Ref<DynamicArrayOfDouble> rescalingCoefs = new DynamicArrayOfDouble();
              rescalingCoefs->resize(30);

              Double logp = forward(hmm.getPtr(), seq.getPtr(), alphaTildes.getPtr(),
                  rescalingCoefs.getPtr());
              CPPUNIT_ASSERT_DOUBLES_EQUAL(-82.076737213731, logp, 0.0001);
            }

            void testForward2()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 5;
              components->data[1] = 3;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, components);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[0]->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 3; ++j)
                  hmm->B->data[1]->data[i][j] = j == 0;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->data[0]->makeStochastic();
              hmm->B->data[1]->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->resize(2, 30);
              seq->setMaxDistinctValues(dai);
              for (Integer i = 0; i < 30; ++i)
              {
                seq->data->data[0]->data[i] = i % 5;
                seq->data->data[1]->data[i] = 0;
              }

              Ref<DynamicMatrixOfDouble> alphaTildes = new DynamicMatrixOfDouble();
              alphaTildes->resize(30, 10);
              Ref<DynamicArrayOfDouble> rescalingCoefs = new DynamicArrayOfDouble();
              rescalingCoefs->resize(30);

              Double logp = forward(hmm.getPtr(), seq.getPtr(), alphaTildes.getPtr(),
                  rescalingCoefs.getPtr());
              CPPUNIT_ASSERT_DOUBLES_EQUAL(-48.852186362466, logp, 0.0001);
            }

            void testFastForward()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 5;
              components->data[1] = 3;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, components);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[0]->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 3; ++j)
                  hmm->B->data[1]->data[i][j] = i + j + 1;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->data[0]->makeStochastic();
              hmm->B->data[1]->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->resize(2, 30);
              seq->setMaxDistinctValues(dai);
              for (Integer i = 0; i < 30; ++i)
              {
                seq->data->data[0]->data[i] = i % 5;
                seq->data->data[1]->data[i] = i % 3;
              }

              Double logp = fastForward(hmm.getPtr(), seq.getPtr());
              CPPUNIT_ASSERT_DOUBLES_EQUAL(-82.076737213731, logp, 0.0001);
            }

            void testBackward()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 5;
              components->data[1] = 3;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, components);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[0]->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 3; ++j)
                  hmm->B->data[1]->data[i][j] = i + j + 1;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->data[0]->makeStochastic();
              hmm->B->data[1]->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->resize(2, 30);
              seq->setMaxDistinctValues(dai);
              for (Integer i = 0; i < 30; ++i)
              {
                seq->data->data[0]->data[i] = i % 5;
                seq->data->data[1]->data[i] = i % 3;
              }

              Ref<DynamicMatrixOfDouble> alphaTildes = new DynamicMatrixOfDouble();
              alphaTildes->resize(30, 10);
              Ref<DynamicArrayOfDouble> rescalingCoefs = new DynamicArrayOfDouble();
              rescalingCoefs->resize(30);

              Double logp = forward(hmm.getPtr(), seq.getPtr(), alphaTildes.getPtr(),
                  rescalingCoefs.getPtr());

              Ref<DynamicMatrixOfDouble> betaTildes = new DynamicMatrixOfDouble();
              betaTildes->resize(30, 10);
              backward(hmm.getPtr(), seq.getPtr(), rescalingCoefs.getPtr(), betaTildes.getPtr());

              CPPUNIT_ASSERT_DOUBLES_EQUAL(-82.076737213731, logp, 0.0001);
            }

            void testBaumWelch()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 5;
              components->data[1] = 3;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, components);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[0]->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 3; ++j)
                  hmm->B->data[1]->data[i][j] = i + j + 1;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->data[0]->makeStochastic();
              hmm->B->data[1]->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->resize(2, 30);
              seq->setMaxDistinctValues(dai);
              for (Integer i = 0; i < 30; ++i)
              {
                seq->data->data[0]->data[i] = i % 5;
                seq->data->data[1]->data[i] = i % 3;
              }

              fastForward(hmm.getPtr(), seq.getPtr());

              Ref<DynamicHMM> newhmm = new DynamicHMM();
              newhmm->resize(10, dai);
              DynamicArrayOfBoolean * dab = new DynamicArrayOfBoolean();
              dab->resize(2);
              dab->data[0] = true;
              dab->data[1] = true;
              Ref<IArray<Boolean> > reevaluateB = dab;

              Double goodValues[10] =
              { -81.135901771049, -81.077533936765, -80.996432700948, -80.881430515268,
                  -80.718421899769, -80.488350040628, -80.165020874888, -79.705694131943,
                  -79.002581631379, -77.758496568221 };

              for (Integer nb = 1; nb <= 10; ++nb)
              {
                Double logbw = baumwelch(hmm.getPtr(), seq.getPtr(), nb, true, reevaluateB, true,
                    newhmm.getPtr());
                CPPUNIT_ASSERT_DOUBLES_EQUAL(goodValues[nb - 1], logbw, 0.0001);
              }

            }

            void testBaumWelch2()
            {
              DynamicArrayOfInteger * dai = new DynamicArrayOfInteger();
              dai->resize(2);
              Ref<IArray<Integer> > components = dai;
              components->data[0] = 5;
              components->data[1] = 3;

              Ref<DynamicHMM> hmm = new DynamicHMM();
              hmm->resize(10, components);
              for (Integer i = 0; i < 10; ++i)
              {
                for (Integer j = 0; j < 10; ++j)
                  hmm->A->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 5; ++j)
                  hmm->B->data[0]->data[i][j] = i + j + 1;
                for (Integer j = 0; j < 3; ++j)
                  hmm->B->data[1]->data[i][j] = j == 0;
                hmm->Pi->data[i] = i + 1;
              }
              hmm->A->makeStochastic();
              hmm->B->data[0]->makeStochastic();
              hmm->B->data[1]->makeStochastic();
              hmm->Pi->makeStochastic();

              Ref<DynamicSequenceOfObservations> seq = new DynamicSequenceOfObservations();
              seq->resize(2, 30);
              seq->setMaxDistinctValues(dai);
              for (Integer i = 0; i < 30; ++i)
              {
                seq->data->data[0]->data[i] = i % 5;
                seq->data->data[1]->data[i] = 0;
              }

              fastForward(hmm.getPtr(), seq.getPtr());

              Ref<DynamicHMM> newhmm = new DynamicHMM();
              newhmm->resize(10, dai);
              DynamicArrayOfBoolean * dab = new DynamicArrayOfBoolean();
              dab->resize(2);
              dab->data[0] = true;
              dab->data[1] = true;
              Ref<IArray<Boolean> > reevaluateB = dab;

              Double goodValues[10] =
              { -48.21779377925154364, -48.17846684636410259, -48.12232887599249409,
                  -48.04040938344959244, -47.91661762097253785, -47.71771933197934601,
                  -47.36788282290679319, -46.69331860257293698, -45.38149439201943380,
                  -43.25480413764215371 };

              for (Integer nb = 1; nb <= 10; ++nb)
              {
                Double logbw = baumwelch(hmm.getPtr(), seq.getPtr(), nb, true, reevaluateB, true,
                    newhmm.getPtr());
                CPPUNIT_ASSERT_DOUBLES_EQUAL(goodValues[nb - 1], logbw, 0.0001);
              }
            }

        };

        CPPUNIT_TEST_SUITE_REGISTRATION( HMMTest);
      }
    }
  }
}
