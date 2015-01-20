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
package org.projectsforge.hmmtk4j.discretehmm;

import java.io.Serializable;
import java.util.Random;
import org.projectsforge.hmmtk4j.ArrayOfBoolean;
import org.projectsforge.hmmtk4j.ArrayOfDouble;
import org.projectsforge.hmmtk4j.MatrixOfBoolean;
import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.Randomizer;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.discretehmm.ClassicalAPITrainer.ClassicalModelArithmetic;
import org.projectsforge.hmmtk4j.discretehmm.NewAPITrainer.NewModelArithmetic;

public final class LambdaModelArithmetic implements ClassicalModelArithmetic, NewModelArithmetic,
    Serializable {

  /**
   * Modify by amplitude.
   * 
   * @param a
   *          the a
   * @param amplitude
   *          the amplitude
   */
  private static void modifyByAmplitude(final ArrayOfBoolean structure, final ArrayOfDouble a,
      final double amplitude) {
    if ((0 > amplitude) || (amplitude > 1)) {
      throw new IllegalArgumentException("The amplitude must be in the range [0;1] : " + amplitude);
    }

    do {
      final double v;
      final Random generator = Randomizer.getRandomGenerator();
      final int len = a.getCount();
      final double val[] = new double[len];
      a.get(val);
      for (int i = len - 1; i >= 0; --i) {
        val[i] += amplitude * (2 * generator.nextDouble() - 1);

        if (val[i] < 0) {
          val[i] = -val[i];
        }
        if (val[i] > 1) {
          val[i] = 2 - val[i];
        }
        val[i] = Math.max(val[i], 0.000001);
        a.set(val);
      }
    } while (RobustMath.isNull(a.makeStochastic()));
  }

  private static void modifyByAmplitude(final ArrayOfBoolean structure, final ArrayOfDouble a,
      final double minAmplitude, final double maxAmplitude) {
    do {
      final double v;
      final Random generator = Randomizer.getRandomGenerator();
      final int len = a.getCount();
      final double val[] = new double[len];
      a.get(val);
      for (int i = len - 1; i >= 0; --i) {
        if (generator.nextBoolean()) {
          val[i] += minAmplitude + (maxAmplitude - minAmplitude) * generator.nextDouble();
        } else {
          val[i] -= minAmplitude + (maxAmplitude - minAmplitude) * generator.nextDouble();
        }

        if (val[i] < 0) {
          val[i] = -val[i];
        }
        if (val[i] > 1) {
          val[i] = 2 - val[i];
        }
        val[i] = Math.max(val[i], 0.000001);
      }
      a.set(val);
      a.applyMask(structure);
    } while (RobustMath.isNull(a.makeStochastic()));
  }

  /**
   * Modify by amplitude.
   * 
   * @param hmm
   *          the hmm
   * @param amplitude
   *          the amplitude
   */
  private static void modifyByAmplitude(final HMMStructure hmmStructure, final HMM hmm,
      final double amplitude) {
    if (hmmStructure == null) {
      LambdaModelArithmetic.modifyByAmplitude(null, hmm.getA(), amplitude);
      LambdaModelArithmetic.modifyByAmplitude(null, hmm.getB(), amplitude);
      LambdaModelArithmetic.modifyByAmplitude(null, hmm.getPi(), amplitude);
    } else {
      LambdaModelArithmetic.modifyByAmplitude(hmmStructure.getA(), hmm.getA(), amplitude);
      LambdaModelArithmetic.modifyByAmplitude(hmmStructure.getB(), hmm.getB(), amplitude);
      LambdaModelArithmetic.modifyByAmplitude(hmmStructure.getPi(), hmm.getPi(), amplitude);
    }
  }

  private static void modifyByAmplitude(final HMMStructure hmmStructure, final HMM hmm,
      final double minAmplitude, final double maxAmplitude) {
    if (hmmStructure == null) {
      LambdaModelArithmetic.modifyByAmplitude(null, hmm.getA(), minAmplitude, maxAmplitude);
      LambdaModelArithmetic.modifyByAmplitude(null, hmm.getB(), minAmplitude, maxAmplitude);
      LambdaModelArithmetic.modifyByAmplitude(null, hmm.getPi(), minAmplitude, maxAmplitude);

    } else {
      LambdaModelArithmetic.modifyByAmplitude(hmmStructure.getA(), hmm.getA(), minAmplitude,
          maxAmplitude);
      LambdaModelArithmetic.modifyByAmplitude(hmmStructure.getB(), hmm.getB(), minAmplitude,
          maxAmplitude);
      LambdaModelArithmetic.modifyByAmplitude(hmmStructure.getPi(), hmm.getPi(), minAmplitude,
          maxAmplitude);
    }
  }

  /**
   * Modify by amplitude.
   * 
   * @param m
   *          the m
   * @param amplitude
   *          the amplitude
   */
  private static void modifyByAmplitude(final MatrixOfBoolean structure, final MatrixOfDouble m,
      final double amplitude) {

    if ((0 > amplitude) || (amplitude > 1)) {
      throw new IllegalArgumentException("The amplitude must be in the range [0;1] : " + amplitude);
    }

    do {
      final double v;
      final Random generator = Randomizer.getRandomGenerator();
      final int len = m.getColCount();
      final double val[] = new double[len];
      for (int i = m.getRowCount() - 1; i >= 0; --i) {
        m.getRow(i, val);
        for (int j = len - 1; j >= 0; --j) {
          val[i] += amplitude * (2 * generator.nextDouble() - 1);

          if (val[i] < 0) {
            val[i] = -val[i];
          }
          if (val[i] > 1) {
            val[i] = 2 - val[i];
          }
          val[i] = Math.max(val[i], 0.000001);

        }
        m.setRow(i, val);
      }
      m.applyMask(structure);
    } while (RobustMath.isNull(m.makeStochastic()));
  }

  private static void modifyByAmplitude(final MatrixOfBoolean structure, final MatrixOfDouble m,
      final double minAmplitude, final double maxAmplitude) {
    do {
      final double v;
      final Random generator = Randomizer.getRandomGenerator();
      final int len = m.getColCount();
      final double val[] = new double[len];
      for (int i = m.getRowCount() - 1; i >= 0; --i) {
        m.getRow(i, val);
        for (int j = len - 1; j >= 0; --j) {
          if (generator.nextBoolean()) {
            val[i] += minAmplitude + (maxAmplitude - minAmplitude) * generator.nextDouble();
          } else {
            val[i] -= minAmplitude + (maxAmplitude - minAmplitude) * generator.nextDouble();
          }

          if (val[i] < 0) {
            val[i] = -val[i];
          }
          if (val[i] > 1) {
            val[i] = 2 - val[i];
          }
          val[i] = Math.max(val[i], 0.000001);
        }
        m.setRow(i, val);
      }
      m.applyMask(structure);
    } while (RobustMath.isNull(m.makeStochastic()));
  }

  public HMM computeClassicalPositionFromSite(final HMMStructure hmmStructure, final HMM siteHMM,
      final double siteAmplitude) {
    final HMM hmm = (HMM) siteHMM.deepClone();
    LambdaModelArithmetic.modifyByAmplitude(hmmStructure, hmm, siteAmplitude);
    return hmm;
  }

  public HMM computeClassicalSiteFromNest(final HMMStructure hmmStructure, final HMM nestHMM,
      final double nestAmplitude) {
    final HMM hmm = (HMM) nestHMM.deepClone();
    LambdaModelArithmetic.modifyByAmplitude(hmmStructure, hmm, nestAmplitude);
    return hmm;
  }

  public HMM computeNewPositionFromSite(final HMMStructure hmmStructure, final HMM siteHMM,
      final double[] amplitudes, final int ringIndex, final double ringFusiness) {
    final HMM hmm = (HMM) siteHMM.deepClone();
    if (ringIndex == 0) {
      LambdaModelArithmetic
          .modifyByAmplitude(hmmStructure, hmm, (amplitudes[0] - 0) * ringFusiness);
    } else {
      LambdaModelArithmetic.modifyByAmplitude(hmmStructure, hmm,
          (amplitudes[ringIndex] - amplitudes[ringIndex - 1]) * ringFusiness);
    }
    return hmm;
  }

  public HMM computeNewSiteFromNest(final HMMStructure hmmStructure, final HMM nestHMM,
      final double[] amplitudes, final int ringIndex) {
    final HMM hmm = (HMM) nestHMM.deepClone();
    if (ringIndex == 0) {
      LambdaModelArithmetic.modifyByAmplitude(hmmStructure, hmm, 0, amplitudes[ringIndex]);
    } else {
      LambdaModelArithmetic.modifyByAmplitude(hmmStructure, hmm, amplitudes[ringIndex - 1],
          amplitudes[ringIndex]);
    }
    return hmm;
  }
}
