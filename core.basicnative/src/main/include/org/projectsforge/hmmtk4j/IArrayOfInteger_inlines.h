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

#ifndef HMMTK4J_IArrayOfInteger_inlines_h
#define HMMTK4J_IArrayOfInteger_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {

      HMMTK4J_INLINE Integer IArrayOfInteger::countElements(Integer value)
      {
        Integer count = 0;
        for (Integer i = size - 1; i >= 0; --i)
          if (data[i] == value)
            count++;
        return count;
      }

      HMMTK4J_INLINE Boolean IArrayOfInteger::isValid(Integer minValue,
          Integer maxValue)
      {
        for (Integer i = size - 1; i >= 0; --i)
          if (data[i] < minValue || data[i] > maxValue)
          {
            // TODO : rewrite
            std::cerr << "Erreur Array : " << data[i] << " not in " << minValue
                << " " << maxValue << "\n";
            return false;
          }
        return true;
      }

      HMMTK4J_INLINE void IArrayOfInteger::applyMask(
          const Ref<IArray<Boolean> >& y)
      {
        HMMTK4J_CheckArgument(size == y->size, "Arrays must be of same size");
        for (Integer i = size - 1; i >= 0; --i)
          if (!y->data[i])
            data[i] = 0;
      }
    }
  }
}

#endif
