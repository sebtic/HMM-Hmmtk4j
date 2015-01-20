/*
 * Copyright 2010 Sébastien Aupetit <sebtic@projectforge.org>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package org.projectsforge.hmmtk4j.executors;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class AlgorithmsExecutionState {
  private final Map<Algorithm, Algorithm> callGraph = new HashMap<Algorithm, Algorithm>();
  private final Map<Thread, Deque<Algorithm>> threadAlgorithms = new HashMap<Thread, Deque<Algorithm>>();

  public Algorithm getCurrentAlgorithm() {
    final Deque<Algorithm> stack = threadAlgorithms.get(Thread.currentThread());

    return (stack == null) ? null : stack.peek();
  }

  public int getNumberOfAlgorithmsToRoot(final Algorithm initial) {
    int count = 0;
    Algorithm parent = callGraph.get(initial);

    while (parent != null) {
      count++;
      parent = callGraph.get(parent);
    }
    return count;
  }

  public boolean isRunning(final Algorithm algorithm) {
    return callGraph.containsKey(algorithm);
  }

  public void startAlgorithm(final Algorithm algorithm) {
    callGraph.put(algorithm, getCurrentAlgorithm());
    Deque<Algorithm> stack = threadAlgorithms.get(Thread.currentThread());
    if (stack == null) {
      stack = new ArrayDeque<Algorithm>();
      threadAlgorithms.put(Thread.currentThread(), stack);
    }
    stack.push(algorithm);
  }

  public void stopAlgorithm(final Algorithm algorithm) {
    callGraph.remove(algorithm);
    final Deque<Algorithm> stack = threadAlgorithms.get(Thread.currentThread());
    if (stack.peek() == algorithm) {
      stack.remove();
    } else {
      throw new IllegalStateException("An algorithm changed of thread");
    }
  }
}
