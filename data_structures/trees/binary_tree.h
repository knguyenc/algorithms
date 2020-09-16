#ifndef ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_
#define ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_

#include <iostream>
#include "data_structures/queues/queue.h"

namespace data_structures {
namespace trees {

template <class T>
class BinaryTree {
 public:
  class Node {
   private:
    T data_;
    Node *parent_;
    Node *left_;
    Node *right_;
    friend class BinaryTree;

   public:
    explicit Node(const T &data) : data_(data), parent_(NULL), left_(NULL), right_(NULL) {}
  };

 public:
  BinaryTree();
  ~BinaryTree();
  int Size() const;
  bool IsEmpty() const;
  const Node &Search(const T &e) const;
  void Insert(const T &e);
  T Remove(const T &e);

  friend std::ostream &operator<<(std::ostream &out, const BinaryTree &tree) {
    if (tree.IsEmpty()) {
      out << "Empty tree" << std::endl;
    } else {
      out << "Preorder traversal: ";
      tree.PreOrder(tree.root_);
      out << std::endl;

      out << "Inorder traversal: ";
      tree.InOrder(tree.root_);
      out << std::endl;

      out << "Postorder traversal: ";
      tree.PostOrder(tree.root_);
      out << std::endl;

      out << "Levelorder traversal: ";
      tree.LevelOrder(tree.root_);
      out << std::endl;
    }
    return out;
  }

 private:
  Node *root_;
  int size_;

 private:
  const Node &Search(const Node &node, const T &e) const;
  // Depth First Traversals
  std::ostream &PreOrder(std::ostream &out, Node *node) const;
  std::ostream &InOrder(std::ostream &out, Node *node) const;
  std::ostream &PostOrder(std::ostream &out, Node *node) const;
  // Breath First Traversal
  std::ostream &LevelOrder(std::ostream &out) const;
  std::ostream &PrintLevel(std::ostream &out, Node *node, int level) const;
  int Height(Node *node) const;
};

template <class T>
BinaryTree<T>::BinaryTree() : root_(NULL), size_(0) {}

template <class T>
BinaryTree<T>::~BinaryTree() {
  delete root_;
}

template <class T>
int BinaryTree<T>::Size() const {
  return size_;
}

template <class T>
bool BinaryTree<T>::IsEmpty() const {
  return (size_ == 0);
}

template <class T>
const class BinaryTree<T>::Node &BinaryTree<T>::Search(const T &e) const {
  return Search(root_, e);
}

template <class T>
const class BinaryTree<T>::Node &BinaryTree<T>::Search(const BinaryTree::Node &node, const T &e) const {
  if (node == NULL) return NULL;
  if (node->data_ == e) return node;
  Node &left_search = Search(node.left_, e);
  if (left_search != NULL) return left_search;
  return Search(node.right_, e);
}

template <class T>
void BinaryTree<T>::Insert(const T &e) {
  Node *node = new Node(e);
  if (IsEmpty()) {
    root_ = node;
  } else {
    data_structures::queues::Queue<Node> queue(size_ + 1);
    queue.Enqueue(root_);
    while (!queue.IsEmpty()) {
      Node *temp = queue.Dequeue();

      if (temp->left_ == NULL) {
        temp->left_ = node;
        node->parent_ = temp;
        break;
      } else queue.Enqueue(temp->left_);

      if (temp->right_ == NULL) {
        temp->right_ = node;
        node->parent_ = temp;
        break;
      } else queue.Enqueue(temp->right_);
    }
  }
  size_++;
}

template <class T>
T BinaryTree<T>::Remove(const T &e) {
  return e;
}

template <class T>
int BinaryTree<T>::Height(BinaryTree::Node *node) const {
  if (node == NULL)
    return 0;
  else
    return 1 + std::max(Height(node->left), Height(node->right));
}

template <class T>
std::ostream &BinaryTree<T>::PreOrder(std::ostream &out, BinaryTree::Node *node) const {
  if (node == NULL) return out;
  out << node->data_ << " ";
  PreOrder(node->left_);
  PreOrder(node->right_);
  return out;
}

template <class T>
std::ostream &BinaryTree<T>::InOrder(std::ostream &out, BinaryTree::Node *node) const {
  if (node == NULL) return out;
  InOrder(node->left_);
  out << node->data_ << " ";
  InOrder(node->right_);
  return out;
}

template <class T>
std::ostream &BinaryTree<T>::PostOrder(std::ostream &out, BinaryTree::Node *node) const {
  if (node == NULL) return out;
  PostOrder(node->left_);
  PostOrder(node->right_);
  out << node->data << " ";
  return out;
}

template <class T>
std::ostream &BinaryTree<T>::LevelOrder(std::ostream &out) const {
  for (int i = 1; i <= Height(root_); i++) out << PrintLevel(root_, i);
  return out;
}

template <class T>
std::ostream &BinaryTree<T>::PrintLevel(std::ostream &out, BinaryTree::Node *node, int level) const {
  if (node == NULL) return out;
  if (level == 1) {
    out << node->data_ << " ";
    return out;
  }
  PrintLevel(node->left_, level - 1);
  PrintLevel(node->right_, level - 1);
  return out;
}

}  // namespace trees
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_
