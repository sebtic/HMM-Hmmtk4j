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
import org.projectsforge.hmmtk4j.ArrayOfDouble;
import org.projectsforge.hmmtk4j.DeepCloneable;
import org.projectsforge.hmmtk4j.MatrixOfDouble;

// TODO: Auto-generated Javadoc
/**
 * The Class representing a discrete HMM.
 */
public class HMM implements Cloneable, Serializable, DeepCloneable {

  /**
   * serialVersionUID
   */
  private static final long serialVersionUID = 74300177583384388L;

  /** The a matrix. */
  private final MatrixOfDouble a = new MatrixOfDouble();

  /** The b matrix. */
  private final MatrixOfDouble b = new MatrixOfDouble();

  /** The pi vector. */
  private final ArrayOfDouble pi = new ArrayOfDouble();

  /**
   * Instantiates a new HMM.
   */
  public HMM() {
    resize(0, 0);
  }

  /**
   * Instantiates a new hMM.
   * 
   * @param hmm
   *          the hmm
   */
  public HMM(final HMM hmm) {
    copy(hmm);
  }

  /**
   * Instantiates a new HMM.
   * 
   * @param stateCount
   *          the state count
   * @param symbolCount
   *          the symbol count
   */
  public HMM(final int stateCount, final int symbolCount) {
    resize(stateCount, symbolCount);
  }

  /**
   * Apply a mask on the HMM.
   * 
   * @param hmms
   *          the hmms
   */
  public void applyMask(final HMMStructure hmms) {
    a.applyMask(hmms.getA());
    a.makeStochastic();
    b.applyMask(hmms.getB());
    b.makeStochastic();
    pi.applyMask(hmms.getPi());
    pi.makeStochastic();
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new HMM(this);
  }

  /**
   * Copy.
   * 
   * @param hmm
   *          the hmm
   */
  public void copy(final HMM hmm) {
    a.copy(hmm.a);
    b.copy(hmm.b);
    pi.copy(hmm.pi);
  }

  @Override
  public DeepCloneable deepClone() {
    return new HMM(this);
  }

  /**
   * Gets the a matrix.
   * 
   * @return the a matrix
   */
  public MatrixOfDouble getA() {
    return a;
  }

  /**
   * Gets the b matrix.
   * 
   * @return the b matrix
   */
  public MatrixOfDouble getB() {
    return b;
  }

  /**
   * Gets the pi vector.
   * 
   * @return the pi vector
   */
  public ArrayOfDouble getPi() {
    return pi;
  }

  /**
   * Gets the state count.
   * 
   * @return the state count
   */
  public int getStateCount() {
    return pi.getCount();
  }

  /**
   * Gets the symbol count.
   * 
   * @return the symbol count
   */
  public int getSymbolCount() {
    return b.getColCount();
  }

  /**
   * Checks if the HMM is valid.
   * 
   * @return true, if is valid
   */
  public boolean isValid() {
    return a.isValid(0.0, 1.0) && b.isValid(0.0, 1.0) && pi.isValid(0.0, 1.0)
        && (a.getColCount() == a.getRowCount()) && (a.getRowCount() == b.getRowCount())
        && (a.getRowCount() == pi.getCount());
  }

  /**
   * Random generate the HMM.
   * 
   * @param allowNullProbabilities
   *          A flag indicating if null probabilities are allowed
   */
  public void randomGenerate(final boolean allowNullProbabilities) {
    pi.generateStochasticVector(allowNullProbabilities);
    a.generateStochasticMatrix(allowNullProbabilities);
    b.generateStochasticMatrix(allowNullProbabilities);
  }

  /**
   * Random generate the HMM from a HMM structure.
   * 
   * @param hmms
   *          the HMM structure
   */
  public void randomGenerate(final HMMStructure hmms) {
    // TODO : a revoir comme la fonction randomGenerate(boolean) ??
    pi.generateStochasticVector(false);
    a.generateStochasticMatrix(false);
    b.generateStochasticMatrix(false);
    applyMask(hmms);
  }

  /**
   * Resize the HMM.
   * 
   * @param stateCount
   *          the state count
   * @param symbolCount
   *          the symbol count
   */
  public void resize(final int stateCount, final int symbolCount) {
    a.resize(stateCount, stateCount);
    b.resize(stateCount, symbolCount);
    pi.resize(stateCount);
  }
}
