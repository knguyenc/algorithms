package org.knguyenc.datastructures.linkedlists;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class CircularlyLinkedList<T> implements Iterable<T> {

    private Node tail;
    private int size;

    public CircularlyLinkedList() {
        tail = null;
        size = 0;
    }

    class Node {

        public final T data;
        private Node next;

        public Node(T data) {
            this.data = data;
            next = null;
        }

        public String toString() {
            return String.format("Node(%s)", data.toString());
        }
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return tail == null;
    }

    public void rotate() {
        tail = tail.next;
    }

    public Node search(T data) {
        if (isEmpty()) return null;
        Node temp = tail.next;
        do {
            if (temp.data == data) return temp;
            temp = temp.next;
        } while (temp != tail.next);
        return null;
    }

    public void insert(T data) {
        Node node = new Node(data);
        if (isEmpty()) {
            tail = node;
            tail.next = tail;
        } else {
            node.next = tail.next;
            tail.next = node;
            rotate();
        }
        size++;
    }

    public T remove(T data) {
        if (isEmpty()) throw new Error("List is empty, can not remove");
        Node node = tail.next, prev = null;
        do {
            prev = node;
            node = node.next;
        } while (node != tail.next && node.data != data);
        if (node == tail.next) throw new Error("Node is not exist in this list");
        T removed = node.data;
        if (tail.next == tail) {
            tail.next = null;
            tail = null;
        } else {
            prev.next = node.next;
            if (node == tail) tail = prev;
        }
        node.next = null;
        size--;
        return removed;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private Node temp = tail.next;

            @Override
            public boolean hasNext() {
                return temp != tail;
            }

            @Override
            public T next() {
                if (!hasNext()) throw new NoSuchElementException("No more element in linked list");
                T ret = temp.data;
                temp = temp.next;
                return ret;
            }
        };
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        for (T element : this)
            out.append("Node(").append(element).append(")").append(" -> ");
        return out.toString();
    }
}
