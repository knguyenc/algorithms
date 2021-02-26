package org.knguyenc.dynamicprogramming;

import java.util.Arrays;
import java.util.Comparator;

/**
 * 0-1 Knapsack problem implemented in Java
 *
 * @author Khoa Nguyen
 */
public class ZeroOneKnapsack {

    public static int knapsack(int[][] knapsack, int weight) {
        Arrays.sort(knapsack, Comparator.comparingInt(arr -> arr[0]));
        int[][] matrix = new int[knapsack.length][weight + 1];
        for (int i = 0; i < matrix.length; i++) {
            matrix[i][0] = 0;
            for (int j = 1; j <= weight; j++)
                matrix[i][j] = (i == 0) ? knapsack[i][1]
                        : (j < knapsack[i][0]) ? matrix[i - 1][j]
                                : Math.max(knapsack[i][1] + matrix[i - 1][j - knapsack[i][0]], matrix[i - 1][j]);
        }
        return matrix[knapsack.length - 1][weight];
    }
}