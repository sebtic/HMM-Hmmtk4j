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

#ifndef HMMTK4J_DMDHMM_IHMM_inlines_h
#define HMMTK4J_DMDHMM_IHMM_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {
        HMMTK4J_INLINE IHMM::IHMM()
        {
          B = new ArrayOfReference<IMatrixOfDouble>();
        }

        HMMTK4J_INLINE void IHMM::copy(const Ref<IHMM> & hmm)
        {
          Pi->copy(hmm->Pi.getPtr());
          A->copy(hmm->A.getPtr());
          for( Integer index = 0; index < B->size; ++index)
            B->data[index]->copy(hmm->B->data[index].getPtr());
        }
      }
    }
  }
}

#endif
