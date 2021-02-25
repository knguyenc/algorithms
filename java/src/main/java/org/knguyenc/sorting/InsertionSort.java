package org.knguyenc.sorting;

public class InsertionSort extends AbstractSortingAlgorithm {

    @Override
    public <T extends Comparable<T>> void sort(T[] array) {
        for (int j = 1; j < array.length; j++) {
            T key = array[j];
            int i = j - 1;
            while (i >= 0 && gt(array[i], key))
                array[i + 1] = array[i--];
            array[i + 1] = key;
        }
    }
}
