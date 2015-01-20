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

#ifndef HMMTK4J_Core_IArrayOfDouble_h
#define HMMTK4J_Core_IArrayOfDouble_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      class IArrayOfDouble: public IArray<Double>
      {
        public:
          /** Subtract the elements of y
           *
           * @param y the second array
           */
          void sub(const Ref<IArray<Double> > & y);

          /** Add the elements of y
           *
           * @param y the second array
           */
          void add(const Ref<IArray<Double> >& y);

          /** Add a constant to the element of the array
           *
           * @param y the value to add
           */
          void add(const Double y);

          /** Multiply the elements of the two arrays
           *
           * @param y the second array
           */
          void mul(const Ref<IArray<Double> >& y);

          /** Multiply the elements of the array by y
           *
           * @param y the multiply value
           */
          void mul(const Double y);

          /** Compute the inner product of the two arrays
           *
           * @param y the second array
           * @return the inner product
           */
          Double innerProduct(const Ref<IArray<Double> >& y);

          /** Compute the sum of the elements of the array
           *
           * @return the sum of the elements
           */
          Double sumOfElements();

          /** Compute the sum of the absolute values of the elements of the array
           *
           * @return the sum of the absolute elements
           */
          Double sumOfAbsoluteElements();

          /** Compute the index of the maximum value of theIArray
           *
           * @return the index or -1 if theIArray is empty
           */
          Integer indexOfMaxElement();

          /** Compute the maximum value of the array
           *
           * @return the maximum value
           */
          Double maxElement();

          /** Compute the index of the minimum value of the array
           *
           * @return the index or -1 if theIArray if empty
           */
          Integer indexOfMinElement();

          /** Compute the minimum value of the array
           *
           * @return the minimum value
           */
          Double minElement();

          /** Count the number of times that the value appears in the array
           *
           * @param value the value to count
           * @return the number of times that the value appears in the array
           */
          Integer countElements(const Double value);

          /** Compute the classical norm of level N of the vector
           *
           * @param n the level of the norm
           * @return the norm
           */
          Double lNNorm(const Double n);

          /** Compute the classical norm of level N of the vector but not applying the root
           *
           * @param n the level of the norm
           * @return the unrooted norm
           */
          Double lNNormUnRooted(const Double n);

          /** Compute the infinite (a.k.a. max) norm of the vector
           *
           * @return the norm
           */
          Double infiniteNorm();

          /** Compute the mean of the vector
           *
           * @return the mean
           */
          Double mean();

          /** Compute the moment of specified order for the vector
           *
           * @param order the order of the moment
           * @return the moment
           */
          Double moment(const Double order);

          /** Compute the standard deviation of the vector
           *
           * @return the standard deviation
           */
          Double stdDev();

          /** Compute the max distance between the arrays
           *
           * @param y the secondIArray
           * @return the distance
           */
          Double maxDistance(const Ref<IArray<Double> >& y);

          /** Check if the elements of the array are in the range [minValue;maxValue]
           *
           * @param minValue the minimal value
           * @param maxValue the maximal value
           * @return true if the elements of the array are in the range [minValue;maxValue], false otherwise
           */
          Boolean isValid(const Double minValue, const Double maxValue);

          /** Apply a boolean mask on the array. If the boolean is false, the value is set to 0.
           *
           * @param y the boolean valued array
           */
          void applyMask(const Ref<IArray<Boolean> >& y);

          /** Transform the array into a stochastic vector
           *
           * @return the sum of the elements before the normalization
           */
          Double makeStochastic();

          /** Compute a weighted addition such that this->data[i] += b.data[i] * weight
           *
           * @param b the second array
           * @param weight the weight
           */
          void addWeighted(const Ref<IArray<Double> >& b, const Double weight);

          /** Raise the elements of the array to the power y
           *
           * @param y the power
           */
          void pow(const Double y);

      };
    }
  }
}

#endif
