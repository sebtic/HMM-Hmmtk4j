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

#include <org_projectsforge_hmmtk4j_discretehmm_nativeimplementors_FastForwardWithWeightedObservations.h>
#include <org/projectsforge/hmmtk4j/discretehmm/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;
using namespace org::projectsforge::hmmtk4j::jni;
using namespace org::projectsforge::hmmtk4j::discretehmm;
using namespace org::projectsforge::hmmtk4j::discretehmm::jni;

#ifdef __cplusplus
extern "C"
{
#endif

  /*
   * Class:     org_projectsforge_hmmtk4j_discretehmm_nativeimplementors_FastForwardWithWeightedObservations
   * Method:    fastForwardWithWeightedObservations
   * Signature: (Lhmmtk4j/discretehmm/HMM;[Lhmmtk4j/WeightedSequenceOfObservations;)D
   */
  JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_discretehmm_nativeimplementors_FastForwardWithWeightedObservations_fastForwardWithWeightedObservations(
      JNIEnv * jenv, jclass, jobject inputHMM, jobjectArray observations)
  {
    org::projectsforge::hmmtk4j::Double val =
        org::projectsforge::hmmtk4j::Math::LOG_NULL;
    HMMTK4J_JNI_TRY

    Ref<discretehmm::IHMM> inputhmm_val = discretehmm::Proxy_IHMM_getJavaObject(
        Object( jenv, inputHMM ) );
    Ref<ArrayOfReference<IWeightedSequenceOfObservations> >
        observations_val = Proxy_ArrayOfIWeightedSequenceOfObservations_getJavaObject(Object(
            jenv, observations));

    val
        = org::projectsforge::hmmtk4j::discretehmm::fastForwardWithWeightedObservations(
            inputhmm_val, observations_val);

HMMTK4J_JNI_CATCH  return val;
}

#ifdef __cplusplus
}
#endif
