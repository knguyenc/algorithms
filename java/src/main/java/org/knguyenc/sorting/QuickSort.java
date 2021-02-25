package org.knguyenc.sorting;

public class QuickSort extends AbstractSortingAlgorithm {

    @Override
    public <T extends Comparable<T>> void sort(T[] array) {
        doSort(array, 0, array.length - 1);
    }

    private <T extends Comparable<T>> void doSort(T[] array, int low, int high) {
        if (low < high) {
            int separator = partition(array, low, high);
            doSort(array, low, separator - 1);
            doSort(array, separator + 1, high);
        }
    }

    private <T extends Comparable<T>> int partition(T[] array, int low, int high) {
        T pivot = array[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
            if (lt(array[j], pivot)) swap(array, ++i, j);
        swap(array, i + 1, high);
        return i + 1;
    }

    private <T extends Comparable<T>> int hoarePartition(T[] array, int low, int high) {
        T pivot = array[low];
        int i = low, j = high;
        while (true) {
            while (lt(array[i], pivot)) i++;
            while (gt(array[j], pivot)) j--;
            if (i < j) swap(array, i, j);
            else return j;
        }
    }
}
