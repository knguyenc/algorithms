package org.knguyenc.searching;

/**
 * Searching algorithm abstract class
 *
 * @author Khoa Nguyen
 */
abstract class AbstractSearchingAlgorithm {

    /**
     * Searches given key in the array by current algorithm
     *
     * @param array array contains desired element
     * @param key   element to be found
     * @param <T>   array's class
     * @return index of element in the array
     */
    public abstract <T extends Comparable<T>> int search(T[] array, T key);

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
