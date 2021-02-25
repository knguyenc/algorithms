package org.knguyenc.searching;

import java.util.Arrays;

public class BinarySearch extends AbstractSearchingAlgorithm {

    @Override
    public <T extends Comparable<T>> int search(T[] array, T key) {
        Arrays.sort(array);
        return doSearch(array, key, 0, array.length - 1);
    }

    private <T extends Comparable<T>> int doSearch(T[] array, T key, int low, int high) {
        if (low > high) return -1;
        int middle = (low + high) / 2;
        if (et(key, array[middle])) return middle;
        else if (lt(key, array[middle])) return doSearch(array, key, low, middle - 1);
        else return doSearch(array, key, middle + 1, high);
    }
}
