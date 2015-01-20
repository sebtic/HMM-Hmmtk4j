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

#ifndef HMMTK4J_JNI_ArrayOfDouble_Java_h
#define HMMTK4J_JNI_ArrayOfDouble_Java_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        class ArrayOfDouble_Java: public IArrayOfDouble
        {
          private:
            JNIEnv * jenv;
            jdoubleArray array;
            Double * buffer;
            bool initialized;
          public:
            /** The constructor */
            ArrayOfDouble_Java();
            void initializeJNI(const Object & _self);
            ~ArrayOfDouble_Java();
          private:
            ArrayOfDouble_Java & operator=(const ArrayOfDouble_Java &);
            ArrayOfDouble_Java(const ArrayOfDouble_Java &);
        };
      }
DECLARE_PROXY    ( ArrayOfDouble_Java, IArrayOfDouble, ::org::projectsforge::hmmtk4j::jni::ArrayOfDouble_Java, "[D");
  }}}

#endif
