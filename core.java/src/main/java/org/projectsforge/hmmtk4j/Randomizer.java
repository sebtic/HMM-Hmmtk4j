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
package org.projectsforge.hmmtk4j;

import java.util.Random;
import org.projectsforge.hmmtk4j.nativeimplementors.Bridge;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.uncommons.maths.random.MersenneTwisterRNG;

/**
 * The Class Randomizer providing utility method related to random processes.
 */
public class Randomizer {

  private static Logger logger = LoggerFactory.getLogger(Randomizer.class);

  static {
    // setup a reasonnable default random number generator
    Randomizer.setRandomGenerator(new MersenneTwisterRNG());
    // shutdown hook to free the global ref taken in native code. Whithout this,
    // the JVM can not stop normally.
    Runtime.getRuntime().addShutdownHook(new Thread() {
      @Override
      public void run() {
        Randomizer.setRandomGenerator(null);
      }
    });
  }

  /** The generator. */
  private static Random generator;

  /**
   * Generate a stochastic matrix using a dichotomic approach
   * 
   * @param mat
   *          the matrix to be filled
   * @param allowNullProbabilities
   *          the flag indicating if null probabilities are allowed
   */
  public static final void generateAStochasticMatrix(final MatrixOfDouble mat,
      final boolean allowNullProbabilities) {
    for (int i = mat.getRowCount() - 1; i >= 0; --i) {
      Randomizer.generateAStochasticMatrixRow(mat, i, allowNullProbabilities);
    }
  }

  /**
   * Generate a stochastic matrix row using a dichotomic approach
   * 
   * @param mat
   *          the matrix to be filled
   * @param row
   *          the row index
   * @param allowNullProbabilities
   *          the flag indicating if null probabilities are allowed
   */
  public static final void generateAStochasticMatrixRow(final MatrixOfDouble mat, final int row,
      final boolean allowNullProbabilities) {
    double biais;
    if (allowNullProbabilities) {
      biais = 0;
    } else {
      biais = 0.0000001;
    }

    for (int i = mat.getColCount() - 1; i >= 0; --i) {
      mat.set(row, i, Randomizer.generator.nextDouble() + biais);
    }
    mat.makeStochasticRow(row);
  }

  /**
   * Generate a stochastic vector using a dichotomic approach
   * 
   * @param array
   *          the array to be filled
   * @param allowNullProbabilities
   *          the flag indicating if null probabilities are allowed
   */
  public static final void generateAStochasticVector(final ArrayOfDouble array,
      final boolean allowNullProbabilities) {
    double biais;
    if (allowNullProbabilities) {
      biais = 0;
    } else {
      biais = 0.0000001;
    }

    for (int i = array.getCount() - 1; i >= 0; --i) {
      array.set(i, Randomizer.generator.nextDouble() + biais);
    }
    array.makeStochastic();
  }

  public static Random getRandomGenerator() {
    return Randomizer.generator;
  }

  synchronized static void setRandomGenerator(final Random generator) {
    Bridge.setRandomGenerator(generator);
    Randomizer.generator = generator;
  }

}
