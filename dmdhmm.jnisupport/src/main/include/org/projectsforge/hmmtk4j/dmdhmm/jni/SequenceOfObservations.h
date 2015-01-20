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

#ifndef HMMTK4J_DMDHMM_JNI_SequenceOfObservations_H
#define HMMTK4J_DMDHMM_JNI_SequenceOfObservations_H

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
          class SequenceOfObservations: public ISequenceOfObservations
          {
            public:
              /** The constructor */
              SequenceOfObservations();
              virtual ~SequenceOfObservations();
              void initializeJNI(const org::projectsforge::hmmtk4j::jni::Object & _self);
            private:
              SequenceOfObservations & operator=(const SequenceOfObservations &);
              SequenceOfObservations(const SequenceOfObservations &);
          };
        }
DECLARE_PROXY      ( ISequenceOfObservations, ISequenceOfObservations, ::org::projectsforge::hmmtk4j::dmdhmm::jni::SequenceOfObservations, "Lorg/projectsforge/hmmtk4j/dmdhmm/SequenceOfObservations;");
      DECLARE_JNIArrayOfReference( ArrayOfISequenceOfObservations, ISequenceOfObservations, ISequenceOfObservations, "[Lorg/projectsforge/hmmtk4j/dmdhmm/SequenceOfObservations;" );
    }}}}

#endif
