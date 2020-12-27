#include "data_structures/trees/binary_tree.h"

#ifndef ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_SEARCH_TREE_H_
#define ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_SEARCH_TREE_H_

namespace data_structures {
namespace trees {

template <class T>
class BinarySearchTree : public trees::BinaryTree<T> {
 public:
  using trees::BinaryTree<T>::BinaryTree;
  using trees::BinaryTree<T>::Search;
  typename BinaryTree<T>::Node *Search(typename BinaryTree<T>::Node *node,
                                       const T &data) const;
  void Insert(const T &data);
  T Remove(const T &data);
  const typename BinaryTree<T>::Node *Maximum() const;
  const typename BinaryTree<T>::Node *Minimum() const;

 protected:
  typename BinaryTree<T>::Node *Maximum(
      typename BinaryTree<T>::Node *node) const;
  typename BinaryTree<T>::Node *Minimum(
      typename BinaryTree<T>::Node *node) const;
};

template <class T>
typename BinaryTree<T>::Node *BinarySearchTree<T>::Search(
    typename BinaryTree<T>::Node *node, const T &data) const {
  if (node == NULL || node->data_ == data) return node;
  return data < node->data_ ? Search(node->left_, data)
                            : Search(node->right_, data);
}

template <class T>
void BinarySearchTree<T>::Insert(const T &data) {
  typename BinaryTree<T>::Node *node = new typename BinaryTree<T>::Node(data);
  typename BinaryTree<T>::Node *temp = this->root_;
  typename BinaryTree<T>::Node *temp_parent = NULL;
  while (temp != NULL) {
    temp_parent = temp;
    temp = data < temp->data_ ? temp->left_ : temp->right_;
  }
  if (temp_parent == NULL)
    this->root_ = node;
  else if (data < temp_parent->data_)
    temp_parent->left_ = node;
  else
    temp_parent->right_ = node;
  node->parent_ = temp_parent;
  this->size_++;
}

template <class T>
T BinarySearchTree<T>::Remove(const T &data) {
  if (this->IsEmpty())
    throw std::runtime_error("Tree is empty, can not remove");
  typename BinaryTree<T>::Node *removed = Search(this->root_, data);
  if (removed == NULL) throw std::runtime_error("Node is not exist in tree");
  T removed_data = removed->data_;
  if (removed->left_ == NULL)
    this->Transplant(removed, removed->right_);
  else if (removed->right_ == NULL)
    this->Transplant(removed, removed->left_);
  else {
    typename BinaryTree<T>::Node *node = Minimum(removed->right_);
    if (node->parent_ != removed) {
      this->Transplant(node, node->right_);
      node->right_ = removed->right_;
      removed->right_->parent_ = node;
    }
    this->Transplant(removed, node);
    node->left_ = removed->left_;
    node->left_->parent_ = node;
  }
  this->size_--;
  return removed_data;
}

template <class T>
const typename BinaryTree<T>::Node *BinarySearchTree<T>::Maximum() const {
  if (this->IsEmpty())
    throw std::runtime_error("Tree is empty, can not get maximum");
  return Maximum(this->root_);
}

template <class T>
typename BinaryTree<T>::Node *BinarySearchTree<T>::Maximum(
    typename BinaryTree<T>::Node *node) const {
  if (this->IsEmpty()) return NULL;
  while (node->right_ != NULL) node = node->right_;
  return node;
}

template <class T>
const typename BinaryTree<T>::Node *BinarySearchTree<T>::Minimum() const {
  if (this->IsEmpty())
    throw std::runtime_error("Tree is empty, can not get minium");
  return Minimum(this->root_);
}

template <class T>
typename BinaryTree<T>::Node *BinarySearchTree<T>::Minimum(
    typename BinaryTree<T>::Node *node) const {
  if (this->IsEmpty()) return NULL;
  while (node->left_ != NULL) node = node->left_;
  return node;
}

}  // namespace trees
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_SEARCH_TREE_H_
