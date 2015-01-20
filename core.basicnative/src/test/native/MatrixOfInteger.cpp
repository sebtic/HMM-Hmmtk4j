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
      class MatrixOfIntegerTest: public CppUnit::TestFixture
      {
        public:
          CPPUNIT_TEST_SUITE( MatrixOfIntegerTest);
          CPPUNIT_TEST( testConstructor);
          CPPUNIT_TEST( testResize);
          CPPUNIT_TEST( testFill);
          CPPUNIT_TEST( testSetRow);
          CPPUNIT_TEST( testSetCol);
          CPPUNIT_TEST( testClear);
          CPPUNIT_TEST( testCopy);CPPUNIT_TEST_SUITE_END();

          void testConstructor()
          {
            Ref<DynamicMatrixOfInteger> a = new DynamicMatrixOfInteger();
            CPPUNIT_ASSERT(a->rowCount == 0 && a->colCount == 0);
          }

          void testResize()
          {
            Ref<DynamicMatrixOfInteger> a = new DynamicMatrixOfInteger();

            for (Integer i = 0; i < 100; ++i)
            {

              Integer s1 = randomGenerator->nextInt(1, 100);
              Integer s2 = randomGenerator->nextInt(1, 100);
              a->resize(s1, s2);
              CPPUNIT_ASSERT_EQUAL((Integer) a->rowCount, s1);
              CPPUNIT_ASSERT_EQUAL((Integer) a->colCount, s2);
              for (Integer j = 0; j < s1; ++j)
                for (Integer k = 0; k < s2; ++k)
                  a->data[j][k] = (Integer)(j + k);
            }
          }

          void testFill()
          {
            Ref<DynamicMatrixOfInteger> a = new DynamicMatrixOfInteger();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s1 = randomGenerator->nextInt(1, 100);
              Integer s2 = randomGenerator->nextInt(1, 100);
              a->resize(s1, s2);
              a->fill((Integer)(s1 + s2));
              for (Integer j = 0; j < s1; ++j)
                for (Integer k = 0; k < s2; ++k)
                  CPPUNIT_ASSERT_DOUBLES_EQUAL((Integer)(s1 + s2),
                      a->data[j][k], 0.0001);
            }
          }

          void testSetRow()
          {
            Ref<DynamicMatrixOfInteger> a = new DynamicMatrixOfInteger();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s1 = randomGenerator->nextInt(1, 100);
              Integer s2 = randomGenerator->nextInt(1, 100);
              a->resize(s1, s2);

              Ref<DynamicArrayOfInteger> val = new DynamicArrayOfInteger();
              val->resize(s2);

              for (Integer j = 0; j < s1; ++j)
              {
                val->fill((Integer) j);
                a->setRow(j, val.getPtr());
                for (Integer k = 0; k < s2; ++k)
                  CPPUNIT_ASSERT_DOUBLES_EQUAL((Integer) j, a->data[j][k],
                      0.0001);
              }
            }
          }

          void testSetCol()
          {
            Ref<DynamicMatrixOfInteger> a = new DynamicMatrixOfInteger();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s1 = randomGenerator->nextInt(1, 100);
              Integer s2 = randomGenerator->nextInt(1, 100);
              a->resize(s1, s2);

              Ref<DynamicArrayOfInteger> val = new DynamicArrayOfInteger();
              val->resize(s1);

              for (Integer j = 0; j < s2; ++j)
              {
                val->fill((Integer) j);
                a->setCol(j, val.getPtr());
                for (Integer k = 0; k < s1; ++k)
                  CPPUNIT_ASSERT_DOUBLES_EQUAL((Integer) j, a->data[k][j],
                      0.0001);
              }
            }
          }

          void testClear()
          {
            Ref<DynamicMatrixOfInteger> a = new DynamicMatrixOfInteger();

            a->resize(100, 100);
            a->clear();
            CPPUNIT_ASSERT_EQUAL((int) a->rowCount, 0);
            CPPUNIT_ASSERT_EQUAL((int) a->colCount, 0);
          }

          void testCopy()
          {
            Ref<DynamicMatrixOfInteger> a = new DynamicMatrixOfInteger();
            Ref<DynamicMatrixOfInteger> b = new DynamicMatrixOfInteger();

            a->resize(10, 10);
            a->fill((Integer) 10);
            b->resize(20, 20);
            b->fill((Integer) 20);
            a->copy(b.getPtr());
            CPPUNIT_ASSERT_EQUAL((int) a->rowCount, 20);
            CPPUNIT_ASSERT_EQUAL((int) a->colCount, 20);
            for (Integer i = 0; i < 20; ++i)
              for (Integer j = 0; j < 20; ++j)
                CPPUNIT_ASSERT_DOUBLES_EQUAL((Integer) 20, a->data[i][j],
                    0.0001);
          }
      };

      CPPUNIT_TEST_SUITE_REGISTRATION( MatrixOfIntegerTest);
    }
  }
}

