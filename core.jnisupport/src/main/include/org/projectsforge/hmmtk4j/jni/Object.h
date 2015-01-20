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

#ifndef HMMTK4J_JNI_Object_h
#define HMMTK4J_JNI_Object_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        /** A class that represent a Java instance */
        class Object
        {
          public:
            /** The JNIEnv pointer */
            JNIEnv * jenv;
            /** The jobject identifier that represent the instance */
            jobject self;
          private:
            /** The jclass identifier of the class of the instance */
            jclass id_class;
            /** A boolean indicating if the jclass identifier of the instance has already been computed */
            Boolean id_class_Computed;
          public:
            /** A constructor
             *
             * @param _jenv the JNIEnv pointer
             * @param _self the jobject identifier of the instance
             */
            Object(JNIEnv * _jenv, jobject _self);

            /** A constructor to access field of an instance
             *
             * @param _owner the owner instance
             * @param _fieldName the field name
             * @param _typeName the type name of the field according to JNI notation
             * @return
             */
            Object(const Object & _owner, const char * _fieldName,
                const char * _typeName);

            /** A constructor */
            Object();

            /** The copy an Object
             *
             * @param o the Object instance to copy
             */
            void copy(const Object & o);

            /** Initialize the object from a jobject identifier
             *
             * @param _jenv the JNIENV pointer
             * @param _self the jobject identifier of the Java instance
             */
            void init(JNIEnv * _jenv, jobject _self);

            /** Initialize the object as the field of a Java instance
             *
             * @param _owner the owner instance
             * @param _fieldName the field name
             * @param _typeName the type name of the field according to JNI notation
             */
            void init(const Object & _owner, const char * _fieldName,
                const char * _typeName);
            jclass getClassId();

          private:
            /** The copy operator
             *
             * @param o the Object instance to copy
             */
            Object & operator=(const Object & o);

            /** A copy constructor
             *
             * @param o the Object instance to copy
             */
            Object(const Object & o);
        };
      }
    }
  }
}

#endif
