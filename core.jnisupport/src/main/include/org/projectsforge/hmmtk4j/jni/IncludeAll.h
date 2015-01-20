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

#ifndef HMMTK4J_JNI_h
#define HMMTK4J_JNI_h

#include <org/projectsforge/hmmtk4j/IncludeAll.h>
#include <org/projectsforge/hmmtk4j/jni/Macros.h>

#include <org/projectsforge/hmmtk4j/jni/Object.h>
#include <org/projectsforge/hmmtk4j/jni/Field.h>

#include <org/projectsforge/hmmtk4j/jni/LongField.h>
#include <org/projectsforge/hmmtk4j/jni/BooleanField.h>
#include <org/projectsforge/hmmtk4j/jni/IntegerField.h>
#include <org/projectsforge/hmmtk4j/jni/DoubleField.h>

#include <org/projectsforge/hmmtk4j/jni/RandomGenerator.h>

#include <org/projectsforge/hmmtk4j/jni/Proxy.h>

#include <org/projectsforge/hmmtk4j/jni/JNIArrayOfReference.h>

#include <org/projectsforge/hmmtk4j/jni/ArrayOfBoolean_Java.h>
#include <org/projectsforge/hmmtk4j/jni/ArrayOfDouble_Java.h>
#include <org/projectsforge/hmmtk4j/jni/ArrayOfInteger_Java.h>

#ifdef HMMTK4J_FULL_INLINING
#include <org/projectsforge/hmmtk4j/jni/Object_inlines.h>
#include <org/projectsforge/hmmtk4j/jni/Field_inlines.h>

#include <org/projectsforge/hmmtk4j/jni/LongField_inlines.h>
#include <org/projectsforge/hmmtk4j/jni/BooleanField_inlines.h>
#include <org/projectsforge/hmmtk4j/jni/IntegerField_inlines.h>
#include <org/projectsforge/hmmtk4j/jni/DoubleField_inlines.h>

#include <org/projectsforge/hmmtk4j/jni/ArrayOfBoolean_Java_inlines.h>
#include <org/projectsforge/hmmtk4j/jni/ArrayOfDouble_Java_inlines.h>
#include <org/projectsforge/hmmtk4j/jni/ArrayOfInteger_Java_inlines.h>

#endif

#endif
