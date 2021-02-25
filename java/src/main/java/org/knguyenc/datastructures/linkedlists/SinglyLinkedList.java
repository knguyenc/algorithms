package org.knguyenc.datastructures.linkedlists;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class SinglyLinkedList<T> implements Iterable<T> {

    private Node head;
    private int size;

    public SinglyLinkedList() {
        head = null;
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
        return head == null;
    }

    public Node search(T data) {
        Node temp = head;
        while (temp != null) {
            if (temp.data == data) return temp;
            temp = temp.next;
        }
        return null;
    }

    public void insert(T data) {
        Node node = new Node(data);
        if (isEmpty()) head = node;
        else {
            Node temp = head;
            while (temp.next != null) temp = temp.next;
            temp.next = node;
        }
        size++;
    }

    public T remove(T data) {
        if (isEmpty()) throw new Error("List is empty, can not remove");
        Node node = head, prev = null;
        while (node != null && node.data != data) {
            prev = node;
            node = node.next;
        }
        if (node == null) throw new Error("Node is not exist in this list");
        T removed = node.data;
        if (node == head) head = head.next;
        else prev.next = node.next;
        node.next = null;
        size--;
        return removed;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private Node temp = head;

            @Override
            public boolean hasNext() {
                return temp.next != null;
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
