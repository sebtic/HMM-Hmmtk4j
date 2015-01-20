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

#ifndef HMMTK4J_DiscreteHMM_JNI_SequenceOfObservations_inlines_H
#define HMMTK4J_DiscreteHMM_JNI_SequenceOfObservations_inlines_H

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
          HMMTK4J_INLINE SequenceOfObservations::SequenceOfObservations()
          {
            ;
          }

          HMMTK4J_INLINE void SequenceOfObservations::initializeJNI(
              const org::projectsforge::hmmtk4j::jni::Object & _self)
          {
            data
                = Proxy_DynamicArrayOfInteger_getJavaFieldObject(_self, "data");

            maxDistinctValuesField.init(_self, "maxDistinctValues");
            ReadOnly<Integer>::set(maxDistinctValues,
                maxDistinctValuesField.getValue());
          }

          HMMTK4J_INLINE void SequenceOfObservations::setMaxDistinctValues(
              const Integer value)
          {
            maxDistinctValuesField.setValue(value);
            ISequenceOfObservations::setMaxDistinctValues(value);
          }
        }
      }
    }
  }
}

#endif
