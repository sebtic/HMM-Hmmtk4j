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

#ifndef HMMTK4J_DMDHMM_JNI_WeightedSequenceOfObservations_H
#define HMMTK4J_DMDHMM_JNI_WeightedSequenceOfObservations_H

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {
        namespace jni
        {
          class WeightedSequenceOfObservations: public IWeightedSequenceOfObservations
          {
            private:
              org::projectsforge::hmmtk4j::jni::DoubleField weightField;
            public:
              /** The constructor */
              WeightedSequenceOfObservations();

              void initializeJNI(
                  const org::projectsforge::hmmtk4j::jni::Object & _self);

              /** Set the weight
               *
               * @param value the weight
               */
              void setWeight(const Double value);

            private:
              WeightedSequenceOfObservations & operator=(
                  const WeightedSequenceOfObservations &);
              WeightedSequenceOfObservations(
                  const WeightedSequenceOfObservations &);
          };

DECLARE_PROXY        ( IWeightedSequenceOfObservations, IWeightedSequenceOfObservations, ::org::projectsforge::hmmtk4j::dmdhmm::jni::WeightedSequenceOfObservations, "Lorg/projectsforge/hmmtk4j/dmdhmm/WeightedSequenceOfObservations;");
        DECLARE_JNIArrayOfReference( ArrayOfIWeightedSequenceOfObservations, IWeightedSequenceOfObservations, IWeightedSequenceOfObservations, "[Lorg/projectsforge/hmmtk4j/dmdhmm/WeightedSequenceOfObservations;" );
      }}
  }}}

#endif
