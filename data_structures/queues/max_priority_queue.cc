#include "max_priority_queue.h"

int main() {
  std::cout << "Test max priority queue: " << std::endl;
  int arr[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  data_structures::queues::MaxPriorityQueue<int> max_priority_queue(arr);
  std::cout << max_priority_queue;
  max_priority_queue.IncreaseKey(8, 15);
  std::cout << max_priority_queue;

  return 0;
}