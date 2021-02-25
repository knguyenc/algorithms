package org.knguyenc.searching;

public class LinearSearch extends AbstractSearchingAlgorithm {

    @Override
    public <T extends Comparable<T>> int search(T[] array, T key) {
        for (int i = 0; i < array.length; i++)
            if (et(array[i], key)) return i;
        return -1;
    }
}
