#include "singly_linked_list.h"

int main() {
  std::cout << "TEST SINGLY LINKED LIST\n" << std::endl;
  data_structures::linked_lists::SinglyLinkedList<int> linked_list;
  std::cout << "Empty: " << linked_list.IsEmpty() << std::endl;
  std::cout << "Size: " << linked_list.Size() << std::endl;
  std::cout << "Insert 8" << std::endl;
  linked_list.Insert(8);
  std::cout << "Insert 12" << std::endl;
  linked_list.Insert(12);
  std::cout << "Insert 6" << std::endl;
  linked_list.Insert(6);
  std::cout << "Insert 10" << std::endl;
  linked_list.Insert(10);
  std::cout << "Size: " << linked_list.Size() << std::endl;
  std::cout << "Empty: " << linked_list.IsEmpty() << std::endl;
  std::cout << linked_list << std::endl;
  std::cout << "Search 8: " << linked_list.Search(8) << std::endl;
  std::cout << "Search 9: " << linked_list.Search(9) << std::endl;
  std::cout << "Remove 10: " << linked_list.Remove(10) << std::endl;
  std::cout << linked_list << std::endl;
  std::cout << "Remove 6: " << linked_list.Remove(6) << std::endl;
  std::cout << linked_list << std::endl;

  return 0;
}
