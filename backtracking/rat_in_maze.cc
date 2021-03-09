#include "backtracking_util.h"

namespace algorithms {
namespace backtracking {

template <size_t N>
bool PossibleMove(const int (&board)[N][N], int x, int y) {
  return (x >= 0 && x < (signed)N && y >= 0 && y < (signed)N &&
          board[x][y] == 1);
}

template <size_t N>
bool RatInMazeRecursive(const int (&board)[N][N], int (&out)[N][N], int x,
                        int y) {
  if (PossibleMove(board, x, y)) {
    out[x][y] = 1;
    if (x == (N - 1) && y == (N - 1)) return true;
    if (RatInMazeRecursive(board, out, x + 1, y) ||
        RatInMazeRecursive(board, out, x, y + 1))
      return true;
    out[x][y] = 0;
    return false;
  }
  return false;
}

void RatInMaze() {
  const unsigned int n = 4;
  int board[n][n] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
  int out[n][n] = {};
  if (RatInMazeRecursive(board, out, 0, 0))
    PrintMatrix(out);
  else
    std::cout << "No solution has been found" << std::endl;
}

}  // namespace backtracking
}  // namespace algorithms

int main() {
  algorithms::backtracking::RatInMaze();
  return 0;
}
