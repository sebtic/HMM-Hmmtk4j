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

#ifndef HMMTK4J_JNI_ArrayOfBoolean_Java_h
#define HMMTK4J_JNI_ArrayOfBoolean_Java_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        class ArrayOfBoolean_Java: public IArrayOfBoolean
        {
          private:
            JNIEnv * jenv;
            jbooleanArray array;
            Boolean * buffer;
            bool initialized;
          public:
            /** The constructor */
            ArrayOfBoolean_Java();
            void initializeJNI(const Object & _self);
            ~ArrayOfBoolean_Java();
          private:
            ArrayOfBoolean_Java & operator=(const ArrayOfBoolean_Java &);
            ArrayOfBoolean_Java(const ArrayOfBoolean_Java &);
        };
      }
DECLARE_PROXY    ( ArrayOfBoolean_Java, IArrayOfBoolean, ::org::projectsforge::hmmtk4j::jni::ArrayOfBoolean_Java, "[Z");
  }}}

#endif
