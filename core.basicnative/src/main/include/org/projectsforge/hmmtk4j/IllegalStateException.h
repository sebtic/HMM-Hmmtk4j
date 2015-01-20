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

#ifndef HMMTK4J_Core_IllegalStateException_h
#define HMMTK4J_Core_IllegalStateException_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      /** The illegal state exception */
      class IllegalStateException: public Exception
      {
        public:
          /** The constructor.
           * @param _msg the message carried by the exception
           */
          IllegalStateException(const std::string & _msg);
      };
    }
  }
}

#endif
