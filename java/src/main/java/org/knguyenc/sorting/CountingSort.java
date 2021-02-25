package org.knguyenc.sorting;

import java.util.Arrays;
import java.util.Collections;

public class CountingSort extends AbstractSortingAlgorithm {

    @Override
    public <T extends Comparable<T>> void sort(T[] array) {
        if (!(array instanceof Integer[] || array instanceof Character[]))
            throw new Error("Only accept non-negative integer or character array");
        doSort(array, Collections.max(Arrays.asList(array)));
    }

    @SuppressWarnings("unchecked")
    private <T extends Comparable<T>> void doSort(T[] array, T key) {
        T[] copy = (T[]) new Comparable[array.length];
        Integer[] auxiliary = key instanceof Character
                              ? new Integer[Character.getNumericValue((Character) key) + 1]
                              : new Integer[(Integer) key + 1];
        System.arraycopy(array, 0, copy, 0, array.length);
        Arrays.fill(auxiliary, 0);

        for (T element : array) {
            if (element instanceof Character) auxiliary[Character.getNumericValue((Character) element)]++;
            else auxiliary[(Integer) element]++;
        }
        for (int i = 1; i < auxiliary.length; i++) auxiliary[i] += auxiliary[i - 1];

        for (int i = array.length - 1; i >= 0; i--) {
            int index = (copy[i] instanceof Character)
                        ? Character.getNumericValue((Character) copy[i]) : (Integer) copy[i];
            array[auxiliary[index] - 1] = copy[i];
            auxiliary[index]--;
        }
    }
}
