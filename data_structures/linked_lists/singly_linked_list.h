#ifndef ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST_H_
#define ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST_H_

#include <iostream>

namespace data_structures {
namespace linked_lists {

template <class T>
class SinglyLinkedList;

template <class T>
std::ostream &operator<<(std::ostream &out, const SinglyLinkedList<T> &list);

template <class T>
class SinglyLinkedList {
 public:
  class Node {
   private:
    T data_;
    Node *next_;
    friend class SinglyLinkedList;

   public:
    Node() : data_(NULL), next_(NULL) {}
    explicit Node(const T &data) : data_(data), next_(NULL) {}
  };

 public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  int Size() const;
  bool IsEmpty() const;
  bool Search(const T &e) const;
  void Insert(const T &e);
  T Remove(const T &e);
  friend std::ostream &operator<< <T>(std::ostream &out, const SinglyLinkedList &list);

 private:
  Node *head_;
  int size_;
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() : head_(NULL), size_(0) {}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
  while (!IsEmpty()) Remove(head_->data_);
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
bool SinglyLinkedList<T>::Search(const T &e) const {
  Node *temp = head_;
  while (temp != NULL) {
    if (temp->data_ == e) return true;
    temp = temp->next_;
  }
  return false;
}

template <class T>
void SinglyLinkedList<T>::Insert(const T &e) {
  Node *node = new Node(e);
  if (IsEmpty()) {
    head_ = node;
  } else {
    Node *temp = head_;
    while (temp->next_ != NULL)
      temp = temp->next_;
    temp->next_ = node;
  }
  size_++;
}

template <class T>
T SinglyLinkedList<T>::Remove(const T &e) {
  if (IsEmpty()) throw std::runtime_error("List is empty, can not remove");
  Node *old = head_, *prev;
  while (old != NULL && old->data_ != e) {
    prev = old;
    old = old->next_;
  }
  if (old == NULL) throw std::runtime_error("Node is not exist in this list");
  T result = old->data_;
  if (old == head_) {
    head_ = head_->next_;
  } else {
    prev->next_ = old->next_;
  }
  delete old;
  size_--;
  return result;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const SinglyLinkedList<T> &list) {
  if (list.IsEmpty()) {
    out << "Empty list";
  } else {
    typename SinglyLinkedList<T>::Node *temp = list.head_;
    out << "List: ";
    while (temp != NULL) {
      out << temp->data_ << " ";
      temp = temp->next_;
    }
  }
  out << std::endl;
  return out;
}

}  // namespace linked_lists
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST_H_
