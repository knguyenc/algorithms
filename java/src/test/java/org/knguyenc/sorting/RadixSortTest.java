package org.knguyenc.sorting;

import junit.framework.TestCase;

import static org.junit.Assert.assertArrayEquals;

public class RadixSortTest extends TestCase {

    public void testVarietyTypesOfArrays() {
        Integer[] integers = {63, 81, 102, 266, 97, 21, 403, 222, 59, 320, 36};
        Character[] characters = {'D', 'A', 'C', 'B', 'G', 'H', 'E'};

        RadixSort radixSort = new RadixSort();
        radixSort.sort(integers);
        assertArrayEquals(new Integer[]{21, 36, 59, 63, 81, 97, 102, 222, 266, 320, 403}, integers);

        radixSort.sort(characters);
        assertArrayEquals(new Character[]{'A', 'B', 'C', 'D', 'E', 'G', 'H'}, characters);
    }
}
