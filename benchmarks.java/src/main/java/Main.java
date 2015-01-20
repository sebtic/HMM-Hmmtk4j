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
import java.io.FileNotFoundException;
import java.io.PrintStream;

import org.apache.log4j.BasicConfigurator;

public class Main {
  final static int TAILLE_MAX = 200;

  public static void JavaArrayBencher_testPurJava()
      throws FileNotFoundException {
    final PrintStream out = new PrintStream("JavaArrayBencher-PurJava.txt");
    for (int i = 1; i < Main.TAILLE_MAX * 500; i += 1000) {
      System.out.println("JavaArrayBencher-PurJava " + i);
      out.println(Math.log10(org.projectsforge.hmmtk4j.benchmarks.JavaArrayBencher
          .benchArray_PurJava(i)));
    }
    out.close();
  }

  public static void JavaArrayBencher_testPurNative()
      throws FileNotFoundException {
    final PrintStream out = new PrintStream("JavaArrayBencher-PurNative.txt");
    for (int i = 1; i < Main.TAILLE_MAX * 500; i += 1000) {
      System.out.println("JavaArrayBencher-PurNative " + i);
      out.println(Math.log10(org.projectsforge.hmmtk4j.benchmarks.JavaArrayBencher
          .benchArray_PurNative(i)));
    }
    out.close();
  }

  public static void JavaForwardBencher_testPurJava()
      throws FileNotFoundException {
    final PrintStream out = new PrintStream("JavaForwardBencher-PurJava.txt");
    for (int i = 1; i < Main.TAILLE_MAX; i += 5) {
      System.out.println("JavaForwardBencher-PurJava " + i);
      out.println(Math.log10(org.projectsforge.hmmtk4j.benchmarks.JavaForwardBencher
          .benchForward_PurJava(i)));
    }
    out.close();
  }

  public static void JavaForwardBencher_testPurNative()
      throws FileNotFoundException {
    final PrintStream out = new PrintStream("JavaForwardBencher-PurNative.txt");
    for (int i = 1; i < Main.TAILLE_MAX; i += 5) {
      System.out.println("JavaForwardBencher-PurNative " + i);
      out.println(Math.log10(org.projectsforge.hmmtk4j.benchmarks.JavaForwardBencher
          .benchForward_PurNative(i)));
    }
    out.close();
  }

  public static void JavaMatrixBencher_testPurJava()
      throws FileNotFoundException {
    final PrintStream out = new PrintStream("JavaMatrixBencher-PurJava.txt");
    for (int i = 1; i < Main.TAILLE_MAX; i += 5) {
      System.out.println("JavaMatrixBencher-PurJava " + i);
      out.println(Math.log10(org.projectsforge.hmmtk4j.benchmarks.JavaMatrixBencher
          .benchArray_PurJava(i)));
    }
    out.close();
  }

  public static void JavaMatrixBencher_testPurNative()
      throws FileNotFoundException {
    final PrintStream out = new PrintStream("JavaMatrixBencher-PurNative.txt");
    for (int i = 1; i < Main.TAILLE_MAX; i += 5) {
      System.out.println("JavaMatrixBencher-PurNative " + i);
      out.println(Math.log10(org.projectsforge.hmmtk4j.benchmarks.JavaMatrixBencher
          .benchArray_PurNative(i)));
    }
    out.close();
  }

  /**
   * @param args
   * @throws FileNotFoundException
   */
  public static void main(final String[] args) throws FileNotFoundException {
    BasicConfigurator.resetConfiguration();
    BasicConfigurator.configure();

    Main.JavaArrayBencher_testPurJava();
    Main.JavaArrayBencher_testPurNative();
    // Main.JavaMatrixBencher_testPurJava();
    Main.JavaMatrixBencher_testPurNative();
    // Main.JavaForwardBencher_testPurJava();
    Main.JavaForwardBencher_testPurNative();
  }
}
