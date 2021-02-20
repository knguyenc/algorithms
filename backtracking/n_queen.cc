#include "backtracking_util.h"

namespace algorithms {
namespace backtracking {

template <size_t N>
bool PossiblePlace(const int (&board)[N][N], int x, int y) {
  int i, j;
  for (i = 0; i < (signed)N; i++)
    if (board[x][i] || board[i][y]) return false;
  for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
    if (board[i][j]) return false;
  for (i = x + 1, j = y + 1; i < (signed)N && j < (signed)N; i++, j++)
    if (board[i][j]) return false;
  for (i = x + 1, j = y - 1; i < (signed)N && j >= 0; i++, j--)
    if (board[i][j]) return false;
  for (i = x - 1, j = y + 1; i >= 0 && j < (signed)N; i--, j++)
    if (board[i][j]) return false;
  return true;
}

template <size_t N>
bool NQueenRecursive(int (&board)[N][N], int y) {
  if (y >= (signed)N) return true;
  for (int i = 0; i < (signed)N; i++) {
    if (PossiblePlace(board, i, y)) {
      board[i][y] = 1;
      if (NQueenRecursive(board, y + 1)) return true;
      board[i][y] = 0;
    }
  }
  return false;
}

void NQueen() {
  const unsigned int n = 4;
  int board[n][n] = {{0}};
  if (NQueenRecursive(board, 0))
    PrintMatrix(board);
  else
    std::cout << "No solution has been found" << std::endl;
}

}  // namespace backtracking
}  // namespace algorithms

int main()
{
  algorithms::backtracking::NQueen();
  return 0;
}

