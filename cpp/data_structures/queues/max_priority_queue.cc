#include "max_priority_queue.h"

int main() {
  std::cout << "TEST MAX PRIORITY QUEUE\n" << std::endl;
  int integers[] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strings[] = {"c",  "java",  "cpp",        "python",
                           "go", "swift", "objective-c"};

  data_structures::queues::MaxPriorityQueue<int> int_max_priority_queue(
      integers);
  data_structures::queues::MaxPriorityQueue<std::string> str_max_priority_queue(
      strings);

  std::cout << int_max_priority_queue << std::endl;
  std::cout << "Size: " << int_max_priority_queue.GetSize() << std::endl;
  std::cout << "Increase key at index 8 to 15" << std::endl;
  int_max_priority_queue.IncreaseKey(8, 15);
  std::cout << "Maximum: " << int_max_priority_queue.Maximum() << std::endl;
  std::cout << "Extract Max: " << int_max_priority_queue.ExtractMax()
            << std::endl;
  std::cout << "Size: " << int_max_priority_queue.GetSize() << std::endl;
  std::cout << int_max_priority_queue << std::endl;

  std::cout << str_max_priority_queue << std::endl;
  std::cout << "Size: " << str_max_priority_queue.GetSize() << std::endl;
  std::cout << "Increase key at index 4 to 'javascript'" << std::endl;
  str_max_priority_queue.IncreaseKey(4, "javascript");
  std::cout << "Maximum: " << str_max_priority_queue.Maximum() << std::endl;
  std::cout << "Extract Max: " << str_max_priority_queue.ExtractMax()
            << std::endl;
  std::cout << "Size: " << str_max_priority_queue.GetSize() << std::endl;
  std::cout << str_max_priority_queue << std::endl;

  return 0;
}