cmake_minimum_required(VERSION 2.6)

PROJECT(hmmtk4j-core-jnisupport)

SET(CMAKE_MODULE_PATH ${PROJECT_BINARY_DIR}/../../../extracted/utils/cmake)

set( ALTERNATIVE_DEPENDENCIES "hmmtk4j-core-basicnative" )

INCLUDE( ${CMAKE_MODULE_PATH}/basiclibraryproject.cmake )
