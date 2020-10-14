#include "queue.h"

int main() {
  std::cout << "TEST QUEUE\n" << std::endl;
  data_structures::queues::Queue<int> queue(20);
  std::cout << "Empty: " << queue.IsEmpty() << std::endl;
  std::cout << "Size: " << queue.Size() << std::endl;
  std::cout << "Enqueue 8" << std::endl;
  queue.Enqueue(8);
  std::cout << "Enqueue 6" << std::endl;
  queue.Enqueue(6);
  std::cout << "Enqueue 26" << std::endl;
  queue.Enqueue(26);
  std::cout << "Enqueue 9" << std::endl;
  queue.Enqueue(9);
  std::cout << "Enqueue 7" << std::endl;
  queue.Enqueue(7);
  std::cout << "Enqueue 22" << std::endl;
  queue.Enqueue(22);
  std::cout << queue << std::endl;
  std::cout << "Empty: " << queue.IsEmpty() << std::endl;
  std::cout << "Size: " << queue.Size() << std::endl;
  std::cout << "Head: " << queue.Head() << std::endl;
  std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
  std::cout << "Head: " << queue.Head() << std::endl;
  std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
  std::cout << "Size: " << queue.Size() << std::endl;
  std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
  std::cout << "Size: " << queue.Size() << std::endl;
  std::cout << queue << std::endl;

  return 0;
}
