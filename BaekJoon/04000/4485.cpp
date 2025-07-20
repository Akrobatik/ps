// Title : 녹색 옷 입은 애가 젤다지?
// Link  : https://www.acmicpc.net/problem/4485 
// Time  : 4 ms
// Memory: 2276 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int tc = 1;; tc++) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<vector<int>> board(n, vector<int>(n));
    for (auto& vec : board) {
      for (auto& e : vec) cin >> e;
    }

    priority_queue<tup, vector<tup>, greater<tup>> pq;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    auto Push = [&](int y, int x, int w) {
      if (!(0 <= y && y < n && 0 <= x && x < n) || dist[y][x] <= (w += board[y][x])) return;
      dist[y][x] = w;
      pq.push({w, y, x});
    };

    Push(0, 0, 0);
    while (!pq.empty()) {
      auto [w, y, x] = pq.top();
      pq.pop();

      if (dist[y][x] != w) continue;
      if (y + 1 == n && x + 1 == n) break;

      for (auto [dy, dx] : kDelta) {
        Push(y + dy, x + dx, w);
      }
    }

    cout << "Problem " << tc << ": " << dist[n - 1][n - 1] << "\n";
  }

  return 0;
}
