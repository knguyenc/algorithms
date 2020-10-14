#include "stack.h"

int main() {
  std::cout << "TEST STACK\n" << std::endl;
  data_structures::stacks::Stack<int> stack(20);
  std::cout << "Empty: " << stack.IsEmpty() << std::endl;
  std::cout << "Size: " << stack.Size() << std::endl;
  std::cout << "Push 8" << std::endl;
  stack.Push(8);
  std::cout << "Push 6" << std::endl;
  stack.Push(6);
  std::cout << "Push 26" << std::endl;
  stack.Push(26);
  std::cout << "Push 9" << std::endl;
  stack.Push(9);
  std::cout << "Push 7" << std::endl;
  stack.Push(7);
  std::cout << "Push 22" << std::endl;
  stack.Push(22);
  std::cout << stack << std::endl;
  std::cout << "Empty: " << stack.IsEmpty() << std::endl;
  std::cout << "Size: " << stack.Size() << std::endl;
  std::cout << "Top: " << stack.Top() << std::endl;
  std::cout << "Pop: " << stack.Pop() << std::endl;
  std::cout << "Top: " << stack.Top() << std::endl;
  std::cout << "Pop: " << stack.Pop() << std::endl;
  std::cout << "Size: " << stack.Size() << std::endl;
  std::cout << "Pop: " << stack.Pop() << std::endl;
  std::cout << "Size: " << stack.Size() << std::endl;
  std::cout << stack << std::endl;

  return 0;
}
