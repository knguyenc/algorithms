#include "max_heap.h"

int main() {
  std::cout << "Test max heap: " << std::endl;
  int arr[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  data_structures::heaps::MaxHeap<int> max_heap(arr, 12);
  std::cout << "Empty: " << max_heap.IsEmpty() << std::endl;
  std::cout << max_heap;
  std::cout << "Size: " << max_heap.GetSize() << std::endl;
  max_heap.Insert(18);
  max_heap.Insert(6);
  std::cout << "Size: " << max_heap.GetSize() << std::endl;
  std::cout << max_heap;
  std::cout << "Remove 5th element: " << max_heap.Remove(5) << std::endl;
  std::cout << "Size: " << max_heap.GetSize() << std::endl;
  std::cout << max_heap;

  return 0;
}