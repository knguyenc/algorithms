package org.knguyenc.sorting;

import junit.framework.TestCase;

import static org.junit.Assert.assertArrayEquals;

public class BucketSortTest extends TestCase {

    public void testVarietyTypesOfArrays() {
        Float[] floats = {0.52f, 0.44f, 0.68f, 0.95f, 0.1f, 0.12f, 0.32f, 0.59f};
        Double[] doubles = {0.52, 0.44, 0.68, 0.95, 0.1, 0.12, 0.32, 0.59};

        BucketSort bucketSort = new BucketSort();
        bucketSort.sort(floats);
        assertArrayEquals(new Float[]{0.1f, 0.12f, 0.32f, 0.44f, 0.52f, 0.59f, 0.68f, 0.95f}, floats);

        bucketSort.sort(doubles);
        assertArrayEquals(new Double[]{0.1, 0.12, 0.32, 0.44, 0.52, 0.59, 0.68, 0.95}, doubles);
    }
}
