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

#include <org/projectsforge/hmmtk4j/IncludeAll.h>
#include <signal.h>

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {

#ifdef HMMTK4J_DEBUG
      static Boolean debugHelper = false;
#endif

      Exception::Exception()
      {
        line = -1;
      }

      Exception::Exception(const String & _msg)
      {
        this->msg = _msg;
        line = -1;
      }

      void Exception::setMessage(const String & _msg)
      {
        this->msg = _msg;
      }

      String Exception::getMessage() const
      {
        return this->msg;
      }

      void Exception::setLocation(const String & _file, Integer _line)
      {
        this->file = _file;
        this->line = _line;
      }

      std::string Exception::getFile() const
      {
        return this->file;
      }

      Integer Exception::getLine() const
      {
        return this->line;
      }

      String Exception::what() const
      {
        char buf[1024];
        buf[0] = '\0';
        sprintf(buf, "%d", (int) line);
        return msg + " (" + file + "," + buf + ")";
      }

      void Exception::raiseSIGTRAP()
      {
#ifndef WIN32
#ifdef HMMTK4J_DEBUG
        if (debugHelper)
        raise(SIGTRAP);
#endif
#endif
      }

      void Exception::activateDebugHelper()
      {
#ifdef HMMTK4J_DEBUG
        debugHelper = true;
#endif
      }

      void Exception::desactivateDebugHelper()
      {
#ifdef HMMTK4J_DEBUG
        debugHelper = false;
#endif
      }

    }
  }
}
