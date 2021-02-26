package org.knguyenc.greedy;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Fractional Knapsack problem implemented in Java
 *
 * @author Khoa Nguyen
 */
public class FractionalKnapsack {

    public static int knapsack(int[][] items, int weight) {
        Arrays.sort(items, Comparator.comparingInt(item -> (item[1] / item[0]) * -1));
        int maxValue = 0;
        for (int[] item : items) {
            if (weight <= 0) break;
            if (weight < item[0]) {
                maxValue += weight * item[1] / item[0];
                weight = 0;
            } else {
                maxValue += item[1];
                weight -= item[0];
            }
        }
        return maxValue;
    }
}
 