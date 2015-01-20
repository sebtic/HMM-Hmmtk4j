cmake_minimum_required(VERSION 2.6)

PROJECT(hmmtk4j-core-jni)

SET(CMAKE_MODULE_PATH ${PROJECT_BINARY_DIR}/../../../extracted/utils/cmake)

set( ALTERNATIVE_DEPENDENCIES hmmtk4j-core-basicnative hmmtk4j-core-jnisupport )
set(ALTERNATIVE_IS_JNI_LIBRARY "1")
set( JAVAH_CLASSES org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfBoolean
                   org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfDouble
                   org.projectsforge.hmmtk4j.nativeimplementors.ArrayOfInteger
                   org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfBoolean
                   org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfDouble
                   org.projectsforge.hmmtk4j.nativeimplementors.MatrixOfInteger
                   org.projectsforge.hmmtk4j.nativeimplementors.Bridge )

INCLUDE( ${CMAKE_MODULE_PATH}/jnilibraryproject.cmake )
