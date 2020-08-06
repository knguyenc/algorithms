#ifndef ALGORITHMS_DATA_STRUCTURES_QUEUE_DEQUE_H_
#define ALGORITHMS_DATA_STRUCTURES_QUEUE_DEQUE_H_

#include <iostream>
#include "data_structures/linked_lists/doubly_linked_list.h"

namespace data_structures {
namespace queues {

template <class T>
class Deque {
 public:
  Deque();
  int Size() const;
  bool IsEmpty() const;
  const T &Front() const noexcept(false);
  const T &Back() const noexcept(false);
  void InsertFront(const T &e);
  void InsertBack(const T &e);
  T RemoveFront() noexcept(false);
  T RemoveBack() noexcept(false);

 private:
  data_structures::linked_lists::DoublyLinkedList<T> list_;
  int size_;
};

template <class T>
Deque<T>::Deque() : list_(), size_(0) {}

template <class T>
int Deque<T>::Size() const {
  return size_;
}

template <class T>
bool Deque<T>::IsEmpty() const {
  return (size_ == 0);
}

template <class T>
const T &Deque<T>::Front() const {
  if (IsEmpty()) throw std::runtime_error("Deque underflow, can not get front.");
  return list_.First();
}

template <class T>
const T &Deque<T>::Back() const {
  if (IsEmpty()) throw std::runtime_error("Deque underflow, can not get back.");
  return list_.Last();
}

template <class T>
void Deque<T>::InsertFront(const T &e) {
  list_.InsertFirst(e);
  size_++;
}

template <class T>
void Deque<T>::InsertBack(const T &e) {
  list_.InsertLast(e);
  size_++;
}

template <class T>
T Deque<T>::RemoveFront() {
  if (IsEmpty()) throw std::runtime_error("Deque underflow, can not remove front.");
  T result = list_.RemoveFirst();
  size_--;
  return result;
}

template <class T>
T Deque<T>::RemoveBack() {
  if (IsEmpty()) throw std::runtime_error("Deque underflow, can not remove back.");
  T result = list_.RemoveLast();
  size_--;
  return result;
}

}  // namespace queues
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_QUEUE_DEQUE_H_
