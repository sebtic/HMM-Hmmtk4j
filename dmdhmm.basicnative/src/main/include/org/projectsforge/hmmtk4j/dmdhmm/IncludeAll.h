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

#ifndef HMMTK4J_DMDHMM_IncludeAll_h
#define HMMTK4J_DMDHMM_IncludeAll_h

#include <org/projectsforge/hmmtk4j/discretehmm/IncludeAll.h>

#include <org/projectsforge/hmmtk4j/dmdhmm/IHMM.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/DynamicHMM.h>

#include <org/projectsforge/hmmtk4j/dmdhmm/ISequenceOfObservations.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/DynamicSequenceOfObservations.h>

#include <org/projectsforge/hmmtk4j/dmdhmm/IWeightedSequenceOfObservations.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/DynamicWeightedSequenceOfObservations.h>

#include <org/projectsforge/hmmtk4j/dmdhmm/Forward.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/FastForward.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/Backward.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/BaumWelch.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/Viterbi.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/LabelledTraining.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/SegmentalKMeans.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/Gradient.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/MaximalMutualInformation.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/FastForwardWithWeightedObservations.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/BaumWelchWithWeightedObservations.h>


#ifdef HMMTK4J_FULL_INLINING
#include <org/projectsforge/hmmtk4j/dmdhmm/IHMM_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/DynamicHMM_inlines.h>

#include <org/projectsforge/hmmtk4j/dmdhmm/ISequenceOfObservations_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/DynamicSequenceOfObservations_inlines.h>

#include <org/projectsforge/hmmtk4j/dmdhmm/IWeightedSequenceOfObservations_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/DynamicWeightedSequenceOfObservations_inlines.h>

#include <org/projectsforge/hmmtk4j/dmdhmm/Forward_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/FastForward_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/Backward_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/BaumWelch_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/Viterbi_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/LabelledTraining_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/SegmentalKMeans_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/Gradient_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/MaximalMutualInformation_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/FastForwardWithWeightedObservations_inlines.h>
#include <org/projectsforge/hmmtk4j/dmdhmm/BaumWelchWithWeightedObservations_inlines.h>

#endif

#endif
