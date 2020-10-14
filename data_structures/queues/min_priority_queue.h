#include "data_structures/heaps/min_heap.h"

#ifndef ALGORITHMS_DATA_STRUCTURES_QUEUES_MIN_PRIORITY_QUEUE_H_
#define ALGORITHMS_DATA_STRUCTURES_QUEUES_MIN_PRIORITY_QUEUE_H_

namespace data_structures {
namespace queues {

template <class T>
class MinPriorityQueue : public heaps::MinHeap<T> {
 public:
  using heaps::MinHeap<T>::MinHeap;
  template <size_t N>
  explicit MinPriorityQueue(const T (&array)[N]);
  template <size_t N>
  explicit MinPriorityQueue(const T (&array)[N], int capacity);
  T Minimum() const;
  T ExtractMin();
  void DecreaseKey(int index, const T &key);
  void Insert(const T &value);

  friend std::ostream &operator<<(std::ostream &out, const MinPriorityQueue &queue) {
    out << "Queue: ";
    for (int i = 0; i < queue.size_; i++) out << "(" << queue.data_[i] << " [" << i << "]) ";
    return out;
  }
};

template <class T>
template <size_t N>
MinPriorityQueue<T>::MinPriorityQueue(const T (&array)[N]) : heaps::MinHeap<T>(array) {
  this->data_ = new T[N];
  this->capacity_ = N;
  this->size_ = 0;
  for (unsigned int i = 0; i < N; i++) Insert(array[i]);
}

template <class T>
template <size_t N>
MinPriorityQueue<T>::MinPriorityQueue(const T (&array)[N], int capacity) : heaps::MinHeap<T>(array, capacity) {
  this->data_ = new T[capacity];
  this->capacity_ = capacity;
  this->size_ = 0;
  for (int i = 0; i < N; i++) Insert(array[i]);
}

template <class T>
T MinPriorityQueue<T>::Minimum() const {
  return this->data_[0];
}

template <class T>
T MinPriorityQueue<T>::ExtractMin() {
  if (this->IsEmpty()) throw std::runtime_error("Priority queue underflow");
  return this->Remove(0);
}

template <class T>
void MinPriorityQueue<T>::DecreaseKey(int index, const T &key) {
  if (key > this->data_[index]) throw std::runtime_error("New key is larger than current key");
  this->data_[index] = key;
  while (index > 0 && this->data_[this->Parent(index)] > this->data_[index]) {
    this->Swap(index, this->Parent(index));
    index = this->Parent(index);
  }
}

template <class T>
void MinPriorityQueue<T>::Insert(const T &value) {
  if (this->IsFull()) throw std::runtime_error("Priority queue overflow");
  this->data_[this->size_++] = value;
  DecreaseKey(this->size_ - 1, value);
}

}  // namespace queues
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_QUEUES_MIN_PRIORITY_QUEUE_H_
