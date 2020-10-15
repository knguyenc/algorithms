#include "binary_tree.h"

int main() {
  std::cout << "TEST BINARY TREE\n" << std::endl;
  data_structures::trees::BinaryTree<int> binary_tree;
  std::cout << "Empty: " << binary_tree.IsEmpty() << std::endl;
  std::cout << "Size: " << binary_tree.Size() << std::endl;
  std::cout << "Insert 1" << std::endl;
  binary_tree.Insert(1);
  std::cout << "Insert 2" << std::endl;
  binary_tree.Insert(2);
  std::cout << "Insert 3" << std::endl;
  binary_tree.Insert(3);
  std::cout << "Insert 4" << std::endl;
  binary_tree.Insert(4);
  std::cout << "Insert 5" << std::endl;
  binary_tree.Insert(5);
  std::cout << "Insert 6" << std::endl;
  binary_tree.Insert(6);
  std::cout << "Insert 7" << std::endl;
  binary_tree.Insert(7);
  std::cout << binary_tree << std::endl;
  std::cout << "Empty: " << binary_tree.IsEmpty() << std::endl;
  std::cout << "Size: " << binary_tree.Size() << std::endl;
  std::cout << "Search 6: " << binary_tree.Search(6)->data_ << std::endl;
  std::cout << "Search 2: " << binary_tree.Search(2)->data_ << std::endl;
  std::cout << "Remove 4: " << binary_tree.Remove(4) << std::endl;
  std::cout << "Size: " << binary_tree.Size() << std::endl;
  std::cout << "Remove 1: " << binary_tree.Remove(1) << std::endl;
  std::cout << "Size: " << binary_tree.Size() << std::endl;
  std::cout << binary_tree << std::endl;

  return 0;
}