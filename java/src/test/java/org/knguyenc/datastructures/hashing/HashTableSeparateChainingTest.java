package org.knguyenc.datastructures.hashing;

import junit.framework.TestCase;

public class HashTableSeparateChainingTest extends TestCase {

    public void testKeysGetInsertRemove() {
        HashTableSeparateChaining<Integer, String> hashTable = new HashTableSeparateChaining<>();
        assertTrue(hashTable.isEmpty());
        assertEquals(0, hashTable.size());
        hashTable.insert(18, "Cat");
        hashTable.insert(60, "Dog");
        hashTable.insert(20, "Dolphin");
        hashTable.insert(96, "Mouse");
        hashTable.insert(71, "Rabbit");
        hashTable.insert(22, "Snake");
        System.out.println(hashTable);
        assertFalse(hashTable.isEmpty());
        assertEquals(6, hashTable.size());
        assertEquals("Rabbit", hashTable.get(71));
        assertEquals("Dog", hashTable.remove(60));
        assertEquals(5, hashTable.size());
    }
}
