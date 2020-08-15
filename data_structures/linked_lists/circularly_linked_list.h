#ifndef ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_CIRCULARLY_LINKED_LIST_H_
#define ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_CIRCULARLY_LINKED_LIST_H_

#include <iostream>

namespace data_structures {
namespace linked_lists {

template <class T>
class CircularlyLinkedList {
 public:
  CircularlyLinkedList();
  ~CircularlyLinkedList();
  int Size() const;
  bool IsEmpty() const;
  const T &First() const;
  const T &Last() const;
  void Rotate();
  void InsertFirst(const T &e);
  void InsertLast(const T &e);
  T RemoveFirst();

 public:
  class Node {
   private:
    T data_;
    Node *next_;
    friend class CircularlyLinkedList;
  };
  Node *tail_;
  int size_;
};

template <class T>
CircularlyLinkedList<T>::CircularlyLinkedList() : tail_(NULL), size_(0) {}

template <class T>
CircularlyLinkedList<T>::~CircularlyLinkedList() {
  while (!IsEmpty()) RemoveFirst();
}

template <class T>
int CircularlyLinkedList<T>::Size() const {
  return size_;
}

template <class T>
bool CircularlyLinkedList<T>::IsEmpty() const {
  return (size_ == 0);
}

template <class T>
const T &CircularlyLinkedList<T>::First() const {
  if (IsEmpty())
    throw std::runtime_error("List is empty, can not get the first element");
  return tail_->next_->data_;
}

template <class T>
const T &CircularlyLinkedList<T>::Last() const {
  if (IsEmpty())
    throw std::runtime_error("List is empty, can not get the last element");
  return tail_->data_;
}

template <class T>
void CircularlyLinkedList<T>::Rotate() {
  tail_ = tail_->next_;
}

template <class T>
void CircularlyLinkedList<T>::InsertFirst(const T &e) {
  Node *n = new Node;
  n->data_ = e;
  if (IsEmpty()) {
    tail_ = n;
    tail_->next_ = tail_;
  } else {
    n->next_ = tail_->next_;
    tail_->next_ = n;
  }
  size_++;
}

template <class T>
void CircularlyLinkedList<T>::InsertLast(const T &e) {
  InsertFirst(e);
  tail_ = tail_->next_;
}

template <class T>
T CircularlyLinkedList<T>::RemoveFirst() {
  if (IsEmpty()) throw std::runtime_error("List is empty, can not remove");
  Node *old = tail_->next_;
  T result = old->data_;
  if (old == tail_) {
    tail_ = NULL;
  } else {
    tail_->next_ = old->next_;
  }
  delete old;
  size_--;
  return result;
}

}  // namespace linked_lists
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_CIRCULARLY_LINKED_LIST_H_
