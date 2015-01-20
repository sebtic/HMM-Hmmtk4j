package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.discretehmm.HMM;

public class UncertainHiddenStateDissimilaritySecondOrder implements Dissimilarity {

  @Override
  public double compute(final HMM first, final HMM second) {
    final int symbolCount = first.getSymbolCount();
    final int stateCount = first.getStateCount();

    final double[][] dep1 = new double[symbolCount][symbolCount];
    // calcul des conjonctions
    for (int i = 0; i < symbolCount; ++i) {
      for (int j = 0; j < symbolCount; ++j) {
        dep1[i][j] = 0;
        for (int k = 0; k < stateCount; ++k) {
          for (int l = 0; l < stateCount; ++l) {
            dep1[i][j] += first.getB().get(k, j) * first.getA().get(l, k) * first.getB().get(l, i)
                / stateCount;
          }
        }
      }
    }

    final double[][] dep2 = new double[symbolCount][symbolCount];
    for (int i = 0; i < symbolCount; ++i) {
      for (int j = 0; j < symbolCount; ++j) {
        dep2[i][j] = 0;
        for (int k = 0; k < stateCount; ++k) {
          for (int l = 0; l < stateCount; ++l) {
            dep2[i][j] += second.getB().get(k, j) * second.getA().get(l, k)
                * second.getB().get(l, i) / stateCount;
          }
        }
      }
    }

    double sum = 0;
    for (int i = 0; i < symbolCount; ++i) {
      for (int j = 0; j < symbolCount; ++j) {
        sum += dep1[i][j] * (RobustMath.log(dep1[i][j]) - RobustMath.log(dep2[i][j]));
        sum += dep2[i][j] * (RobustMath.log(dep2[i][j]) - RobustMath.log(dep1[i][j]));
      }
    }
    return sum / 2.0;
  }

}
