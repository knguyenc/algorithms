package org.knguyenc.greedy;

import junit.framework.TestCase;

public class FractionalKnapsackTest extends TestCase {

    public void testVarietyInputs() {
        assertEquals(240, FractionalKnapsack.knapsack(new int[][]{{10, 60}, {30, 120}, {20, 100}}, 50));
    }
}
