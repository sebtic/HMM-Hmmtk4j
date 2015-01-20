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

#include <org_projectsforge_hmmtk4j_nativeimplementors_Bridge.h>
#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;

#ifdef __cplusplus
extern "C"
{
#endif

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_Bridge
   * Method:    getLOG_NULL
   * Signature: ()D
   */
  JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_Bridge_getLOG_1NULL(
      JNIEnv *, jclass)
  {
    return Math::LOG_NULL;
  }

  /*
   * Class:     org_projectsforge_hmmtk4j_nativeimplementors_Bridge
   * Method:    getNULL_VALUE
   * Signature: ()D
   */
  JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_Bridge_getNULL_1VALUE(
      JNIEnv *, jclass)
  {
    return Math::NULL_VALUE;
  }

/*
 * Class:     org_projectsforge_hmmtk4j_nativeimplementors_Bridge
 * Method:    setRandomGenerator
 * Signature: (Ljava/util/Random;)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_nativeimplementors_Bridge_setRandomGenerator
(JNIEnv * jenv, jclass, jobject generator)
{
  if (generator == 0)
  randomGenerator = NULL;
  else
  randomGenerator = new jni::RandomGenerator(jenv,generator);
}

#ifdef __cplusplus
}
#endif

