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
package org.projectsforge.hmmtk4j;

import java.lang.management.ManagementFactory;
import java.lang.management.ThreadMXBean;
import junit.framework.TestCase;

public class BenchmarkTest extends TestCase {

  public void testArray() {
    final ThreadMXBean newBean = ManagementFactory.getThreadMXBean();
    if (!newBean.isCurrentThreadCpuTimeSupported()) {
      System.out.println("CPU Usage monitoring is not avaliable!");
    } else {
      newBean.setThreadCpuTimeEnabled(true);
    }

    long start1, start2, end1, end2;

    start1 = newBean.getCurrentThreadUserTime();

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10000000; j++) {
        j = j + 1 - 1;
      }
    }
    end1 = newBean.getCurrentThreadUserTime();

    System.out.println("Warm up: " + ((end1 - start1) / 100) + " ms");

    for (int len = 1; len < 1000; len += 50) {
      final ArrayOfDouble val = new ArrayOfDouble(len, 0);

      start1 = newBean.getCurrentThreadUserTime();
      for (int essai = 0; essai < 10000; ++essai) {
        for (int i = val.getCount() - 1; i >= 0; --i) {
          val.set(i, val.get(i) + 1);
        }
      }

      end1 = newBean.getCurrentThreadUserTime();

      start2 = newBean.getCurrentThreadUserTime();
      for (int essai = 0; essai < 10000; ++essai) {
        final double[] val2 = new double[val.getCount()];
        val.get(val2);
        for (int i = val2.length - 1; i >= 0; --i) {
          val2[i] = val2[i] + 1;
        }
        val.set(val2);
      }
      end2 = newBean.getCurrentThreadUserTime();

      System.out.println("Vector len=" + len + " takes " + ((end1 - start1) / 1000000.) + " ms >> "
          + ((end2 - start2) / 1000000.) + " ms");
    }
  }

}
