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

#ifndef HMMTK4J_DMDHMM_DynamicHMM_inlines_h
#define HMMTK4J_DMDHMM_DynamicHMM_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {
        HMMTK4J_INLINE DynamicHMM::DynamicHMM()
        {
          dynamic_A = new DynamicMatrixOfDouble();
          A = dynamic_A.getPtr();
          dynamic_B = new ArrayOfReference<DynamicMatrixOfDouble> ();
          B->clear();
          dynamic_Pi = new DynamicArrayOfDouble();
          Pi = dynamic_Pi.getPtr();
        }
        HMMTK4J_INLINE void DynamicHMM::resize(Integer stateCount, const Ref<
            IArray<Integer> > & symbolCounts)
        {
          dynamic_A->resize(stateCount, stateCount);
          dynamic_B->resize(symbolCounts->size);
          B->resize(symbolCounts->size);
          for (Integer index = 0; index < symbolCounts->size; ++index)
          {
            if (dynamic_B->data[index].isNull())
              dynamic_B->data[index] = new DynamicMatrixOfDouble();
            dynamic_B->data[index]->resize(stateCount,
                symbolCounts->data[index]);
            B->data[index] = dynamic_B->data[index].getPtr();
          }
          dynamic_Pi->resize(stateCount);
        }

        HMMTK4J_INLINE void DynamicHMM::copy(const Ref<IHMM> & hmm)
        {
          dynamic_A->copy(hmm->A.getPtr());
          Integer stateCount = hmm->A->rowCount;
          dynamic_B->resize(hmm->B->size);
          B->resize(hmm->B->size);
          for (Integer index = 0; index < dynamic_B->size; ++index)
          {
            if (dynamic_B->data[index].isNull())
              dynamic_B->data[index] = new DynamicMatrixOfDouble();
            dynamic_B->data[index]->resize(stateCount,
                hmm->B->data[index]->colCount);
            dynamic_B->data[index]->copy(hmm->B->data[index].getPtr());
            B->data[index] = dynamic_B->data[index].getPtr();
          }
          dynamic_Pi->copy(hmm->Pi.getPtr());
        }
      }
    }
  }
}

#endif
