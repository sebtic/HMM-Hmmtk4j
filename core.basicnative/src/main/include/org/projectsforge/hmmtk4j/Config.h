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

#ifndef HMMTK4J_Core_Config_h
#define HMMTK4J_Core_Config_h

#ifndef HMMTK4J_DEBUG
  /** Disable assertion checking */
  #define HMMTK4J_DISABLE_ASSERTS
  /** Disable arguments and index checking */
  #define HMMTK4J_DISABLE_EXPENSIVE_CHECKS
  /** Allow full inlining of the code */
  #define HMMTK4J_FULL_INLINING
#else
  #undef HMMTK4J_DISABLE_ASSERTS
  #undef HMMTK4J_DISABLE_EXPENSIVE_CHECKS
  #define HMMTK4J_FULL_INLINING
#endif

#endif
