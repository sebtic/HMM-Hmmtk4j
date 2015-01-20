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

#include <org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble.h>
#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;

#ifdef __cplusplus
extern "C"
{
#endif
  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
   * Method:    nativeAdd
   * Signature: (JD)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_add__JD
  (JNIEnv * jenv, jclass, jlong instance, jdouble value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfDouble*)instance)->add( value );
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
   * Method:    nativeAddToRow
   * Signature: (JID)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_addToRow
  (JNIEnv * jenv, jclass, jlong instance, jint row, jdouble value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfDouble*)instance)->addToRow( row, value );
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
   * Method:    nativeApplyMask
   * Signature: (JJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_applyMask
  (JNIEnv * jenv, jclass, jlong instance, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfDouble*)instance)->applyMask( (DynamicMatrixOfBoolean*)value );
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
   * Method:    nativeClear
   * Signature: (J)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_clear
  (JNIEnv * jenv, jclass, jlong instance)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfDouble*)instance)->clear();
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
   * Method:    nativeCopy
   * Signature: (JJ)V
   */
  JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_copy
  (JNIEnv * jenv, jclass, jlong instance, jlong value)
  {
    HMMTK4J_JNI_TRY
    ((DynamicMatrixOfDouble*)instance)->copy( (DynamicMatrixOfDouble*)value);
    HMMTK4J_JNI_CATCH
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
   * Method:    nativeCountElementsOnRow
   * Signature: (JID)I
   */
  JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_countElementsOnRow(
      JNIEnv * jenv, jclass, jlong instance, jint row, jdouble value)
  {
HMMTK4J_JNI_TRY  return ((DynamicMatrixOfDouble*)instance)->countElementsOnRow(row, value );
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeDeleteInstance
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_deleteInstance
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  Referenced::releaseReference((DynamicMatrixOfDouble*)instance);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeFill
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_fill
(JNIEnv * jenv, jclass, jlong instance, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->fill( value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeFillRow
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_fillRow
(JNIEnv * jenv, jclass, jlong instance, jint row, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->fillRow( row,value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeGetCol
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_getCol
(JNIEnv * jenv, jclass, jlong instance, jint col, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->getCol( col, (DynamicArrayOfDouble*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeGetColCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_getColCount
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->colCount;
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeGetElement
 * Signature: (JII)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_getElement
(JNIEnv * jenv, jclass, jlong instance, jint row, jint col)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(row,0,((DynamicMatrixOfDouble*)instance)->rowCount-1);
  HMMTK4J_CheckBounds(col,0,((DynamicMatrixOfDouble*)instance)->colCount-1);
  return ((DynamicMatrixOfDouble*)instance)->data[row][col];
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeGetRow
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_getRow
(JNIEnv * jenv, jclass, jlong instance, jint row, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->getRow( row, (DynamicArrayOfDouble*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeGetRowCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_getRowCount
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->rowCount;
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeIndexOfMaxElement
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_indexOfMaxElement
(JNIEnv * jenv, jclass, jlong instance, jint row)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->indexOfMaxElement( row);
  HMMTK4J_JNI_CATCH
  return -1;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeIndexOfMinElement
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_indexOfMinElement
(JNIEnv * jenv, jclass, jlong instance, jint row)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->indexOfMinElement( row);
  HMMTK4J_JNI_CATCH
  return -1;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeIsValid
 * Signature: (JDD)Z
 */
JNIEXPORT jboolean JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_isValid
(JNIEnv * jenv, jclass, jlong instance, jdouble minValue, jdouble maxValue)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->isValid( minValue, maxValue);
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeMakeStochastic
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_makeStochastic
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->makeStochastic();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeMakeStochasticRow
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_makeStochasticRow
(JNIEnv * jenv, jclass, jlong instance, jint row)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->makeStochasticRow( row);
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeMaxElement
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_maxElement__J
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->maxElement();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeMaxElement
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_maxElement__JI
(JNIEnv * jenv, jclass, jlong instance, jint row)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->maxElement(row);
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeMinElement
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_minElement__J
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->minElement();
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeMinElement
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_minElement__JI
(JNIEnv * jenv, jclass, jlong instance, jint row)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->minElement(row);
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeMul
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_mul
(JNIEnv * jenv, jclass, jlong instance, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->mul( (DynamicMatrixOfDouble*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeMulRow
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_mulRow
(JNIEnv * jenv, jclass, jlong instance, jint row, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->mulRow(row, value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeNewInstance
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_newInstance
(JNIEnv * jenv, jclass)
{
  jlong instance = 0;
  HMMTK4J_JNI_TRY
  DynamicMatrixOfDouble * ptr = new DynamicMatrixOfDouble();
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
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativePow
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_pow
(JNIEnv * jenv, jclass, jlong instance, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->pow(value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativePowRow
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_powRow
(JNIEnv * jenv, jclass, jlong instance, jint row, jdouble value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->powRow(row, value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeResize
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_resize
(JNIEnv * jenv, jclass, jlong instance, jint row, jint col)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->resize(row, col);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeSetCol
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_setCol
(JNIEnv * jenv, jclass, jlong instance, jint col, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->setCol( col, (DynamicArrayOfDouble*)value);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeSetElement
 * Signature: (JIID)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_setElement
(JNIEnv * jenv, jclass, jlong instance, jint row, jint col, jdouble value)
{
  HMMTK4J_JNI_TRY
  HMMTK4J_CheckBounds(row,0,((DynamicMatrixOfDouble*)instance)->rowCount-1);
  HMMTK4J_CheckBounds(col,0,((DynamicMatrixOfDouble*)instance)->colCount-1);
  ((DynamicMatrixOfDouble*)instance)->data[row][col] = value;
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeSetRow
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_setRow
(JNIEnv * jenv, jclass, jlong instance, jint row, jlong value)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->setRow( row, (DynamicArrayOfDouble*)value);
  HMMTK4J_JNI_CATCH
}
/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeSwapCol
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_swapCol
(JNIEnv * jenv, jclass, jlong instance, jint coli, jint colj)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->swapCol( coli, colj);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeSwapRow
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_swapRow
(JNIEnv * jenv, jclass, jlong instance, jint rowi, jint rowj)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->swapRow( rowi, rowj);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    nativeOrthogonalize
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_orthogonalize
(JNIEnv * jenv, jclass, jlong instance)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->orthogonalize();
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    getColJava
 * Signature: (JI[D)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_getColJava
(JNIEnv * jenv, jclass, jlong instance, jint col, jdoubleArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfDouble_Java> val = new jni::ArrayOfDouble_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfDouble*)instance)->rowCount, "The arrays should have a size of a column");
  ((IMatrix<Double>*)instance)->getCol(col, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    getRowJava
 * Signature: (JI[D)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_getRowJava
(JNIEnv * jenv, jclass, jlong instance, jint row, jdoubleArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfDouble_Java> val = new jni::ArrayOfDouble_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfDouble*)instance)->colCount, "The arrays should have a size of a row");
  ((IMatrix<Double>*)instance)->getRow(row, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfBDouble
 * Method:    setColJava
 * Signature: (JI[D)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_setColJava
(JNIEnv * jenv, jclass, jlong instance, jint col, jdoubleArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfDouble_Java> val = new jni::ArrayOfDouble_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfDouble*)instance)->rowCount, "The arrays should have a size of a column");
  ((DynamicMatrixOfDouble*)instance)->setCol(col, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    setRowJava
 * Signature: (JI[Z)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_setRowJava
(JNIEnv * jenv, jclass, jlong instance, jint row, jdoubleArray array)
{
  HMMTK4J_JNI_TRY
  Ref<jni::ArrayOfDouble_Java> val = new jni::ArrayOfDouble_Java();
  val->initializeJNI(jni::Object(jenv,array));
  HMMTK4J_CheckArgument(val->size == ((DynamicMatrixOfDouble*)instance)->colCount, "The arrays should have a size of a row");
  ((DynamicMatrixOfDouble*)instance)->setRow(row, val.getPtr());
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    product
 * Signature: (JJJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_product
(JNIEnv * jenv, jclass, jlong instance, jlong x , jlong y)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->product((DynamicMatrixOfDouble*)x,(DynamicMatrixOfDouble*)y);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    fourthpowerSquareMatrix
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_fourthpowerSquareMatrix
(JNIEnv * jenv, jclass, jlong instance, jint powerLevel)
{
  HMMTK4J_JNI_TRY
  ((DynamicMatrixOfDouble*)instance)->fourthpowerSquareMatrix(powerLevel);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    innerProductOfCols
 * Signature: (JII)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_innerProductOfCols
(JNIEnv * jenv, jclass, jlong instance, jint coli, jint colj)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->innerProductOfCols(coli,colj);
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    innerProductOfRows
 * Signature: (JII)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_innerProductOfRows
(JNIEnv * jenv, jclass, jlong instance, jint rowi, jint rowj)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->innerProductOfRows(rowi,rowj);
  HMMTK4J_JNI_CATCH
  return 0;
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    sub
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_sub
(JNIEnv * jenv, jclass, jlong instance, jlong matrix)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->sub((DynamicMatrixOfDouble*)matrix);
  HMMTK4J_JNI_CATCH
}

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble
 * Method:    add
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_MatrixOfDouble_add__JJ
(JNIEnv * jenv, jclass, jlong instance, jlong matrix)
{
  HMMTK4J_JNI_TRY
  return ((DynamicMatrixOfDouble*)instance)->add((DynamicMatrixOfDouble*)matrix);
  HMMTK4J_JNI_CATCH
}

#ifdef __cplusplus
}
#endif

