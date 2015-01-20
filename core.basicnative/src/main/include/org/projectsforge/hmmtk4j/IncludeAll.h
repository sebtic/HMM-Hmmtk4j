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

#ifndef HMMTK4J_IncludeAll_h
#define HMMTK4J_IncludeAll_h

#include <org/projectsforge/hmmtk4j/Config.h>
#include <org/projectsforge/hmmtk4j/Inliner.h>

#include <org/projectsforge/hmmtk4j/BasicType.h>

#include <org/projectsforge/hmmtk4j/Math.h>

#include <org/projectsforge/hmmtk4j/Exception.h>
#include <org/projectsforge/hmmtk4j/AssertException.h>
#include <org/projectsforge/hmmtk4j/IndexOutOfBoundsException.h>
#include <org/projectsforge/hmmtk4j/IllegalArgumentException.h>
#include <org/projectsforge/hmmtk4j/IllegalStateException.h>
#include <org/projectsforge/hmmtk4j/MemoryException.h>
#include <org/projectsforge/hmmtk4j/RuntimeException.h>

#include <org/projectsforge/hmmtk4j/Mutex.h>

#include <org/projectsforge/hmmtk4j/Referenced.h>
#include <org/projectsforge/hmmtk4j/Ref.h>

#include <org/projectsforge/hmmtk4j/RandomGenerator.h>

#include <org/projectsforge/hmmtk4j/Memory.h>
#include <org/projectsforge/hmmtk4j/ReadOnlyProperty.h>

#include <org/projectsforge/hmmtk4j/IArray.h>
#include <org/projectsforge/hmmtk4j/IArrayOfInteger.h>
#include <org/projectsforge/hmmtk4j/IArrayOfDouble.h>
#include <org/projectsforge/hmmtk4j/IArrayOfBoolean.h>
#include <org/projectsforge/hmmtk4j/DynamicArray.h>
#include <org/projectsforge/hmmtk4j/ArrayOfReference.h>

#include <org/projectsforge/hmmtk4j/IMatrix.h>
#include <org/projectsforge/hmmtk4j/IMatrixOfDouble.h>
#include <org/projectsforge/hmmtk4j/IMatrixOfInteger.h>
#include <org/projectsforge/hmmtk4j/IMatrixOfBoolean.h>
#include <org/projectsforge/hmmtk4j/DynamicMatrix.h>


#ifdef HMMTK4J_FULL_INLINING
#include <org/projectsforge/hmmtk4j/Math_inlines.h>

#include <org/projectsforge/hmmtk4j/RandomGenerator_inlines.h>

#include <org/projectsforge/hmmtk4j/IArrayOfBoolean_inlines.h>
#include <org/projectsforge/hmmtk4j/IArrayOfInteger_inlines.h>
#include <org/projectsforge/hmmtk4j/IArrayOfDouble_inlines.h>

#include <org/projectsforge/hmmtk4j/IMatrixOfBoolean_inlines.h>
#include <org/projectsforge/hmmtk4j/IMatrixOfInteger_inlines.h>
#include <org/projectsforge/hmmtk4j/IMatrixOfDouble_inlines.h>

#endif

#endif
