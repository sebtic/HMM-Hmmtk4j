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

#ifndef HMMTK4J_JNI_LongField_h
#define HMMTK4J_JNI_LongField_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        /** A class managing access to field of type long from a Java instance */
        class LongField
        {
          private:
            Field fieldwrap;
          public:
            /** A constructor
             *
             * @param _owner the owner Java instance
             * @param fieldname the field name
             */
            LongField(const Object & _owner, const char * fieldname);

            /** A constructor */
            LongField();

            /** Initialize the object
             *
             * @param _owner the owner Java instance
             * @param fieldname the field name
             */
            void init(const Object & _owner, const char * fieldname);

            /** Get the value of the field
             *
             * @return the value
             */
            Long getValue() const;

            /** Set the value of the field
             *
             * @param value the value
             */
            void setValue(Long value);

            /** Convenience operator to read the value of the field
             *
             * @return the value of the field
             */
            operator Long() const;

          private:
            LongField & operator=(const LongField &);
            LongField(const LongField &);
        };
      }
    }
  }
}

#endif
