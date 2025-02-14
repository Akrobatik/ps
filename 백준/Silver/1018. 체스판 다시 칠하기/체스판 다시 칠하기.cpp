#include <bits/stdc++.h>

using namespace std;

char board[50][50];
int sum[51][51];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int rows, cols;
  cin >> rows >> cols;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) cin >> board[i][j];
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (board[i][j] == (((i + j) & 1) ? 'B' : 'W'));
    }
  }

  int ans = INT_MAX;
  for (int i = 8; i <= rows; i++) {
    for (int j = 8; j <= cols; j++) {
      int now = sum[i][j] - sum[i - 8][j] - sum[i][j - 8] + sum[i - 8][j - 8];
      if (now & 0x60) now = 64 - now;
      if (ans > now) ans = now;
    }
  }
  cout << ans;

  return 0;
}
