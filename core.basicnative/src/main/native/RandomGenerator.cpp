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

#include <org/projectsforge/hmmtk4j/IncludeAll.h>

#ifndef HMMTK4J_FULL_INLINING
#include <org/projectsforge/hmmtk4j/RandomGenerator_inlines.h>
#endif

#include <time.h>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      BasicRandomGenerator::BasicRandomGenerator()
      {
        srand((unsigned int) time(NULL));
        haveNextNextGaussian = false;
      }

      Integer BasicRandomGenerator::nextInt()
      {
        return rand();
      }
      Integer BasicRandomGenerator::nextInt(Integer n)
      {
        return (Integer)(rand() * (n / (RAND_MAX + 1.)));
      }
      Boolean BasicRandomGenerator::nextBoolean()
      {
        return rand() % 2 == 0;
      }
      Double BasicRandomGenerator::nextDouble()
      {
        return rand() / (RAND_MAX + 1.);
      }
      Double BasicRandomGenerator::nextGaussian()
      {
        // implementation based on code from java.util.Random.nextGaussian method
        if (haveNextNextGaussian)
        {
          haveNextNextGaussian = false;
          return nextNextGaussian;
        }
        else
        {
          Double v1, v2, s;
          do
          {
            v1 = 2 * nextDouble() - 1; // between -1 and 1
            v2 = 2 * nextDouble() - 1; // between -1 and 1
            s = v1 * v1 + v2 * v2;
          }
          while (s >= 1 || s < Math::NULL_VALUE);
          Double multiplier = Math::sqrt(-2 * Math::log(s) / s);
          nextNextGaussian = v2 * multiplier;
          haveNextNextGaussian = true;
          return v1 * multiplier;
        }
      }

      Ref<RandomGenerator> randomGenerator = new BasicRandomGenerator();
    }
  }
}
