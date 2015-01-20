package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.discretehmm.HMM;

public class MeanMinimalEuclideanDistanceOnB implements Dissimilarity {
  @Override
  public double compute(final HMM first, final HMM second) {
    final int stateCount = first.getStateCount();
    final int symbolCount = first.getSymbolCount();

    final MatrixOfDouble deltaB = new MatrixOfDouble(first.getB());
    deltaB.sub(second.getB());

    double sum = 0;
    final double[] firstrow = new double[stateCount];
    final double[] secondrow = new double[stateCount];
    for (int i = 0; i < stateCount; ++i) {
      first.getB().getCol(i, firstrow);
      double min = Double.MAX_VALUE;
      for (int j = 0; j < stateCount; ++j) {
        second.getB().getCol(j, secondrow);
        double s = 0;
        for (int k = 0; k < symbolCount; ++k) {
          s += RobustMath.square(firstrow[k] - secondrow[k]);
        }
        min = Math.min(min, s);
      }
      sum += min;
    }
    return Math.sqrt(sum / (stateCount * first.getSymbolCount()));
  }
}
