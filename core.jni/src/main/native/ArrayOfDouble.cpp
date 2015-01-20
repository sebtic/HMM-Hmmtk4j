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

#include <org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble.h>
#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;

#ifdef __cplusplus
extern "C"
{
#endif

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
   * Method:    nativeAdd
   * Signature: (JD)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_add
  (JNIEnv * jenv, jclass, jlong instance, jdouble value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfDouble*)instance)->add( value );
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
   * Method:    nativeAddArray
   * Signature: (JJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_addArray
  (JNIEnv * jenv, jclass, jlong instance, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfDouble*)instance)->add( (DynamicArrayOfDouble*)value );
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
   * Method:    nativeApplyMask
   * Signature: (JJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_applyMask
  (JNIEnv * jenv, jclass, jlong instance, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfDouble*)instance)->applyMask( (DynamicArrayOfBoolean*)value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
   * Method:    nativeClear
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_clear
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfDouble*)instance)->clear();
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
   * Method:    nativeCopy
   * Signature: (JJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_copy
  (JNIEnv * jenv, jclass, jlong instance, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicArrayOfDouble*)instance)->copy( (DynamicArrayOfDouble*)value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
   * Method:    nativeCountElements
   * Signature: (JD)I
   */
  JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_countElements(
      JNIEnv * jenv, jclass, jlong instance, jdouble value)
  {
HMMTK4J_JNI_TRY  return ((DynamicArrayOfDouble*)instance)->countElements( value );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeDeleteInstance
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_deleteInstance
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  Referenced::releaseReference( (DynamicArrayOfDouble*)instance);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeErase
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_erase
(JNIEnv * jenv, jclass, jlong instance, jint index)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->erase(index);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeFill
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_fill
(JNIEnv * jenv, jclass, jlong instance, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->fill(value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeGetCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_getCount
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->size;
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeGetElement
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_getElement
(JNIEnv * jenv, jclass, jlong instance, jint index)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(index,0,((DynamicArrayOfDouble*)instance)->size-1);
  return ((DynamicArrayOfDouble*)instance)->data[index];
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeIndexOfMaxElement
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_indexOfMaxElement
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->indexOfMaxElement();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeIndexOfMinElement
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_indexOfMinElement
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->indexOfMinElement( );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeInfiniteNorm
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_infiniteNorm
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->infiniteNorm( );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeInnerProduct
 * Signature: (JJ)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_innerProduct
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->innerProduct( (DynamicArrayOfDouble*)value );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeInsert
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_insert
(JNIEnv * jenv, jclass, jlong instance, jint index, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->insert(index, value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeInsertArray
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_insertArray
(JNIEnv * jenv, jclass, jlong instance, jint index, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->insert(index, (DynamicArrayOfDouble*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeIsValid
 * Signature: (JDD)Z
 */
JNIEXPORT jboolean JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_isValid
(JNIEnv * jenv, jclass, jlong instance, jdouble minValue, jdouble maxValue )
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->isValid( minValue, maxValue );
  HMMTK4J_JNI_CATCH
  return false;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeLNNorm
 * Signature: (JD)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_lNNorm
(JNIEnv * jenv, jclass, jlong instance, jdouble order)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->lNNorm( order );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeLNNormUnRooted
 * Signature: (JD)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_lNNormUnRooted
(JNIEnv * jenv, jclass, jlong instance, jdouble order)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->lNNormUnRooted( order );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeMaxDistance
 * Signature: (JJ)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_maxDistance
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->maxDistance( (DynamicArrayOfDouble*)value );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeMaxElement
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_maxElement
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->maxElement();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeMinElement
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_minElement
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->minElement( );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeMoment
 * Signature: (JD)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_moment
(JNIEnv * jenv, jclass, jlong instance, jdouble order)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->moment( order );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeMul
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_mul
(JNIEnv * jenv, jclass, jlong instance, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->mul( value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeMulArray
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_mulArray
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->mul( (DynamicArrayOfDouble*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeNewInstance
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_newInstance
(JNIEnv * jenv, jclass)
{
  jlong instance = 0;
  HMMTK4J_JNI_TRY
  DynamicArrayOfDouble * ptr = new DynamicArrayOfDouble();
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
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativePow
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_pow
(JNIEnv * jenv, jclass, jlong instance, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->pow( value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativePushBack
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_pushBack
(JNIEnv * jenv, jclass, jlong instance, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->pushBack(value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativePushBackArray
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_pushBackArray
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->pushBack( (DynamicArrayOfDouble*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativePushFront
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_pushFront
(JNIEnv * jenv, jclass, jlong instance, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->pushFront(value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativePushFrontArray
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_pushFrontArray
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->pushFront( (DynamicArrayOfDouble*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeReserve
 * Signature: (JIZZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_reserve
(JNIEnv * jenv, jclass, jlong instance, jint newSize, jboolean preserveContent, jboolean reduceMemory)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->reserve(newSize, preserveContent, reduceMemory);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeResize
 * Signature: (JIZZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_resize
(JNIEnv * jenv, jclass, jlong instance, jint newSize, jboolean preserveContent, jboolean reduceMemory)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->resize(newSize, preserveContent, reduceMemory);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeSetElement
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_setElement
(JNIEnv * jenv, jclass, jlong instance, jint index, jdouble value)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(index,0,((DynamicArrayOfDouble*)instance)->size-1);
  ((DynamicArrayOfDouble*)instance)->data[index] = value;
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeStdDev
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_stdDev
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->stdDev();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeSub
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_sub
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicArrayOfDouble*)instance)->sub( (DynamicArrayOfDouble*)value );
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeSumOfAbsoluteElements
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_sumOfAbsoluteElements
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->sumOfAbsoluteElements();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    nativeSumOfElements
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_sumOfElements
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicArrayOfDouble*)instance)->sumOfElements();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    getElements
 * Signature: (J[D)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_getElements
(JNIEnv * jenv, jclass, jlong instance, jdoubleArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfDouble_Java> val = new jni::ArrayOfDouble_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicArrayOfDouble*)instance)->size, "The arrays should be of same size");
  val->copy((DynamicArrayOfDouble*)instance);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble
 * Method:    setElements
 * Signature: (J[D)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_ArrayOfDouble_setElements
(JNIEnv * jenv, jclass, jlong instance, jdoubleArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfDouble_Java> val = new jni::ArrayOfDouble_Java();
  val->initializeJNI(jni::Object(jenv,array));
  ((DynamicArrayOfDouble*)instance)->copy(val.getPtr());
  HMMTK4J_JNI_CATCH
}

#ifdef __cplusplus
}
#endif

