package org.knguyenc.datastructures.queues;

import org.knguyenc.datastructures.heaps.MaxHeap;

public class MaxPriorityQueue<T extends Comparable<T>> extends MaxHeap<T> {

    public MaxPriorityQueue() {
        super();
    }

    public MaxPriorityQueue(int capacity) {
        super(capacity);
    }

    public T maximum() {
        return data[0];
    }

    public T extractMax() {
        if (isEmpty()) throw new Error("Priority queue underflow, can not extract max");
        return remove(0);
    }

    public void increaseKey(int index, T key) {
        if (index < 0 && index >= size) throw new Error("Invalid index");
        if (key.compareTo(data[index]) < 0) throw new Error("New key is smaller than current key");
        data[index] = key;
        while (index > 0 && data[index].compareTo(data[parent(index)]) > 0) {
            swap(index, parent(index));
            index = parent(index);
        }
    }

    @Override
    public void insert(T value) {
        if (isFull()) throw new Error("Priority queue overflow, can not insert");
        data[size++] = value;
        increaseKey(size - 1, value);
    }
}
