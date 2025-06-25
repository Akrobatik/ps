// Title : 색종이와 공예
// Link  : https://www.acmicpc.net/problem/26598 
// Time  : 140 ms
// Memory: 3388 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (auto& e : board) cin >> e;

  vector<vector<bool>> visited(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j]) continue;
      char color = board[i][j];
      int sy = INT_MAX, sx = INT_MAX;
      int ey = INT_MIN, ex = INT_MIN;
      int cnt = 0;

      queue<pair<int, int>> q;

      auto Push = [&](int y, int x) {
        if (!(0 <= y && y < n && 0 <= x && x < m) ||
            visited[y][x] || board[y][x] != color) return;
        visited[y][x] = true;
        sy = min<int>(sy, y), sx = min<int>(sx, x);
        ey = max<int>(ey, y), ex = max<int>(ex, x);
        ++cnt;
        q.push({y, x});
      };

      Push(i, j);
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (auto [dy, dx] : kDelta) {
          Push(y + dy, x + dx);
        }
      }

      if ((ey - sy + 1) * (ex - sx + 1) != cnt) {
        cout << "BaboBabo";
        return 0;
      }
    }
  }
  cout << "dd";

  return 0;
}
