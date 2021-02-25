package org.knguyenc.datastructures.queues;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Queue<T> implements Iterable<T> {

    private final int DEFAULT_CAPACITY = 50;
    private final T[] data;
    private int head;
    private int tail;

    @SuppressWarnings("unchecked")
    public Queue() {
        data = (T[]) new Object[DEFAULT_CAPACITY];
        head = 0;
        tail = 0;
    }

    @SuppressWarnings("unchecked")
    public Queue(int capacity) {
        if (capacity <= 0) capacity = DEFAULT_CAPACITY;
        data = (T[]) new Object[capacity];
        head = 0;
        tail = 0;
    }

    public int size() {
        return head > tail ? data.length - head + tail : tail - head;
    }

    public boolean isEmpty() {
        return head == tail;
    }

    public boolean isFull() {
        int temp = (tail + 1) == data.length ? 0 : tail + 1;
        return head == temp;
    }

    public T head() {
        if (isEmpty()) throw new Error("Queue underflow, can not get head");
        return data[head];
    }

    public void enqueue(T value) {
        if (isFull()) throw new Error("Queue overflow, can not enqueue");
        data[tail] = value;
        tail = (tail + 1) == data.length ? 0 : tail + 1;
    }

    public T dequeue() {
        if (isEmpty()) throw new Error("Queue underflow, can not dequeue");
        T removed = data[head];
        head = (head + 1) == data.length ? 0 : head + 1;
        return removed;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private int index = head;

            @Override
            public boolean hasNext() {
                return head > tail
                       ? (index >= head && index < data.length) || (index >= 0 && index < tail)
                       : index >= head && index < tail;
            }

            @Override
            public T next() {
                if (!hasNext()) throw new NoSuchElementException("No more element in queue");
                T ret = data[index];
                index = (index + 1) == data.length ? 0 : index + 1;
                return ret;
            }
        };
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        for (T element : this)
            out.append(element).append(" ");
        return out.toString();
    }
}
