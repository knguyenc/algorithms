package org.knguyenc.divideconquer;

import junit.framework.TestCase;

public class MaximumSubarrayTest extends TestCase {

    public void testMixedPositiveNegativeArray() {
        int[] integers = {12, -2, -23, 18, -1, -14, -21, 16, 19, -5, 10, -3, -20, 13, -4, -7};
        int[] ret = MaximumSubarray.maximumSubarray(integers, 0, integers.length - 1);
        assertEquals(7, ret[0]);
        assertEquals(10, ret[1]);
        assertEquals(40, ret[2]);
    }
}
