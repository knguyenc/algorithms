package org.knguyenc.datastructures.hashing;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class HashTableSeparateChaining<K extends Number, V> implements Iterable<K> {

    private final Node[] buckets;
    private final List<K> keys;
    private int size;
    private final int slots;
    private final int DEFAULT_SLOTS = 10;

    @SuppressWarnings("unchecked")
    public HashTableSeparateChaining() {
        slots = DEFAULT_SLOTS;
        buckets = new HashTableSeparateChaining.Node[slots];
        Arrays.fill(buckets, null);
        keys = new ArrayList<>();
        size = 0;
    }

    @SuppressWarnings("unchecked")
    public HashTableSeparateChaining(int slots) {
        if (slots <= 0) slots = DEFAULT_SLOTS;
        this.slots = slots;
        buckets = new HashTableSeparateChaining.Node[slots];
        Arrays.fill(buckets, null);
        keys = new ArrayList<>();
        size = 0;
    }

    class Node {
        protected final K key;
        protected final V value;
        protected Node next;

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
            next = null;
        }

        public String toString() {
            return String.format("(%s: %s)", key.toString(), value.toString());
        }
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    @SuppressWarnings("unchecked")
    public K[] keys() {
        return (K[]) keys.toArray();
    }

    private int hashing(K key) {
        int hash = key.intValue() % slots;
        if (hash < 0) hash += slots;
        return hash;
    }

    public V get(K key) {
        int hash = hashing(key);
        Node node = buckets[hash];
        while (node != null && !node.key.equals(key)) node = node.next;
        if (node == null) throw new Error("Node is not exist in this hash table");
        return node.value;
    }

    public void insert(K key, V value) {
        int hash = hashing(key);
        Node node = new Node(key, value);
        if (buckets[hash] == null) buckets[hash] = node;
        else {
            Node temp = buckets[hash];
            if (temp.key.equals(key)) throw new Error("Key is already exist");
            while (temp.next != null) {
                if (temp.key.equals(key)) throw new Error("Key is already exist");
                temp = temp.next;
            }
            temp.next = node;
        }
        keys.add(key);
        size++;
    }

    public V remove(K key) {
        int hash = hashing(key);
        Node node = buckets[hash], prev = null;
        while (node != null && !node.key.equals(key)) {
            prev = node;
            node = node.next;
        }
        if (node == null) throw new Error("Key is not exist in this hash table");
        V removed = node.value;
        if (node == buckets[hash]) buckets[hash] = node.next;
        else if (prev == null) buckets[hash] = null;
        else prev.next = node.next;
        node.next = null;
        keys.remove(key);
        size--;
        return removed;
    }

    @Override
    public Iterator<K> iterator() {
        return keys.iterator();
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        for (K key : this)
            out.append("(").append(key).append(": ").append(get(key)).append(") ");
        return out.toString();
    }
}
