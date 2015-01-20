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

#ifndef HMMTK4J_JNI_ArrayOfBoolean_Java_inlines_h
#define HMMTK4J_JNI_ArrayOfBoolean_Java_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        HMMTK4J_INLINE ArrayOfBoolean_Java::ArrayOfBoolean_Java()
        {
          jenv = NULL;
          array = 0;
          buffer = NULL;
          initialized = false;
        }
        HMMTK4J_INLINE void ArrayOfBoolean_Java::initializeJNI(
            const Object & _self)
        {
          jenv = _self.jenv;
          array = jbooleanArray(_self.self);
          buffer = jenv->GetBooleanArrayElements(array, 0);
          initialized = true;
          this->update(jenv->GetArrayLength(array), buffer);
        }
        HMMTK4J_INLINE ArrayOfBoolean_Java::~ArrayOfBoolean_Java()
        {
          if (initialized)
            jenv->ReleaseBooleanArrayElements(array, buffer, 0);
        }
      }
    }
  }
}

#endif
