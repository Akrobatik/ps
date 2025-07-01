// Title : 말이 되고픈 원숭이
// Link  : https://www.acmicpc.net/problem/1600 
// Time  : 40 ms
// Memory: 3368 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta1[] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

constexpr pair<int, int> kDelta2[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool visited[200][200][31];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, n, m;
  cin >> k >> m >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      if (x == 0) continue;
      for (int l = 0; l <= k; l++) {
        visited[i][j][l] = true;
      }
    }
  }

  queue<tuple<int, int, int>> q;

  auto Push = [&](int y, int x, int r) {
    if (!(0 <= y && y < n && 0 <= x && x < m && r <= k && !visited[y][x][r])) return;
    visited[y][x][r] = true;
    q.push({y, x, r});
  };

  Push(0, 0, 0);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [y, x, r] = q.front();
      q.pop();

      if (y + 1 == n && x + 1 == m) {
        cout << i;
        return 0;
      }

      for (auto [dy, dx] : kDelta1) {
        Push(y + dy, x + dx, r + 1);
      }
      for (auto [dy, dx] : kDelta2) {
        Push(y + dy, x + dx, r);
      }
    }
  }
  cout << "-1";

  return 0;
}
