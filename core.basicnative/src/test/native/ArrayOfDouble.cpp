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
      class ArrayOfDoubleTest: public CppUnit::TestFixture
      {
        public:
          CPPUNIT_TEST_SUITE( ArrayOfDoubleTest);
          CPPUNIT_TEST( testConstructor);
          CPPUNIT_TEST( testResize);
          CPPUNIT_TEST( testFill);
          CPPUNIT_TEST( testPushBack);
          CPPUNIT_TEST( testPushFront);
          CPPUNIT_TEST( testClear);
          CPPUNIT_TEST( testInsert);
          CPPUNIT_TEST( testErase);
          CPPUNIT_TEST( testCopy);CPPUNIT_TEST_SUITE_END();

          void testConstructor()
          {
            {
              Ref<DynamicArrayOfDouble> a = new DynamicArrayOfDouble();
              CPPUNIT_ASSERT(a->size == 0);
            }
          }

          void testResize()
          {
            Ref<DynamicArrayOfDouble> a = new DynamicArrayOfDouble();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s = randomGenerator->nextInt(1, 1000);
              a->resize(s);
              CPPUNIT_ASSERT_EQUAL((Integer) a->size, s);
              for (Integer j = 0; j < a->size; ++j)
                a->data[j] = (Double) j;
            }
          }

          void testFill()
          {
            Ref<DynamicArrayOfDouble> a = new DynamicArrayOfDouble();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s = randomGenerator->nextInt(1, 1000);
              a->resize(s);
              a->fill((Double) s);
              for (Integer j = 0; j < s; ++j)
                CPPUNIT_ASSERT_DOUBLES_EQUAL((Double) s, a->data[j], 0.0001);
            }
          }

          void testPushBack()
          {
            Ref<DynamicArrayOfDouble> a = new DynamicArrayOfDouble();

            for (Integer i = 0; i < 100; ++i)
              a->pushBack((Double) i);

            for (Integer i = 0; i < 100; ++i)
              CPPUNIT_ASSERT_DOUBLES_EQUAL((Double) i, a->data[i], 0.0001);
          }

          void testPushFront()
          {
            Ref<DynamicArrayOfDouble> a = new DynamicArrayOfDouble();

            for (Integer i = 0; i < 100; ++i)
              a->pushFront((Double) i);

            for (Integer i = 0; i < 100; ++i)
              CPPUNIT_ASSERT_DOUBLES_EQUAL((Double) 99 - i, a->data[i], 0.0001);
            printf("\n");
          }

          void testClear()
          {
            Ref<DynamicArrayOfDouble> a = new DynamicArrayOfDouble();

            a->resize(100);
            a->clear();
            CPPUNIT_ASSERT_EQUAL((int) a->size, (int) 0);
          }

          void testCopy()
          {
            Ref<DynamicArrayOfDouble> a = new DynamicArrayOfDouble();
            Ref<DynamicArrayOfDouble> b = new DynamicArrayOfDouble();

            a->resize(10);
            a->fill((Double) 10);
            b->resize(20);
            b->fill((Double) 20);
            a->copy(b.getPtr());

            CPPUNIT_ASSERT_EQUAL((int) a->size, (int) 20);
            for (Integer i = 0; i < 20; ++i)
              CPPUNIT_ASSERT_DOUBLES_EQUAL((Double) 20, a->data[i], 0.0001);
          }

          void testErase()
          {
            Ref<DynamicArrayOfDouble> a = new DynamicArrayOfDouble();

            for (Integer i = 0; i < 10; ++i)
              a->pushBack((Double) i);

            for (Integer i = 9; i >= 0; i -= 2)
              a->erase(i);

            for (int i = 0; i < 5; ++i)
              CPPUNIT_ASSERT_DOUBLES_EQUAL(a->data[i], (Double) 2 * i, 0.01);

            for (int i = 0; i < 5000; ++i)
            {
              Integer p = randomGenerator->nextInt(a->size);
              a->erase(p);
              a->pushBack(i);
            }
          }

          void testInsert()
          {
            Ref<DynamicArrayOfDouble> a = new DynamicArrayOfDouble();

            for (int i = 1; i < 10; ++i)
              a->insert(i - 1, i);

            for (int i = 0; i < 10; ++i)
              a->insert(0, -i);

            for (int i = 0; i < 19; ++i)
              CPPUNIT_ASSERT_DOUBLES_EQUAL(a->data[i], (Double)(i - 9), 0.01);
          }
      };

      CPPUNIT_TEST_SUITE_REGISTRATION( ArrayOfDoubleTest);
    }
  }
}

