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

#ifndef HMMTK4J_Core_Referenced_h
#define HMMTK4J_Core_Referenced_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** The top class that allows to manage the instances with reference counting */
      class Referenced
      {
        private:
          int refCounter;
          Mutex mutex;
        public:
          Referenced()
          {
            refCounter = 0;
          }
          virtual ~Referenced()
          {
            ;
          }
          static inline void takeReference(const Referenced * ptr)
          {
            if (ptr != NULL)
            {
              CriticalSection cs(((Referenced *) ptr)->mutex);
              ((Referenced *) ptr)->refCounter++;
            }
          }
          static inline void releaseReference(const Referenced * ptr)
          {
            bool deleteObject = false;

            {
              if (ptr != NULL)
              {
                CriticalSection cs(((Referenced *) ptr)->mutex);
                ((Referenced *) ptr)->refCounter--;
                if (ptr->refCounter == 0)
                  deleteObject = true;
              }
            }
            if (deleteObject)
              delete ((Referenced *) ptr);
          }
      };
    }
  }
}

#endif
