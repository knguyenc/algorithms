#include "circularly_linked_list.h"

int main() {
  std::cout << "Test circularly linked list: " << std::endl;
  data_structures::linked_lists::CircularlyLinkedList<int> cl;
  std::cout << "Empty: " << cl.IsEmpty() << std::endl;
  cl.InsertFirst(8);
  cl.InsertFirst(6);
  std::cout << "First: " << cl.First() << std::endl;
  std::cout << "Last: " << cl.Last() << std::endl;
  cl.Rotate();
  std::cout << "First: " << cl.First() << std::endl;
  std::cout << "Last: " << cl.Last() << std::endl;
  cl.InsertLast(12);
  cl.InsertLast(10);
  std::cout << "Size: " << cl.Size() << std::endl;
  std::cout << "Empty: " << cl.IsEmpty() << std::endl;
  std::cout << "Remove: " << cl.RemoveFirst() << std::endl;
  std::cout << "Remove: " << cl.RemoveFirst() << std::endl;

  return 0;
}
