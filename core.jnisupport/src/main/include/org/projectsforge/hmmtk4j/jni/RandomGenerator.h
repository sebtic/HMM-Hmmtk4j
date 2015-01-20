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

#ifndef HMMTK4J_JNI_RandomGenerator_H
#define HMMTK4J_JNI_RandomGenerator_H

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        class RandomGenerator: public hmmtk4j::RandomGenerator
        {
          private:
            jobject globalRefGenerator;
            jmethodID nextIntMethodId;
            jmethodID nextInt2MethodId;
            jmethodID nextBooleanMethodId;
            jmethodID nextDoubleMethodId;
            jmethodID nextGaussianMethodId;
            JNIEnv * jenv;
          public:
            RandomGenerator(JNIEnv * jenv, jobject generator);
            virtual ~RandomGenerator();
            virtual Integer nextInt();
            virtual Integer nextInt(Integer n);
            virtual Boolean nextBoolean();
            virtual Double nextDouble();
            virtual Double nextGaussian();
          private:
            RandomGenerator & operator=(const RandomGenerator &);
            RandomGenerator(const RandomGenerator &);
        };
      }
    }
  }
}
#endif
