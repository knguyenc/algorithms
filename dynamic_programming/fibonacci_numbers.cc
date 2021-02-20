#include <iostream>

namespace algorithms {
namespace dynamic_programming {

unsigned int FibonacciNumber(unsigned int n) {
  unsigned int fibonacci[n + 1];
  fibonacci[0] = 0;
  fibonacci[1] = 1;
  for (unsigned int i = 2; i <= n; i++)
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
  return fibonacci[n];
}

}  // namespace dynamic_programming
}  // namespace algorithms

int main()
{
  int n = 6;
  std::cout << "The " << n << "th fibonacci number is: ";
  std::cout << algorithms::dynamic_programming::FibonacciNumber(n);
  std::cout << std::endl;
  return 0;
}

