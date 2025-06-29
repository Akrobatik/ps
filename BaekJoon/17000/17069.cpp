// Title : 파이프 옮기기 2
// Link  : https://www.acmicpc.net/problem/17069 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<tuple<int, int, int>>> table = {
      {{0, 1, 0}, {1, 1, 1}},
      {{0, 1, 0}, {1, 1, 1}, {1, 0, 2}},
      {{1, 1, 1}, {1, 0, 2}},
  };

  int n;
  cin >> n;
  vector<vector<int>> board(n + 1, vector<int>(n + 1, 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  vector<vector<array<int64_t, 3>>> memo(n, vector<array<int64_t, 3>>(n));
  memo[0][1][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 3; k++) {
        int64_t cur = memo[i][j][k];
        if (cur == 0) continue;
        for (auto [dy, dx, dt] : table[k]) {
          int y = i + dy, x = j + dx;
          if (board[y][x] || (dt == 1 && (board[i][x] || board[y][j]))) continue;
          memo[y][x][dt] += cur;
        }
      }
    }
  }

  int64_t ans = 0;
  for (int i = 0; i < 3; i++) ans += memo[n - 1][n - 1][i];
  cout << ans;

  return 0;
}
