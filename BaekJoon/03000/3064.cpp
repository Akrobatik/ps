// Title : Minesweeper
// Link  : https://www.acmicpc.net/problem/3064 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char board[100][100];

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> board[i][j];
      }
    }

    if (n <= 2) {
      cout << "0\n";
      continue;
    }
    if (n == 3) {
      cout << board[0][0] << "\n";
      continue;
    }

    int ans = (n - 4) * (n - 4);
    for (int i = 0; i < n - 2; i++) {
      if (board[0][i] != '0') {
        --board[0][i + 1], --board[0][i + 2];
        ++ans;
      }
      if (board[n - 1][i] != '0') {
        --board[n - 1][i + 1], --board[n - 1][i + 2];
        ++ans;
      }
    }
    if (board[0][0] == '1') {
      --board[1][0], --board[2][0];
    }
    if (board[0][n - 1] == '1') {
      --board[1][n - 1], --board[2][n - 1];
    }
    if (board[n - 1][0] == '1') {
      --board[n - 2][0], --board[n - 3][0];
    }
    if (board[n - 1][n - 1] == '1') {
      --board[n - 2][n - 1], --board[n - 3][n - 1];
    }
    for (int i = 1; i < n - 3; i++) {
      if (board[i][0] != '0') {
        --board[i + 1][0], --board[i + 2][0];
        ++ans;
      }
      if (board[i][n - 1] != '0') {
        --board[i + 1][n - 1], --board[i + 2][n - 1];
        ++ans;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
