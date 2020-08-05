#include "min_priority_queue.h"

int main() {
  std::cout << "Test min priority queue: " << std::endl;
  int arr[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  data_structures::queues::MinPriorityQueue<int> min_priority_queue(arr);
  std::cout << min_priority_queue;
  min_priority_queue.DecreaseKey(8, 6);
  std::cout << min_priority_queue;

  return 0;
}