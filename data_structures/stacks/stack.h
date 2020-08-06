#ifndef ALGORITHMS_DATA_STRUCTURES_STACK_STACK_H_
#define ALGORITHMS_DATA_STRUCTURES_STACK_STACK_H_

#include <iostream>

namespace data_structures {
namespace stacks {

template <class T>
class Stack {
  enum { CAPACITY = 100 };

 public:
  Stack();
  int Size() const;
  bool IsEmpty() const;
  const T &Top() const noexcept(false);
  void Push(const T &e) noexcept(false);
  T Pop() noexcept(false);

 private:
  T *data_;
  int cap_;
  int top_;
};

template <class T>
Stack<T>::Stack() : data_(new T[CAPACITY]), cap_(CAPACITY), top_(-1) {}

template <class T>
int Stack<T>::Size() const {
  return (top_ + 1);
}

template <class T>
bool Stack<T>::IsEmpty() const {
  return (top_ < 0);
}

template <class T>
const T &Stack<T>::Top() const {
  if (IsEmpty()) throw std::runtime_error("Stack underflow, can not get top.");
  return data_[top_];
}

template <class T>
void Stack<T>::Push(const T &e) {
  if (Size() == cap_) throw std::runtime_error("Stack overflow");
  data_[++top_] = e;
}

template <class T>
T Stack<T>::Pop() {
  if (IsEmpty()) throw std::runtime_error("Stack underflow, can not pop");
  T result = data_[top_];
  --top_;
  return result;
}

}  // namespace stacks
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_STACK_STACK_H_
