#ifndef ALGORITHMS_BACKTRACKING_BACKTRACKING_UTIL_H_
#define ALGORITHMS_BACKTRACKING_BACKTRACKING_UTIL_H_

#include <iomanip>
#include <iostream>

namespace algorithms {
namespace backtracking {

template <class T, size_t N>
void PrintMatrix(const T (&matrix)[N][N]) {
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int j = 0; j < N; j++)
      std::cout << std::setw(2) << matrix[i][j] << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

}  // namespace backtracking
}  // namespace algorithms

#endif  // ALGORITHMS_BACKTRACKING_BACKTRACKING_UTIL_H_
