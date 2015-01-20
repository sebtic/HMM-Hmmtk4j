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

#ifndef HMMTK4J_JNI_Field_h
#define HMMTK4J_JNI_Field_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {
        /** An object to access a field of an Java instance */
        class Field
        {
          private:
            Object owner;
            jfieldID id_field;
            Object asObject;
          public:
            /** A constructor
             *
             * @param _owner the Java instance owning the field
             * @param _fieldName the field name
             * @param _typeName the JNI type name of the field (e.g. "Ljava/lang/String;")
             */
            Field(const Object & _owner, const char * _fieldName,
                const char * _typeName);

            /** The constructor */
            Field();

            /** Initialize the Field object from the parameters
             *
             * @param _owner the Java instance owning the field
             * @param _fieldName the field name
             * @param _typeName the JNI type name of the field (e.g. "Ljava/lang/String;")
             */
            void init(const Object & _owner, const char * _fieldName,
                const char * _typeName);

            /** Initialize the Object to reference the field
             *
             * @param o the Object that will reference the field
             */
            void getObject(Object & o) const;

            /** Define the value of the field if the field is of Java type int
             *
             * @param value the value
             */
            void setIntField(Integer value);

            /** Get the value of the field if the field is of Java type int
             *
             * @return the value
             */
            Integer getIntField() const;

            /** Define the value of the field if the field is of Java type long
             *
             * @param value the value
             */
            void setLongField(Long value);
            /** Get the value of the field if the field is of Java type long
             *
             * @return the value
             */

            Long getLongField() const;

            /** Define the value of the field if the field is of Java type double
             *
             * @param value the value
             */
            void setDoubleField(Double value);
            /** Get the value of the field if the field is of Java type double
             *
             * @return the value
             */

            Double getDoubleField() const;

            /** Define the value of the field if the field is of Java type boolean
             *
             * @param value the value
             */

            void setBooleanField(Boolean value);
            /** Get the value of the field if the field is of Java type boolean
             *
             * @return the value
             */
            Boolean getBooleanField() const;

          private:
            /** A copy constructor
             *
             * @param f the Field instance to copy
             */
            Field(const Field & f);
            /** The copy operator
             *
             * @param f the Field instance to copy
             */
            Field & operator=(const Field & f);
        };
      }
    }
  }
}

#endif
