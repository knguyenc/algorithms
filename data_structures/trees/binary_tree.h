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

 private:
  Node *root_;
  int size_;
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

}  // namespace trees
}  // namespace data_structures

#endif //ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_
