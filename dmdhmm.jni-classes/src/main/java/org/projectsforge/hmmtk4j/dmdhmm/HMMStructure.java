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

package org.projectsforge.hmmtk4j.dmdhmm;

import java.io.Serializable;
import org.projectsforge.hmmtk4j.ArrayOfBoolean;
import org.projectsforge.hmmtk4j.DeepCloneable;
import org.projectsforge.hmmtk4j.MatrixOfBoolean;

/**
 * The Class HMMStructure.
 */
public class HMMStructure implements Cloneable, Serializable, DeepCloneable {

  /**
   * serialVersionUID
   */
  private static final long serialVersionUID = 4214508955057207801L;

  /** The a mask. */
  private final MatrixOfBoolean a = new MatrixOfBoolean();

  /** The b mask. */
  private MatrixOfBoolean b[] = new MatrixOfBoolean[0];

  /** The pi mask. */
  private final ArrayOfBoolean pi = new ArrayOfBoolean();

  /**
   * Instantiates a new hMM structure.
   */
  public HMMStructure() {
    resize(0, new int[] {});
  }

  /**
   * Instantiates a new hMM structure.
   * 
   * @param structure
   *          the structure
   */
  public HMMStructure(final HMMStructure structure) {
    copy(structure);
  }

  /**
   * Instantiates a new hMM structure.
   * 
   * @param stateCount
   *          the state count
   * @param symbolCount
   *          the symbol count
   */
  public HMMStructure(final int stateCount, final int[] symbolCounts) {
    resize(stateCount, symbolCounts);
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new HMMStructure(this);
  }

  /**
   * Copy.
   * 
   * @param hmms
   *          the hmms
   */
  public void copy(final HMMStructure hmms) {
    resize(hmms.getStateCount(), hmms.getSymbolCounts());
    a.copy(hmms.a);
    for (int index = 0; index < b.length; ++index) {
      b[index].copy(hmms.b[index]);
    }
    pi.copy(hmms.pi);
  }

  @Override
  public DeepCloneable deepClone() {
    return new HMMStructure(this);
  }

  /**
   * Gets the a mask.
   * 
   * @return the a mask
   */
  public MatrixOfBoolean getA() {
    return a;
  }

  /**
   * Gets the b mask.
   * 
   * @return the b mask
   */
  public MatrixOfBoolean getB(final int index) {
    return b[index];
  }

  /**
   * Gets the pi mask.
   * 
   * @return the pi mask
   */
  public ArrayOfBoolean getPi() {
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

  public int getSymbolComponentCount() {
    return b.length;
  }

  /**
   * Gets the symbol count.
   * 
   * @return the symbol count
   */
  public int getSymbolCount(final int index) {
    return b[index].getColCount();
  }

  public int[] getSymbolCounts() {
    final int[] result = new int[b.length];
    for (int index = 0; index < b.length; ++index) {
      result[index] = b[index].getColCount();
    }
    return result;
  }

  /**
   * Checks if the mask is valid.
   * 
   * @return true, if is valid
   */
  public boolean isValid() {
    boolean valid = true;
    for (final MatrixOfBoolean m : b) {
      valid = valid && m.isValidMask() && (a.getRowCount() == m.getRowCount());
    }
    return a.isValidMask() && valid && pi.isValidMask() && (a.getColCount() == a.getRowCount())
        && (a.getRowCount() == pi.getCount());
  }

  /**
   * Resize the mask.
   * 
   * @param stateCount
   *          the state count
   * @param symbolCount
   *          the symbol count
   */
  public void resize(final int stateCount, final int[] symbolCounts) {
    a.resize(stateCount, stateCount);

    final MatrixOfBoolean[] temp = new MatrixOfBoolean[symbolCounts.length];
    for (int index = 0; index < symbolCounts.length; ++index) {
      temp[index] = (index < b.length) ? b[index] : new MatrixOfBoolean();
      temp[index].resize(stateCount, symbolCounts[index]);
    }
    b = temp;
    pi.resize(stateCount);
  }
}
