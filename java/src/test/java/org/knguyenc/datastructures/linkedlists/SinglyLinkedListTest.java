package org.knguyenc.datastructures.linkedlists;

import junit.framework.TestCase;

public class SinglyLinkedListTest extends TestCase {

    public void testInsertRemove() {
        SinglyLinkedList<Integer> linkedList = new SinglyLinkedList<>();
        assertTrue(linkedList.isEmpty());
        assertEquals(0, linkedList.size());
        linkedList.insert(8);
        linkedList.insert(6);
        linkedList.insert(26);
        linkedList.insert(9);
        linkedList.insert(7);
        linkedList.insert(22);
        System.out.println(linkedList);
        assertFalse(linkedList.isEmpty());
        assertEquals(6, linkedList.size());
        assertEquals((Integer) 7, linkedList.search(7).data);
        assertNull(linkedList.search(5));
        assertEquals((Integer) 6, linkedList.remove(6));
        assertEquals(5, linkedList.size());
    }
}
