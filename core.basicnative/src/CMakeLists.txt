cmake_minimum_required(VERSION 2.6)

PROJECT(hmmtk4j-core-basicnative)

SET(CMAKE_MODULE_PATH ${PROJECT_BINARY_DIR}/../../../extracted/utils/cmake)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  add_definitions( -DHMMTK4J_DEBUG )
  if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set( PKGCONFIG_COMPILE_FLAGS "-DHMMTK4J_DEBUG" )
  endif()
endif()

INCLUDE( ${CMAKE_MODULE_PATH}/basiclibraryproject.cmake )



