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
  T Head() const;
  void Enqueue(const T &value);
  T Dequeue();

  friend std::ostream &operator<<(std::ostream &out, const Queue &queue) {
    if (queue.IsEmpty())
      out << "Empty queue";
    else {
      int index = queue.head_;
      out << "Queue: ";
      while (true) {
        out << queue.data_[index] << " ";
        index = (index + 1) == queue.capacity_ ? 0 : index + 1;
        bool cond = queue.head_ < queue.tail_;
        if (cond)
          cond = index >= queue.head_ && index < queue.tail_;
        else
          cond = (index >= queue.head_ && index < queue.capacity_) ||
                 (index >= 0 && index < queue.tail_);
        if (!cond) break;
      }
    }
    return out;
  }

 private:
  T *data_;
  int capacity_;
  int head_;
  int tail_;
};

template <class T>
Queue<T>::Queue()
    : data_(new T[DEFAULT_CAPACITY]),
      capacity_(DEFAULT_CAPACITY),
      head_(0),
      tail_(0) {}

template <class T>
Queue<T>::Queue(int capacity)
    : data_(new T[capacity]), capacity_(capacity), head_(0), tail_(0) {}

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
  int temp = (tail_ + 1 == capacity_) ? 0 : tail_ + 1;
  return head_ == temp;
}

template <class T>
T Queue<T>::Head() const {
  if (IsEmpty()) throw std::runtime_error("Queue underflow, can not get head.");
  return data_[head_];
}

template <class T>
void Queue<T>::Enqueue(const T &value) {
  if (IsFull()) throw std::runtime_error("Queue overflow, can not enqueue.");
  data_[tail_] = value;
  tail_ = (capacity_ == (tail_ + 1)) ? 0 : tail_ + 1;
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
