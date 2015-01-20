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

#ifndef HMMTK4J_JNI_IntegerField_h
#define HMMTK4J_JNI_IntegerField_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        /** A class managing access to field of type int from a Java instance */
        class IntegerField
        {
          private:
            Field fieldwrap;
          public:
            /** A constructor
             *
             * @param _owner the owner Java instance
             * @param fieldname the field name
             */
            IntegerField(const Object & _owner, const char * fieldname);

            /** A constructor */
            IntegerField();

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
            Integer getValue() const;

            /** Set the value of the field
             *
             * @param value the value
             */
            void setValue(const Integer value);

            /** Convenience operator to read the value of the field
             *
             * @return the value of the field
             */
            operator Integer() const;

          private:
            IntegerField & operator=(const IntegerField &);
            IntegerField(const IntegerField &);
        };
      }
    }
  }
}

#endif
