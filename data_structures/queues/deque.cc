#include "deque.h"

int main() {
  std::cout << "Test linked deque: " << std::endl;
  data_structures::queues::Deque<int> deque;
  std::cout << "Empty: " << deque.IsEmpty() << std::endl;
  deque.InsertFront(8);
  deque.InsertFront(6);
  deque.InsertBack(10);
  deque.InsertBack(12);
  std::cout << "Size: " << deque.Size() << std::endl;
  std::cout << "Empty: " << deque.IsEmpty() << std::endl;
  std::cout << "Front: " << deque.Front() << std::endl;
  std::cout << "Back: " << deque.Back() << std::endl;
  std::cout << "Remove front: " << deque.RemoveFront() << std::endl;
  std::cout << "Remove back: " << deque.RemoveBack() << std::endl;
  std::cout << "Size: " << deque.Size() << std::endl;

  return EXIT_SUCCESS;
}
