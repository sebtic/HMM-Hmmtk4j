cmake_minimum_required(VERSION 2.6)

PROJECT(hmmtk4j-dmdhmm-jni)

SET(CMAKE_MODULE_PATH ${PROJECT_BINARY_DIR}/../../../extracted/utils/cmake)

set( ALTERNATIVE_DEPENDENCIES hmmtk4j-core-basicnative hmmtk4j-core-jnisupport hmmtk4j-discretehmm-basicnative hmmtk4j-discretehmm-jnisupport hmmtk4j-dmdhmm-basicnative hmmtk4j-dmdhmm-jnisupport)
set(ALTERNATIVE_IS_JNI_LIBRARY "1")
set( JAVAH_CLASSES org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.Forward
                   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.FastForward
                   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.Backward
                   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.BaumWelch
                   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.FastForwardWithWeightedObservations
                   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.BaumWelchWithWeightedObservations 
		   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.Viterbi
		   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.LabelledTraining
		   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.SegmentalKMeans
		   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.Gradient
		   org.projectsforge.hmmtk4j.dmdhmm.nativeimplementors.MaximalMutualInformation )

INCLUDE( ${CMAKE_MODULE_PATH}/jnilibraryproject.cmake )

