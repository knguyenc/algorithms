package org.knguyenc.mathematics;

/**
 * Fibonacci number calculation implemented in Java
 *
 * @author Khoa Nguyen
 */
public class Fibonacci {

    public static int binaryFibonacci(int n) {
        if (n <= 1) return n;
        return binaryFibonacci(n - 1) + binaryFibonacci(n - 2);
    }

    public static int[] linearFibonacci(int n) {
        if (n <= 1) return new int[]{n, 0};
        int[] ret = linearFibonacci(n - 1);
        return new int[]{ret[0] + ret[1], ret[0]};
    }
}
