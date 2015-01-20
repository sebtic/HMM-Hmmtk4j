cmake_minimum_required(VERSION 2.6)

PROJECT(hmmtk4j-dmdhmm-jnisupport)

SET(CMAKE_MODULE_PATH ${PROJECT_BINARY_DIR}/../../../extracted/utils/cmake)

set( ALTERNATIVE_DEPENDENCIES "hmmtk4j-core-basicnative hmmtk4j-core-jnisupport hmmtk4j-discretehmm-basicnative hmmtk4j-discretehmm-jnisupport hmmtk4j-dmdhmm-basicnative" )

INCLUDE( ${CMAKE_MODULE_PATH}/basiclibraryproject.cmake )


