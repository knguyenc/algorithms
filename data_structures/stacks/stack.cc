#include "stack.h"

int main() {
  std::cout << "Test array stack: " << std::endl;
  data_structures::stacks::Stack<int> stack;
  std::cout << "Empty: " << stack.IsEmpty() << std::endl;
  stack.Push(8);
  stack.Push(6);
  std::cout << "Size: " << stack.Size() << std::endl;
  std::cout << "Empty: " << stack.IsEmpty() << std::endl;
  std::cout << "Top: " << stack.Top() << std::endl;
  std::cout << "Pop: " << stack.Pop() << std::endl;
  std::cout << "Top: " << stack.Top() << std::endl;
  std::cout << "Pop: " << stack.Pop() << std::endl;

  return 0;
}
