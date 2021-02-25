#include <iostream>

namespace algorithms {
namespace dynamic_programming {

unsigned int UglyNumber(unsigned int n) {
  unsigned int *ugly_numbers = new unsigned int[n];
  unsigned int i2 = 0, i3 = 0, i5 = 0;
  unsigned int multiplication_2 = 2;
  unsigned int multiplication_3 = 3;
  unsigned int multiplication_5 = 5;
  unsigned int next_ugly_number = 1;
  ugly_numbers[0] = next_ugly_number;

  for (unsigned int i = 1; i < n; i++) {
    next_ugly_number = std::min(multiplication_2,
                                std::min(multiplication_3, multiplication_5));
    ugly_numbers[i] = next_ugly_number;
    if (multiplication_2 == next_ugly_number)
      multiplication_2 = ugly_numbers[++i2] * 2;
    if (multiplication_3 == next_ugly_number)
      multiplication_3 = ugly_numbers[++i3] * 3;
    if (multiplication_5 == next_ugly_number)
      multiplication_5 = ugly_numbers[++i5] * 5;
  }

  delete[] ugly_numbers;
  return next_ugly_number;
}

}  // namespace dynamic_programming
}  // namespace algorithms

int main() {
  int n = 190;
  std::cout << "The " << n << "th ugly number is: ";
  std::cout << algorithms::dynamic_programming::UglyNumber(n);
  std::cout << std::endl;
  return 0;
}
