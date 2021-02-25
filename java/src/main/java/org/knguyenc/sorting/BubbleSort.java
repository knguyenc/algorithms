package org.knguyenc.sorting;

/**
 * Java implementation of bubble sort algorithm
 *
 * @author Khoa Nguyen
 */
public class BubbleSort extends AbstractSortingAlgorithm {

    @Override
    public <T extends Comparable<T>> void sort(T[] array) {
        for (int i = 0; i < array.length - 1; i++)
            for (int j = i + 1; j < array.length; j++)
                if (gt(array[i], array[j]))
                    swap(array, i, j);
    }
}
