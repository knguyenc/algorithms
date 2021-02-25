package org.knguyenc.datastructures.heaps;

public class MinHeap<T extends Comparable<T>> extends AbstractHeap<T> {

    public MinHeap() {
        super();
        buildHeap();
    }

    public MinHeap(int capacity) {
        super(capacity);
        buildHeap();
    }

    @Override
    public void buildHeap() {
        for (int i = size / 2; i >= 0; i--)
            heapify(i);
    }

    @Override
    public void heapify(int index) {
        int left = left(index), right = right(index), smallest = index;
        if (left < size && data[left].compareTo(data[index]) < 0)
            smallest = left;
        if (right < size && data[right].compareTo(data[smallest]) < 0)
            smallest = right;
        if (smallest != index) {
            swap(smallest, index);
            heapify(smallest);
        }
    }

    @Override
    public void insert(T value) {
        if (isFull()) throw new Error("Heap overflow, can not insert");
        data[size] = value;
        int current = size;
        while (current > 0 && data[current].compareTo(data[parent(current)]) < 0) {
            swap(current, parent(current));
            current = parent(current);
        }
        size++;
    }
}
