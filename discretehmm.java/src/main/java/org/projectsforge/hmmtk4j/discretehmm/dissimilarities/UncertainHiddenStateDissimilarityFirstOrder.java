package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.RobustMath;
import org.projectsforge.hmmtk4j.discretehmm.HMM;

public class UncertainHiddenStateDissimilarityFirstOrder implements Dissimilarity {

  @Override
  public double compute(final HMM first, final HMM second) {
    final int symbolCount = first.getSymbolCount();
    final int stateCount = first.getStateCount();

    final double[] dep1 = new double[symbolCount];
    // calcul des conjonctions
    for (int i = 0; i < symbolCount; ++i) {
      dep1[i] = 0;
      for (int k = 0; k < stateCount; ++k) {
        dep1[i] += first.getB().get(k, i) / stateCount;
      }
    }

    final double[] dep2 = new double[symbolCount];
    // calcul des conjonctions
    for (int i = 0; i < symbolCount; ++i) {
      dep2[i] = 0;
      for (int k = 0; k < stateCount; ++k) {
        dep2[i] += second.getB().get(k, i) / stateCount;
      }
    }

    double sum = 0;
    for (int i = 0; i < symbolCount; ++i) {
      sum += dep1[i] * (RobustMath.log(dep1[i]) - RobustMath.log(dep2[i]));
      sum += dep2[i] * (RobustMath.log(dep2[i]) - RobustMath.log(dep1[i]));
    }
    return sum / 2.0;
  }

}
