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

#ifndef HMMTK4J_Core_AssertException_h
#define HMMTK4J_Core_AssertException_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** The assert exception for failed assertion */
      class AssertException: public Exception
      {
        public:
          /** The constructor
           * @param _msg the message carried by the exception
           */
          AssertException(const std::string & _msg);
      };
    }
  }
}

/** The assertion checker.
 * The message carried by the assertion is defined to msg
 * @warning This check is done only when HMMTK4J_DISABLE_ASSERTS is not defined
 */
#ifndef HMMTK4J_DISABLE_ASSERTS
  #define HMMTK4J_ASSERT_MSG( cond, msg ) \
    { \
     if (!(cond)) \
     { \
      org::projectsforge::hmmtk4j::AssertException __e( msg ); \
      HMMTK4J_RaiseException( __e ); \
     } \
    }
#else
  #define HMMTK4J_ASSERT_MSG( cond, msg ) { }
#endif

/** The assertion checker
 * @warning This check is done only when HMMTK4J_DISABLE_ASSERTS is not defined
 */
#define HMMTK4J_ASSERT( cond ) \
  HMMTK4J_ASSERT_MSG( cond, "Assertion " #cond " not verified" )

#endif
