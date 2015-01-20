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

#include <org_projectsforge_hmmtk4j_benchmarks_nativeimplementors_Bencher.h>
#include <org/projectsforge/hmmtk4j/discretehmm/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;
using namespace org::projectsforge::hmmtk4j::jni;

#ifdef __cplusplus
extern "C" {
#endif
  /*
   * Class:     org_projectsforge_hmmtk4j_benchmarks_nativeimplementors_Bencher
   * Method:    getSum
   * Signature: (Lhmmtk4j/ArrayOfDouble;)D
   */
  JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_benchmarks_nativeimplementors_Bencher_getSum__Lorg_projectsforge_hmmtk4j_ArrayOfDouble_2(
      JNIEnv * jenv, jclass, jobject array) {
    org::projectsforge::hmmtk4j::Double sum = 0;
    HMMTK4J_JNI_TRY

    IArrayOfDouble * val = Proxy_IArrayOfDouble_getJavaObject(Object(jenv,array));

    for (org::projectsforge::hmmtk4j::Integer i = val->size - 1; i >= 0; --i)
      sum += val->data[i];

HMMTK4J_JNI_CATCH  return sum;
}

/*
 * Class:     org_projectsforge_hmmtk4j_benchmarks_nativeimplementors_Bencher
 * Method:    getSum
 * Signature: (Lhmmtk4j/MatrixOfDouble;)D
 */
JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_benchmarks_nativeimplementors_Bencher_getSum__Lorg_projectsforge_hmmtk4j_MatrixOfDouble_2
(JNIEnv * jenv, jclass, jobject matrix)
{
  org::projectsforge::hmmtk4j::Double sum = 0;
  HMMTK4J_JNI_TRY

  IMatrixOfDouble * val = Proxy_IMatrixOfDouble_getJavaObject(Object(jenv,matrix));

  for( org::projectsforge::hmmtk4j::Integer i = 0; i < val->rowCount; ++i )
  for( org::projectsforge::hmmtk4j::Integer j = 0; j < val->colCount; ++j )
  sum += val->data[i][j];

  HMMTK4J_JNI_CATCH
  return sum;
}

#ifdef __cplusplus
}
#endif
