#include <iostream>

namespace algorithms {
namespace dynamic_programming {

unsigned int CatalanNumber(unsigned int n) {
  unsigned int catalan[n + 1];
  catalan[0] = catalan[1] = 1;
  for (unsigned int i = 2; i <= n; i++) {
    catalan[i] = 0;
    for (unsigned int j = 0; j < i; j++)
      catalan[i] += catalan[j] * catalan[i - j - 1];
  }
  return catalan[n];
}

}  // namespace dynamic_programming
}  // namespace algorithms

int main()
{
  int n = 9;
  std::cout << "The " << n << "th catalan number is: ";
  std::cout << algorithms::dynamic_programming::CatalanNumber(n);
  std::cout << std::endl;
  return 0;
}

