package org.knguyenc.datastructures.trees;

public class BinarySearchTree<T extends Comparable<T>> extends BinaryTree<T> {

    public BinarySearchTree() {
        super();
    }

    @Override
    protected Node search(Node node, T data) {
        if (node == null || node.data == data) return node;
        return data.compareTo(node.data) < 0 ? search(node.left, data) : search(node.right, data);
    }

    @Override
    public void insert(T data) {
        Node node = new Node(data);
        Node temp = root;
        Node tempParent = null;
        while (temp != null) {
            tempParent = temp;
            temp = data.compareTo(temp.data) < 0 ? temp.left : temp.right;
        }
        if (tempParent == null) root = node;
        else if (data.compareTo(tempParent.data) < 0) tempParent.left = node;
        else tempParent.right = node;
        node.parent = tempParent;
        size++;
    }

    @Override
    public T remove(T data) {
        if (isEmpty()) throw new Error("Tree is empty, can not remove");
        Node removed = search(root, data);
        if (removed == null) throw new Error("Node is not exist in tree");
        T removedData = removed.data;
        if (removed.left == null) transplant(removed, removed.right);
        else if (removed.right == null) transplant(removed, removed.left);
        else {
            Node node = minimum(removed.right);
            if (node.parent != removed) {
                transplant(node, node.right);
                node.right = removed.right;
                removed.right.parent = node;
            }
            transplant(removed, node);
            node.left = removed.left;
            node.left.parent = node;
        }
        size--;
        return removedData;
    }

    public Node minimum() {
        if (isEmpty()) throw new Error("Tree is empty, can not get minimum");
        return minimum(root);
    }

    protected Node minimum(Node node) {
        if (isEmpty()) return null;
        while (node.left != null) node = node.left;
        return node;
    }

    public Node maximum() {
        if (isEmpty()) throw new Error("Tree is empty, can not get maximum");
        return maximum(root);
    }

    protected Node maximum(Node node) {
        if (isEmpty()) return null;
        while (node.right != null) node = node.right;
        return node;
    }
}
