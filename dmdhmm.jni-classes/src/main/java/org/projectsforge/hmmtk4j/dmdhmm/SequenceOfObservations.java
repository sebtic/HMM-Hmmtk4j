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
import java.util.Arrays;
import java.util.Random;
import org.projectsforge.hmmtk4j.ArrayOfInteger;
import org.projectsforge.hmmtk4j.DeepCloneable;
import org.projectsforge.hmmtk4j.Randomizer;

public class SequenceOfObservations implements Cloneable, Serializable, DeepCloneable {

  private ArrayOfInteger data[] = new ArrayOfInteger[0];
  private int[] maxDistinctValues = new int[0];

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
   * @param seq
   *          the sequence of symbols used for the initialization
   */
  public SequenceOfObservations(final int maxDistinctValues[], final ArrayOfInteger seq[]) {
    setMaxDistinctValues(maxDistinctValues);
    data = new ArrayOfInteger[seq.length];
    for (int index = 0; index < seq.length; ++index) {
      data[index] = new ArrayOfInteger(seq[index]);
    }
  }

  /**
   * Instantiates a new sequence.
   * 
   * @param maxDistinctValues
   *          the maximum number of distinct values
   */
  public SequenceOfObservations(final int[] maxDistinctValues) {
    setMaxDistinctValues(maxDistinctValues);
  }

  public SequenceOfObservations(
      final org.projectsforge.hmmtk4j.discretehmm.SequenceOfObservations seq[]) {
    copy(seq);
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

  public void copy(final org.projectsforge.hmmtk4j.discretehmm.SequenceOfObservations seq[]) {
    final ArrayOfInteger temp[] = new ArrayOfInteger[seq.length];
    final int[] values = new int[seq.length];

    for (int index = 0; index < seq.length; ++index) {
      if (index < data.length) {
        temp[index] = data[index];
      } else {
        temp[index] = new ArrayOfInteger();
      }
      temp[index].copy(seq[index].getData());
      values[index] = seq[index].getMaxDistinctValues();
    }
    data = temp;
    maxDistinctValues = values;
  }

  /**
   * Copy.
   * 
   * @param seq
   *          the seq
   */
  public void copy(final SequenceOfObservations seq) {
    final ArrayOfInteger temp[] = new ArrayOfInteger[seq.data.length];

    for (int index = 0; index < seq.data.length; ++index) {
      if (index < data.length) {
        temp[index] = data[index];
      } else {
        temp[index] = new ArrayOfInteger();
      }
      temp[index].copy(seq.data[index]);
    }
    data = temp;
    maxDistinctValues = Arrays.copyOf(seq.maxDistinctValues, seq.maxDistinctValues.length);
  }

  @Override
  public DeepCloneable deepClone() {
    return new SequenceOfObservations(this);
  }

  public ArrayOfInteger[] getData() {
    return data;
  }

  /**
   * @return the data
   */
  public ArrayOfInteger getData(final int index) {
    return data[index];
  }

  public int getLength() {
    if (data.length == 0) {
      return 0;
    } else {
      return data[0].getCount();
    }
  }

  public int[] getMaxDistinctValues() {
    return Arrays.copyOf(maxDistinctValues, maxDistinctValues.length);
  }

  /**
   * Gets the maximum number of distinct values.
   * 
   * @return the maxDistinctValues
   */
  public int getMaxDistinctValues(final int index) {
    return this.maxDistinctValues[index];
  }

  /**
   * Checks if the elements have acceptable values.
   * 
   * @return true, if is valid
   */
  public boolean isValid() {
    // TODO : plus efficace
    for (int index = 0; index < data.length; ++index) {
      for (int i = 0; i < data[index].getCount(); ++i) {
        final int e = data[index].get(i);
        if ((e < 0) || (e >= this.maxDistinctValues[index])) {
          System.out.println("SequenceOfObservations: The element " + e
              + " is not in the valid range [0;" + (this.maxDistinctValues[index] - 1) + "]");
          return false;
        }
      }
    }
    return true;
  }

  /**
   * Random generate the sequence.
   */
  public void randomGenerate() {
    // TODO: plus efficace
    final Random generator = Randomizer.getRandomGenerator();
    for (int index = 0; index < data.length; ++index) {
      for (int i = 0; i < data[index].getCount(); ++i) {
        data[index].set(i, generator.nextInt(this.maxDistinctValues[index]));
      }
    }
  }

  /**
   * Sets the max distinct values.
   * 
   * @param maxDistinctValues
   *          the maxDistinctValues to set
   */
  public void setMaxDistinctValues(final int maxDistinctValues[]) {
    final ArrayOfInteger temp[] = new ArrayOfInteger[maxDistinctValues.length];

    for (int index = 0; index < maxDistinctValues.length; ++index) {
      if (index < data.length) {
        temp[index] = data[index];
      } else {
        temp[index] = new ArrayOfInteger();
      }
      if (maxDistinctValues[index] < 0) {
        throw new IllegalArgumentException("maxDistinctValues must be positive");
      }
    }
    data = temp;
    this.maxDistinctValues = Arrays.copyOf(maxDistinctValues, maxDistinctValues.length);
  }
}
