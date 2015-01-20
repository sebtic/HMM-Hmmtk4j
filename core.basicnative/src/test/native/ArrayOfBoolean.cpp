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
      class ArrayOfBooleanTest: public CppUnit::TestFixture
      {
        public:
          CPPUNIT_TEST_SUITE( ArrayOfBooleanTest);
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
              Ref<DynamicArrayOfBoolean> a = new DynamicArrayOfBoolean();
              CPPUNIT_ASSERT(a->size == 0);
            }
          }

          void testResize()
          {
            Ref<DynamicArrayOfBoolean> a = new DynamicArrayOfBoolean();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s = randomGenerator->nextInt(1, 1000);
              a->resize(s);
              CPPUNIT_ASSERT_EQUAL((Integer) a->size, s);
              for (Integer j = 0; j < a->size; ++j)
                a->data[j] = (Boolean) j;
            }
          }

          void testFill()
          {
            Ref<DynamicArrayOfBoolean> a = new DynamicArrayOfBoolean();

            for (Integer i = 0; i < 100; ++i)
            {
              Integer s = randomGenerator->nextInt(1, 1000);
              a->resize(s);
              a->fill((Boolean) s);
              for (Integer j = 0; j < s; ++j)
                CPPUNIT_ASSERT_DOUBLES_EQUAL((Boolean) s, a->data[j], 0.0001);
            }
          }

          void testPushBack()
          {
            Ref<DynamicArrayOfBoolean> a = new DynamicArrayOfBoolean();

            for (Integer i = 0; i < 100; ++i)
              a->pushBack((Boolean) i);

            for (Integer i = 0; i < 100; ++i)
              CPPUNIT_ASSERT_DOUBLES_EQUAL((Boolean) i, a->data[i], 0.0001);
          }

          void testPushFront()
          {
            Ref<DynamicArrayOfBoolean> a = new DynamicArrayOfBoolean();

            for (Integer i = 0; i < 100; ++i)
              a->pushFront((Boolean) i);

            for (Integer i = 0; i < 100; ++i)
              CPPUNIT_ASSERT_DOUBLES_EQUAL((Boolean) 99 - i, a->data[i], 0.0001);
            printf("\n");
          }

          void testClear()
          {
            Ref<DynamicArrayOfBoolean> a = new DynamicArrayOfBoolean();

            a->resize(100);
            a->clear();
            CPPUNIT_ASSERT_EQUAL((int) a->size, (int) 0);
          }

          void testCopy()
          {
            Ref<DynamicArrayOfBoolean> a = new DynamicArrayOfBoolean();
            Ref<DynamicArrayOfBoolean> b = new DynamicArrayOfBoolean();

            a->resize(10);
            a->fill((Boolean) 10);
            b->resize(20);
            b->fill((Boolean) 20);
            a->copy(b.getPtr());

            CPPUNIT_ASSERT_EQUAL((int) a->size, (int) 20);
            for (Integer i = 0; i < 20; ++i)
              CPPUNIT_ASSERT_DOUBLES_EQUAL((Boolean) 20, a->data[i], 0.0001);
          }

          void testErase()
          {
            Ref<DynamicArrayOfBoolean> a = new DynamicArrayOfBoolean();

            for (Integer i = 0; i < 10; ++i)
              a->pushBack((Boolean) i);

            for (Integer i = 9; i >= 0; i -= 2)
              a->erase(i);

            for (int i = 0; i < 5; ++i)
              CPPUNIT_ASSERT_DOUBLES_EQUAL(a->data[i], (Boolean) 2 * i, 0.01);

            for (int i = 0; i < 5000; ++i)
            {
              Integer p = randomGenerator->nextInt(a->size);
              a->erase(p);
              a->pushBack((Boolean) i);
            }
          }

          void testInsert()
          {
            Ref<DynamicArrayOfBoolean> a = new DynamicArrayOfBoolean();

            for (int i = 1; i < 10; ++i)
              a->insert(i - 1, (Boolean) i);

            for (int i = 0; i < 10; ++i)
              a->insert(0, (Boolean) - i);

            for (int i = 0; i < 19; ++i)
              CPPUNIT_ASSERT(a->data[i] == (Boolean)(i - 9));
          }
      };

      CPPUNIT_TEST_SUITE_REGISTRATION( ArrayOfBooleanTest);
    }
  }
}
