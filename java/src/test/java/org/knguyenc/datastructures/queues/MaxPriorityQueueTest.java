package org.knguyenc.datastructures.queues;

import junit.framework.TestCase;

import static org.junit.Assert.assertArrayEquals;

public class MaxPriorityQueueTest extends TestCase {

    public void testInsertExtractMax() {
        Integer[] integers = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
        MaxPriorityQueue<Integer> maxPriorityQueue = new MaxPriorityQueue<>(integers.length + 1);
        for (Integer element : integers)
            maxPriorityQueue.insert(element);
        assertArrayEquals(new Integer[]{40, 32, 26, 10, 22, 2, 8, 6, 5, 9, 3, null}, maxPriorityQueue.data());
        assertEquals((Integer) 40, maxPriorityQueue.maximum());

        maxPriorityQueue.insert(80);
        assertArrayEquals(new Integer[]{80, 32, 40, 10, 22, 26, 8, 6, 5, 9, 3, 2}, maxPriorityQueue.data());

        assertEquals((Integer) 80, maxPriorityQueue.extractMax());
        assertArrayEquals(new Integer[]{40, 32, 26, 10, 22, 2, 8, 6, 5, 9, 3, null}, maxPriorityQueue.data());
    }
}
