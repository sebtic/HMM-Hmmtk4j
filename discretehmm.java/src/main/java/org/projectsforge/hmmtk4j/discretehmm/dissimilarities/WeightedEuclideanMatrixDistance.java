package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.ArrayOfDouble;
import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.discretehmm.HMM;

public class WeightedEuclideanMatrixDistance implements Dissimilarity {

  @Override
  public double compute(final HMM first, final HMM second) {
    final MatrixOfDouble deltaA = new MatrixOfDouble(first.getA());
    deltaA.sub(second.getA());

    final MatrixOfDouble deltaB = new MatrixOfDouble(first.getB());
    deltaB.sub(second.getB());

    final ArrayOfDouble deltaPi = new ArrayOfDouble(first.getPi());
    deltaPi.sub(second.getPi());

    final int stateCount = first.getStateCount();
    final int symbolCount = first.getSymbolCount();

    return RobustMath.sqrt(deltaA.unrootedL2Norm() / (stateCount * stateCount)
        + deltaB.unrootedL2Norm() / (stateCount * symbolCount) + deltaPi.unrootedL2Norm()
        / stateCount);
  }

}
