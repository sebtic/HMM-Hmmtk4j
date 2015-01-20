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

#ifndef HMMTK4J_DiscreteHMM_IncludeAll_h
#define HMMTK4J_DiscreteHMM_IncludeAll_h

#include <org/projectsforge/hmmtk4j/IncludeAll.h>

#include <org/projectsforge/hmmtk4j/discretehmm/IHMM.h>
#include <org/projectsforge/hmmtk4j/discretehmm/DynamicHMM.h>

#include <org/projectsforge/hmmtk4j/discretehmm/ISequenceOfObservations.h>
#include <org/projectsforge/hmmtk4j/discretehmm/DynamicSequenceOfObservations.h>

#include <org/projectsforge/hmmtk4j/discretehmm/IWeightedSequenceOfObservations.h>
#include <org/projectsforge/hmmtk4j/discretehmm/DynamicWeightedSequenceOfObservations.h>

#include <org/projectsforge/hmmtk4j/discretehmm/Forward.h>
#include <org/projectsforge/hmmtk4j/discretehmm/FastForward.h>
#include <org/projectsforge/hmmtk4j/discretehmm/Backward.h>
#include <org/projectsforge/hmmtk4j/discretehmm/BaumWelch.h>
#include <org/projectsforge/hmmtk4j/discretehmm/Viterbi.h>
#include <org/projectsforge/hmmtk4j/discretehmm/LabelledTraining.h>
#include <org/projectsforge/hmmtk4j/discretehmm/SegmentalKMeans.h>
#include <org/projectsforge/hmmtk4j/discretehmm/Gradient.h>
#include <org/projectsforge/hmmtk4j/discretehmm/MaximalMutualInformation.h>

#include <org/projectsforge/hmmtk4j/discretehmm/FastForwardWithWeightedObservations.h>
#include <org/projectsforge/hmmtk4j/discretehmm/BaumWelchWithWeightedObservations.h>

#ifdef HMMTK4J_FULL_INLINING
#include <org/projectsforge/hmmtk4j/discretehmm/IHMM_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/DynamicHMM_inlines.h>

#include <org/projectsforge/hmmtk4j/discretehmm/ISequenceOfObservations_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/DynamicSequenceOfObservations_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/IWeightedSequenceOfObservations_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/DynamicWeightedSequenceOfObservations_inlines.h>

#include <org/projectsforge/hmmtk4j/discretehmm/Forward_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/FastForward_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/Backward_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/BaumWelch_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/Viterbi_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/LabelledTraining_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/SegmentalKMeans_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/Gradient_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/MaximalMutualInformation_inlines.h>

#include <org/projectsforge/hmmtk4j/discretehmm/FastForwardWithWeightedObservations_inlines.h>
#include <org/projectsforge/hmmtk4j/discretehmm/BaumWelchWithWeightedObservations_inlines.h>
#endif

#endif
