#include "max_heap.h"

int main() {
  std::cout << "TEST MAX HEAP\n" << std::endl;
  int integers[] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strings[] = {"c", "java", "cpp", "python", "go", "swift", "objective-c"};

  data_structures::heaps::MaxHeap<int> int_max_heap(integers, 20);
  data_structures::heaps::MaxHeap<std::string> str_max_heap(strings, 20);

  std::cout << int_max_heap << std::endl;
  std::cout << "Empty: " << int_max_heap.IsEmpty() << std::endl;
  std::cout << "Size: " << int_max_heap.GetSize() << std::endl;
  std::cout << "Insert 18" << std::endl;
  int_max_heap.Insert(18);
  std::cout << "Insert 6" << std::endl;
  int_max_heap.Insert(6);
  std::cout << "Size: " << int_max_heap.GetSize() << std::endl;
  std::cout << "Remove 5th element: " << int_max_heap.Remove(5) << std::endl;
  std::cout << "Size: " << int_max_heap.GetSize() << std::endl;
  std::cout << int_max_heap << std::endl;

  std::cout << str_max_heap << std::endl;
  std::cout << "Empty: " << str_max_heap.IsEmpty() << std::endl;
  std::cout << "Size: " << str_max_heap.GetSize() << std::endl;
  std::cout << "Insert 'javascript'" << std::endl;
  str_max_heap.Insert("javascript");
  std::cout << "Insert 'rust'" << std::endl;
  str_max_heap.Insert("rust");
  std::cout << "Size: " << str_max_heap.GetSize() << std::endl;
  std::cout << "Remove 5th element: " << str_max_heap.Remove(5) << std::endl;
  std::cout << "Size: " << str_max_heap.GetSize() << std::endl;
  std::cout << str_max_heap << std::endl;

  return 0;
}