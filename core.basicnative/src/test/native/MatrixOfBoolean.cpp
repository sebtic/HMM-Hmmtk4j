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
#include <org/projectsforge/hmmtk4j/IncludeAll.h>

#include <stdio.h>
#include <iostream>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      class MatrixOfBooleanTest: public CppUnit::TestFixture
      {
        public:
          CPPUNIT_TEST_SUITE( MatrixOfBooleanTest);
          CPPUNIT_TEST( testConstructor);
          CPPUNIT_TEST( testResize);
          CPPUNIT_TEST( testFill);
          CPPUNIT_TEST( testSetRow);
          CPPUNIT_TEST( testSetCol);
          CPPUNIT_TEST( testClear);
          CPPUNIT_TEST( testCopy);CPPUNIT_TEST_SUITE_END();

          void testConstructor()
          {
            Ref<DynamicMatrixOfBoolean> a = new DynamicMatrixOfBoolean();
            CPPUNIT_ASSERT(a->rowCount == 0 && a->colCount == 0);
          }

          void testResize()
          {
            Ref<DynamicMatrixOfBoolean> a = new DynamicMatrixOfBoolean();

            for (Integer i = 0; i < 100; ++i)
            {

              Integer s1 = randomGenerator->nextInt(1, 100);
              Integer s2 = randomGenerator->nextInt(1, 100);
              a->resize(s1, s2);
              CPPUNIT_ASSERT_EQUAL((Integer) a->rowCount, s1);
              CPPUNIT_ASSERT_EQUAL((Integer) a->colCount, s2);
              for (Integer j = 0; j < s1; ++j)
                for (Integer k = 0; k < s2; ++k)
                  a->data[j][k] = (Boolean)(j + k);
            }
          }

          void testFill()
          {
            Ref<DynamicMatrixOfBoolean> a = new DynamicMatrixOfBoolean();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s1 = randomGenerator->nextInt(1, 100);
              Integer s2 = randomGenerator->nextInt(1, 100);
              a->resize(s1, s2);
              a->fill((Boolean)(s1 + s2));
              for (Integer j = 0; j < s1; ++j)
                for (Integer k = 0; k < s2; ++k)
                  CPPUNIT_ASSERT_DOUBLES_EQUAL((Boolean)(s1 + s2),
                      a->data[j][k], 0.0001);
            }
          }

          void testSetRow()
          {
            Ref<DynamicMatrixOfBoolean> a = new DynamicMatrixOfBoolean();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s1 = randomGenerator->nextInt(1, 100);
              Integer s2 = randomGenerator->nextInt(1, 100);
              a->resize(s1, s2);

              Ref<DynamicArrayOfBoolean> val = new DynamicArrayOfBoolean();
              val->resize(s2);

              for (Integer j = 0; j < s1; ++j)
              {
                val->fill((Boolean) j);
                a->setRow(j, val.getPtr());
                for (Integer k = 0; k < s2; ++k)
                  CPPUNIT_ASSERT_EQUAL((Boolean) j, a->data[j][k]);
              }
            }
          }

          void testSetCol()
          {
            Ref<DynamicMatrixOfBoolean> a = new DynamicMatrixOfBoolean();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s1 = randomGenerator->nextInt(1, 100);
              Integer s2 = randomGenerator->nextInt(1, 100);
              a->resize(s1, s2);

              Ref<DynamicArrayOfBoolean> val = new DynamicArrayOfBoolean();
              val->resize(s1);

              for (Integer j = 0; j < s2; ++j)
              {
                val->fill((Boolean) j);
                a->setCol(j, val.getPtr());
                for (Integer k = 0; k < s1; ++k)
                  CPPUNIT_ASSERT_EQUAL((Boolean) j, a->data[k][j]);
              }
            }
          }

          void testClear()
          {
            Ref<DynamicMatrixOfBoolean> a = new DynamicMatrixOfBoolean();

            a->resize(100, 100);
            a->clear();
            CPPUNIT_ASSERT_EQUAL((int) a->rowCount, 0);
            CPPUNIT_ASSERT_EQUAL((int) a->colCount, 0);
          }

          void testCopy()
          {
            Ref<DynamicMatrixOfBoolean> a = new DynamicMatrixOfBoolean();
            Ref<DynamicMatrixOfBoolean> b = new DynamicMatrixOfBoolean();

            a->resize(10, 10);
            a->fill((Boolean) 10);
            b->resize(20, 20);
            b->fill((Boolean) 20);
            a->copy(b.getPtr());
            CPPUNIT_ASSERT_EQUAL((int) a->rowCount, 20);
            CPPUNIT_ASSERT_EQUAL((int) a->colCount, 20);
            for (Integer i = 0; i < 20; ++i)
              for (Integer j = 0; j < 20; ++j)
                CPPUNIT_ASSERT_EQUAL((Boolean) 20, a->data[i][j]);
          }
      };

      CPPUNIT_TEST_SUITE_REGISTRATION( MatrixOfBooleanTest);
    }
  }
}

