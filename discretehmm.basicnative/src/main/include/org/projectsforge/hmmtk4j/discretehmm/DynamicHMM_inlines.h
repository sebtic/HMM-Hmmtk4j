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

#ifndef HMMTK4J_DiscreteHMM_DynamicHMM_inlines_h
#define HMMTK4J_DiscreteHMM_DynamicHMM_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace discretehmm
      {
        HMMTK4J_INLINE DynamicHMM::DynamicHMM()
        {
          dynamic_A = new DynamicMatrixOfDouble();
          A = dynamic_A.getPtr();
          dynamic_B = new DynamicMatrixOfDouble();
          B = dynamic_B.getPtr();
          dynamic_Pi = new DynamicArrayOfDouble();
          Pi = dynamic_Pi.getPtr();
        }
        HMMTK4J_INLINE void DynamicHMM::resize(Integer stateCount,
            Integer symbolCount)
        {
          dynamic_A->resize(stateCount, stateCount);
          dynamic_B->resize(stateCount, symbolCount);
          dynamic_Pi->resize(stateCount);
        }

        HMMTK4J_INLINE void DynamicHMM::copy(const Ref<IHMM> & hmm)
        {
          dynamic_A->copy(hmm->A.getPtr());
          dynamic_B->copy(hmm->B.getPtr());
          dynamic_Pi->copy(hmm->Pi.getPtr());
        }
      }
    }
  }
}

#endif
