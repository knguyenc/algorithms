package org.knguyenc.sorting;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * Java implementation of bucket sort algorithm
 *
 * @author Khoa Nguyen
 */
public class BucketSort extends AbstractSortingAlgorithm {

    @Override
    @SuppressWarnings("unchecked")
    public <T extends Comparable<T>> void sort(T[] array) {
        if (!(array instanceof Float[] || array instanceof Double[]))
            throw new Error("Only accept non-negative floating point number in range [0, 1)");

        int slots = 10, index = 0;
        List<T>[] buckets = new ArrayList[slots];
        for (int i = 0; i < buckets.length; i++)
            buckets[i] = new ArrayList<>();
        for (T element : array) {
            int bucketIndex = 0;
            if (element instanceof Float) bucketIndex = (int) ((Float) element * slots);
            if (element instanceof Double) bucketIndex = (int) ((Double) element * slots);
            buckets[bucketIndex].add(element);
        }

        for (int i = 0; i < slots; i++) {
            buckets[i].sort(Comparator.naturalOrder());
            for (int j = 0; j < buckets[i].size(); j++)
                array[index++] = buckets[i].get(j);
        }
    }
}
