// Title : 구간 합 구하기 3
// Link  : https://www.acmicpc.net/problem/11658 
// Time  : 172 ms
// Memory: 10360 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> fwt(n + 1, vector<int>(n + 1));

  auto Update = [&](int y, int x, int v) {
    for (int i = y; i <= n; i += (i & -i)) {
      for (int j = x; j <= n; j += (j & -j)) {
        fwt[i][j] += v;
      }
    }
  };

  auto _Query = [&](int y, int x) -> int {
    int res = 0;
    for (int i = y; i > 0; i -= (i & -i)) {
      for (int j = x; j > 0; j -= (j & -j)) {
        res += fwt[i][j];
      }
    }
    return res;
  };

  auto Query = [&](int y1, int x1, int y2, int x2) -> int {
    return _Query(y2, x2) - _Query(y1 - 1, x2) - _Query(y2, x1 - 1) + _Query(y1 - 1, x1 - 1);
  };

  vector<vector<int>> board(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> board[i][j];
      Update(i, j, board[i][j]);
    }
  }

  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      int y, x, v;
      cin >> y >> x >> v;
      int old = board[y][x];
      board[y][x] = v;
      Update(y, x, v - old);
    } else {
      int y1, x1, y2, x2;
      cin >> y1 >> x1 >> y2 >> x2;
      cout << Query(y1, x1, y2, x2) << "\n";
    }
  }

  return 0;
}