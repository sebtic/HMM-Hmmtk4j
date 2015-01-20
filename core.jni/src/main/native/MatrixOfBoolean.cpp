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

#include <org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean.h>
#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;

#ifdef __cplusplus
extern "C"
{
#endif
  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
   * Method:    nativeClear
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_clear
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfBoolean*)instance)->clear();
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
   * Method:    nativeCopy
   * Signature: (JJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_copy
  (JNIEnv * jenv, jclass, jlong instance, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfBoolean*)instance)->copy( (DynamicMatrixOfBoolean*)value );
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
   * Method:    nativeDeleteInstance
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_deleteInstance
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    Referenced::releaseReference((DynamicMatrixOfBoolean*)instance);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
   * Method:    nativeFill
   * Signature: (JZ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_fill
  (JNIEnv * jenv, jclass, jlong instance, jboolean value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfBoolean*)instance)->fill( value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
   * Method:    nativeFillRow
   * Signature: (JIZ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_fillRow
  (JNIEnv * jenv, jclass, jlong instance, jint row, jboolean value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfBoolean*)instance)->fillRow( row,value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
   * Method:    nativeGetCol
   * Signature: (JIJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_getCol
  (JNIEnv * jenv, jclass, jlong instance, jint col, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfBoolean*)instance)->getCol( col, (DynamicArrayOfBoolean*)value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
   * Method:    nativeGetColCount
   * Signature: (J)I
   */
  JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_getColCount(
      JNIEnv * jenv, jclass, jlong instance)
  {
HMMTK4J_JNI_TRY  return ((DynamicMatrixOfBoolean*)instance)->colCount;
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeGetElement
 * Signature: (JII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_getElement
(JNIEnv * jenv, jclass, jlong instance, jint row, jint col)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(row,0,((DynamicMatrixOfBoolean*)instance)->rowCount-1);
  HMMTK4J_CheckBounds(col,0,((DynamicMatrixOfBoolean*)instance)->colCount-1);
  return ((DynamicMatrixOfBoolean*)instance)->data[row][col];
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeGetRow
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_getRow
(JNIEnv * jenv, jclass, jlong instance, jint row, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfBoolean*)instance)->getRow( row, (DynamicArrayOfBoolean*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeGetRowCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_getRowCount
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfBoolean*)instance)->rowCount;
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeIsValidMask
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_isValidMask
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfBoolean*)instance)->isValidMask();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeNewInstance
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_newInstance
(JNIEnv * jenv, jclass)
{
  jlong instance = 0;
  HMMTK4J_JNI_TRY
  DynamicMatrixOfBoolean * ptr = new DynamicMatrixOfBoolean();
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
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeResize
 * Signature: (JIIZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_resize
(JNIEnv * jenv, jclass, jlong instance, jint row, jint col)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfBoolean*)instance)->resize(row, col);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeSetCol
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_setCol
(JNIEnv * jenv, jclass, jlong instance, jint col, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfBoolean*)instance)->setCol(col, (DynamicArrayOfBoolean*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeSetElement
 * Signature: (JIIZ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_setElement
(JNIEnv * jenv, jclass, jlong instance, jint row, jint col, jboolean value)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(row,0,((DynamicMatrixOfBoolean*)instance)->rowCount-1);
  HMMTK4J_CheckBounds(col,0,((DynamicMatrixOfBoolean*)instance)->colCount-1);
  ((DynamicMatrixOfBoolean*)instance)->data[row][col] = value;
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeSetRow
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_setRow
(JNIEnv * jenv, jclass, jlong instance, jint row, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfBoolean*)instance)->setRow( row, (DynamicArrayOfBoolean*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeSwapCol
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_swapCol
(JNIEnv * jenv, jclass, jlong instance, jint coli, jint colj)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfBoolean*)instance)->swapCol( coli, colj);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    nativeSwapRow
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_swapRow
(JNIEnv * jenv, jclass, jlong instance, jint rowi, jint rowj)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfBoolean*)instance)->swapRow( rowi, rowj);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    getColJava
 * Signature: (JI[Z)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_getColJava
(JNIEnv * jenv, jclass, jlong instance, jint col, jbooleanArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfBoolean_Java> val = new jni::ArrayOfBoolean_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfBoolean*)instance)->rowCount, "The arrays should have a size of a column");
  ((IMatrix<Boolean>*)instance)->getCol(col, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    getRowJava
 * Signature: (JI[Z)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_getRowJava
(JNIEnv * jenv, jclass, jlong instance, jint row, jbooleanArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfBoolean_Java> val = new jni::ArrayOfBoolean_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfBoolean*)instance)->colCount, "The arrays should have a size of a row");
  ((IMatrix<Boolean>*)instance)->getRow(row, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    setColJava
 * Signature: (JI[Z)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_setColJava
(JNIEnv * jenv, jclass, jlong instance, jint col, jbooleanArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfBoolean_Java> val = new jni::ArrayOfBoolean_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfBoolean*)instance)->rowCount, "The arrays should have a size of a column");
  ((DynamicMatrixOfBoolean*)instance)->setCol(col, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean
 * Method:    setRowJava
 * Signature: (JI[Z)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBoolean_setRowJava
(JNIEnv * jenv, jclass, jlong instance, jint row, jbooleanArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfBoolean_Java> val = new jni::ArrayOfBoolean_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfBoolean*)instance)->colCount, "The arrays should have a size of a row");
  ((DynamicMatrixOfBoolean*)instance)->setRow(row, val.getPtr());
  HMMTK4J_JNI_CATCH
}

#ifdef __cplusplus
}
#endif

