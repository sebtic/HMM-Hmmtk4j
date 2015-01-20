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

#include <org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean.h>
#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;

#ifdef __cplusplus
extern "C"
{
#endif
  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
   * Method:    nativeClear
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_clear
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfBoolean*)instance)->clear();
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
   * Method:    nativeCopy
   * Signature: (JJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_copy
  (JNIEnv * jenv, jclass, jlong instance, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfBoolean*)instance)->copy( (DynamicArrayOfBoolean*)value );
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
   * Method:    nativeDeleteInstance
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_deleteInstance
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    Referenced::releaseReference((DynamicArrayOfBoolean*)instance);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_org_projectsforge_nativeimplementors_ArrayOfBoolean
   * Method:    nativeErase
   * Signature: (JI)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_erase
  (JNIEnv * jenv, jclass, jlong instance, jint index)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfBoolean*)instance)->erase(index);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
   * Method:    nativeFill
   * Signature: (JZ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_fill
  (JNIEnv * jenv, jclass, jlong instance, jboolean value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfBoolean*)instance)->fill( value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
   * Method:    nativeGetCount
   * Signature: (J)I
   */
  JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_getCount(
      JNIEnv * jenv, jclass, jlong instance)
  {
HMMTK4J_JNI_TRY  return ((DynamicArrayOfBoolean*)instance)->size;
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativeGetElement
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_getElement
(JNIEnv * jenv, jclass, jlong instance, jint index)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(index,0,((DynamicArrayOfBoolean*)instance)->size-1);
  return ((DynamicArrayOfBoolean*)instance)->data[index];
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativeInsert
 * Signature: (JIZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_insert
(JNIEnv * jenv, jclass, jlong instance, jint index, jboolean value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfBoolean*)instance)->insert(index, value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativeInsertArray
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_insertArray
(JNIEnv * jenv, jclass, jlong instance, jint index, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfBoolean*)instance)->insert(index, (DynamicArrayOfBoolean*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativeIsValidMask
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_isValidMask
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfBoolean*)instance)->isValidMask();
  HMMTK4J_JNI_CATCH
  return true;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativeNewInstance
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_newInstance
(JNIEnv * jenv, jclass)
{
  jlong instance = 0;
  HMMTK4J_JNI_TRY
  DynamicArrayOfBoolean * ptr = new DynamicArrayOfBoolean();
  Referenced::takeReference(ptr);
  instance = (jlong)ptr;
  if (ptr == NULL)
  {
    org::projectsforge::hmmtk4j::IllegalArgumentException __e( "Can not create a native instance");
    HMMTK4J_RaiseException(__e);
  }
  HMMTK4J_JNI_CATCH
  return instance;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativePushBack
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_pushBack
(JNIEnv * jenv, jclass, jlong instance, jboolean value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfBoolean*)instance)->pushBack(value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativePushBackArray
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_pushBackArray
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfBoolean*)instance)->pushBack( (DynamicArrayOfBoolean*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativePushFront
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_pushFront
(JNIEnv * jenv, jclass, jlong instance, jboolean value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfBoolean*)instance)->pushFront(value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativePushFrontArray
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_pushFrontArray
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfBoolean*)instance)->pushFront( (DynamicArrayOfBoolean*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativeReserve
 * Signature: (JIZZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_reserve
(JNIEnv * jenv, jclass, jlong instance, jint newSize, jboolean preserveContent, jboolean reduceMemory)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfBoolean*)instance)->reserve(newSize, preserveContent, reduceMemory);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativeResize
 * Signature: (JIZZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_resize
(JNIEnv * jenv, jclass, jlong instance, jint newSize, jboolean preserveContent, jboolean reduceMemory)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfBoolean*)instance)->resize(newSize, preserveContent, reduceMemory);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    nativeSetElement
 * Signature: (JIZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_setElement
(JNIEnv * jenv, jclass, jlong instance, jint index, jboolean value)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(index,0,((DynamicArrayOfBoolean*)instance)->size-1);
  ((DynamicArrayOfBoolean*)instance)->data[index] = value;
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    setElements
 * Signature: (J[Z)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_setElements
(JNIEnv * jenv, jclass, jlong instance, jbooleanArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfBoolean_Java> val = new jni::ArrayOfBoolean_Java();
  val->initializeJNI(jni::Object(jenv,array));
  ((DynamicArrayOfBoolean*)instance)->copy(val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean
 * Method:    getElements
 * Signature: (J[Z)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfBoolean_getElements
(JNIEnv * jenv, jclass, jlong instance, jbooleanArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfBoolean_Java> val = new jni::ArrayOfBoolean_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicArrayOfBoolean*)instance)->size, "The arrays should be of same size");
  val->copy((DynamicArrayOfBoolean*)instance);
  HMMTK4J_JNI_CATCH
}

#ifdef __cplusplus
}
#endif
