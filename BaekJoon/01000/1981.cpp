// Title : 배열에서 이동
// Link  : https://www.acmicpc.net/problem/1981 
// Time  : 96 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(n));
  for (auto& vec : mat) {
    for (auto& e : vec) cin >> e;
  }

  queue<pair<int, int>> q;
  vector<vector<bool>> visited;

  auto Push = [&](int y, int x, int lo, int hi) {
    if (!(0 <= y && y < n && 0 <= x && x < n) || !(lo <= mat[y][x] && mat[y][x] <= hi) || visited[y][x]) return;
    visited[y][x] = true;
    q.push({y, x});
  };

  auto Check = [&](int lo, int hi) {
    while (!q.empty()) q.pop();
    visited.assign(n, vector<bool>(n));

    Push(0, 0, lo, hi);
    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();

      if (y + 1 == n && x + 1 == n) return true;

      for (auto [dy, dx] : kDelta) {
        Push(y + dy, x + dx, lo, hi);
      }
    }
    return false;
  };

  int minn = INT_MAX, limit = min<int>(mat[0][0], mat[n - 1][n - 1]);
  for (int i = 0; i <= limit; i++) {
    int lo = limit - 1, hi = 201;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (Check(i, mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    if (hi != 201) minn = min<int>(minn, hi - i);
  }
  cout << minn;

  return 0;
}
