#include "backtracking_util.h"

namespace algorithms {
namespace backtracking {

template <size_t N>
bool PossibleMove(int (&board)[N][N], int x, int y) {
  return (x >= 0 && x < (signed)N && y >= 0 && y < (signed)N &&
          board[x][y] == -1);
}

template <size_t N>
bool KnightTourRecursive(int (&board)[N][N], const int (&x_mv)[8],
                         const int (&y_mv)[8], int mv, int x, int y) {
  if (mv == N * N) return true;
  int x_next, y_next;

  for (int i = 0; i < 8; i++) {
    x_next = x + x_mv[i];
    y_next = y + y_mv[i];

    if (PossibleMove(board, x_next, y_next)) {
      board[x_next][y_next] = mv;
      if (KnightTourRecursive(board, x_mv, y_mv, mv + 1, x_next, y_next))
        return true;
      else
        board[x_next][y_next] = -1;
    }
  }
  return false;
}

void KnightTour() {
  const int n = 8;
  int board[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) board[i][j] = -1;

  int x_move[] = {2, 1, -1, -2, -2, -1, 2, 1};
  int y_move[] = {1, 2, 2, 1, -1, -2, -1, -2};

  board[0][0] = 0;
  if (KnightTourRecursive(board, x_move, y_move, 1, 0, 0))
    PrintMatrix(board);
  else
    std::cout << "No solution has been found" << std::endl;
}

}  // namespace backtracking
}  // namespace algorithms

int main() {
  algorithms::backtracking::KnightTour();
  return 0;
}