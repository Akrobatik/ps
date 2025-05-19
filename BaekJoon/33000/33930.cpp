// Title : 삼각형 수열
// Link  : https://www.acmicpc.net/problem/33930 
// Time  : 40 ms
// Memory: 13512 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> board(n, vector<int>(n));
  vector<pair<int, int>> type[3];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      type[(i + j) % 3].push_back({i, j});
    }
  }

  for (int i = n; i; i--) {
    int bt = INT_MAX, bi = -1;
    for (int t = 0; t < 3; t++) {
      int sz = type[t].size();
      if (bt > sz && sz >= i) bt = sz, bi = t;
    }

    if (bi == -1) {
      cout << "-1";
      return 0;
    }

    int r = i;
    while (r--) {
      auto [y, x] = type[bi].back();
      type[bi].pop_back();
      board[y][x] = i;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}