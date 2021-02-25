package org.knguyenc.datastructures.trees;

import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import static org.junit.Assert.assertArrayEquals;

public class BinarySearchTreeTest extends TestCase {

    public void testTraversalInsertRemove() {
        BinarySearchTree<Integer> bst = new BinarySearchTree<>();
        assertTrue(bst.isEmpty());

        assertEquals(0, bst.size());
        bst.insert(4);
        bst.insert(2);
        bst.insert(1);
        bst.insert(3);
        bst.insert(6);
        bst.insert(5);
        bst.insert(7);
        System.out.println(bst);

        assertFalse(bst.isEmpty());
        assertEquals(7, bst.size());

        List<Integer> nodeList = new ArrayList<>(bst.size());
        for (Iterator<Integer> it = bst.preOrder(true); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{4, 2, 1, 3, 6, 5, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = bst.preOrder(false); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{4, 2, 1, 3, 6, 5, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = bst.inOrder(true); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{1, 2, 3, 4, 5, 6, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = bst.inOrder(false); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{1, 2, 3, 4, 5, 6, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = bst.postOrder(true); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{1, 3, 2, 5, 7, 6, 4}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = bst.postOrder(false); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{1, 3, 2, 5, 7, 6, 4}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = bst.levelOrder(true); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{4, 2, 6, 1, 3, 5, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = bst.levelOrder(false); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{4, 2, 6, 1, 3, 5, 7}, nodeList.toArray());

        assertEquals((Integer) 6, bst.search(6).data);
        assertNull(bst.search(9));

        assertEquals((Integer) 1, bst.minimum().data);
        assertEquals((Integer) 7, bst.maximum().data);

        assertEquals((Integer) 4, bst.remove(4));
        assertEquals(6, bst.size());
        nodeList.clear();
        for (Integer element : bst)
            nodeList.add(element);
        assertArrayEquals(new Integer[]{1, 2, 3, 5, 6, 7}, nodeList.toArray());
        System.out.println(bst);

        assertEquals((Integer) 1, bst.remove(1));
        assertEquals(5, bst.size());
        nodeList.clear();
        for (Integer element : bst)
            nodeList.add(element);
        assertArrayEquals(new Integer[]{2, 3, 5, 6, 7}, nodeList.toArray());
        System.out.println(bst);
    }
}
