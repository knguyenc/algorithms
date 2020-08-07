#ifndef ALGORITHMS_DATA_STRUCTURES_QUEUE_QUEUE_H_
#define ALGORITHMS_DATA_STRUCTURES_QUEUE_QUEUE_H_

#include <iostream>

namespace data_structures {
namespace queues {

template <class T>
class Queue {
  enum { DEFAULT_CAPACITY = 100 };

 public:
  Queue();
  explicit Queue(int capacity);
  ~Queue();
  int Size() const;
  bool IsEmpty() const;
  bool IsFull() const;
  T &Head() const;
  void Enqueue(const T &e);
  T Dequeue();

 private:
  T *data_;
  int capacity_;
  int head_;
  int tail_;
};

template <class T>
Queue<T>::Queue() : data_(new T[DEFAULT_CAPACITY]), capacity_(DEFAULT_CAPACITY), head_(0), tail_(0) {}

template <class T>
Queue<T>::Queue(int capacity) : data_(new T[capacity]), capacity_(capacity), head_(0), tail_(0) {}

template <class T>
Queue<T>::~Queue() {
  delete[] data_;
}

template <class T>
int Queue<T>::Size() const {
  return (head_ > tail_) ? capacity_ - head_ + tail_ : tail_ - head_;
}

template <class T>
bool Queue<T>::IsEmpty() const {
  return head_ == tail_;
}

template <class T>
bool Queue<T>::IsFull() const {
  return head_ == tail_ + 1;
}

template <class T>
T &Queue<T>::Head() const {
  if (IsEmpty()) throw std::runtime_error("Queue underflow, can not get head.");
  return data_[head_];
}

template <class T>
void Queue<T>::Enqueue(const T &e) {
  if (IsFull()) throw std::runtime_error("Queue overflow, can not enqueue.");
  data_[tail_] = e;
  tail_ = (capacity_ == tail_ + 1) ? 0 : tail_ + 1;
}

template <class T>
T Queue<T>::Dequeue() {
  if (IsEmpty()) throw std::runtime_error("Queue underflow, can not dequeue.");
  T removed = data_[head_];
  head_ = (capacity_ == head_ + 1) ? 0 : head_ + 1;
  return removed;
}

}  // namespace queues
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_QUEUE_QUEUE_H_
