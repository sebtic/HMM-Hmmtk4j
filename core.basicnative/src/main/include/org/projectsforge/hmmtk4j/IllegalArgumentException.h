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

#ifndef HMMTK4J_Core_IllegalArgumentException_h
#define HMMTK4J_Core_IllegalArgumentException_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** The illegal  argument exception */
      class IllegalArgumentException: public Exception
      {
        public:
          /** The constructor.
           * @param _msg the message carried by the exception
           */
          IllegalArgumentException(const std::string & _msg);
      };
    }
  }
}

/** Raise an IllegalArgumentException if Value < 0
 * @warning This check is done only when HMMTK4J_DISABLE_EXPENSIVE_CHECKS is not defined
 */
#ifndef HMMTK4J_DISABLE_EXPENSIVE_CHECKS
#define HMMTK4J_EnsureNonNegative( Value ) \
     if (Value < 0) \
     { \
      org::projectsforge::hmmtk4j::IllegalArgumentException __e( #Value " must be a non negative value"); \
      HMMTK4J_RaiseException(__e); \
     }
#else
#define HMMTK4J_EnsureNonNegative( Value ) { }
#endif

/** Raise an IllegalArgumentException if Value <= 0
 * @warning This check is done only when HMMTK4J_DISABLE_EXPENSIVE_CHECKS is not defined
 */
#ifndef HMMTK4J_DISABLE_EXPENSIVE_CHECKS
#define HMMTK4J_EnsurePositive( Value ) \
     if (Value <= 0) \
     { \
      org::projectsforge::hmmtk4j::IllegalArgumentException __e( #Value " must be a strictly positive value"); \
      HMMTK4J_RaiseException(__e); \
     }
#else
#define HMMTK4J_EnsurePositive( Value ) { }
#endif

/** Raise an IllegalArgumentException if test is false. The message carried by the exception is defined to msg
 * @warning This check is done only when HMMTK4J_DISABLE_EXPENSIVE_CHECKS is not defined
 */
#ifndef HMMTK4J_DISABLE_EXPENSIVE_CHECKS
#define HMMTK4J_CheckArgument( test, msg ) \
     if (!(test)) \
     { \
      org::projectsforge::hmmtk4j::IllegalArgumentException __e(msg); \
      HMMTK4J_RaiseException(__e); \
     }
#else
#define HMMTK4J_CheckArgument( test, msg ) { }
#endif

#endif
