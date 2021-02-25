package org.knguyenc.datastructures.graphs;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class AdjacencyListGraph<T> implements Iterable<T> {

    private final ArrayList<Vertex> vertices;

    public AdjacencyListGraph() {
        vertices = new ArrayList<>();
    }

    public class Vertex {
        public T data;
        protected ArrayList<Vertex> adjacentVertices;

        public Vertex(T data) {
            this.data = data;
            adjacentVertices = new ArrayList<>();
        }

        protected void insertAdjacentVertex(Vertex dest) {
            for (Vertex v : adjacentVertices)
                if (v.data.equals(dest.data)) throw new Error("The edge is already exist");
            adjacentVertices.add(dest);
        }

        protected T removeAdjacentVertex(T destData) {
            for (int i = 0; i < adjacentVertices.size(); i++) {
                if (adjacentVertices.get(i).data.equals(destData)) {
                    adjacentVertices.remove(i);
                    return destData;
                }
            }
            throw new Error("The edge is not exist");
        }

        @Override
        public String toString() {
            return String.format("Vertex(%s): %s", data.toString(), adjacentVertices.toString());
        }
    }

    public int size() {
        return vertices.size();
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public void insertEdge(T src, T dest) {
        Vertex srcVertex = null, destVertex = null;
        for (Vertex v : vertices) {
            if (v.data.equals(src)) {
                srcVertex = v;
            }
            if (v.data.equals(dest)) {
                destVertex = v;
            }
            if (srcVertex != null && destVertex != null) break;
        }
        if (srcVertex == null) {
            srcVertex = new Vertex(src);
            vertices.add(srcVertex);
        }
        if (destVertex == null) {
            destVertex = new Vertex(dest);
            vertices.add(destVertex);
        }
        srcVertex.insertAdjacentVertex(destVertex);
    }

    public T removeEdge(T src, T dest) {
        for (Vertex v : vertices)
            if (v.data.equals(src)) return v.removeAdjacentVertex(dest);
        throw new Error("The edge is not exist");
    }

    public Iterator<T> breadthFirstTraversal() {
        List<T> list = new ArrayList<>();
        for (Vertex vertex : vertices) {
            if (!list.contains(vertex.data)) list.add(vertex.data);
            for (Vertex v : vertex.adjacentVertices)
                if (!list.contains(v.data)) list.add(v.data);
        }
        return list.iterator();
    }

    @Override
    public Iterator<T> iterator() {
        return breadthFirstTraversal();
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        for (T element : this)
            out.append("Vertex(").append(element).append(")").append(" ");
        return out.toString();
    }
}
