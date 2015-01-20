cmake_minimum_required(VERSION 2.6)

PROJECT(hmmtk4j-discretehmm-jni)

SET(CMAKE_MODULE_PATH ${PROJECT_BINARY_DIR}/../../../extracted/utils/cmake)

set( ALTERNATIVE_DEPENDENCIES hmmtk4j-core-basicnative hmmtk4j-core-jnisupport hmmtk4j-discretehmm-basicnative hmmtk4j-discretehmm-jnisupport )
set(ALTERNATIVE_IS_JNI_LIBRARY "1")
set( JAVAH_CLASSES org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.Forward
                   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.FastForward
                   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.Backward
                   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.BaumWelch
                   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.FastForwardWithWeightedObservations
                   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.BaumWelchWithWeightedObservations 
		   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.Viterbi
		   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.LabelledTraining
		   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.SegmentalKMeans
		   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.Gradient
		   org.projectsforge.hmmtk4j.discretehmm.nativeimplementors.MaximalMutualInformation )

INCLUDE( ${CMAKE_MODULE_PATH}/jnilibraryproject.cmake )

