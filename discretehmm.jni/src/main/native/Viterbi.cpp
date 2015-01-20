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

#include <org_projectsforge_hmmtk4j_discretehmm_nativeimplementors_Viterbi.h>
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
   * Class:     org_projectsforge_hmmtk4j_discretehmm_nativeimplementors_Viterbi
   * Method:    viterbi
   * Signature: (Lhmmtk4j/SequenceOfObservations;Lhmmtk4j/discretehmm/HMM;Lhmmtk4j/SequenceOfObservations;)D
   */
  JNIEXPORT jdouble JNICALL Java_org_projectsforge_hmmtk4j_discretehmm_nativeimplementors_Viterbi_viterbi(
      JNIEnv * jenv, jclass, jobject observation, jobject hmm,
      jobject stateSequence)
  {
    org::projectsforge::hmmtk4j::Double val =
        org::projectsforge::hmmtk4j::Math::LOG_NULL;

    HMMTK4J_JNI_TRY

    Ref< discretehmm::IHMM > hmm_val = discretehmm::Proxy_IHMM_getJavaObject(
        Object( jenv, hmm ) );
    Ref<ISequenceOfObservations> obs_val = Proxy_ISequenceOfObservations_getJavaObject(Object(jenv,
        observation));
    Ref<ISequenceOfObservations> stateSeq_val = Proxy_ISequenceOfObservations_getJavaObject(Object(jenv,
        stateSequence));

    val = org::projectsforge::hmmtk4j::discretehmm::viterbi(obs_val, hmm_val,
        stateSeq_val);

HMMTK4J_JNI_CATCH  return val;
}

#ifdef __cplusplus
}
#endif
