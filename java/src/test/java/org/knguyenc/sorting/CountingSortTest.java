package org.knguyenc.sorting;

import junit.framework.TestCase;

import static org.junit.Assert.assertArrayEquals;

public class CountingSortTest extends TestCase {

    public void testVarietyTypesOfArrays() {
        Integer[] integers = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
        Character[] characters = {'d', 'a', 'c', 'b', 'g', 'h', 'e'};

        CountingSort countingSort = new CountingSort();
        countingSort.sort(integers);
        assertArrayEquals(new Integer[]{2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40}, integers);

        countingSort.sort(characters);
        assertArrayEquals(new Character[]{'a', 'b', 'c', 'd', 'e', 'g', 'h'}, characters);
    }
}
