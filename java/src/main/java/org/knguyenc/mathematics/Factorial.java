package org.knguyenc.mathematics;

/**
 * Factorial calculation implemented in Java
 *
 * @author Khoa Nguyen
 */
public class Factorial {

    public static int factorial(int n) {
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }
}
