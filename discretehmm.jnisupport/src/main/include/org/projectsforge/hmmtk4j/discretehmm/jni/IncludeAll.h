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

#ifndef HMMTK4J_DiscreteHMM_JNI_IncludeAll_h
#define HMMTK4J_DiscreteHMM_JNI_IncludeAll_h

#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>
#include <org/projectsforge/hmmtk4j/discretehmm/IncludeAll.h>

#include <org/projectsforge/hmmtk4j/discretehmm/jni/HMM.h>

#include <org/projectsforge/hmmtk4j/discretehmm/jni/SequenceOfObservations.h>
#include <org/projectsforge/hmmtk4j/discretehmm/jni/WeightedSequenceOfObservations.h>

#ifdef HMMTK4J_FULL_INLINING
#include <org/projectsforge/hmmtk4j/discretehmm/jni/HMM_inlines.h>

#include <org/projectsforge/hmmtk4j/discretehmm/jni/SequenceOfObservations_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/jni/WeightedSequenceOfObservations_inlines.h>
#endif

#endif
