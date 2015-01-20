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

#ifndef HMMTK4J_Core_Ref_h
#define HMMTK4J_Core_Ref_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** A pointer like object that allows reference counting */
      template<class TReferenced>
      class Ref
      {
        private:
          TReferenced * reference;
        public:
          Ref()
          {
            reference = NULL;
          }
          Ref(const TReferenced * _reference)
          {
            Referenced::takeReference(_reference);
            reference = (TReferenced*) _reference;
          }
          Ref(const Ref<TReferenced> & ref)
          {
            reference = ref.reference;
            Referenced::takeReference(reference);
          }
          ~Ref()
          {
            Referenced::releaseReference(reference);
            reference = NULL;
          }
          TReferenced * getPtr() const
          {
            return reference;
          }
          TReferenced * operator->() const
          {
            return reference;
          }
          TReferenced & operator*() const
          {
            HMMTK4J_ASSERT_MSG(reference != NULL,
                "Can not dereference a NULL pointer");
            return *reference;
          }
          Ref<TReferenced> & operator=(const Ref<TReferenced> & ref)
          {
            Referenced::takeReference(ref.reference);
            Referenced::releaseReference(reference);
            reference = ref.reference;
            return *this;
          }
          Ref<TReferenced> & operator=(TReferenced * ref)
          {
            Referenced::takeReference(ref);
            Referenced::releaseReference(reference);
            reference = ref;
            return *this;
          }
          bool isNull()
          {
            return reference == NULL;
          }
      };
    }
  }
}

#endif
