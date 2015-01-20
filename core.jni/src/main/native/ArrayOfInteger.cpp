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

#include <org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger.h>
#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;

#ifdef __cplusplus
extern "C"
{
#endif
  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
   * Method:    nativeClear
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_clear
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfInteger*)instance)->clear();
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
   * Method:    nativeCopy
   * Signature: (JJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_copy
  (JNIEnv * jenv, jclass, jlong instance, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfInteger*)instance)->copy( (DynamicArrayOfInteger*)value );
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
   * Method:    nativeDeleteInstance
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_deleteInstance
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    Referenced::releaseReference((DynamicArrayOfInteger*)instance);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
   * Method:    nativeErase
   * Signature: (JI)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_erase
  (JNIEnv * jenv, jclass, jlong instance, jint index)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfInteger*)instance)->erase(index);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
   * Method:    nativeFill
   * Signature: (JI)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_fill
  (JNIEnv * jenv, jclass, jlong instance, jint value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfInteger*)instance)->fill(value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
   * Method:    nativeGetCount
   * Signature: (J)I
   */
  JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_getCount(
      JNIEnv * jenv, jclass, jlong instance)
  {
HMMTK4J_JNI_TRY  return ((DynamicArrayOfInteger*)instance)->size;
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativeGetElement
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_getElement
(JNIEnv * jenv, jclass, jlong instance, jint index)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(index,0,((DynamicArrayOfInteger*)instance)->size-1);
  return ((DynamicArrayOfInteger*)instance)->data[index];
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativeInsert
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_insert
(JNIEnv * jenv, jclass, jlong instance, jint index, jint value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfInteger*)instance)->insert(index, value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativeInsertArray
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_insertArray
(JNIEnv * jenv, jclass, jlong instance, jint index, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfInteger*)instance)->insert(index, (DynamicArrayOfInteger*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativeNewInstance
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_newInstance
(JNIEnv * jenv, jclass)
{
  jlong instance = 0;
  HMMTK4J_JNI_TRY
  DynamicArrayOfInteger * ptr = new DynamicArrayOfInteger();
  Referenced::takeReference(ptr);
  instance = (jlong) ptr;
  if (ptr == NULL)
  {
    org::projectsforge::hmmtk4j::IllegalArgumentException __e( "Can not create a native instance");
    HMMTK4J_RaiseException(__e);
  }
  HMMTK4J_JNI_CATCH
  return instance;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativePushBack
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_pushBack
(JNIEnv * jenv, jclass, jlong instance, jint value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfInteger*)instance)->pushBack(value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativePushBackArray
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_pushBackArray
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfInteger*)instance)->pushBack( (DynamicArrayOfInteger*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativePushFront
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_pushFront
(JNIEnv * jenv, jclass, jlong instance, jint value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfInteger*)instance)->pushFront(value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativePushFrontArray
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_pushFrontArray
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfInteger*)instance)->pushFront( (DynamicArrayOfInteger*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativeReserve
 * Signature: (JIZZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_reserve
(JNIEnv * jenv, jclass, jlong instance, jint newSize, jboolean preserveContent, jboolean reduceMemory)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfInteger*)instance)->reserve(newSize, preserveContent, reduceMemory);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativeResize
 * Signature: (JIZZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_resize
(JNIEnv * jenv, jclass, jlong instance, jint newSize, jboolean preserveContent, jboolean reduceMemory)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfInteger*)instance)->resize(newSize, preserveContent, reduceMemory);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    nativeSetElement
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_setElement
(JNIEnv * jenv, jclass, jlong instance, jint index, jint value)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(index,0,((DynamicArrayOfInteger*)instance)->size-1);
  ((DynamicArrayOfInteger*)instance)->data[index] = value;
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    getElements
 * Signature: (J[I)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_getElements
(JNIEnv * jenv, jclass, jlong instance, jintArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfInteger_Java> val = new jni::ArrayOfInteger_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicArrayOfInteger*)instance)->size, "The arrays should be of same size");
  val->copy((DynamicArrayOfInteger*)instance);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger
 * Method:    setElements
 * Signature: (J[I)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfInteger_setElements
(JNIEnv * jenv, jclass, jlong instance, jintArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfInteger_Java> val = new jni::ArrayOfInteger_Java();
  val->initializeJNI(jni::Object(jenv,array));
  ((DynamicArrayOfInteger*)instance)->copy(val.getPtr());
  HMMTK4J_JNI_CATCH
}

#ifdef __cplusplus
}
#endif
