#include "singly_linked_list.h"

int main() {
  std::cout << "Test singly linked list: " << std::endl;
  data_structures::linked_lists::SinglyLinkedList<int> sl;
  std::cout << "Empty: " << sl.IsEmpty() << std::endl;
  std::cout << sl;
  sl.Insert(8);
  sl.Insert(12);
  sl.Insert(6);
  sl.Insert(10);
  std::cout << "Size: " << sl.Size() << std::endl;
  std::cout << "Empty: " << sl.IsEmpty() << std::endl;
  std::cout << sl;
  std::cout << "Search 8: " << sl.Search(8) << std::endl;
  std::cout << "Search 9: " << sl.Search(9) << std::endl;
  std::cout << "Remove 8: " << sl.Remove(8) << std::endl;
  std::cout << sl;
  std::cout << "Remove 6: " << sl.Remove(6) << std::endl;
  std::cout << sl;

  return 0;
}
