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

#include <org/projectsforge/hmmtk4j/jni/IncludeAll.h>

#ifndef HMMTK4J_FULL_INLINING
#include <org/projectsforge/hmmtk4j/jni/ArrayOfBoolean_Java_inlines.h>
#endif

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        ArrayOfBoolean_Java & ArrayOfBoolean_Java::operator=(
            const ArrayOfBoolean_Java &)
        {
          return *this;
        }

        ArrayOfBoolean_Java::ArrayOfBoolean_Java(const ArrayOfBoolean_Java &)
        {
        }
      }
    }
  }
}

