#include "hash_table_open_addressing.h"

int main() {
  std::cout << "TEST HASH TABLE OPEN ADDRESSING\n" << std::endl;
  data_structures::hashing::HashTableOpenAddressing<int, std::string> hash_table;
  std::cout << "Empty: " << hash_table.IsEmpty() << std::endl;
  std::cout << "Size: " << hash_table.Size() << std::endl;
  std::cout << "Insert 18: Cat" << std::endl;
  hash_table.Insert(18, "Cat");
  std::cout << "Insert 60: Dog" << std::endl;
  hash_table.Insert(60, "Dog");
  std::cout << "Insert 20: Dolphin" << std::endl;
  hash_table.Insert(20, "Dolphin");
  std::cout << "Insert 96: Mouse" << std::endl;
  hash_table.Insert(96, "Mouse");
  std::cout << "Insert 71: Rabbit" << std::endl;
  hash_table.Insert(71, "Rabbit");
  std::cout << "Insert 22: Snake" << std::endl;
  hash_table.Insert(22, "Snake");
  std::cout << hash_table << std::endl;
  std::cout << "Empty: " << hash_table.IsEmpty() << std::endl;
  std::cout << "Size: " << hash_table.Size() << std::endl;
  std::cout << "Get key 71: " << hash_table.Get(71) << std::endl;
  std::cout << "Remove key 60: " << hash_table.Remove(60) << std::endl;
  std::cout << "Size: " << hash_table.Size() << std::endl;
  std::cout << "Remove key 22: " << hash_table.Remove(22) << std::endl;
  std::cout << "Size: " << hash_table.Size() << std::endl;
  std::cout << hash_table << std::endl;
  return 0;
}