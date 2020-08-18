#ifndef ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_H_
#define ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_H_

#include <iostream>

namespace data_structures {
namespace linked_lists {

template <class T>
class DoublyLinkedList {
 public:
  class Node {
   private:
    T data_;
    Node *prev_;
    Node *next_;
    friend class DoublyLinkedList;

   public:
    Node() : data_(NULL), prev_(NULL), next_(NULL) {}
    explicit Node(const T &data) : data_(data), prev_(NULL), next_(NULL) {}
  };

 public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  int Size() const;
  bool IsEmpty() const;
  void InsertFirst(const T &e);
  void InsertLast(const T &e);
  T RemoveFirst();
  T RemoveLast();

 private:
  Node *header_;
  Node *trailer_;
  int size_;

 protected:
  void Insert(Node *n, const T &e);
  void Remove(Node *n);
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : size_(0) {
  header_ = new Node();
  trailer_ = new Node();
  header_->prev_ = NULL;
  header_->next_ = trailer_;
  trailer_->prev_ = header_;
  trailer_->next_ = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  while (!IsEmpty()) RemoveFirst();
  delete header_;
  delete trailer_;
}

template <class T>
int DoublyLinkedList<T>::Size() const {
  return size_;
}

template <class T>
bool DoublyLinkedList<T>::IsEmpty() const {
  return (size_ == 0);
}

template <class T>
void DoublyLinkedList<T>::InsertFirst(const T &e) {
  Insert(header_->next_, e);
  size_++;
}

template <class T>
void DoublyLinkedList<T>::InsertLast(const T &e) {
  Insert(trailer_, e);
  size_++;
}

template <class T>
T DoublyLinkedList<T>::RemoveFirst() {
  if (IsEmpty()) throw std::runtime_error("List is empty, can not remove");
  T result = header_->next_->data_;
  Remove(header_->next_);
  size_--;
  return result;
}

template <class T>
T DoublyLinkedList<T>::RemoveLast() {
  if (IsEmpty()) throw std::runtime_error("List is empty, can not remove");
  T result = trailer_->prev_->data_;
  Remove(trailer_->prev_);
  size_--;
  return result;
}

template <class T>
void DoublyLinkedList<T>::Insert(Node *n, const T &e) {
  Node *node = new Node;
  node->data_ = e;
  node->next_ = n;
  node->prev_ = n->prev_;
  n->prev_->next_ = node;
  n->prev_ = node;
}

template <class T>
void DoublyLinkedList<T>::Remove(Node *n) {
  Node *predecessor = n->prev_;
  Node *successor = n->next_;
  predecessor->next_ = successor;
  successor->prev_ = predecessor;
  delete n;
}

}  // namespace linked_lists
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_H_
