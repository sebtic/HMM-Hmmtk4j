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

#ifndef HMMTK4J_DiscreteHMM_DynamicHMM_h
#define HMMTK4J_DiscreteHMM_DynamicHMM_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        /** A dynamic HMM */
        class DynamicHMM: public IHMM
        {
          public:
            /** The dynamic Pi matrix */
            Ref<DynamicArrayOfDouble> dynamic_Pi;
            /** The dynamic A matrix */
            Ref<DynamicMatrixOfDouble> dynamic_A;
            /** The dynamic B matrix */
            Ref<DynamicMatrixOfDouble> dynamic_B;
          public:
            DynamicHMM();
            /** Resize the HMM
             *
             * @param stateCount the state count
             * @param symbolCount the symbol count
             */
            void resize(Integer stateCount, Integer symbolCount);
            /** Copy a HMM
             *
             * @param hmm the HMM to be copied
             */
            virtual void copy(const Ref<IHMM> & hmm);
        };
      }
    }
  }
}

#endif
