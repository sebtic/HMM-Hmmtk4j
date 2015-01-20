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
      class DummyTest: public Referenced
      {
        public:
        static int created;
        public:
        DummyTest()
        {
          created++;
        }
        ~DummyTest()
        {
          created--;
        }
      };

      int DummyTest::created = 0;

      class RefTest: public CppUnit::TestFixture
      {
        public:
        CPPUNIT_TEST_SUITE( RefTest);

        CPPUNIT_TEST( testRef);

        CPPUNIT_TEST_SUITE_END();

        void testRef()
        {
          Ref<DummyTest> first = new DummyTest();
          Ref<DummyTest> second = new DummyTest();
          Ref<DummyTest> third = new DummyTest();

          CPPUNIT_ASSERT_EQUAL(3, DummyTest::created);
          third = second;
          CPPUNIT_ASSERT_EQUAL(2, DummyTest::created);
          second = NULL;
          CPPUNIT_ASSERT_EQUAL(2, DummyTest::created);
          first = third;
          CPPUNIT_ASSERT_EQUAL(1, DummyTest::created);
          first = NULL;
          third = NULL;
          CPPUNIT_ASSERT_EQUAL(0, DummyTest::created);
        }

      };

      CPPUNIT_TEST_SUITE_REGISTRATION( RefTest);
    }
  }
}

