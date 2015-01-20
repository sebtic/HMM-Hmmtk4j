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

#ifndef HMMTK4J_JNI_LongField_inlines_h
#define HMMTK4J_JNI_LongField_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        HMMTK4J_INLINE LongField::LongField(const Object & _owner,
            const char * fieldName)
        {
          init(_owner, fieldName);
        }
        HMMTK4J_INLINE LongField::LongField()
        {
          ;
        }
        HMMTK4J_INLINE void LongField::init(const Object & _owner,
            const char * fieldName)
        {
          fieldwrap.init(_owner, fieldName, "J");
        }

        HMMTK4J_INLINE Long LongField::getValue() const
        {
          return fieldwrap.getLongField();
        }

        HMMTK4J_INLINE void LongField::setValue(Long value)
        {
          fieldwrap.setLongField(value);
        }

        HMMTK4J_INLINE LongField::operator Long() const
        {
          return fieldwrap.getLongField();
        }
      }
    }
  }
}

#endif
