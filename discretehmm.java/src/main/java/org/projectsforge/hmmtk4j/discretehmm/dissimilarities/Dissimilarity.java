package org.projectsforge.hmmtk4j.discretehmm.dissimilarities;

import org.projectsforge.hmmtk4j.discretehmm.HMM;

public interface Dissimilarity {
  public double compute(HMM first, HMM second);
}
