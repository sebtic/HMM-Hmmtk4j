package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.discretehmm.HMM;

/**
 * A fast approximation of the Kullback-Leibler distance.
 * <p>
 * The implementation and logic is adapted from
 * <em>Fast approximation of Kullback-Leibler distance for dependence trees and hidden markov models, Minh N. Do,
 * Signal Processing Letters, IEEE, Aug. 2003, pp250-250, volume 10, Issue 8, ISSN 1070-9908.</em>
 */
public class FastKullbackLeiblerDistance implements Dissimilarity {
  private int precision = 4;

  @Override
  public double compute(final HMM first, final HMM second) {
    return 0.5 * (computeAsymetric(first, second) + computeAsymetric(second, first));
  }

  public double computeAsymetric(final HMM first, final HMM second) {
    final int stateCount = first.getStateCount();
    final int symbolCount = first.getSymbolCount();

    final MatrixOfDouble temp = new MatrixOfDouble(first.getA());
    temp.fourthpowerSquareMatrix(getPrecision());

    double x[] = new double[stateCount];
    double[] pi = new double[stateCount];
    first.getPi().get(pi);
    for (int i = 0; i < first.getStateCount(); ++i) {
      x[i] = 0;
      for (int j = 0; j < first.getStateCount(); ++j) {
        x[i] += temp.get(i, j) * pi[j];
      }
    }

    double FKLD = 0;
    final double firstRowA[] = x; // we recycle the previous array
    x = null;
    final double secondRowA[] = pi; // we recycle the previous array
    pi = null;
    final double firstRowB[] = new double[symbolCount];
    final double secondRowB[] = new double[symbolCount];
    for (int i = 0; i < stateCount; ++i) {
      double sum = 0;
      first.getA().getRow(i, firstRowA);
      second.getA().getRow(i, secondRowA);

      first.getB().getRow(i, firstRowB);
      second.getB().getRow(i, secondRowB);
      for (int j = 0; j < stateCount; ++j) {
        sum += firstRowA[j] * (RobustMath.log(firstRowA[j]) - RobustMath.log(secondRowA[j]));
      }

      for (int j = 0; j < symbolCount; ++j) {
        sum += firstRowB[j] * (RobustMath.log(firstRowB[j]) - RobustMath.log(secondRowB[j]));
      }

      FKLD += x[i] * sum;
    }
    return FKLD;
  }

  public int getPrecision() {
    return precision;
  }

  public void setPrecision(final int precision) {
    if (precision < 0) {
      throw new IllegalArgumentException("precision can not be negative");
    }
    this.precision = precision;
  }
}
