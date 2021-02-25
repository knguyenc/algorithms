package org.knguyenc.datastructures.queues;

import org.knguyenc.datastructures.heaps.MinHeap;

public class MinPriorityQueue<T extends Comparable<T>> extends MinHeap<T> {

    public MinPriorityQueue() {
        super();
    }

    public MinPriorityQueue(int capacity) {
        super(capacity);
    }

    public T minimum() {
        return data[0];
    }

    public T extractMin() {
        if (isEmpty()) throw new Error("Priority queue underflow, can not extract max");
        return remove(0);
    }

    public void decreaseKey(int index, T key) {
        if (index < 0 && index >= size) throw new Error("Invalid index");
        if (key.compareTo(data[index]) > 0) throw new Error("New key is larger than current key");
        data[index] = key;
        while (index > 0 && data[index].compareTo(data[parent(index)]) < 0) {
            swap(index, parent(index));
            index = parent(index);
        }
    }

    @Override
    public void insert(T value) {
        if (isFull()) throw new Error("Priority queue overflow, can not insert");
        data[size++] = value;
        decreaseKey(size - 1, value);
    }
}
