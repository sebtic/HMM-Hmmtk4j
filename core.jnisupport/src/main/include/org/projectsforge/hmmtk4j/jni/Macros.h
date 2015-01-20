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

#ifndef HMMTK4J_JNI_Macros_h
#define HMMTK4J_JNI_Macros_h

#include <string.h>

#define HMMTK4J_JNI_TRY \
  try \
  {

#define HMMTK4J_JNI_CATCH \
  }\
  catch(org::projectsforge::hmmtk4j::IllegalStateException e)\
  {\
    jenv->ExceptionClear();\
    jclass except = jenv->FindClass("java/lang/IllegalStateException");\
    char * msg = strdup( e.what().c_str() ); \
    jenv->ThrowNew(except, msg);\
    free(msg); \
  }\
  catch(org::projectsforge::hmmtk4j::IllegalArgumentException e)\
  {\
    jenv->ExceptionClear();\
    jclass except = jenv->FindClass("java/lang/IllegalArgumentException");\
    char * msg = strdup( e.what().c_str() ); \
    jenv->ThrowNew(except, msg);\
    free(msg); \
  }\
  catch(org::projectsforge::hmmtk4j::MemoryException e)\
  {\
    jenv->ExceptionClear();\
    jclass except = jenv->FindClass("java/lang/OutOfMemoryError");\
    char * msg = strdup( e.what().c_str() ); \
    jenv->ThrowNew(except, msg);\
    free(msg); \
  }\
  catch(org::projectsforge::hmmtk4j::IndexOutOfBoundsException e)\
  {\
    jenv->ExceptionClear();\
    jclass except = jenv->FindClass("java/lang/IndexOutOfBoundsException");\
    char * msg = strdup( e.what().c_str() ); \
    jenv->ThrowNew(except, msg);\
    free(msg); \
  }\
  catch(org::projectsforge::hmmtk4j::Exception e)\
  {\
    jenv->ExceptionClear();\
    jclass except = jenv->FindClass("java/lang/RuntimeException");\
    char * msg = strdup( e.what().c_str() ); \
    jenv->ThrowNew(except, msg);\
    free(msg); \
  }\
  catch(...)\
  {\
    jenv->ExceptionClear();\
    jclass except = jenv->FindClass("java/lang/RuntimeException");\
    jenv->ThrowNew(except, "Unexpected exception");\
  }

#define HMMTK4J_JNIError(id) \
  if ((id) == 0) \
  { \
    org::projectsforge::hmmtk4j::RuntimeException __e( "Error in JNI implementation or null object accessed" ); \
    HMMTK4J_RaiseException(__e); \
  }

#endif
