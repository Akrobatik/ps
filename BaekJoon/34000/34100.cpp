// Title : └┘
// Link  : https://www.acmicpc.net/problem/34100 
// Time  : 276 ms
// Memory: 11880 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> board;

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    board.resize(n);
    for (auto& s : board) cin >> s;

    bool ok = true;
    for (int i = n - 1; ok && i > 0; i--) {
      for (int j = 1; ok && j < m; j++) {
        if (board[i][j - 1] != '.') continue;

        if (board[i][j] == '.') {
          if (board[i - 1][j - 1] == '.' && board[i - 1][j] == '.') {
            int p = j - 1;
            while (p > 0 && board[i - 1][p - 1] == '.') --p;
            if ((j - p) & 1) {
              board[i][j] = board[i][j - 1] = board[i - 1][j - 1] = 'a';
            } else {
              board[i][j] = board[i][j - 1] = board[i - 1][j] = 'b';
            }
          } else if (board[i - 1][j - 1] == '.') {
            board[i][j] = board[i][j - 1] = board[i - 1][j - 1] = 'a';
          } else if (board[i - 1][j] == '.') {
            board[i][j] = board[i][j - 1] = board[i - 1][j] = 'b';
          }
        }
        ok = (board[i][j - 1] != '.');
      }
      if (ok) ok = (board[i][m - 1] != '.');
    }

    for (int i = 0; ok && i < m; i++) {
      ok = (board[0][i] != '.');
    }

    if (ok) {
      for (auto& s : board) cout << s << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
