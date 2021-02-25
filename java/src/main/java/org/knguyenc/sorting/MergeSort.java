package org.knguyenc.sorting;

public class MergeSort extends AbstractSortingAlgorithm {

    @Override
    public <T extends Comparable<T>> void sort(T[] array) {
        doSort(array, 0, array.length - 1);
    }

    private <T extends Comparable<T>> void doSort(T[] array, int low, int high) {
        if (low < high) {
            int middle = (low + high) / 2;
            doSort(array, low, middle);
            doSort(array, middle + 1, high);
            merge(array, low, middle, high);
        }
    }

    @SuppressWarnings("unchecked")
    private <T extends Comparable<T>> void merge(T[] array, int low, int middle, int high) {
        T[] lArr = (T[]) new Comparable[middle - low + 1];
        T[] rArr = (T[]) new Comparable[high - middle];
        System.arraycopy(array, low, lArr, 0, lArr.length);
        System.arraycopy(array, middle + 1, rArr, 0, rArr.length);

        int i = 0, j = 0, k = low;
        while (i < lArr.length && j < rArr.length)
            array[k++] = (le(lArr[i], rArr[j])) ? lArr[i++] : rArr[j++];
        while (i < lArr.length) array[k++] = lArr[i++];
        while (j < rArr.length) array[k++] = rArr[j++];
    }
}
