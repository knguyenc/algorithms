package org.knguyenc.datastructures.heaps;

import java.util.Iterator;
import java.util.NoSuchElementException;

public abstract class AbstractHeap<T extends Comparable<T>> implements Iterable<T> {

    private final int DEFAULT_CAPACITY = 50;
    protected final T[] data;
    protected int size;

    @SuppressWarnings("unchecked")
    protected AbstractHeap() {
        data = (T[]) new Comparable[DEFAULT_CAPACITY];
        size = 0;
    }

    @SuppressWarnings("unchecked")
    protected AbstractHeap(int capacity) {
        if (capacity <= 0) capacity = DEFAULT_CAPACITY;
        data = (T[]) new Comparable[capacity];
        size = 0;
    }

    public abstract void buildHeap();

    public abstract void heapify(int index);

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == data.length;
    }

    public void swap(int i, int j) {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    public abstract void insert(T value);

    public T remove(int index) {
        if (isEmpty()) throw new Error("Heap underflow, can not remove");
        if (index < 0 && index >= size) throw new Error("Invalid index");
        T removed = data[index];
        data[index] = data[--size];
        data[size] = null;
        heapify(index);
        return removed;
    }

    protected static int parent(int index) {
        return (index - 1) / 2;
    }

    protected static int left(int index) {
        return 2 * index + 1;
    }

    protected static int right(int index) {
        return 2 * index + 2;
    }

    public T[] data() {
        return data;
    }

    public int size() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private int index = 0;

            @Override
            public boolean hasNext() {
                return index < size;
            }

            @Override
            public T next() {
                if (!hasNext()) throw new NoSuchElementException("No more element in heap");
                return data[index++];
            }
        };
    }

    @Override
    public String toString() {
        int breakLine = 0;
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < size / 2; i++) {
            if (i == 0) out.append("(").append(data[i]).append(" [").append(i).append("])\n");
            if (left(i) < size) out.append("(").append(data[left(i)]).append(" [").append(left(i)).append("])");
            if (right(i) < size) out.append("(").append(data[right(i)]).append(" [").append(right(i)).append("])");
            if (i == breakLine) {
                out.append("\n");
                breakLine = 2 * breakLine + 2;
            } else out.append("  ");
        }
        return out.toString();
    }
}
