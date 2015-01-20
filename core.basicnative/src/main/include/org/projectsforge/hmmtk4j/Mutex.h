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

#ifndef HMMTK4J_Core_Mutex_h
#define HMMTK4J_Core_Mutex_h

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** A mutex class */
      class Mutex
      {
        private:
#ifdef WIN32
          CRITICAL_SECTION mutex;
#else        
          pthread_mutex_t mutex;
#endif          
        private:
          Mutex(const Mutex &)
          {
          }
          Mutex & operator=(const Mutex &)
          {
            return *this;
          }
        public:
          /** The constructor */
          Mutex()
          {
#ifdef WIN32
            InitializeCriticalSection(&mutex);
#else
            if (pthread_mutex_init(&mutex, NULL) != 0)
            {
              org::projectsforge::hmmtk4j::RuntimeException __e(
                  "pthread_mutex_init failed");
              HMMTK4J_RaiseException(__e);
            }
#endif            
          }
          /** The destructor */
          ~Mutex()
          {
#ifndef WIN32          
            if (pthread_mutex_destroy(&mutex) != 0)
            {
              org::projectsforge::hmmtk4j::RuntimeException __e(
                  "pthread_mutex_destroy failed");
              HMMTK4J_RaiseException(__e);
            }
#endif            
          }
          /** Lock the mutex */
          void lock()
          {
#ifdef WIN32
            EnterCriticalSection(&mutex);
#else          
            if (pthread_mutex_lock(&mutex) != 0)
            {
              org::projectsforge::hmmtk4j::RuntimeException __e(
                  "pthread_mutex_lock failed");
              HMMTK4J_RaiseException(__e);
            }
#endif            
          }
          /** Unlock the mutex */
          void unlock()
          {
#ifdef WIN32
            LeaveCriticalSection(&mutex);
#else          
            if (pthread_mutex_unlock(&mutex) != 0)
            {
              org::projectsforge::hmmtk4j::RuntimeException __e(
                  "pthread_mutex_unlock failed");
              HMMTK4J_RaiseException(__e);
            }
#endif            
          }
      };

      /** A class that automatically enforce critical section associated with a mutex */
      class CriticalSection
      {
        private:
          Mutex * mutex;
        private:
          CriticalSection(const CriticalSection &) :
            mutex(NULL)
          {
          }
          CriticalSection & operator=(const CriticalSection &)
          {
            return *this;
          }
        public:
          /** The constructor which begins the critical section.
           * @param _mutex the mutex associated with the critical section
           */
          CriticalSection(Mutex & _mutex) :
            mutex(&_mutex)
          {
            mutex->lock();
          }
          /** The destructor which ends the critical section */
          ~CriticalSection()
          {
            mutex->unlock();
          }
      };
    }
  }
}

#endif
