// Title : 전쟁 － 전투
// Link  : https://www.acmicpc.net/problem/1303
// Time  : 0 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

char cells[100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> cells[i][j];
    }
  }

  int b = 0, w = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!cells[i][j]) continue;

      char color = cells[i][j];
      cells[i][j] = 0;
      int cnt = 0;
      queue<pair<int, int>> q;
      q.push({i, j});
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        ++cnt;
        for (auto [dy, dx] : kDelta) {
          int yy = y + dy, xx = x + dx;
          if (0 <= yy && yy < n && 0 <= xx && xx < m && color == cells[yy][xx]) {
            cells[yy][xx] = 0;
            q.push({yy, xx});
          }
        }
      }

      (color == 'B' ? b : w) += cnt * cnt;
    }
  }
  cout << w << " " << b;

  return 0;
}
