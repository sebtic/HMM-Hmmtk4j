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

#ifndef HMMTK4J_Core_Exception_h
#define HMMTK4J_Core_Exception_h

#include <stdlib.h>
#include <string.h>
#include <iostream>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** The ancestor of all exceptions */
      class Exception
      {
        private:
          String msg;
          String file;
          Integer line;
        public:
          /** The default constructor */
          Exception();
          /** The constructor defining the message carried by the exception */
          Exception(const String & _msg);

          /** Define the message carried by the exception */
          void setMessage(const String & _msg);
          /** Get the message carried by the exception */
          String getMessage() const;
          /** Define the location where the exception is thrown */
          void setLocation(const String & _file, Integer _line);
          /** Get the file where the exception was thrown */
          String getFile() const;
          /** Get the line in the file where the exception was thrown */
          Integer getLine() const;
          /** Get a complete description of the carried data of the exception (message,file and line) */
          String what() const;

          /** Make a call to raise(SIGTRAP) in the debug version of the library if the debug help is enabled
           * @see activateDebugHelper
           * @see desactivateDebugHelper
           */
          static void raiseSIGTRAP();

          /** Enable the use of raise(SIGTRAP) when raising an exception to help in debugging
           * @warning This method has an effect only in the debug version of the library
           */
          static void activateDebugHelper();
          /** Disable the use of raise(SIGTRAP) when raising an exception to help in debugging
           * @warning This method has an effect only in the debug version of the library.
           * @attention By default, this debug help is disabled.
           */
          static void desactivateDebugHelper();
      };

    /** Raise a HMMTK4J exception derived from Exception */
  #define HMMTK4J_RaiseException(_e) \
      { \
        _e.setLocation( __FILE__, __LINE__ ); \
        std::cerr <<  "Exception : " << _e.what() << "\n"; \
        org::projectsforge::hmmtk4j::Exception::raiseSIGTRAP(); \
        throw _e; \
      }
    }
  }
}

#endif
