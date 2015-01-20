package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.MatrixOfDouble;
import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.discretehmm.HMM;

public class MarkovDissimilarity implements Dissimilarity {

  private int powerLevel = 4;

  @Override
  public double compute(final HMM first, final HMM second) {
    final int symbolCount = first.getSymbolCount();
    final int stateCount = first.getStateCount();

    final double[][] dep1 = computeLimitsConjonction(first);
    final double[][] dep2 = computeLimitsConjonction(second);

    double sum = 0;
    for (int i = 0; i < symbolCount; ++i) {
      for (int j = 0; j < symbolCount; ++j) {
        sum += dep1[i][j] * (RobustMath.log(dep1[i][j]) - RobustMath.log(dep2[i][j]));
        sum += dep2[i][j] * (RobustMath.log(dep2[i][j]) - RobustMath.log(dep1[i][j]));
      }
    }
    return sum / 2.0;
  }

  // Calcul P(o_t=i,o_t-1=j/lambda)
  private double[][] computeLimitsConjonction(final HMM h) {
    final int symbolCount = h.getSymbolCount();
    final int stateCount = h.getStateCount();
    final double[][] dep = new double[symbolCount][symbolCount];
    final MatrixOfDouble a = new MatrixOfDouble(h.getA());
    final double[] x = new double[stateCount];

    // calcul de la distribution limite des etats
    a.fourthpowerSquareMatrix(powerLevel);
    final double[] pi = new double[stateCount];
    h.getPi().get(pi);
    for (int i = 0; i < stateCount; ++i) {
      x[i] = 0;
      for (int j = 0; j < stateCount; ++j) {
        x[i] += a.get(i, j) * pi[j];
      }
    }

    // calcul des conjonctions
    for (int i = 0; i < symbolCount; ++i) {
      for (int j = 0; j < symbolCount; ++j) {
        dep[i][j] = 0;
        for (int k = 0; k < stateCount; ++k) {
          for (int l = 0; l < stateCount; ++l) {
            dep[i][j] += h.getB().get(k, j) * h.getA().get(l, k) * h.getB().get(l, i) * x[l];
          }
        }
      }
    }
    return dep;
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
