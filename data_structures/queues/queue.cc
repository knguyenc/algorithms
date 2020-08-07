#include "queue.h"

int main() {
  std::cout << "Test array queue: " << std::endl;
  data_structures::queues::Queue<int> queue;
  std::cout << "Empty: " << queue.IsEmpty() << std::endl;
  queue.Enqueue(8);
  queue.Enqueue(6);
  std::cout << "Size: " << queue.Size() << std::endl;
  std::cout << "Empty: " << queue.IsEmpty() << std::endl;
  std::cout << "Head: " << queue.Head() << std::endl;
  std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
  std::cout << "Head: " << queue.Head() << std::endl;
  std::cout << "Dequeue: " << queue.Dequeue() << std::endl;

  return 0;
}
