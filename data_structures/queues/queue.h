#ifndef ALGORITHMS_DATA_STRUCTURES_QUEUE_QUEUE_H_
#define ALGORITHMS_DATA_STRUCTURES_QUEUE_QUEUE_H_

#include <iostream>

namespace data_structures {
namespace queues {

template <class T>
class Queue {
  enum { CAPACITY = 100 };

 public:
  Queue();
  int Size() const;
  bool IsEmpty() const;
  const T &Front() const noexcept(false);
  void Enqueue(const T &e) noexcept(false);
  T Dequeue() noexcept(false);

 private:
  T *data_;
  int cap_;
  int front_;
  int size_;
};

template <class T>
Queue<T>::Queue()
    : data_(new T[CAPACITY]), cap_(CAPACITY), front_(0), size_(0) {}

template <class T>
int Queue<T>::Size() const {
  return size_;
}

template <class T>
bool Queue<T>::IsEmpty() const {
  return (size_ == 0);
}

template <class T>
const T &Queue<T>::Front() const {
  if (IsEmpty()) throw std::runtime_error("Queue underflow, can not get front.");
  return data_[front_];
}

template <class T>
void Queue<T>::Enqueue(const T &e) {
  if (Size() == cap_) throw std::runtime_error("Queue overflow.");
  int ps = (front_ + size_) % cap_;
  data_[ps] = e;
  size_++;
}

template <class T>
T Queue<T>::Dequeue() {
  if (IsEmpty()) throw std::runtime_error("Queue underflow, can not dequeue.");
  T result = data_[front_];
  front_ = (front_ + 1) % sizeof(data_);
  size_--;
  return result;
}

}  // namespace queues
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_QUEUE_QUEUE_H_
