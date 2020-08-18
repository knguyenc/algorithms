#include "doubly_linked_list.h"

int main() {
  std::cout << "Test doubly linked list: " << std::endl;
  data_structures::linked_lists::DoublyLinkedList<int> dl;
  std::cout << "Empty: " << dl.IsEmpty() << std::endl;
  dl.InsertFirst(8);
  dl.InsertLast(12);
  dl.InsertFirst(6);
  dl.InsertLast(10);
  std::cout << "Size: " << dl.Size() << std::endl;
  std::cout << "Empty: " << dl.IsEmpty() << std::endl;
  std::cout << "Remove first: " << dl.RemoveFirst() << std::endl;
  std::cout << "Remove last: " << dl.RemoveLast() << std::endl;

  return 0;
}
