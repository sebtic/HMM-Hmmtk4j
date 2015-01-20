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

#include <org_projectsforge_hmmtk4j_dmdhmm_nativeimplementors_MaximalMutualInformation.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/jni/IncludeAll.h>

using namespace org::projectsforge::hmmtk4j;
using namespace org::projectsforge::hmmtk4j::jni;
using namespace org::projectsforge::hmmtk4j::dmdhmm;
using namespace org::projectsforge::hmmtk4j::dmdhmm::jni;

#ifdef __cplusplus
extern "C"
{
#endif
  /*
   * Class:     org_projectsforge_hmmtk4j_dmdhmm_nativeimplementors_MaximalMutualInformation
   * Method:    maximalMutualInformation
   * Signature: ([Lorg/projectsforge/hmmtk4j/dmdhmm/WeightedSequenceOfObservations;[Lorg/projectsforge/hmmtk4j/dmdhmm/WeightedSequenceOfObservations;Lorg/projectsforge/hmmtk4j/dmdhmm/HMM;ILorg/projectsforge/hmmtk4j/dmdhmm/HMM;)D
   */
  JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_dmdhmm_nativeimplementors_MaximalMutualInformation_maximalMutualInformation(
      JNIEnv * jenv, jclass, jobjectArray positiveObservations, jobjectArray negativeObservations,
      jobject inputHMM, jint nbMaxIteration, jobject outputHMM)
  {
    org::projectsforge::hmmtk4j::Double val = org::projectsforge::hmmtk4j::Math::LOG_NULL;
    HMMTK4J_JNI_TRY

    Ref<dmdhmm::IHMM> inputhmm_val = dmdhmm::Proxy_IHMM_getJavaObject( Object( jenv, inputHMM ) );
    Ref<dmdhmm::IHMM> outputhmm_val = dmdhmm::Proxy_IHMM_getJavaObject(Object(jenv, outputHMM));

    Ref<ArrayOfReference<IWeightedSequenceOfObservations> > positiveObservations_val =
        Proxy_ArrayOfIWeightedSequenceOfObservations_getJavaObject(Object(jenv,
            positiveObservations));
    Ref<ArrayOfReference<IWeightedSequenceOfObservations> > negativeObservations_val =
        Proxy_ArrayOfIWeightedSequenceOfObservations_getJavaObject(Object(jenv,
            negativeObservations));

    val = org::projectsforge::hmmtk4j::dmdhmm::maximalMutualInformation(positiveObservations_val,
        negativeObservations_val, inputhmm_val, nbMaxIteration, outputhmm_val);

    HMMTK4J_JNI_CATCH;
    return val;
  }

#ifdef __cplusplus
}
#endif
