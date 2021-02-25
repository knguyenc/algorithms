package org.knguyenc.sorting;

import java.util.Arrays;
import java.util.Collections;

public class RadixSort extends AbstractSortingAlgorithm {

    @Override
    public <T extends Comparable<T>> void sort(T[] array) {
        if (!(array instanceof Integer[] || array instanceof Character[]))
            throw new Error("Only accept non-negative integer or character array");
        int maxElement = array instanceof Character[]
                         ? Character.getNumericValue((Character) Collections.max(Arrays.asList(array)))
                         : (Integer) Collections.max(Arrays.asList(array));
        for (int position = 1; maxElement / position > 0; position *= 10)
            digitCountingSort(array, position);
    }

    @SuppressWarnings("unchecked")
    public <T extends Comparable<T>> void digitCountingSort(T[] array, int position) {
        T[] copy = (T[]) new Comparable[array.length];
        Integer[] auxiliary = new Integer[10];
        System.arraycopy(array, 0, copy, 0, array.length);
        Arrays.fill(auxiliary, 0);

        for (T element : array) {
            if (element instanceof Character)
                auxiliary[(Character.getNumericValue((Character) element) / position) % 10]++;
            else auxiliary[((Integer) element / position) % 10]++;
        }
        for (int i = 1; i < auxiliary.length; i++) auxiliary[i] += auxiliary[i - 1];

        for (int i = array.length - 1; i >= 0; i--) {
            int index = (copy[i] instanceof Character)
                        ? Character.getNumericValue((Character) copy[i]) / position % 10
                        : ((Integer) copy[i] / position) % 10;
            array[auxiliary[index] - 1] = copy[i];
            auxiliary[index]--;
        }
    }
}
