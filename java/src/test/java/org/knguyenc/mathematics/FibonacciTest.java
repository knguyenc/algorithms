package org.knguyenc.mathematics;

import junit.framework.TestCase;

public class FibonacciTest extends TestCase {

    public void testVarietyInputs() {
        assertEquals(8, Fibonacci.binaryFibonacci(6));
        assertEquals(55, Fibonacci.binaryFibonacci(10));
        assertEquals(21, Fibonacci.binaryFibonacci(8));

        assertEquals(8, Fibonacci.linearFibonacci(6)[0]);
        assertEquals(55, Fibonacci.linearFibonacci(10)[0]);
        assertEquals(21, Fibonacci.linearFibonacci(8)[0]);
    }
}
