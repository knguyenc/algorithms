#include "min_heap.h"

int main() {
  std::cout << "Test min heap: " << std::endl;
  int arr[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  data_structures::heaps::MinHeap<int> min_heap(arr, 12);
  std::cout << "Empty: " << min_heap.IsEmpty() << std::endl;
  std::cout << min_heap;
  std::cout << "Size: " << min_heap.GetSize() << std::endl;
  min_heap.Insert(18);
  min_heap.Insert(6);
  std::cout << "Size: " << min_heap.GetSize() << std::endl;
  std::cout << min_heap;
  std::cout << "Remove 5th element: " << min_heap.Remove(5) << std::endl;
  std::cout << "Size: " << min_heap.GetSize() << std::endl;
  std::cout << min_heap;

  return 0;
}