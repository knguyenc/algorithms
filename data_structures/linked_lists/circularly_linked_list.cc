#include "circularly_linked_list.h"

int main() {
  std::cout << "Test circularly linked list: " << std::endl;
  data_structures::linked_lists::CircularlyLinkedList<int> cl;
  std::cout << "Empty: " << cl.IsEmpty() << std::endl;
  std::cout << cl;
  cl.Insert(8);
  cl.Insert(12);
  cl.Insert(6);
  cl.Insert(10);
  std::cout << "Size: " << cl.Size() << std::endl;
  std::cout << "Empty: " << cl.IsEmpty() << std::endl;
  std::cout << cl;
  std::cout << "Search 8: " << cl.Search(8) << std::endl;
  std::cout << "Search 9: " << cl.Search(9) << std::endl;
  std::cout << "Remove 8: " << cl.Remove(8) << std::endl;
  std::cout << cl;
  std::cout << "Remove 6: " << cl.Remove(6) << std::endl;
  std::cout << cl;

  return 0;
}
