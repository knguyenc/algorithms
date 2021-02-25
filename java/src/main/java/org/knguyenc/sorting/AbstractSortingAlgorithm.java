package org.knguyenc.sorting;

/**
 * Sorting algorithm abstract class
 *
 * @author Khoa Nguyen
 */
abstract class AbstractSortingAlgorithm {

    /**
     * Sorts given array by current algorithm
     *
     * @param array unsorted array
     * @param <T>   array's class
     */
    public abstract <T extends Comparable<T>> void sort(T[] array);

    /**
     * Swaps elements of array from given indexes
     *
     * @param array given array
     * @param i     first index
     * @param j     second index
     * @param <T>   array's class
     */
    protected <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /**
     * Returns <tt>true</tt> if first element greater than second one.
     *
     * @param u   first element
     * @param v   second element
     * @param <T> elements' class
     * @return <tt>true</tt> if first element greater than second one
     */
    protected <T extends Comparable<T>> boolean gt(T u, T v) {
        return u.compareTo(v) > 0;
    }

    /**
     * Returns <tt>true</tt> if first element greater than or equal to second one.
     *
     * @param u   first element
     * @param v   second element
     * @param <T> elements' class
     * @return <tt>true</tt> if first element greater than or equal to second one
     */
    protected <T extends Comparable<T>> boolean ge(T u, T v) {
        return u.compareTo(v) >= 0;
    }

    /**
     * Returns <tt>true</tt> if first element equal to second one.
     *
     * @param u   first element
     * @param v   second element
     * @param <T> elements' class
     * @return <tt>true</tt> if first element equal to second one
     */
    protected <T extends Comparable<T>> boolean et(T u, T v) {
        return u.compareTo(v) == 0;
    }

    /**
     * Returns <tt>true</tt> if first element less than or equal to second one.
     *
     * @param u   first element
     * @param v   second element
     * @param <T> elements' class
     * @return <tt>true</tt> if first element less than or equal to second one
     */
    protected <T extends Comparable<T>> boolean le(T u, T v) {
        return u.compareTo(v) <= 0;
    }

    /**
     * Returns <tt>true</tt> if first element less than second one.
     *
     * @param u   first element
     * @param v   second element
     * @param <T> elements' class
     * @return <tt>true</tt> if first element less than second one
     */
    protected <T extends Comparable<T>> boolean lt(T u, T v) {
        return u.compareTo(v) < 0;
    }
}
