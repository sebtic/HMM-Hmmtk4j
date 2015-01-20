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

#ifndef HMMTK4J_DiscreteHMM_JNI_WeightedSequenceOfObservations_inlines_H
#define HMMTK4J_DiscreteHMM_JNI_WeightedSequenceOfObservations_inlines_H

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        namespace jni
        {
          HMMTK4J_INLINE WeightedSequenceOfObservations::WeightedSequenceOfObservations()
          {
            ;
          }
          HMMTK4J_INLINE void WeightedSequenceOfObservations::initializeJNI(
              const org::projectsforge::hmmtk4j::jni::Object & _self)
          {
            sequence = Proxy_ISequenceOfObservations_getJavaFieldObject(_self, "sequence");

            weightField.init(_self, "weight");
            setWeight(weightField.getValue());
          }
          HMMTK4J_INLINE void WeightedSequenceOfObservations::setWeight(
              const Double value)
          {
            weightField.setValue(value);
            IWeightedSequenceOfObservations::setWeight(value);
          }
        }
      }
    }
  }
}

#endif
