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

#ifndef HMMTK4J_JNI_Object_inlines_h
#define HMMTK4J_JNI_Object_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {

        HMMTK4J_INLINE Object::Object()
        {
          jenv = NULL;
          self = 0;
          id_class = 0;
        }

        HMMTK4J_INLINE Object::Object(const Object & _owner,
            const char * _fieldName, const char * _typeName)
        {
          init(_owner, _fieldName, _typeName);
        }

        HMMTK4J_INLINE Object::Object(JNIEnv * _jenv, jobject _self)
        {
          init(_jenv, _self);
        }

        HMMTK4J_INLINE void Object::copy(const Object & o)
        {
          jenv = o.jenv;
          self = o.self;
          id_class = o.id_class;
          id_class_Computed = o.id_class_Computed;
        }

        HMMTK4J_INLINE void Object::init(const Object & _owner,
            const char * _fieldName, const char * _typeName)
        {
          Field(_owner, _fieldName, _typeName).getObject(*this);
        }

        HMMTK4J_INLINE void Object::init(JNIEnv * _jenv, jobject _self)
        {
          jenv = _jenv;
          self = _self;
          HMMTK4J_JNIError(_self);
          id_class_Computed = false;
        }

        HMMTK4J_INLINE jclass Object::getClassId()
        {
          if (!id_class_Computed)
          {
            id_class = jenv->GetObjectClass(self);
            HMMTK4J_JNIError( id_class);
            id_class_Computed = true;
          }
          return id_class;
        }
      }
    }
  }
}

#endif

