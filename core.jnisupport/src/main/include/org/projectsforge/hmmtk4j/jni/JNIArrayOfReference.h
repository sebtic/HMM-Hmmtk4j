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

#ifndef HMMTK4J_JNI_ArrayOfReference_H
#define HMMTK4J_JNI_ArrayOfReference_H

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {

#define DECLARE_JNIArrayOfReference( Name, ReferencedClass, ReferencedProxyName, JavaTypeName ) \
    class Proxy_ ## Name ## _JNIArrayOfReference : public org::projectsforge::hmmtk4j::ArrayOfReference< ReferencedClass > \
    { \
      public: \
        Proxy_ ## Name ## _JNIArrayOfReference() \
        { \
          ; \
        } \
        void initializeJNI(const ::org::projectsforge::hmmtk4j::jni::Object & _self) \
        { \
          jobjectArray joa = (jobjectArray) _self.self; \
          Integer len = _self.jenv->GetArrayLength( joa ); \
          this->resize( len, false ); \
          for( Integer i = 0; i < len; ++i ) \
          { \
            org::projectsforge::hmmtk4j::jni::Object obj( _self.jenv, _self.jenv->GetObjectArrayElement( joa, i ) ); \
            this->data[i] = Proxy_ ## ReferencedProxyName ## _getJavaObject( obj ); \
          } \
        } \
      private: \
        Proxy_ ## Name ## _JNIArrayOfReference & operator=(const Proxy_ ## Name ## _JNIArrayOfReference &) \
        { \
          return *this; \
        } \
        Proxy_ ## Name ## _JNIArrayOfReference(const Proxy_ ## Name ## _JNIArrayOfReference &) \
        { \
          ; \
        } \
    }; \
    DECLARE_PROXY( Name, Proxy_ ## Name ## _JNIArrayOfReference, Proxy_ ## Name ## _JNIArrayOfReference, JavaTypeName)

    DECLARE_JNIArrayOfReference( ArrayOfIMatrixOfDouble, IMatrixOfDouble, IMatrixOfDouble, "[Lorg/projectsforge/hmmtk4j/MatrixOfDouble;" );
    DECLARE_JNIArrayOfReference( ArrayOfIMatrixOfBoolean, IMatrixOfBoolean, IMatrixOfBoolean, "[Lorg/projectsforge/hmmtk4j/MatrixOfBoolean;" );
    DECLARE_JNIArrayOfReference( ArrayOfIMatrixOfInteger, IMatrixOfInteger, IMatrixOfInteger, "[Lorg/projectsforge/hmmtk4j/MatrixOfInteger;" );
    DECLARE_JNIArrayOfReference( ArrayOfIArrayOfDouble, IArrayOfDouble, IArrayOfDouble, "[Lorg/projectsforge/hmmtk4j/ArrayOfDouble;" );
    DECLARE_JNIArrayOfReference( ArrayOfIArrayOfBoolean, IArrayOfBoolean, IArrayOfBoolean, "[Lorg/projectsforge/hmmtk4j/ArrayOfBoolean;" );
    DECLARE_JNIArrayOfReference( ArrayOfIArrayOfInteger, IArrayOfInteger, IArrayOfInteger, "[Lorg/projectsforge/hmmtk4j/ArrayOfInteger;" );

    DECLARE_JNIArrayOfReference( ArrayOfDynamicMatrixOfDouble, DynamicMatrixOfDouble, DynamicMatrixOfDouble, "[Lorg/projectsforge/hmmtk4j/MatrixOfDouble;" );
    DECLARE_JNIArrayOfReference( ArrayOfDynamicMatrixOfBoolean, DynamicMatrixOfBoolean, DynamicMatrixOfBoolean, "[Lorg/projectsforge/hmmtk4j/MatrixOfBoolean;" );
    DECLARE_JNIArrayOfReference( ArrayOfDynamicMatrixOfInteger, DynamicMatrixOfInteger, DynamicMatrixOfInteger, "[Lorg/projectsforge/hmmtk4j/MatrixOfInteger;" );
    DECLARE_JNIArrayOfReference( ArrayOfDynamicArrayOfDouble, DynamicArrayOfDouble, DynamicArrayOfDouble, "[Lorg/projectsforge/hmmtk4j/ArrayOfDouble;" );
    DECLARE_JNIArrayOfReference( ArrayOfDynamicArrayOfBoolean, DynamicArrayOfBoolean, DynamicArrayOfBoolean, "[Lorg/projectsforge/hmmtk4j/ArrayOfBoolean;" );
    DECLARE_JNIArrayOfReference( ArrayOfDynamicArrayOfInteger, DynamicArrayOfInteger, DynamicArrayOfInteger, "[Lorg/projectsforge/hmmtk4j/ArrayOfInteger;" );
      }
    }
  }
}

#endif
