#ifndef ALGORITHMS_DATA_STRUCTURES_HEAPS_HEAP_H_
#define ALGORITHMS_DATA_STRUCTURES_HEAPS_HEAP_H_

#include <iostream>

namespace data_structures {
namespace heaps {

template <class T>
class Heap {
 public:
  Heap();
  explicit Heap(int capacity);
  ~Heap();
  virtual void BuildHeap() = 0;
  virtual void Heapify(int index) = 0;
  virtual void Insert(const T &value) = 0;
  virtual T Remove(int index) = 0;
  void Swap(int i, int j);
  bool IsEmpty() { return size_ == 0; }
  bool IsFull() { return size_ == capacity_; }

  friend std::ostream &operator<<(std::ostream &out, const Heap &heap) {
    int break_line = 0;
    for (int i = 0; i < heap.size_ / 2; i++) {
      if (i == 0) out << "(" << heap.data_[i] << " [" << i << "])" << std::endl;
      out << "(" << heap.data_[heap.Left(i)] << " [" << heap.Left(i) << "]) (" << heap.data_[heap.Right(i)] << " ["
          << heap.Right(i) << "])";
      if (i == break_line) {
        out << std::endl;
        break_line = 2 * break_line + 2;
      } else {
        out << "  ";
      }
    }
    out << std::endl;
    return out;
  }

 protected:
  enum { DEFAULT_CAPACITY = 10 };
  T *data_;
  int size_;
  int capacity_;

 protected:
  static int Parent(int index) { return (index - 1) / 2; }
  static int Left(int index) { return 2 * index + 1; }
  static int Right(int index) { return 2 * index + 2; }

 public:
  int GetSize() const { return size_; }
  void SetSize(int size) { size_ = size; }
  T *GetData() const { return data_; }
};

template <class T>
Heap<T>::Heap() : data_(new T[DEFAULT_CAPACITY]), size_(0), capacity_(DEFAULT_CAPACITY) {}

template <class T>
Heap<T>::Heap(int capacity) : data_(new T[capacity]), size_(0), capacity_(capacity) {}

template <class T>
Heap<T>::~Heap() {
  delete[] data_;
}

template <class T>
void Heap<T>::Swap(int i, int j) {
  std::swap(data_[i], data_[j]);
}

}  // namespace heaps
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_HEAPS_HEAP_H_
