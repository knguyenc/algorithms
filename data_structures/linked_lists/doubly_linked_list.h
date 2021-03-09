#ifndef ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_H_
#define ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_H_

#include <iostream>

namespace data_structures {
namespace linked_lists {

template <class T>
class DoublyLinkedList {
 public:
  class Node {
   public:
    T data_;
    Node *prev_;
    Node *next_;
    friend class DoublyLinkedList;
    explicit Node(const T &data) : data_(data), prev_(NULL), next_(NULL) {}
  };

 public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  int Size() const;
  bool IsEmpty() const;
  bool Search(const T &data) const;
  void Insert(const T &data);
  T Remove(const T &data);

  friend std::ostream &operator<<(std::ostream &out,
                                  const DoublyLinkedList &list) {
    if (list.IsEmpty()) {
      out << "Empty list";
    } else {
      typename DoublyLinkedList::Node *temp = list.head_;
      out << "List: ";
      while (temp != NULL) {
        out << "[" << temp->data_ << "]->";
        temp = temp->next_;
      }
    }
    return out;
  }

 private:
  Node *head_;
  int size_;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : head_(NULL), size_(0) {}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  while (!IsEmpty()) Remove(head_->data_);
  delete head_;
}

template <class T>
int DoublyLinkedList<T>::Size() const {
  return size_;
}

template <class T>
bool DoublyLinkedList<T>::IsEmpty() const {
  return (head_ == NULL);
}

template <class T>
bool DoublyLinkedList<T>::Search(const T &data) const {
  Node *temp = head_;
  while (temp != NULL) {
    if (temp->data_ == data) return true;
    temp = temp->next_;
  }
  return false;
}

template <class T>
void DoublyLinkedList<T>::Insert(const T &data) {
  Node *node = new Node(data);
  if (IsEmpty())
    head_ = node;
  else {
    Node *temp = head_;
    while (temp->next_ != NULL) temp = temp->next_;
    node->prev_ = temp;
    temp->next_ = node;
  }
  size_++;
}

template <class T>
T DoublyLinkedList<T>::Remove(const T &data) {
  if (IsEmpty()) throw std::runtime_error("List is empty, can not remove");
  Node *old = head_;
  while (old != NULL && old->data_ != data) old = old->next_;
  if (old == NULL) throw std::runtime_error("Node is not exist in this list");
  T removed = old->data_;
  if (old == head_) {
    head_ = head_->next_;
    if (head_ != NULL) head_->prev_ = NULL;
  } else {
    old->prev_->next_ = old->next_;
    if (old->next_ != NULL) old->next_->prev_ = old->prev_;
  }
  old->prev_ = NULL;
  old->next_ = NULL;
  delete old;
  size_--;
  return removed;
}

}  // namespace linked_lists
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_H_
