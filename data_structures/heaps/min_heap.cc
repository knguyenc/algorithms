#include "min_heap.h"

int main() {
  std::cout << "TEST MIN HEAP\n" << std::endl;
  int integers[] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strings[] = {"c", "java", "cpp", "python", "go", "swift", "objective-c"};

  data_structures::heaps::MinHeap<int> int_min_heap(integers, 20);
  data_structures::heaps::MinHeap<std::string> str_min_heap(strings, 20);

  std::cout << int_min_heap << std::endl;
  std::cout << "Empty: " << int_min_heap.IsEmpty() << std::endl;
  std::cout << "Size: " << int_min_heap.GetSize() << std::endl;
  std::cout << "Insert 18" << std::endl;
  int_min_heap.Insert(18);
  std::cout << "Insert 6" << std::endl;
  int_min_heap.Insert(6);
  std::cout << "Size: " << int_min_heap.GetSize() << std::endl;
  std::cout << "Remove 5th element: " << int_min_heap.Remove(5) << std::endl;
  std::cout << "Size: " << int_min_heap.GetSize() << std::endl;
  std::cout << int_min_heap << std::endl;

  std::cout << str_min_heap << std::endl;
  std::cout << "Empty: " << str_min_heap.IsEmpty() << std::endl;
  std::cout << "Size: " << str_min_heap.GetSize() << std::endl;
  std::cout << "Insert 'javascript'" << std::endl;
  str_min_heap.Insert("javascript");
  std::cout << "Insert 'rust'" << std::endl;
  str_min_heap.Insert("rust");
  std::cout << "Size: " << str_min_heap.GetSize() << std::endl;
  std::cout << "Remove 5th element: " << str_min_heap.Remove(5) << std::endl;
  std::cout << "Size: " << str_min_heap.GetSize() << std::endl;
  std::cout << str_min_heap << std::endl;

  return 0;
}