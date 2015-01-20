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

#include <org_projectsforge_hmmtk4j_discretehmm_nativeimplementors_LabelledTraining.h>
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
 * Class:     org_projectsforge_hmmtk4j_discretehmm_nativeimplementors_LabelledTraining
 * Method:    labelledTraining
 * Signature: (Lhmmtk4j/SequenceOfObservations;Lhmmtk4j/SequenceOfObservations;DLhmmtk4j/discretehmm/HMM;)V
 */
JNIEXPORT void JNICALL Java_org_projectsforge_hmmtk4j_discretehmm_nativeimplementors_LabelledTraining_labelledTraining(
    JNIEnv * jenv, jclass, jobject obs, jobject stateSeq, jdouble smoothing,
    jobject outputhmm)
{
  HMMTK4J_JNI_TRY

  Ref< discretehmm::IHMM > outputhmm_val = discretehmm::Proxy_IHMM_getJavaObject(
      Object( jenv, outputhmm ) );
  Ref< ISequenceOfObservations > obs_val = Proxy_ISequenceOfObservations_getJavaObject( Object(
          jenv, obs ) );
  Ref< ISequenceOfObservations > stateSeq_val = Proxy_ISequenceOfObservations_getJavaObject( Object(
          jenv, stateSeq ) );

  org::projectsforge::hmmtk4j::discretehmm::labelledTraining( obs_val, stateSeq_val, smoothing,
      outputhmm_val );

  HMMTK4J_JNI_CATCH
}

#ifdef __cplusplus
}
#endif

