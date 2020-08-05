#include "singly_linked_list.h"

int main() {
  std::cout << "Test singly linked list: " << std::endl;
  data_structures::linked_lists::SinglyLinkedList<int> sl;
  std::cout << "Empty: " << sl.IsEmpty() << std::endl;
  sl.InsertFirst(8);
  sl.InsertFirst(6);
  std::cout << "Size: " << sl.Size() << std::endl;
  std::cout << "Empty: " << sl.IsEmpty() << std::endl;
  std::cout << "First: " << sl.First() << std::endl;
  std::cout << "Remove first: " << sl.RemoveFirst() << std::endl;
  std::cout << "Remove first: " << sl.RemoveFirst() << std::endl;

  return 0;
}
