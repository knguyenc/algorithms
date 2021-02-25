package org.knguyenc.divideconquer;

/**
 * Maximum subarray problem implemented in Java
 *
 * @author Khoa Nguyen
 */
public class MaximumSubarray {

    public static int[] maximumSubarray(int[] array, int low, int high) {
        if (low == high) return new int[]{low, high, array[low]};
        int middle = (low + high) / 2;

        int[] lArr = maximumSubarray(array, low, middle);
        int[] rArr = maximumSubarray(array, middle + 1, high);
        int[] cArr = maxCrossingSubarray(array, low, middle, high);

        if (lArr[2] >= rArr[2] && lArr[2] >= cArr[2])
            return lArr;
        else if (rArr[2] > lArr[2] && rArr[2] >= cArr[2])
            return rArr;
        else return cArr;
    }

    private static int[] maxCrossingSubarray(int[] array, int low, int middle, int high) {
        int lSum = Integer.MIN_VALUE, rSum = Integer.MIN_VALUE;
        int sum = 0, lMax = middle, rMax = middle + 1;

        for (int i = middle; i >= low; i--) {
            sum += array[i];
            if (sum > lSum) {
                lSum = sum;
                lMax = i;
            }
        }

        sum = 0;
        for (int i = middle + 1; i <= high; i++) {
            sum += array[i];
            if (sum > rSum) {
                rSum = sum;
                rMax = i;
            }
        }

        if (lSum >= rSum && lSum >= (lSum + rSum))
            return new int[]{lMax, middle, lSum};
        else if (rSum > lSum && rSum >= (lSum + rSum))
            return new int[]{middle + 1, rMax, rSum};
        else return new int[]{lMax, rMax, lSum + rSum};
    }
}
