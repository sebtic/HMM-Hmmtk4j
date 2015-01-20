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

#ifndef HMMTK4J_JNI_Proxy_H
#define HMMTK4J_JNI_Proxy_H

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {

#define DECLARE_PROXY_BEGIN( Name, CPPClass, JavaTypeName) \
    inline const char * Proxy_ ## Name ## _getJavaTypeName() \
    { \
      return JavaTypeName; \
    } \
    inline CPPClass * Proxy_ ## Name ## _getJavaObject( \
      const ::org::projectsforge::hmmtk4j::jni::Object & obj) \
    {

#define DECLARE_PROXY_END( Name, CPPClass, JavaTypeName) \
    } \
    inline CPPClass * Proxy_## Name ## _getJavaFieldObject( \
      const ::org::projectsforge::hmmtk4j::jni::Object & obj, \
      const char * fieldName) \
    { \
      ::org::projectsforge::hmmtk4j::jni::Field field(obj, fieldName, JavaTypeName); \
      ::org::projectsforge::hmmtk4j::jni::Object object; \
      field.getObject( object ); \
      return Proxy_ ## Name ## _getJavaObject(object); \
    }

#define DECLARE_PROXY( Name, CPPClass, JNIClass, JavaTypeName) \
    DECLARE_PROXY_BEGIN(Name, CPPClass, JavaTypeName) \
      JNIClass * instance = new JNIClass(); \
      instance->initializeJNI( obj ); \
      return instance; \
    DECLARE_PROXY_END(Name, CPPClass, JavaTypeName)

#define DECLARE_PROXY_NATIVE( Name, CPPClass, JNIClass, JavaTypeName ) \
    DECLARE_PROXY_BEGIN(Name, CPPClass, JavaTypeName) \
      ::org::projectsforge::hmmtk4j::jni::LongField nativeInstance( obj, "instance" ); \
      return (JNIClass*) nativeInstance.getValue(); \
    DECLARE_PROXY_END(Name, CPPClass, JavaTypeName)

      DECLARE_PROXY_NATIVE( DynamicArrayOfInteger,
          DynamicArrayOfInteger,
          DynamicArrayOfInteger,
          "Lorg/projectsforge/hmmtk4j/ArrayOfInteger;")
      ;

      DECLARE_PROXY_NATIVE( IArrayOfInteger,
          IArrayOfInteger,
          DynamicArrayOfInteger,
          "Lorg/projectsforge/hmmtk4j/ArrayOfInteger;")
      ;

      DECLARE_PROXY_NATIVE( DynamicArrayOfDouble,
          DynamicArrayOfDouble,
          DynamicArrayOfDouble,
          "Lorg/projectsforge/hmmtk4j/ArrayOfDouble;")
      ;

      DECLARE_PROXY_NATIVE( IArrayOfDouble,
          IArrayOfDouble,
          DynamicArrayOfDouble,
          "Lorg/projectsforge/hmmtk4j/ArrayOfDouble;")
      ;

      DECLARE_PROXY_NATIVE( DynamicArrayOfBoolean,
          DynamicArrayOfBoolean,
          DynamicArrayOfBoolean,
          "Lorg/projectsforge/hmmtk4j/ArrayOfBoolean;")
      ;

      DECLARE_PROXY_NATIVE( IArrayOfBoolean,
          IArrayOfBoolean,
          DynamicArrayOfBoolean,
          "Lorg/projectsforge/hmmtk4j/ArrayOfBoolean;")
      ;

      DECLARE_PROXY_NATIVE( DynamicMatrixOfInteger,
          DynamicMatrixOfInteger,
          DynamicMatrixOfInteger,
          "Lorg/projectsforge/hmmtk4j/MatrixOfInteger;")
      ;

      DECLARE_PROXY_NATIVE( IMatrixOfInteger,
          IMatrixOfInteger,
          DynamicMatrixOfInteger,
          "Lorg/projectsforge/hmmtk4j/MatrixOfInteger;")
      ;

      DECLARE_PROXY_NATIVE( DynamicMatrixOfDouble,
          DynamicMatrixOfDouble,
          DynamicMatrixOfDouble,
          "Lorg/projectsforge/hmmtk4j/MatrixOfDouble;")
      ;

      DECLARE_PROXY_NATIVE( IMatrixOfDouble,
          IMatrixOfDouble,
          DynamicMatrixOfDouble,
          "Lorg/projectsforge/hmmtk4j/MatrixOfDouble;")
      ;

      DECLARE_PROXY_NATIVE( DynamicMatrixOfBoolean,
          DynamicMatrixOfBoolean,
          DynamicMatrixOfBoolean,
          "Lorg/projectsforge/hmmtk4j/MatrixOfBoolean;")
      ;

      DECLARE_PROXY_NATIVE( IMatrixOfBoolean,
          IMatrixOfBoolean,
          DynamicMatrixOfBoolean,
          "Lorg/projectsforge/hmmtk4j/MatrixOfBoolean;")
      ;
    }
  }
}

#endif

