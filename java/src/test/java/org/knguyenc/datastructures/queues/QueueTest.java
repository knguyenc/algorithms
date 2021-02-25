package org.knguyenc.datastructures.queues;

import junit.framework.TestCase;

public class QueueTest extends TestCase {

    public void testEnqueueDequeue() {
        Queue<Integer> queue = new Queue<>(20);
        assertTrue(queue.isEmpty());
        assertFalse(queue.isFull());
        assertEquals(0, queue.size());
        queue.enqueue(8);
        queue.enqueue(6);
        queue.enqueue(26);
        queue.enqueue(9);
        queue.enqueue(7);
        queue.enqueue(22);
        System.out.println(queue);
        assertFalse(queue.isEmpty());
        assertEquals(6, queue.size());
        assertEquals((Integer) 8, queue.head());
        assertEquals((Integer) 8, queue.dequeue());
        assertEquals(5, queue.size());
    }
}
