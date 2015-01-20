package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.ArrayOfDouble;
import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.discretehmm.HMM;

public class MaxNormDistance implements Dissimilarity {

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

    double max = Double.MIN_VALUE;
    final double[] rowA = new double[stateCount];
    final double[] rowB = new double[symbolCount];
    for (int i = 0; i < stateCount; ++i) {
      deltaA.getRow(i, rowA);
      for (int j = 0; j < symbolCount; ++j) {
        max = Math.max(max, Math.abs(rowA[i]));
      }

      deltaB.getRow(i, rowB);
      for (int j = 0; j < symbolCount; ++j) {
        max = Math.max(max, Math.abs(rowB[i]));
      }

      max = Math.max(max, Math.abs(deltaPi.get(i)));
    }

    return max;
  }
}
