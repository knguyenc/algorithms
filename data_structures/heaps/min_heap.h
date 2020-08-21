#include "heap.h"

#ifndef ALGORITHMS_DATA_STRUCTURES_HEAPS_MIN_HEAP_H_
#define ALGORITHMS_DATA_STRUCTURES_HEAPS_MIN_HEAP_H_

namespace data_structures {
namespace heaps {

template <class T>
class MinHeap : public Heap<T> {
 public:
  using Heap<T>::Heap;
  template <size_t N>
  explicit MinHeap(const T (&array)[N]);
  template <size_t N>
  explicit MinHeap(const T (&array)[N], int capacity);
  void BuildHeap();
  void Heapify(int index);
  virtual void Insert(T element);
  T Remove(int index);
};

template <class T>
template <size_t N>
MinHeap<T>::MinHeap(const T (&array)[N]) {
  this->data_ = new T[N];
  for (unsigned int i = 0; i < N; i++)
    this->data_[i] = array[i];
  this->size_ = N;
  this->capacity_ = N;
  BuildHeap();
}

template <class T>
template <size_t N>
MinHeap<T>::MinHeap(const T (&array)[N], int capacity) {
  this->data_ = new T[capacity];
  for (unsigned int i = 0; i < N; i++)
    this->data_[i] = array[i];
  this->size_ = N;
  this->capacity_ = capacity;
  BuildHeap();
}

template <class T>
void MinHeap<T>::BuildHeap() {
  for (int i = this->size_ / 2; i >= 0; i--)
    Heapify(i);
}

template <class T>
void MinHeap<T>::Heapify(int index) {
  int left = this->Left(index), right = this->Right(index), smallest;
  smallest = (left < this->size_ && this->data_[left] < this->data_[index]) ? left : index;
  if (right < this->size_ && this->data_[right] < this->data_[smallest]) smallest = right;
  if (smallest != index) {
    this->Swap(index, smallest);
    Heapify(smallest);
  }
}

template <class T>
void MinHeap<T>::Insert(T element) {
  if (this->IsFull()) throw std::runtime_error("Heap overflow");
  this->data_[this->size_++] = element;
  int cur = this->size_ - 1;
  while (cur > 0 && (this->data_[cur] < this->data_[this->Parent(cur)])) {
    this->Swap(cur, this->Parent(cur));
    cur = this->Parent(cur);
  }
}

template <class T>
T MinHeap<T>::Remove(int index) {
  if (this->IsEmpty()) throw std::runtime_error("Heap underflow");
  T removed = this->data_[index];
  this->data_[index] = this->data_[--this->size_];
  Heapify(index);
  return removed;
}

}  // namespace heaps
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_HEAPS_MIN_HEAP_H_
