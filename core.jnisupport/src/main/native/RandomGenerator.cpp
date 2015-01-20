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

#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {

        RandomGenerator::RandomGenerator(JNIEnv * _jenv, jobject generator)
        {
          this->jenv = _jenv;

          globalRefGenerator = jenv->NewGlobalRef(generator);
          HMMTK4J_JNIError( globalRefGenerator);

          jclass localRefClass = jenv->GetObjectClass(globalRefGenerator);
          HMMTK4J_JNIError(localRefClass);

          /** public int nextInt(); Signature: ()I */
          nextIntMethodId = jenv->GetMethodID(localRefClass, "nextInt", "()I");
          HMMTK4J_JNIError( nextIntMethodId);

          /** public int nextInt(int); Signature: (I)I */
          nextInt2MethodId
              = jenv->GetMethodID(localRefClass, "nextInt", "(I)I");
          HMMTK4J_JNIError( nextInt2MethodId);

          /** public boolean nextBoolean(); Signature: ()Z */
          nextBooleanMethodId = jenv->GetMethodID(localRefClass, "nextBoolean",
              "()Z");
          HMMTK4J_JNIError( nextBooleanMethodId);

          /** public double nextDouble(); Signature: ()D */
          nextDoubleMethodId = jenv->GetMethodID(localRefClass, "nextDouble",
              "()D");
          HMMTK4J_JNIError( nextDoubleMethodId);

          /** public synchronized double nextGaussian(); Signature: ()D */
          nextGaussianMethodId = jenv->GetMethodID(localRefClass,
              "nextGaussian", "()D");
          HMMTK4J_JNIError( nextGaussianMethodId);
        }

        RandomGenerator::~RandomGenerator()
        {
          if (globalRefGenerator != 0)
            jenv->DeleteGlobalRef(globalRefGenerator);
        }

        Integer RandomGenerator::nextInt()
        {
          return jenv->CallIntMethod(globalRefGenerator, nextIntMethodId);
        }
        Integer RandomGenerator::nextInt(Integer n)
        {
          return jenv->CallIntMethod(globalRefGenerator, nextInt2MethodId,
              (jint) n);
        }
        Boolean RandomGenerator::nextBoolean()
        {
          return jenv->CallBooleanMethod(globalRefGenerator,
              nextBooleanMethodId);
        }
        Double RandomGenerator::nextDouble()
        {
          return jenv->CallDoubleMethod(globalRefGenerator, nextDoubleMethodId);
        }
        Double RandomGenerator::nextGaussian()
        {
          return jenv->CallDoubleMethod(globalRefGenerator,
              nextGaussianMethodId);
        }

        RandomGenerator & RandomGenerator::operator=(const RandomGenerator &)
        {
          return *this;
        }

        RandomGenerator::RandomGenerator(const RandomGenerator &)
        {
        }
      }
    }
  }
}
