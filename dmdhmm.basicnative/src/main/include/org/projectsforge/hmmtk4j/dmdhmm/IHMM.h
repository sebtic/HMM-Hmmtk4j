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

#ifndef HMMTK4J_DMDHMM_IHMM_h
#define HMMTK4J_DMDHMM_IHMM_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace dmdhmm
      {
        /** A discrete hidden Markov model */
        class IHMM: public Referenced
        {
          public:
            /** The Pi matrix */
            Ref<IArrayOfDouble> Pi;
            /** The state transition matrix */
            Ref<IMatrixOfDouble> A;
            /** The symbol emission matrix */
            Ref<ArrayOfReference<IMatrixOfDouble> > B;
          public:
            /** The constructor */
            IHMM();

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
