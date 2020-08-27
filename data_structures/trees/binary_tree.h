#ifndef ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_
#define ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_

#include <iostream>

namespace data_structures {
namespace trees {

template <class T>
class BinaryTree;

template <class T>
std::ostream &operator<<(std::ostream &out, const BinaryTree<T> &tree);

template <class T>
class BinaryTree {
 public:
  class Node {
   private:
    T data_;
    Node *left_;
    Node *right_;
    friend class BinaryTree;

   public:
    explicit Node(const T &data) : data_(data), left_(NULL), right_(NULL) {}
  };

 public:
  BinaryTree();
  ~BinaryTree();
  int Size() const;
  bool IsEmpty() const;
  void Insert();
  T Remove();

 private:
  Node *root_;
  int size_;

 private:
  // Depth First Traversals
  void PreOrder(Node *node) const;
  void InOrder(Node *node) const;
  void PostOrder(Node *node) const;
  // Breath First Traversal
  void LevelOrder(Node *node) const;
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
void BinaryTree<T>::Insert() {

}

template <class T>
T BinaryTree<T>::Remove() {
  return nullptr;
}

template <class T>
void BinaryTree<T>::PreOrder(BinaryTree::Node *node) const {
  if (node == NULL) return;
  std::cout << node->data_ << " ";
  PreOrder(node->left_);
  PreOrder(node->right_);
}

template <class T>
void BinaryTree<T>::InOrder(BinaryTree::Node *node) const {
  if (node == NULL) return;
  InOrder(node->left_);
  std::cout << node->data_ << " ";
  InOrder(node->right_);
}

template <class T>
void BinaryTree<T>::PostOrder(BinaryTree::Node *node) const {
  if (node == NULL) return;
  PostOrder(node->left_);
  PostOrder(node->right_);
  std::cout << node->data << " ";
}

template <class T>
void BinaryTree<T>::LevelOrder(BinaryTree::Node *node) const {

}

}  // namespace trees
}  // namespace data_structures

#endif //ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_
