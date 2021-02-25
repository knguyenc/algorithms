package org.knguyenc.datastructures.graphs;

import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import static org.junit.Assert.assertArrayEquals;

public class AdjacencyListGraphTest extends TestCase {

    public void testInserRemoveEdgesTraversalGraph() {
        AdjacencyListGraph<Integer> graph = new AdjacencyListGraph<>();
        assertTrue(graph.isEmpty());

        assertEquals(0, graph.size());
        graph.insertEdge(2, 0);
        graph.insertEdge(0, 2);
        graph.insertEdge(2, 3);
        graph.insertEdge(0, 1);
        graph.insertEdge(1, 2);
        graph.insertEdge(3, 3);
        System.out.println(graph);

        assertFalse(graph.isEmpty());
        assertEquals(4, graph.size());

        List<Integer> vertexList = new ArrayList<>(graph.size());
        for (Iterator<Integer> it = graph.breadthFirstTraversal(); it.hasNext(); )
            vertexList.add(it.next());
        assertArrayEquals(new Integer[]{2, 0, 3, 1}, vertexList.toArray());
    }
}
