package org.knguyenc.datastructures.heaps;

import junit.framework.TestCase;

import static org.junit.Assert.assertArrayEquals;

public class MaxHeapTest extends TestCase {

    public void testVarietyTypes() {
        Integer[] integers = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
        String[] strings = {"c", "java", "cpp", "python", "go", "swift", "objective-c"};

        MaxHeap<Integer> integerMaxHeap = new MaxHeap<>(integers.length);
        for (Integer element : integers)
            integerMaxHeap.insert(element);
        System.out.printf("Integer max heap:\n%s\n", integerMaxHeap);
        assertArrayEquals(new Integer[]{40, 32, 26, 10, 22, 2, 8, 6, 5, 9, 3}, integerMaxHeap.data());

        MaxHeap<String> stringMaxHeap = new MaxHeap<>(strings.length);
        for (String element : strings)
            stringMaxHeap.insert(element);
        System.out.printf("String max heap:\n%s\n", stringMaxHeap);
        assertArrayEquals(new String[]{"swift", "java", "python", "c", "go", "cpp", "objective-c"}, stringMaxHeap.data());
    }

    public void testInsertRemove() {
        Integer[] integers = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
        MaxHeap<Integer> integerMaxHeap = new MaxHeap<>(integers.length + 1);
        for (Integer element : integers)
            integerMaxHeap.insert(element);
        assertArrayEquals(new Integer[]{40, 32, 26, 10, 22, 2, 8, 6, 5, 9, 3, null}, integerMaxHeap.data());
        assertEquals(integers.length, integerMaxHeap.size());

        integerMaxHeap.insert(80);
        assertArrayEquals(new Integer[]{80, 32, 40, 10, 22, 26, 8, 6, 5, 9, 3, 2}, integerMaxHeap.data());

        assertEquals((Integer) 10, integerMaxHeap.remove(3));
        assertArrayEquals(new Integer[]{80, 32, 40, 6, 22, 26, 8, 2, 5, 9, 3, null}, integerMaxHeap.data());
    }
}
