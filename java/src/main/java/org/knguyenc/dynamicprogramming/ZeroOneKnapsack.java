package org.knguyenc.dynamicprogramming;

import java.util.Arrays;
import java.util.Comparator;

/**
 * 0-1 Knapsack problem implemented in Java
 *
 * @author Khoa Nguyen
 */
public class ZeroOneKnapsack {

    public static int knapsack(int[][] items, int weight) {
        Arrays.sort(items, Comparator.comparingInt(item -> item[0]));
        int[][] matrix = new int[items.length][weight + 1];
        for (int i = 0; i < matrix.length; i++) {
            matrix[i][0] = 0;
            for (int j = 1; j <= weight; j++)
                matrix[i][j] = (i == 0) ? items[i][1]
                        : (j < items[i][0]) ? matrix[i - 1][j]
                        : Math.max(items[i][1] + matrix[i - 1][j - items[i][0]], matrix[i - 1][j]);
        }
        return matrix[items.length - 1][weight];
    }
}
