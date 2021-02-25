package org.knguyenc.datastructures.stacks;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Stack<T> implements Iterable<T> {

    private final int DEFAULT_CAPACITY = 50;
    private final T[] data;
    private int top;

    @SuppressWarnings("unchecked")
    public Stack() {
        data = (T[]) new Object[DEFAULT_CAPACITY];
        top = -1;
    }

    @SuppressWarnings("unchecked")
    public Stack(int capacity) {
        if (capacity <= 0) capacity = DEFAULT_CAPACITY;
        data = (T[]) new Object[capacity];
        top = -1;
    }

    public int size() {
        return top + 1;
    }

    public boolean isEmpty() {
        return top < 0;
    }

    public boolean isFull() {
        return (top + 1) == data.length;
    }

    public T top() {
        if (isEmpty()) throw new Error("Stack underflow, can not get top");
        return data[top];
    }

    public void push(T value) {
        if (isFull()) throw new Error("Stack overflow, can not push");
        data[++top] = value;
    }

    public T pop() {
        if (isEmpty()) throw new Error("Stack underflow, can not pop");
        return data[top--];
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private int index = 0;

            @Override
            public boolean hasNext() {
                return index <= top;
            }

            @Override
            public T next() {
                if (!hasNext()) throw new NoSuchElementException("No more element in stack");
                return data[index++];
            }
        };
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        for (T element : this)
            out.append(element).append(" ");
        return out.toString();
    }
}
