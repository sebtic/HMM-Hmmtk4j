package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.discretehmm.HMM;

public class FastMarkovDissimilarity implements Dissimilarity {

  private int powerLevel;

  @Override
  public double compute(final HMM first, final HMM second) {
    final int symbolCount = first.getSymbolCount();
    final double[] proba1 = computeLimits(first);
    final double[] proba2 = computeLimits(second);

    double sum = 0;
    for (int i = 0; i < symbolCount; ++i) {
      sum += proba1[i] * (RobustMath.log(proba1[i]) - RobustMath.log(proba2[i]));
      sum += proba2[i] * (RobustMath.log(proba2[i]) - RobustMath.log(proba1[i]));
    }
    return sum / 2.0;
  }

  double[] computeLimits(final HMM h) {
    final int symbolCount = h.getSymbolCount();
    final int stateCount = h.getStateCount();

    final double[] result = new double[symbolCount];
    final MatrixOfDouble a = new MatrixOfDouble(h.getA());
    a.fourthpowerSquareMatrix(powerLevel);

    final double[] x = new double[stateCount];
    final double[] pi = new double[stateCount];
    h.getPi().get(pi);
    for (int i = 0; i < stateCount; ++i) {
      x[i] = 0;
      for (int j = 0; j < stateCount; ++j) {
        x[i] += a.get(i, j) * pi[j];
      }
    }

    for (int i = 0; i < symbolCount; ++i) {
      result[i] = 0;
      for (int j = 0; j < stateCount; ++j) {
        result[i] += h.getB().get(j, i) * x[j];
      }
    }
    return result;
  }

  public int getPowerLevel() {
    return powerLevel;
  }

  public void setPowerLevel(final int powerLevel) {
    if (powerLevel < 0) {
      throw new IllegalArgumentException("powerLevel can not be negative");
    }
    this.powerLevel = powerLevel;
  }
}
