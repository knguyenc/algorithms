package org.knguyenc.mathematics;

import junit.framework.TestCase;

public class FactorialTest extends TestCase {

    public void testVarietyInputs() {
        assertEquals(720, Factorial.factorial(6));
        assertEquals(3628800, Factorial.factorial(10));
        assertEquals(40320, Factorial.factorial(8));
    }
}
