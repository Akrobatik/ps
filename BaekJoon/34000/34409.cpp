// Title : 무등산 등반
// Link  : https://www.acmicpc.net/problem/34409 
// Time  : 76 ms
// Memory: 8200 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int, int>;

constexpr int64_t kInf = 1e18;
constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, sy, sx, a, b, c;
  cin >> n >> m >> sy >> sx >> a >> b >> c;
  --sy, --sx;

  int mh = -1, ey, ex;
  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mh < mat[i][j]) mh = mat[i][j], ey = i, ex = j;
    }
  }

  vector<vector<int64_t>> dist(n, vector<int64_t>(m, kInf));
  priority_queue<tup, vector<tup>, greater<tup>> pq;

  auto Push = [&](int y, int x, int oh, int64_t od) {
    if (!(0 <= y && y < n && 0 <= x && x < m)) return;

    int ch = mat[y][x];
    if (abs(oh - ch) > c) return;

    int64_t cd = od + (oh == ch ? 1 : (oh < ch ? a : b) * abs(oh - ch));
    if (dist[y][x] <= cd) return;
    dist[y][x] = cd;

    pq.push({cd, y, x});
  };

  dist[sy][sx] = 0;
  pq.push({0, sy, sx});

  while (!pq.empty()) {
    auto [d, y, x] = pq.top();
    pq.pop();

    if (dist[y][x] != d) continue;
    if (y == ey && x == ex) break;

    for (auto [dy, dx] : kDelta) {
      Push(y + dy, x + dx, mat[y][x], d);
    }
  }

  cout << (dist[ey][ex] != kInf ? dist[ey][ex] : -1);

  return 0;
}