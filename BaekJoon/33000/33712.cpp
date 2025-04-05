// Title : 블록 굴리기
// Link  : https://www.acmicpc.net/problem/33712
// Time  : 4 ms
// Memory: 2312 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInvalid = 0xDEAD;

constexpr tuple<int, int, int, int, int> kDelta[3][4] = {
    {
        {-2, 0, -1, 0, 1},
        {1, 0, 2, 0, 1},
        {0, -2, 0, -1, 2},
        {0, 1, 0, 2, 2},
    },
    {
        {-1, 0, kInvalid, kInvalid, 0},
        {2, 0, kInvalid, kInvalid, 0},
        {0, -1, 1, -1, 1},
        {0, 1, 1, 1, 1},
    },
    {
        {-1, 0, -1, 1, 2},
        {1, 0, 1, 1, 2},
        {0, -1, kInvalid, kInvalid, 0},
        {0, 2, kInvalid, kInvalid, 0},
    },
};

char board[150][150];
bool _visited[2][3][150][150];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  int sy, sx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == '2') sy = i, sx = j;
    }
  }

  auto Check = [&](int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m && board[y][x] != '0';
  };

  int ans = 0;
  queue<tuple<int, int, int>> q;
  _visited[0][0][sy][sx] = true;
  q.push({sy, sx, 0});
  for (int i = 0; !q.empty() && i < k; i++) {
    int nq = q.size();
    bool ok = (i & 1) != (k & 1);
    auto visited = _visited[(i & 1) ^ 1];
    while (nq--) {
      auto [y, x, t] = q.front();
      q.pop();

      for (auto [dy1, dx1, dy2, dx2, dt] : kDelta[t]) {
        int y1 = y + dy1, x1 = x + dx1;
        int y2 = y + dy2, x2 = x + dx2;
        if (Check(y1, x1) && ((dy2 == kInvalid && dx2 == kInvalid) || Check(y2, x2)) && !visited[dt][y1][x1]) {
          visited[dt][y1][x1] = true;
          ans += (dt == 0 && ok && (y1 != sy || x1 != sx));
          q.push({y1, x1, dt});
        }
      }
    }
  }
  cout << ans;

  return 0;
}
