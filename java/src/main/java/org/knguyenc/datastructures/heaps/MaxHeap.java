package org.knguyenc.datastructures.heaps;

public class MaxHeap<T extends Comparable<T>> extends AbstractHeap<T> {

    public MaxHeap() {
        super();
        buildHeap();
    }

    public MaxHeap(int capacity) {
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
        int left = left(index), right = right(index), largest = index;
        if (left < size && data[left].compareTo(data[index]) > 0)
            largest = left;
        if (right < size && data[right].compareTo(data[largest]) > 0)
            largest = right;
        if (largest != index) {
            swap(largest, index);
            heapify(largest);
        }
    }

    @Override
    public void insert(T value) {
        if (isFull()) throw new Error("Heap overflow, can not insert");
        data[size] = value;
        int current = size;
        while (current > 0 && data[current].compareTo(data[parent(current)]) > 0) {
            swap(current, parent(current));
            current = parent(current);
        }
        size++;
    }
}
