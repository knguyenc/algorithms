#include "doubly_linked_list.h"

int main() {
  std::cout << "Test doubly linked list: " << std::endl;
  data_structures::linked_lists::DoublyLinkedList<int> dl;
  std::cout << "Empty: " << dl.IsEmpty() << std::endl;
  std::cout << dl;
  dl.Insert(8);
  dl.Insert(12);
  dl.Insert(6);
  dl.Insert(10);
  std::cout << "Size: " << dl.Size() << std::endl;
  std::cout << "Empty: " << dl.IsEmpty() << std::endl;
  std::cout << dl;
  std::cout << "Search 8: " << dl.Search(8) << std::endl;
  std::cout << "Search 9: " << dl.Search(9) << std::endl;
  std::cout << "Remove 8: " << dl.Remove(8) << std::endl;
  std::cout << dl;
  std::cout << "Remove 6: " << dl.Remove(6) << std::endl;
  std::cout << dl;

  return 0;
}
