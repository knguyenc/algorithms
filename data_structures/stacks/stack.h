#ifndef ALGORITHMS_DATA_STRUCTURES_STACK_STACK_H_
#define ALGORITHMS_DATA_STRUCTURES_STACK_STACK_H_

#include <iostream>

namespace data_structures {
namespace stacks {

template <class T>
class Stack {
  enum { DEFAULT_CAPACITY = 100 };

 public:
  Stack();
  explicit Stack(int capacity);
  ~Stack();
  int Size() const;
  bool IsEmpty() const;
  bool IsFull() const;
  T &Top() const;
  void Push(const T &e);
  T Pop();

 private:
  T *data_;
  int capacity_;
  int top_;
};

template <class T>
Stack<T>::Stack() : data_(new T[DEFAULT_CAPACITY]), capacity_(DEFAULT_CAPACITY), top_(-1) {}

template <class T>
Stack<T>::Stack(int capacity) : data_(new T[capacity]), capacity_(capacity), top_(-1) {}

template <class T>
Stack<T>::~Stack() {
  delete[] data_;
}

template <class T>
int Stack<T>::Size() const {
  return top_ + 1;
}

template <class T>
bool Stack<T>::IsEmpty() const {
  return top_ < 0;
}

template <class T>
bool Stack<T>::IsFull() const {
  return Size() == capacity_;
}

template <class T>
T &Stack<T>::Top() const {
  if (IsEmpty()) throw std::runtime_error("Stack underflow, can not get top.");
  return data_[top_];
}

template <class T>
void Stack<T>::Push(const T &e) {
  if (IsFull()) throw std::runtime_error("Stack overflow, can not push.");
  data_[++top_] = e;
}

template <class T>
T Stack<T>::Pop() {
  if (IsEmpty()) throw std::runtime_error("Stack underflow, can not pop");
  return data_[top_--];
}

}  // namespace stacks
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_STACK_STACK_H_
