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
import org.projectsforge.hmmtk4j.DeepCloneable;

// TODO: Auto-generated Javadoc
/**
 * The Class managing a weighted sequenceOfObservations.
 */
public final class WeightedSequenceOfObservations implements Cloneable, Serializable, DeepCloneable {

  /** The weight defaulting to 1. */
  private double weight = 1;

  private final SequenceOfObservations sequenceOfObservations = new SequenceOfObservations();

  /**
   * Instantiates a new weighted sequenceOfObservations.
   */
  public WeightedSequenceOfObservations() {
    // nothing to do
  }

  /**
   * Instantiates a new weighted sequenceOfObservations.
   * 
   * @param sequenceOfObservations
   *          the sequenceOfObservations
   * @param weight
   *          the weight
   */
  public WeightedSequenceOfObservations(final SequenceOfObservations sequenceOfObservations,
      final double weight) {
    sequenceOfObservations.copy(sequenceOfObservations);
    setWeight(weight);
  }

  /**
   * Instantiates a new weighted sequenceOfObservations.
   * 
   * @param weightedSequenceOfObservations
   *          the weighted sequenceOfObservations
   */
  public WeightedSequenceOfObservations(
      final WeightedSequenceOfObservations weightedSequenceOfObservations) {
    copy(weightedSequenceOfObservations);
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    return new WeightedSequenceOfObservations(this);
  }

  /**
   * Copy.
   * 
   * @param seq
   *          the seq
   */
  public void copy(final WeightedSequenceOfObservations seq) {
    sequenceOfObservations.copy(seq.sequenceOfObservations);
    weight = seq.weight;
  }

  @Override
  public DeepCloneable deepClone() {
    return new WeightedSequenceOfObservations(this);
  }

  /**
   * @return the sequenceOfObservations
   */
  public SequenceOfObservations getSequence() {
    return sequenceOfObservations;
  }

  /**
   * Gets the weight.
   * 
   * @return the weight
   */
  public double getWeight() {
    return weight;
  }

  /**
   * Sets the weight.
   * 
   * @param weight
   *          the weight to set
   */
  public void setWeight(final double weight) {
    if (weight <= 0) {
      throw new IllegalArgumentException("The weight must be strictly positive");
    }
    this.weight = weight;
  }
}
