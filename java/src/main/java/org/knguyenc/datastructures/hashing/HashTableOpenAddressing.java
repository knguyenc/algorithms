package org.knguyenc.datastructures.hashing;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class HashTableOpenAddressing<K extends Number, V> implements Iterable<K> {

    private final K[] keys;
    private final V[] values;
    private int size;
    private final int DEFAULT_CAPACITY = 10;

    @SuppressWarnings("unchecked")
    public HashTableOpenAddressing() {
        keys = (K[]) new Number[DEFAULT_CAPACITY];
        values = (V[]) new Object[DEFAULT_CAPACITY];
        Arrays.fill(keys, null);
        Arrays.fill(values, null);
        size = 0;
    }

    @SuppressWarnings("unchecked")
    public HashTableOpenAddressing(int capacity) {
        if (capacity <= 0) capacity = DEFAULT_CAPACITY;
        keys = (K[]) new Number[capacity];
        values = (V[]) new Object[capacity];
        Arrays.fill(keys, null);
        Arrays.fill(values, null);
        size = 0;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public K[] keys() {
        return keys;
    }

    private int hashing(K key) {
        int hash = key.intValue() % keys.length;
        if (hash < 0) hash += keys.length;
        return hash;
    }

    private int rehashing() {
        int index;
        for (index = 0; index < keys.length; index++)
            if (keys[index] == null) return index;
        throw new Error("Hash table is full");
    }

    public V get(K key) {
        int index;
        for (index = 0; index < keys.length; index++)
            if (keys[index] != null && keys[index].equals(key)) break;
        if (index > keys.length - 1) throw new Error("Node is not exist in this hash table");
        return values[index];
    }

    public void insert(K key, V value) {
        for (K element : keys)
            if (element != null && element.equals(key)) throw new Error("Key is already exist");
        int hash = hashing(key);
        if (keys[hash] != null) hash = rehashing();
        keys[hash] = key;
        values[hash] = value;
        size++;
    }

    public V remove(K key) {
        int index = 0;
        for (; index < keys.length; index++)
            if (keys[index].equals(key)) break;
        if (index >= keys.length) throw new Error("Key is not exist");
        V removed = values[index];
        keys[index] = null;
        values[index] = null;
        size--;
        return removed;
    }

    @Override
    public Iterator<K> iterator() {
        List<K> list = new ArrayList<>();
        for (K key : keys)
            if (key != null) list.add(key);
        return list.iterator();
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        for (K key : this)
            out.append("(").append(key).append(": ").append(get(key)).append(") ");
        return out.toString();
    }
}
