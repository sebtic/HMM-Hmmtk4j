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

#include <org/projectsforge/hmmtk4j/IncludeAll.h>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      IndexOutOfBoundsException::IndexOutOfBoundsException(Integer _index,
          Integer _min, Integer _max) :
        index(_index), min(_min), max(_max)
      {
        char buf[1024];
        buf[0] = '\0';
        snprintf(buf, 1023, "Index %d out of bounds [%d;%d]", (int) _index,
            (int) _min, (int) _max);
        setMessage(buf);
      }

      Integer IndexOutOfBoundsException::getIndex() const
      {
        return index;
      }

      Integer IndexOutOfBoundsException::getMin() const
      {
        return min;
      }

      Integer IndexOutOfBoundsException::getMax() const
      {
        return max;
      }
    }
  }
}
