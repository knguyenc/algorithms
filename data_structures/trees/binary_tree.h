#ifndef ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_
#define ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_

#include <iostream>

#include "data_structures/queues/queue.h"
#include "data_structures/stacks/stack.h"

namespace data_structures {
namespace trees {

template <class T>
class BinaryTree {
 public:
  class Node {
   public:
    T data_;
    Node *parent_;
    Node *left_;
    Node *right_;
    friend class BinaryTree;
    explicit Node(const T &data) : data_(data), parent_(NULL), left_(NULL), right_(NULL) {}
  };

 public:
  BinaryTree();
  ~BinaryTree();
  int Size() const;
  bool IsEmpty() const;
  const Node *Search(const T &data) const;
  virtual void Insert(const T &data);
  virtual T Remove(const T &data);

  friend std::ostream &operator<<(std::ostream &out, const BinaryTree &tree) {
    if (tree.IsEmpty()) {
      out << "Empty tree";
    } else {
      out << "Preorder traversal: ";
      tree.PreOrder(out, tree.root_, true);
      out << std::endl;

      out << "Non-recursive preorder traversal: ";
      tree.PreOrder(out, tree.root_, false);
      out << std::endl;

      out << "Inorder traversal: ";
      tree.InOrder(out, tree.root_, true);
      out << std::endl;

      out << "Non-recursive inorder traversal: ";
      tree.InOrder(out, tree.root_, false);
      out << std::endl;

      out << "Postorder traversal: ";
      tree.PostOrder(out, tree.root_, true);
      out << std::endl;

      out << "Non-recursive postorder traversal: ";
      tree.PostOrder(out, tree.root_, false);
      out << std::endl;

      out << "Levelorder traversal: ";
      tree.LevelOrder(out, true);
      out << std::endl;

      out << "Non-recursive levelorder traversal: ";
      tree.LevelOrder(out, false);
    }
    return out;
  }

 protected:
  virtual Node *Search(Node *node, const T &data) const;
  // Depth First Traversals
  void PreOrder(std::ostream &out, Node *node, bool recursive) const;
  void InOrder(std::ostream &out, Node *node, bool recursive) const;
  void PostOrder(std::ostream &out, Node *node, bool recursive) const;
  // Breadth First Traversal
  void LevelOrder(std::ostream &out, bool recursive) const;
  void PrintLevel(std::ostream &out, Node *node, int level) const;
  int Height(Node *node) const;
  void Transplant(Node *node, Node *child);

 protected:
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
  return (root_ == NULL);
}

template <class T>
const typename BinaryTree<T>::Node *BinaryTree<T>::Search(const T &data) const {
  return Search(root_, data);
}

template <class T>
typename BinaryTree<T>::Node *BinaryTree<T>::Search(BinaryTree::Node *node, const T &data) const {
  if (node == NULL || node->data_ == data) return node;
  Node *left_search = Search(node->left_, data);
  if (left_search != NULL) return left_search;
  return Search(node->right_, data);
}

template <class T>
void BinaryTree<T>::Insert(const T &data) {
  Node *node = new Node(data);
  if (IsEmpty())
    root_ = node;
  else {
    data_structures::queues::Queue<Node *> queue(size_ + 1);
    queue.Enqueue(root_);
    while (!queue.IsEmpty()) {
      Node *temp = queue.Dequeue();

      if (temp->left_ == NULL) {
        temp->left_ = node;
        node->parent_ = temp;
        break;
      } else
        queue.Enqueue(temp->left_);

      if (temp->right_ == NULL) {
        temp->right_ = node;
        node->parent_ = temp;
        break;
      } else
        queue.Enqueue(temp->right_);
    }
  }
  size_++;
}

template <class T>
T BinaryTree<T>::Remove(const T &data) {
  if (IsEmpty()) throw std::runtime_error("Tree is empty, can not remove");
  Node *removed = NULL;
  Node *node = NULL;
  data_structures::queues::Queue<Node *> queue(size_ + 1);
  queue.Enqueue(root_);
  while (!queue.IsEmpty()) {
    node = queue.Dequeue();
    if (node->data_ == data) removed = node;
    if (node->left_ != NULL) queue.Enqueue(node->left_);
    if (node->right_ != NULL) queue.Enqueue(node->right_);
  }
  if (removed == NULL) throw std::runtime_error("Node is not exist in tree");
  T saved_data = node->data_;
  T removed_data = removed->data_;
  Transplant(node, NULL);
  removed->data_ = saved_data;
  size_--;
  return removed_data;
}

template <class T>
void BinaryTree<T>::Transplant(Node *node, Node *child) {
  if (node->parent_ == NULL)
    root_ = child;
  else if (node == node->parent_->left_)
    node->parent_->left_ = child;
  else
    node->parent_->right_ = child;
  if (child != NULL) child->parent_ = node->parent_;
  node->parent_ = NULL;
}

template <class T>
int BinaryTree<T>::Height(BinaryTree::Node *node) const {
  if (node == NULL)
    return 0;
  else
    return 1 + std::max(Height(node->left_), Height(node->right_));
}

template <class T>
void BinaryTree<T>::PreOrder(std::ostream &out, BinaryTree::Node *node, bool recursive) const {
  if (recursive) {
    if (node == NULL) return;
    out << "[" << node->data_ << "]->";
    PreOrder(out, node->left_, recursive);
    PreOrder(out, node->right_, recursive);
  } else {
    Node *temp = root_;
    data_structures::stacks::Stack<Node *> stack(size_);
    while (true) {
      if (temp != NULL) {
        stack.Push(temp);
        out << "[" << temp->data_ << "]->";
        temp = temp->left_;
      } else if (!stack.IsEmpty()) {
        temp = stack.Pop();
        temp = temp->right_;
      } else
        break;
    }
  }
}

template <class T>
void BinaryTree<T>::InOrder(std::ostream &out, BinaryTree::Node *node, bool recursive) const {
  if (recursive) {
    if (node == NULL) return;
    InOrder(out, node->left_, recursive);
    out << "[" << node->data_ << "]->";
    InOrder(out, node->right_, recursive);
  } else {
    Node *temp = root_;
    data_structures::stacks::Stack<Node *> stack(size_);
    while (true) {
      if (temp != NULL) {
        stack.Push(temp);
        temp = temp->left_;
      } else if (!stack.IsEmpty()) {
        temp = stack.Pop();
        out << "[" << temp->data_ << "]->";
        temp = temp->right_;
      } else
        break;
    }
  }
}

template <class T>
void BinaryTree<T>::PostOrder(std::ostream &out, BinaryTree::Node *node, bool recursive) const {
  if (recursive) {
    if (node == NULL) return;
    PostOrder(out, node->left_, recursive);
    PostOrder(out, node->right_, recursive);
    out << "[" << node->data_ << "]->";
  } else {
    Node *temp = root_;
    data_structures::stacks::Stack<Node *> stack(size_);
    do {
      while (temp != NULL) {
        if (temp->right_ != NULL) stack.Push(temp->right_);
        stack.Push(temp);
        temp = temp->left_;
      }
      temp = stack.Pop();
      if (!stack.IsEmpty() && temp->right_ != NULL && stack.Top() == temp->right_) {
        stack.Pop();
        stack.Push(temp);
        temp = temp->right_;
      } else {
        out << "[" << temp->data_ << "]->";
        temp = NULL;
      }
    } while (!stack.IsEmpty());
  }
}

template <class T>
void BinaryTree<T>::LevelOrder(std::ostream &out, bool recursive) const {
  if (recursive)
    for (int i = 1; i <= Height(root_); i++) PrintLevel(out, root_, i);
  else {
    if (IsEmpty()) return;
    data_structures::queues::Queue<Node *> queue(size_);
    queue.Enqueue(root_);
    while (!queue.IsEmpty()) {
      Node *temp = queue.Dequeue();
      out << "[" << temp->data_ << "]->";
      if (temp->left_ != NULL) queue.Enqueue(temp->left_);
      if (temp->right_ != NULL) queue.Enqueue(temp->right_);
    }
  }
}

template <class T>
void BinaryTree<T>::PrintLevel(std::ostream &out, BinaryTree::Node *node, int level) const {
  if (node == NULL) return;
  if (level == 1)
    out << "[" << node->data_ << "]->";
  else if (level > 1) {
    PrintLevel(out, node->left_, level - 1);
    PrintLevel(out, node->right_, level - 1);
  }
}

}  // namespace trees
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_
