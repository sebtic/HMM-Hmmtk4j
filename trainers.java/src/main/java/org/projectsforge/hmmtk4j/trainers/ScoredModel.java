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
package org.projectsforge.hmmtk4j.trainers;

import org.projectsforge.hmmtk4j.DeepCloneable;

/**
 * The Class ScoredModel.
 */
public class ScoredModel implements DeepCloneable, Cloneable {

  /** The model. */
  public DeepCloneable model;

  /** The score. */
  public double score;

  @Override
  protected Object clone() {
    return deepClone();
  }

  /**
   * Copy a model and a score.
   * 
   * @param model
   *          the model
   * @param score
   *          the score
   * @param needToDeepCloneModel
   *          a flag indicating if the model must be deep cloned
   */
  public void copy(final DeepCloneable model, final double score, final boolean needToDeepCloneModel) {
    if (needToDeepCloneModel) {
      this.model = model.deepClone();
    } else {
      this.model = model;
    }
    this.score = score;
  }

  /**
   * Copy a scored model.
   * 
   * @param sm
   *          the ScoredModel
   * @param needToDuplicateModel
   *          a flag indicating if the model must be deep duplicated
   */
  public void copy(final ScoredModel sm, final boolean needToDuplicateModel) {
    copy(sm.model, sm.score, needToDuplicateModel);
  }

  @Override
  public DeepCloneable deepClone() {
    final ScoredModel sm = new ScoredModel();
    sm.model = model.deepClone();
    sm.score = score;
    return sm;
  }

}
