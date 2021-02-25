package org.knguyenc.datastructures.heaps;

import junit.framework.TestCase;

import static org.junit.Assert.assertArrayEquals;

public class MinHeapTest extends TestCase {

    public void testVarietyTypes() {
        Integer[] integers = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
        String[] strings = {"c", "java", "cpp", "python", "go", "swift", "objective-c"};

        MinHeap<Integer> integerMinHeap = new MinHeap<>(integers.length);
        for (Integer element : integers)
            integerMinHeap.insert(element);
        System.out.printf("Integer max heap:\n%s\n", integerMinHeap);
        assertArrayEquals(new Integer[]{2, 3, 6, 8, 5, 10, 40, 26, 22, 32, 9}, integerMinHeap.data());

        MinHeap<String> stringMinHeap = new MinHeap<>(strings.length);
        for (String element : strings)
            stringMinHeap.insert(element);
        System.out.printf("String max heap:\n%s\n", stringMinHeap);
        assertArrayEquals(new String[]{"c", "go", "cpp", "python", "java", "swift", "objective-c"}, stringMinHeap.data());
    }

    public void testInsertRemove() {
        Integer[] integers = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
        MinHeap<Integer> integerMinHeap = new MinHeap<>(integers.length + 1);
        for (Integer element : integers)
            integerMinHeap.insert(element);
        assertArrayEquals(new Integer[]{2, 3, 6, 8, 5, 10, 40, 26, 22, 32, 9, null}, integerMinHeap.data());
        assertEquals(integers.length, integerMinHeap.size());

        integerMinHeap.insert(80);
        assertArrayEquals(new Integer[]{2, 3, 6, 8, 5, 10, 40, 26, 22, 32, 9, 80}, integerMinHeap.data());

        assertEquals((Integer) 8, integerMinHeap.remove(3));
        assertArrayEquals(new Integer[]{2, 3, 6, 22, 5, 10, 40, 26, 80, 32, 9, null}, integerMinHeap.data());
    }
}
