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

#ifndef HMMTK4J_IArrayOfDouble_inlines_h
#define HMMTK4J_IArrayOfDouble_inlines_h

namespace org
{
  namespace projectsforge
  {
    namespace hmmtk4j
    {
      HMMTK4J_INLINE void IArrayOfDouble::sub(const Ref<IArray<Double> >& y)
      {
        HMMTK4J_CheckArgument(size == y->size, "Arrays must be of same size");
        for (Integer i = size - 1; i >= 0; --i)
          data[i] -= y->data[i];
      }

      HMMTK4J_INLINE void IArrayOfDouble::add(const Ref<IArray<Double> >& y)
      {
        HMMTK4J_CheckArgument(size == y->size, "Arrays must be of same size");
        for (Integer i = size - 1; i >= 0; --i)
          data[i] += y->data[i];
      }

      HMMTK4J_INLINE void IArrayOfDouble::add(const Double y)
      {
        for (Integer i = size - 1; i >= 0; --i)
          data[i] += y;
      }

      HMMTK4J_INLINE void IArrayOfDouble::mul(const Ref<IArray<Double> >& y)
      {
        HMMTK4J_CheckArgument(size == y->size, "Arrays must be of same size");
        for (Integer i = size - 1; i >= 0; --i)
          data[i] *= y->data[i];
      }

      HMMTK4J_INLINE void IArrayOfDouble::mul(const Double y)
      {
        for (Integer i = size - 1; i >= 0; --i)
          data[i] *= y;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::innerProduct(const Ref<IArray<
          Double> >& y)
      {
        Double sum = 0;
        HMMTK4J_CheckArgument(size == y->size, "Arrays must be of same size");
        for (Integer i = size - 1; i >= 0; --i)
          sum += data[i] * y->data[i];
        return sum;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::sumOfElements()
      {
        Double sum = 0;
        for (Integer i = size - 1; i >= 0; --i)
          sum += data[i];
        return sum;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::sumOfAbsoluteElements()
      {
        Double sum = 0;
        for (Integer i = size - 1; i >= 0; --i)
          sum += fabs(data[i]);
        return sum;
      }

      HMMTK4J_INLINE Integer IArrayOfDouble::indexOfMaxElement()
      {
        Integer maxIndex = -1;
        for (Integer i = size - 1; i >= 0; --i)
          if (maxIndex == -1 || data[maxIndex] < data[i])
            maxIndex = i;
        return maxIndex;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::maxElement()
      {
        Integer maxIndex = indexOfMaxElement();
        HMMTK4J_CheckArgument(maxIndex != -1, "The array is empty");
        return data[maxIndex];
      }

      HMMTK4J_INLINE Integer IArrayOfDouble::indexOfMinElement()
      {
        Integer minIndex = -1;
        for (Integer i = size - 1; i >= 0; --i)
          if (minIndex == -1 || data[minIndex] > data[i])
            minIndex = i;
        return minIndex;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::minElement()
      {
        Integer minIndex = indexOfMinElement();
        HMMTK4J_CheckArgument(minIndex != -1, "The array is empty");
        return data[minIndex];
      }

      HMMTK4J_INLINE Integer IArrayOfDouble::countElements(Double value)
      {
        Integer count = 0;
        for (Integer i = size - 1; i >= 0; --i)
          if (Math::isNull(data[i] - value))
            count++;
        return count;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::lNNorm(Double n)
      {
        Double sum = 0;
        HMMTK4J_CheckArgument(n <= 0, "n must be strictly positive");
        for (Integer i = size - 1; i >= 0; --i)
          sum += Math::pow(fabs(data[i]), n);
        return Math::pow(sum, 1. / n);
      }

      HMMTK4J_INLINE Double IArrayOfDouble::lNNormUnRooted(Double n)
      {
        Double sum = 0;
        HMMTK4J_CheckArgument(n <= 0, "n must be strictly positive");
        for (Integer i = size - 1; i >= 0; --i)
          sum += Math::pow(fabs(data[i]), n);
        return sum;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::infiniteNorm()
      {
        Integer maxIndex = -1;
        for (Integer i = size - 1; i >= 0; --i)
          if (maxIndex == -1 || fabs(data[maxIndex]) < fabs(data[i]))
            maxIndex = i;
        HMMTK4J_CheckArgument(maxIndex != -1, "The array is empty");
        return data[maxIndex];
      }

      HMMTK4J_INLINE Double IArrayOfDouble::mean()
      {
        Double sum = 0;
        for (Integer i = size - 1; i >= 0; --i)
          sum += data[i];
        HMMTK4J_CheckArgument(size > 0, "The array is empty");
        return sum / size;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::moment(Double order)
      {
        Double m = mean();
        HMMTK4J_CheckArgument(order > 0, "The order must be strictly positive");
        Double sum = 0;
        for (Integer i = size - 1; i >= 0; --i)
          sum += Math::pow(fabs((Double) data[i] - m), order);
        return sum / size;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::stdDev()
      {
        Double s1 = 0;
        Double s2 = mean();

        for (Integer i = size - 1; i >= 0; --i)
          s1 += data[i] * data[i];

        Double s = s1 / size - s2 * s2;
        if (s <= 0)
          return 0;

        return sqrt(s);
      }

      HMMTK4J_INLINE Double IArrayOfDouble::maxDistance(const Ref<
          IArray<Double> >& y)
      {
        Double m = -DBL_MAX;
        HMMTK4J_CheckArgument(size == y->size, "Arrays must be of same size");
        for (Integer i = size - 1; i >= 0; --i)
          m = Math::max(m, data[i] - y->data[i]);
        return m;
      }

      HMMTK4J_INLINE Boolean IArrayOfDouble::isValid(Double minValue,
          Double maxValue)
      {
        for (Integer i = size - 1; i >= 0; --i)
          if (data[i] < minValue || data[i] > maxValue)
          {
            std::cerr << "Erreur Array : " << data[i] << " not in " << minValue
                << " " << maxValue << "\n";
            return false;
          }
        return true;
      }

      HMMTK4J_INLINE void IArrayOfDouble::applyMask(
          const Ref<IArray<Boolean> >& y)
      {
        HMMTK4J_CheckArgument(size == y->size, "Arrays must be of same size");
        for (Integer i = size - 1; i >= 0; --i)
          if (!y->data[i])
            data[i] = 0.0;
      }

      HMMTK4J_INLINE Double IArrayOfDouble::makeStochastic()
      {
        Double sum = 0;
        for (Integer i = size - 1; i >= 0; --i)
          sum += data[i];
        if (sum > 0)
        {
          Double inv = 1.0 / sum;
          for (Integer i = size - 1; i >= 0; --i)
            data[i] *= inv;
        }
        return sum;
      }

      HMMTK4J_INLINE void IArrayOfDouble::addWeighted(
          const Ref<IArray<Double> >& b, const Double weight)
      {
        HMMTK4J_ASSERT(size == b->size);
        for (Integer i = size - 1; i >= 0; --i)
          data[i] += b->data[i] * weight;
      }

      HMMTK4J_INLINE void IArrayOfDouble::pow(const Double y)
      {
        if (Math::isNull(y))
          fill(1.);
        else
          for (Integer i = size - 1; i >= 0; --i)
            data[i] = Math::pow(data[i], y);
      }
    }
  }
}

#endif
