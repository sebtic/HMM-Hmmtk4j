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

#include <org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger.h>
#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;

#ifdef __cplusplus
extern "C"
{
#endif
  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
   * Method:    nativeClear
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_clear
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfInteger*)instance)->clear();
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
   * Method:    nativeCopy
   * Signature: (JJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_copy
  (JNIEnv * jenv, jclass, jlong instance, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfInteger*)instance)->copy( (DynamicMatrixOfInteger*)value );
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
   * Method:    nativeDeleteInstance
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_deleteInstance
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    Referenced::releaseReference((DynamicMatrixOfInteger*)instance);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
   * Method:    nativeFill
   * Signature: (JI)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_fill
  (JNIEnv * jenv, jclass, jlong instance, jint value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfInteger*)instance)->fill(value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
   * Method:    nativeFillRow
   * Signature: (JII)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_fillRow
  (JNIEnv * jenv, jclass, jlong instance, jint row, jint value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfInteger*)instance)->fillRow(row,value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
   * Method:    nativeGetCol
   * Signature: (JIJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_getCol
  (JNIEnv * jenv, jclass, jlong instance, jint col, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfInteger*)instance)->getCol( col, (DynamicArrayOfInteger*)value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
   * Method:    nativeGetColCount
   * Signature: (J)I
   */
  JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_getColCount(
      JNIEnv * jenv, jclass, jlong instance)
  {
HMMTK4J_JNI_TRY  return ((DynamicMatrixOfInteger*)instance)->colCount;
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeGetElement
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_getElement
(JNIEnv * jenv, jclass, jlong instance, jint row, jint col)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(row,0,((DynamicMatrixOfInteger*)instance)->rowCount-1);
  HMMTK4J_CheckBounds(col,0,((DynamicMatrixOfInteger*)instance)->colCount-1);
  return ((DynamicMatrixOfInteger*)instance)->data[row][col];
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeGetRow
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_getRow
(JNIEnv * jenv, jclass, jlong instance, jint row, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfInteger*)instance)->getRow( row, (DynamicArrayOfInteger*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeGetRowCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_getRowCount
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfInteger*)instance)->rowCount;
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeIndexOfMaxElement
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_indexOfMaxElement
(JNIEnv * jenv, jclass, jlong instance, jint row)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfInteger*)instance)->indexOfMaxElement( row);
  HMMTK4J_JNI_CATCH
  return -1;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeIndexOfMinElement
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_indexOfMinElement
(JNIEnv * jenv, jclass, jlong instance, jint row)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfInteger*)instance)->indexOfMinElement( row);
  HMMTK4J_JNI_CATCH
  return -1;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeIsValid
 * Signature: (JII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_isValid
(JNIEnv * jenv, jclass, jlong instance, jint minValue, jint maxValue)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfInteger*)instance)->isValid( minValue, maxValue);
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeMaxElement
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_maxElement__J
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfInteger*)instance)->maxElement();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeMaxElement
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_maxElement__JI
(JNIEnv * jenv, jclass, jlong instance, jint row)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfInteger*)instance)->maxElement(row);
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeMinElement
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_minElement__J
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfInteger*)instance)->minElement();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeMinElement
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_minElement__JI
(JNIEnv * jenv, jclass, jlong instance, jint row)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfInteger*)instance)->minElement(row);
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeNewInstance
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_newInstance
(JNIEnv * jenv, jclass)
{
  jlong instance = 0;
  HMMTK4J_JNI_TRY
  DynamicMatrixOfInteger * ptr = new DynamicMatrixOfInteger();
  Referenced::takeReference(ptr);
  instance = (jlong)(ptr);
  if (ptr == NULL)
  {
    org::projectsforge::hmmtk4j::IllegalArgumentException __e( "Can not create a native instance");
    HMMTK4J_RaiseException(__e);
  }
  HMMTK4J_JNI_CATCH
  return instance;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeResize
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_resize
(JNIEnv * jenv, jclass, jlong instance, jint row, jint col)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfInteger*)instance)->resize(row, col);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeSetCol
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_setCol
(JNIEnv * jenv, jclass, jlong instance, jint col, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfInteger*)instance)->setCol(col, (DynamicArrayOfInteger*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeSetElement
 * Signature: (JIII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_setElement
(JNIEnv * jenv, jclass, jlong instance, jint row, jint col, jint value)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(row,0,((DynamicMatrixOfInteger*)instance)->rowCount-1);
  HMMTK4J_CheckBounds(col,0,((DynamicMatrixOfInteger*)instance)->colCount-1);
  ((DynamicMatrixOfInteger*)instance)->data[row][col] = value;
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeSetRow
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_setRow
(JNIEnv * jenv, jclass, jlong instance, jint row, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfInteger*)instance)->setRow(row, (DynamicArrayOfInteger*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeSwapCol
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_swapCol
(JNIEnv * jenv, jclass, jlong instance, jint coli, jint colj)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfInteger*)instance)->swapCol( coli, colj);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    nativeSwapRow
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_swapRow
(JNIEnv * jenv, jclass, jlong instance, jint rowi, jint rowj)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfInteger*)instance)->swapRow( rowi, rowj);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    getColJava
 * Signature: (JI[I)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_getColJava
(JNIEnv * jenv, jclass, jlong instance, jint col, jintArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfInteger_Java> val = new jni::ArrayOfInteger_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfInteger*)instance)->rowCount, "The arrays should have a size of a column");
  ((IMatrix<Integer>*)instance)->getCol(col, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    getRowJava
 * Signature: (JI[I)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_getRowJava
(JNIEnv * jenv, jclass, jlong instance, jint row, jintArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfInteger_Java> val = new jni::ArrayOfInteger_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfInteger*)instance)->colCount, "The arrays should have a size of a row");
  ((IMatrix<Integer>*)instance)->getRow(row, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    setColJava
 * Signature: (JI[I)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_setColJava
(JNIEnv * jenv, jclass, jlong instance, jint col, jintArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfInteger_Java> val = new jni::ArrayOfInteger_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfInteger*)instance)->rowCount, "The arrays should have a size of a column");
  ((DynamicMatrixOfInteger*)instance)->setCol(col, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger
 * Method:    setRowJava
 * Signature: (JI[I)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfInteger_setRowJava
(JNIEnv * jenv, jclass, jlong instance, jint row, jintArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfInteger_Java> val = new jni::ArrayOfInteger_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfInteger*)instance)->colCount, "The arrays should have a size of a row");
  ((DynamicMatrixOfInteger*)instance)->setRow(row, val.getPtr());
  HMMTK4J_JNI_CATCH
}

#ifdef __cplusplus
}
#endif

