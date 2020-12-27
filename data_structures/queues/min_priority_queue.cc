#include "min_priority_queue.h"

int main() {
  std::cout << "TEST MIN PRIORITY QUEUE\n" << std::endl;
  int integers[] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strings[] = {"c",  "java",  "cpp",        "python",
                           "go", "swift", "objective-c"};

  data_structures::queues::MinPriorityQueue<int> int_min_priority_queue(
      integers);
  data_structures::queues::MinPriorityQueue<std::string> str_min_priority_queue(
      strings);

  std::cout << int_min_priority_queue << std::endl;
  std::cout << "Size: " << int_min_priority_queue.GetSize() << std::endl;
  std::cout << "Decrease key at index 8 to 15" << std::endl;
  int_min_priority_queue.DecreaseKey(8, 15);
  std::cout << "Minimum: " << int_min_priority_queue.Minimum() << std::endl;
  std::cout << "Extract Min: " << int_min_priority_queue.ExtractMin()
            << std::endl;
  std::cout << "Size: " << int_min_priority_queue.GetSize() << std::endl;
  std::cout << int_min_priority_queue << std::endl;

  std::cout << str_min_priority_queue << std::endl;
  std::cout << "Size: " << str_min_priority_queue.GetSize() << std::endl;
  std::cout << "Decrease key at index 3 to 'javascript'" << std::endl;
  str_min_priority_queue.DecreaseKey(3, "javascript");
  std::cout << "Minimum: " << str_min_priority_queue.Minimum() << std::endl;
  std::cout << "Extract Min: " << str_min_priority_queue.ExtractMin()
            << std::endl;
  std::cout << "Size: " << str_min_priority_queue.GetSize() << std::endl;
  std::cout << str_min_priority_queue << std::endl;

  return 0;
}