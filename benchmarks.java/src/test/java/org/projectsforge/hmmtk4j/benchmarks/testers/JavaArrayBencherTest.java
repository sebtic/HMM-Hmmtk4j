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
package org.projectsforge.hmmtk4j.benchmarks.testers;

import junit.framework.TestCase;

import org.apache.log4j.BasicConfigurator;

public class JavaArrayBencherTest extends TestCase {

  static {
    BasicConfigurator.resetConfiguration();
    BasicConfigurator.configure();
  }

  public void testIt() {
    // nothing to do
  }

  /*
   * public void testHybrid() throws FileNotFoundException {
   * Main.JavaArrayBencher_testHybrid(); } public void testPurJava() throws
   * FileNotFoundException { Main.JavaArrayBencher_testPurJava(); } public void
   * testPurNative() throws FileNotFoundException {
   * Main.JavaArrayBencher_testPurNative(); }
   */
}
