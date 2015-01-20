cmake_minimum_required(VERSION 2.6)

PROJECT(hmmtk4j-benchmarks-jni)

SET(CMAKE_MODULE_PATH ${PROJECT_BINARY_DIR}/../../../extracted/utils/cmake)

set( ALTERNATIVE_DEPENDENCIES hmmtk4j-core-basicnative hmmtk4j-core-jnisupport hmmtk4j-discretehmm-basicnative hmmtk4j-discretehmm-jnisupport )
set(ALTERNATIVE_IS_JNI_LIBRARY "1")
set( JAVAH_CLASSES org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.Bencher org.projectsforge.hmmtk4j.benchmarks.nativeimplementors.CPUUsageMeasurer )

INCLUDE( ${CMAKE_MODULE_PATH}/jnilibraryproject.cmake )
