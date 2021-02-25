package org.knguyenc.datastructures.trees;

import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import static org.junit.Assert.assertArrayEquals;

public class BinaryTreeTest extends TestCase {

    public void testTraversalInsertRemove() {
        BinaryTree<Integer> binaryTree = new BinaryTree<>();
        assertTrue(binaryTree.isEmpty());

        assertEquals(0, binaryTree.size());
        binaryTree.insert(1);
        binaryTree.insert(2);
        binaryTree.insert(3);
        binaryTree.insert(4);
        binaryTree.insert(5);
        binaryTree.insert(6);
        binaryTree.insert(7);
        System.out.println(binaryTree);

        assertFalse(binaryTree.isEmpty());
        assertEquals(7, binaryTree.size());

        List<Integer> nodeList = new ArrayList<>(binaryTree.size());
        for (Iterator<Integer> it = binaryTree.preOrder(true); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{1, 2, 4, 5, 3, 6, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = binaryTree.preOrder(false); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{1, 2, 4, 5, 3, 6, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = binaryTree.inOrder(true); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{4, 2, 5, 1, 6, 3, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = binaryTree.inOrder(false); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{4, 2, 5, 1, 6, 3, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = binaryTree.postOrder(true); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{4, 5, 2, 6, 7, 3, 1}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = binaryTree.postOrder(false); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{4, 5, 2, 6, 7, 3, 1}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = binaryTree.levelOrder(true); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{1, 2, 3, 4, 5, 6, 7}, nodeList.toArray());

        nodeList.clear();
        for (Iterator<Integer> it = binaryTree.levelOrder(false); it.hasNext(); )
            nodeList.add(it.next());
        assertArrayEquals(new Integer[]{1, 2, 3, 4, 5, 6, 7}, nodeList.toArray());

        assertEquals((Integer) 6, binaryTree.search(6).data);
        assertNull(binaryTree.search(9));

        assertEquals((Integer) 4, binaryTree.remove(4));
        assertEquals(6, binaryTree.size());
        nodeList.clear();
        for (Integer element : binaryTree)
            nodeList.add(element);
        assertArrayEquals(new Integer[]{7, 2, 5, 1, 6, 3}, nodeList.toArray());
        System.out.println(binaryTree);

        assertEquals((Integer) 1, binaryTree.remove(1));
        assertEquals(5, binaryTree.size());
        nodeList.clear();
        for (Integer element : binaryTree)
            nodeList.add(element);
        assertArrayEquals(new Integer[]{7, 2, 5, 6, 3}, nodeList.toArray());
        System.out.println(binaryTree);
    }
}
