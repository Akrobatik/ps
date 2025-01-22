#include <bits/stdc++.h>

using namespace std;

char board[3072][6145];

void Triangle(int row, int col, int n) {
  if (n == 3) {
    col--;
    board[row][col] =
        board[row + 1][col - 1] = board[row + 1][col + 1] =
            board[row + 2][col - 2] = board[row + 2][col - 1] = board[row + 2][col] = board[row + 2][col + 1] = board[row + 2][col + 2] = '*';
    return;
  }

  int half = n / 2;
  Triangle(row, col, half);
  Triangle(row + half, col - half, half);
  Triangle(row + half, col + half, half);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) memset(board[i], ' ', n * 2 - 1);
  Triangle(0, n, n);
  for (int i = 0; i < n; i++) cout << board[i] << "\n";

  return 0;
}
