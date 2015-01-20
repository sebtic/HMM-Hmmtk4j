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

#ifndef HMMTK4J_Core_RandomGenerator_h
#define HMMTK4J_Core_RandomGenerator_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** The interface which represents a random generator. The definition is based on the java.lang.Random Java class */
      class RandomGenerator: public Referenced
      {
        public:
          /**
           * Returns the next pseudorandom, uniformly distributed \c Integer
           * value from this random number generator's sequence. The general
           * contract of \c nextInt is that one \c Integer value is
           * pseudorandomly generated and returned. All 2<sup>32
           * </sup> possible \c int values are produced with
           * (approximately) equal probability.
           * @return the next pseudorandom value
           */
          virtual Integer nextInt() = 0;
          /**
           * Returns a pseudorandom, uniformly distributed \c Integer value
           * between 0 (inclusive) and the specified value (exclusive), drawn from
           * this random number generator's sequence.
           * @param n the bound on the random number to be returned.  Must be positive.
           * @return the next pseudorandom value
           */
          virtual Integer nextInt(Integer n) = 0;
          /**
           * Returns the next pseudorandom, uniformly distributed
           * \c Boolean value from this random number generator's
           * sequence.
           * @return the next pseudorandom value
           */
          virtual Boolean nextBoolean() = 0;
          /**
           * Returns the next pseudorandom, uniformly distributed
           * \c Double value between  0.0 and
           * 1.0 from this random number generator's sequence.
           * @return the next pseudorandom, uniformly distributed \c double
           *         value between \c 0.0 and \c 1.0 from this
           *         random number generator's sequence
           */
          virtual Double nextDouble() = 0;
          /**
           * Returns the next pseudorandom, Gaussian ("normally") distributed
           * \c double value with mean 0.0 and standard
           * deviation 1.0 from this random number generator's sequence.
           * @return the next pseudorandom, Gaussian ("normally") distributed
           *         \c double value with mean \c 0.0 and
           *         standard deviation \c 1.0 from this random number
           *         generator's sequence
           */
          virtual Double nextGaussian() = 0;

          /** Returns a pseudorandom, uniformly distributed \¢ Integer value
           * between \c min_value (inclusive) and \c min_value (exclusive)
           * @param min_value the lower bound of the range
           * @param max_value the upper bound of the range
           * @return a random value in [min_value;max_value]
           */
          Integer nextInt(Integer min_value, Integer max_value);
      };

      /** Poor quality random generator based on standard \c rand() function. It's the default until Java code replaces it. */
      class BasicRandomGenerator: public RandomGenerator
      {
        private:
          Double nextNextGaussian;
          Boolean haveNextNextGaussian;
        public:
          BasicRandomGenerator();
          virtual Integer nextInt();
          virtual Integer nextInt(Integer n);
          virtual Boolean nextBoolean();
          virtual Double nextDouble();
          virtual Double nextGaussian();
      };

      /** The reference on the random generator instance */
      extern Ref<RandomGenerator> randomGenerator;
    }
  }
}
#endif

