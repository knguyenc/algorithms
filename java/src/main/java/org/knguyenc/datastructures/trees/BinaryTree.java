package org.knguyenc.datastructures.trees;

import org.knguyenc.datastructures.queues.Queue;
import org.knguyenc.datastructures.stacks.Stack;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class BinaryTree<T> implements Iterable<T> {

    protected Node root;
    protected int size;

    public BinaryTree() {
        root = null;
        size = 0;
    }

    class Node {

        public T data;
        protected Node parent;
        protected Node left;
        protected Node right;

        public Node(T data) {
            this.data = data;
            parent = null;
            left = null;
            right = null;
        }

        public String toString() {
            return String.format("Node(%s)", data.toString());
        }
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return root == null;
    }

    public Node search(T data) {
        return search(root, data);
    }

    protected Node search(Node node, T data) {
        if (node == null || node.data == data) return node;
        Node leftSearch = search(node.left, data);
        if (leftSearch != null) return leftSearch;
        return search(node.right, data);
    }

    public void insert(T data) {
        Node node = new Node(data);
        if (isEmpty()) root = node;
        else {
            Queue<Node> queue = new Queue<>(size + 1);
            queue.enqueue(root);
            while (!queue.isEmpty()) {
                Node temp = queue.dequeue();
                if (temp.left == null) {
                    temp.left = node;
                    node.parent = temp;
                    break;
                } else queue.enqueue(temp.left);
                if (temp.right == null) {
                    temp.right = node;
                    node.parent = temp;
                    break;
                } else queue.enqueue(temp.right);
            }
        }
        size++;
    }

    public T remove(T data) {
        if (isEmpty()) throw new Error("Tree is empty, can not remove");
        Node removed = null;
        Node node = null;
        Queue<Node> queue = new Queue<>(size + 1);
        queue.enqueue(root);
        while (!queue.isEmpty()) {
            node = queue.dequeue();
            if (node.data == data) removed = node;
            if (node.left != null) queue.enqueue(node.left);
            if (node.right != null) queue.enqueue(node.right);
        }
        if (removed == null) throw new Error("Node is not exist in tree");
        T savedData = node.data;
        T removedData = removed.data;
        transplant(node, null);
        removed.data = savedData;
        size--;
        return removedData;
    }

    public void transplant(Node node, Node child) {
        if (node.parent == null) root = child;
        else if (node == node.parent.left) node.parent.left = child;
        else node.parent.right = child;
        if (child != null) child.parent = node.parent;
        node.parent = null;
    }

    public int height(Node node) {
        if (node == null) return 0;
        return 1 + Math.max(height(node.left), height(node.right));
    }

    public Iterator<T> preOrder(boolean recursive) {
        List<T> nodeList = new ArrayList<>(size + 1);
        if (recursive) preOrder(nodeList, root);
        else nonRecursivePreOrder(nodeList);
        return nodeList.iterator();
    }

    protected void preOrder(List<T> list, Node node) {
        if (node != null) {
            list.add(node.data);
            preOrder(list, node.left);
            preOrder(list, node.right);
        }
    }

    protected void nonRecursivePreOrder(List<T> list) {
        Node temp = root;
        Stack<Node> stack = new Stack<>(size);
        while (true) {
            if (temp != null) {
                stack.push(temp);
                list.add(temp.data);
                temp = temp.left;
            } else if (!stack.isEmpty()) {
                temp = stack.pop();
                temp = temp.right;
            } else break;
        }
    }

    public Iterator<T> inOrder(boolean recursive) {
        List<T> nodeList = new ArrayList<>(size + 1);
        if (recursive) inOrder(nodeList, root);
        else nonRecursiveInOrder(nodeList);
        return nodeList.iterator();
    }

    protected void inOrder(List<T> list, Node node) {
        if (node != null) {
            inOrder(list, node.left);
            list.add(node.data);
            inOrder(list, node.right);
        }
    }

    protected void nonRecursiveInOrder(List<T> list) {
        Node temp = root;
        Stack<Node> stack = new Stack<>(size);
        while (true) {
            if (temp != null) {
                stack.push(temp);
                temp = temp.left;
            } else if (!stack.isEmpty()) {
                temp = stack.pop();
                list.add(temp.data);
                temp = temp.right;
            } else break;
        }
    }

    public Iterator<T> postOrder(boolean recursive) {
        List<T> nodeList = new ArrayList<>(size + 1);
        if (recursive) postOrder(nodeList, root);
        else nonRecursivePostOrder(nodeList);
        return nodeList.iterator();
    }

    protected void postOrder(List<T> list, Node node) {
        if (node != null) {
            postOrder(list, node.left);
            postOrder(list, node.right);
            list.add(node.data);
        }
    }

    protected void nonRecursivePostOrder(List<T> list) {
        Node temp = root;
        Stack<Node> stack = new Stack<>(size);
        do {
            while (temp != null) {
                if (temp.right != null) stack.push(temp.right);
                stack.push(temp);
                temp = temp.left;
            }
            temp = stack.pop();
            if (!stack.isEmpty() && temp.right != null && stack.top() == temp.right) {
                stack.pop();
                stack.push(temp);
                temp = temp.right;
            } else {
                list.add(temp.data);
                temp = null;
            }
        } while (!stack.isEmpty());
    }

    public Iterator<T> levelOrder(boolean recursive) {
        List<T> nodeList = new ArrayList<>(size + 1);
        if (recursive) {
            for (int i = 1; i <= height(root); i++)
                iterGivenLevel(nodeList, root, i);
        } else nonRecursiveLevelOrder(nodeList);
        return nodeList.iterator();
    }

    protected void iterGivenLevel(List<T> list, Node node, int level) {
        if (node == null) return;
        if (level == 1) list.add(node.data);
        else if (level > 1) {
            iterGivenLevel(list, node.left, level - 1);
            iterGivenLevel(list, node.right, level - 1);
        }
    }

    protected void nonRecursiveLevelOrder(List<T> list) {
        if (isEmpty()) return;
        Queue<Node> queue = new Queue<>(size);
        queue.enqueue(root);
        while (!queue.isEmpty()) {
            Node temp = queue.dequeue();
            list.add(temp.data);
            if (temp.left != null) queue.enqueue(temp.left);
            if (temp.right != null) queue.enqueue(temp.right);
        }
    }

    @Override
    public Iterator<T> iterator() {
        return inOrder(true); // recursive in-order traversal is default
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        for (T element : this)
            out.append("Node(").append(element).append(")").append(" -> ");
        return out.toString();
    }
}
