package org.knguyenc.searching;

import junit.framework.TestCase;

public class BinarySearchTest extends TestCase {

    public void testVarietyTypesOfArrays() {
        Integer[] integers = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
        String[] strings = {"c", "cpp", "go", "java", "objective-c", "python", "swift"};
        Double[] doubles = {0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5};

        BinarySearch binarySearch = new BinarySearch();
        assertEquals(4, binarySearch.search(integers, 8));
        assertEquals(1, binarySearch.search(integers, 3));
        assertEquals(-1, binarySearch.search(integers, 1));

        assertEquals(1, binarySearch.search(strings, "cpp"));
        assertEquals(3, binarySearch.search(strings, "java"));
        assertEquals(-1, binarySearch.search(strings, "rust"));

        assertEquals(7, binarySearch.search(doubles, 9.5));
        assertEquals(4, binarySearch.search(doubles, 5.2));
        assertEquals(-1, binarySearch.search(doubles, 4.5));
    }
}
