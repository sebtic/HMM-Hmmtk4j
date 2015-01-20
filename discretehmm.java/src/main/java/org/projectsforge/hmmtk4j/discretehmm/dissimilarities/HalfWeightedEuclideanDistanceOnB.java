package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.discretehmm.HMM;

public class HalfWeightedEuclideanDistanceOnB implements Dissimilarity {

  @Override
  public double compute(final HMM first, final HMM second) {
    final MatrixOfDouble deltaB = new MatrixOfDouble(first.getB());
    deltaB.sub(second.getB());

    return Math.sqrt(deltaB.unrootedL2Norm() / first.getStateCount());
  }

}
