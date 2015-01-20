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
import org.projectsforge.hmmtk4j.ArrayOfInteger;
import org.projectsforge.hmmtk4j.DeepCloneable;
import org.projectsforge.hmmtk4j.Randomizer;

/**
 * The Class SequenceOfObservations representing a sequence of discrete
 * elements.
 */
public final class SequenceOfObservations implements Cloneable, Serializable, DeepCloneable {

  /**
   * serialVersionUID
   */
  private static final long serialVersionUID = -3498304404697644996L;

  /** The maximum number of distinct values. */
  private int maxDistinctValues = 0;

  private final ArrayOfInteger data = new ArrayOfInteger();

  /**
   * Instantiates a new sequence.
   */
  public SequenceOfObservations() {
    ;
  }

  /**
   * Instantiates a new sequence.
   * 
   * @param maxDistinctValues
   *          the maximum number of distinct values
   */
  public SequenceOfObservations(final int maxDistinctValues) {
    setMaxDistinctValues(maxDistinctValues);
  }

  /**
   * Instantiates a new sequence.
   * 
   * @param maxDistinctValues
   *          the maximum number of distinct values
   * @param seq
   *          the sequence of symbols used for the initialization
   */
  public SequenceOfObservations(final int maxDistinctValues, final ArrayOfInteger seq) {
    setMaxDistinctValues(maxDistinctValues);
    data.copy(seq);
  }

  /**
   * Instantiates a new sequence.
   * 
   * @param sequenceOfObservations
   *          the sequence
   */
  public SequenceOfObservations(final SequenceOfObservations sequenceOfObservations) {
    copy(sequenceOfObservations);
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new SequenceOfObservations(this);
  }

  /**
   * Copy.
   * 
   * @param seq
   *          the seq
   */
  public void copy(final SequenceOfObservations seq) {
    data.copy(seq.data);
    maxDistinctValues = seq.maxDistinctValues;
  }

  @Override
  public DeepCloneable deepClone() {
    return new SequenceOfObservations(this);
  }

  /**
   * @return the data
   */
  public ArrayOfInteger getData() {
    return data;
  }

  public int getLength() {
    return data.getCount();
  }

  /**
   * Gets the maximum number of distinct values.
   * 
   * @return the maxDistinctValues
   */
  public int getMaxDistinctValues() {
    return this.maxDistinctValues;
  }

  /**
   * Checks if the elements have acceptable values.
   * 
   * @return true, if is valid
   */
  public boolean isValid() {
    for (int i = 0; i < data.getCount(); ++i) {
      final int e = data.get(i);
      if ((e < 0) || (e >= this.maxDistinctValues)) {
        System.out
            .println("SequenceOfObservations: The element " + e + " is not in the valid range [0;" + (this.maxDistinctValues - 1) + "]"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
        return false;
      }
    }
    return true;
  }

  /**
   * Random generate the sequence.
   */
  public void randomGenerate() {
    for (int i = 0; i < data.getCount(); ++i) {
      data.set(i, Randomizer.getRandomGenerator().nextInt(this.maxDistinctValues));
    }
  }

  /**
   * Sets the max distinct values.
   * 
   * @param maxDistinctValues
   *          the maxDistinctValues to set
   */
  public void setMaxDistinctValues(final int maxDistinctValues) {
    if (maxDistinctValues < 0) {
      throw new IllegalArgumentException("maxDistinctValues must be positive");
    }
    this.maxDistinctValues = maxDistinctValues;
  }
}
