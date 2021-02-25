package org.knguyenc.sorting;

import org.knguyenc.datastructures.heaps.MaxHeap;

public class HeapSort extends AbstractSortingAlgorithm {

    @Override
    public <T extends Comparable<T>> void sort(T[] array) {
        MaxHeap<T> maxHeap = new MaxHeap<>(array.length);
        for (T element : array) maxHeap.insert(element);
        for (int i = array.length - 1; i > 0; i--) {
            maxHeap.swap(0, i);
            maxHeap.setSize(maxHeap.size() - 1);
            maxHeap.heapify(0);
        }
        maxHeap.setSize(array.length);
        for (int i = 0; i < array.length; i++)
            array[i] = maxHeap.data()[i];
    }
}
