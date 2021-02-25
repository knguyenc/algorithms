package org.knguyenc.datastructures.queues;

import junit.framework.TestCase;

import static org.junit.Assert.assertArrayEquals;

public class MinPriorityQueueTest extends TestCase {

    public void testInsertExtractMin() {
        Integer[] integers = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
        MinPriorityQueue<Integer> minPriorityQueue = new MinPriorityQueue<>(integers.length + 1);
        for (Integer element : integers)
            minPriorityQueue.insert(element);
        assertArrayEquals(new Integer[]{2, 3, 6, 8, 5, 10, 40, 26, 22, 32, 9, null}, minPriorityQueue.data());
        assertEquals((Integer) 2, minPriorityQueue.minimum());

        minPriorityQueue.insert(80);
        assertArrayEquals(new Integer[]{2, 3, 6, 8, 5, 10, 40, 26, 22, 32, 9, 80}, minPriorityQueue.data());

        assertEquals((Integer) 2, minPriorityQueue.extractMin());
        assertArrayEquals(new Integer[]{3, 5, 6, 8, 9, 10, 40, 26, 22, 32, 80, null}, minPriorityQueue.data());
    }
}
