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

#ifndef HMMTK4J_JNI_Field_inlines_h
#define HMMTK4J_JNI_Field_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      namespace jni
      {

        HMMTK4J_INLINE Field::Field()
        {
          id_field = 0;
        }

        HMMTK4J_INLINE Field::Field(const Object & _owner,
            const char * fieldName, const char * typeName)
        {
          init(_owner, fieldName, typeName);
        }

        HMMTK4J_INLINE void Field::init(const Object & _owner,
            const char * fieldName, const char * typeName)
        {
          owner.copy(_owner);
          id_field = owner.jenv->GetFieldID(owner.getClassId(), fieldName,
              typeName);

          if (id_field == 0)
          {
            std::cerr << "Error 'Field::init(const Object & _owner, const char * fieldName, const char * typeName)' failed : "
                << fieldName << " " << typeName << std::endl;
          }
          HMMTK4J_JNIError( id_field);
        }

        HMMTK4J_INLINE void Field::getObject(Object & o) const
        {
          o.init(owner.jenv, owner.jenv->GetObjectField(owner.self, id_field));
        }

        HMMTK4J_INLINE void Field::setIntField(Integer value)
        {
          owner.jenv->SetIntField(owner.self, id_field, value);
        }

        HMMTK4J_INLINE Integer Field::getIntField() const
        {
          return owner.jenv->GetIntField(owner.self, id_field);
        }

        HMMTK4J_INLINE void Field::setLongField(Long value)
        {
          owner.jenv->SetLongField(owner.self, id_field, value);
        }

        HMMTK4J_INLINE Long Field::getLongField() const
        {
          return owner.jenv->GetLongField(owner.self, id_field);
        }

        HMMTK4J_INLINE void Field::setDoubleField(Double value)
        {
          owner.jenv->SetDoubleField(owner.self, id_field, value);
        }

        HMMTK4J_INLINE Double Field::getDoubleField() const
        {
          return owner.jenv->GetDoubleField(owner.self, id_field);
        }

        HMMTK4J_INLINE void Field::setBooleanField(Boolean value)
        {
          owner.jenv->SetBooleanField(owner.self, id_field, value);
        }

        HMMTK4J_INLINE Boolean Field::getBooleanField() const
        {
          return owner.jenv->GetBooleanField(owner.self, id_field);
        }
      }
    }
  }
}

#endif
