package org.knguyenc.dynamicprogramming;

import junit.framework.TestCase;

public class ZeroOneKnapsackTest extends TestCase {

    public void testVarietyInputs() {
        assertEquals(9, ZeroOneKnapsack.knapsack(new int[][]{ { 1, 1 }, { 4, 5 }, { 3, 4 }, { 5, 7 } }, 7));
    }
}
