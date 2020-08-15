#ifndef ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST_H_
#define ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST_H_

#include <iostream>

namespace data_structures {
namespace linked_lists {

template <class T>
class SinglyLinkedList {
 private:
  class Node {
   private:
    T data_;
    Node *next_;
    friend class SinglyLinkedList;
  };

 public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  int Size() const;
  bool IsEmpty() const;
  const T &First() const;
  void InsertFirst(const T &e);
  T RemoveFirst();

 private:
  Node *Search(const T &e) const;

 private:
  Node *head_;
  int size_;
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() : head_(NULL), size_(0) {}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
  while (!IsEmpty()) RemoveFirst();
}

template <class T>
int SinglyLinkedList<T>::Size() const {
  return size_;
}

template <class T>
bool SinglyLinkedList<T>::IsEmpty() const {
  return (size_ == 0);
}

template <class T>
const T &SinglyLinkedList<T>::First() const {
  if (IsEmpty()) throw std::runtime_error("List is empty, can not get the first element");
  return head_->data_;
}

template <class T>
void SinglyLinkedList<T>::InsertFirst(const T &e) {
  Node *node = new Node;
  node->data_ = e;
  node->next_ = head_;
  head_ = node;
  size_++;
}

template <class T>
T SinglyLinkedList<T>::RemoveFirst() {
  if (IsEmpty()) throw std::runtime_error("List is empty, can not remove");
  Node *old = head_;
  T result = old->data_;
  head_ = head_->next_;
  delete old;
  size_--;
  return result;
}

template <class T>
typename SinglyLinkedList<T>::Node *SinglyLinkedList<T>::Search(const T &e) const {
  Node *temp = head_;
  while (temp != NULL && temp->data_ != e)
    temp = temp->next_;
  return temp;
}

}  // namespace linked_lists
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST_H_
