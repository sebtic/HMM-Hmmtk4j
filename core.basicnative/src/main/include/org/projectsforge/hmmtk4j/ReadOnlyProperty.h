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

#ifndef HMMTK4J_Core_ReadOnlyProperty_h
#define HMMTK4J_Core_ReadOnlyProperty_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {

      /** @internal An internal class to easy the debugging of read only properties */
      template<class TData>
      class ReadOnly
      {
        public:
#ifdef HMMTK4J_DEBUG

          class TProperty
          {
            private:
            TData data;
            private:
            TProperty( const TProperty & p )
            {
              ;
            }
            TProperty & operator=( const TProperty & prop )
            {
              return *this;
            }
            public:
            TProperty()
            {
              ;
            }
            void set( const TData _data )
            {
              data = _data;
            }
            operator TData() const
            {
              return data;
            }
          };
#else

          typedef TData TProperty;
#endif

          class TProxy
          {
            private:
              TData data;
              TProperty * property;
            private:
              TProxy(const TProperty & p)
              {
                ;
              }
              TProxy & operator=(const TProperty & prop)
              {
                return *this;
              }
            public:
              TProxy() :
                property(NULL)
              {
                ;
              }
              void setProperty(TProperty * _property)
              {
                property = _property;
                update();
              }
              void update()
              {
                if (property != NULL)
                  ReadOnly<TData>::set(*property, data);
              }
              void set(const TData _data)
              {
                data = _data;
                update();
              }
              operator TData() const
              {
                return data;
              }
          };
        public:
          static inline void set(TProperty & property, const TData &data)
          {
#ifdef HMMTK4J_DEBUG
            property.set(data);
#else

            property = data;
#endif

          }
          static inline void set(TProxy & proxy, const TData & data)
          {
            proxy.set(data);
          }
      };
    }
  }
}

#endif
