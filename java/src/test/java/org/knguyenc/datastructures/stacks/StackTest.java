package org.knguyenc.datastructures.stacks;

import junit.framework.TestCase;
import org.knguyenc.datastructures.queues.Queue;

public class StackTest extends TestCase {

    public void testPushPop() {
        Stack<Integer> stack = new Stack<>(20);
        assertTrue(stack.isEmpty());
        assertFalse(stack.isFull());
        assertEquals(0, stack.size());
        stack.push(8);
        stack.push(6);
        stack.push(26);
        stack.push(9);
        stack.push(7);
        stack.push(22);
        System.out.println(stack);
        assertFalse(stack.isEmpty());
        assertEquals(6, stack.size());
        assertEquals((Integer) 22, stack.top());
        assertEquals((Integer) 22, stack.pop());
        assertEquals(5, stack.size());
    }
}
