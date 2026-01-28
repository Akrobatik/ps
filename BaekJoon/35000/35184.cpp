// Title : 수돗물과 게 임
// Link  : https://www.acmicpc.net/problem/35184 
// Time  : 256 ms
// Memory: 12640 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

constexpr int64_t kInf = 1e18;

using tup = tuple<int64_t, int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, t;
  cin >> n >> m >> t;

  vector<string> mat(n);
  for (auto& s : mat) cin >> s;

  int sy, sx, sd;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ('0' <= mat[i][j] && mat[i][j] <= '3') {
        sy = i, sx = j, sd = mat[i][j] - '0';
        mat[i][j] = '.';
      }
    }
  }

  priority_queue<tup, vector<tup>, greater<tup>> pq;
  vector<vector<array<int64_t, 4>>> memo(n, vector<array<int64_t, 4>>(m, {kInf, kInf, kInf, kInf}));

  auto Push = [&](this auto&& self, int y, int x, int d, int64_t v) {
    if (!(0 <= y && y < n && 0 <= x && x < m)) return;
    if (memo[y][x][d] <= v) return;
    memo[y][x][d] = v;

    if (mat[y][x] == 'T') {
      d = (d + 1) & 3;
      auto [dy, dx] = kDelta[d];
      self(y + dy, x + dx, d, v);
      return;
    }

    pq.push({v, y, x, d});
  };

  Push(sy, sx, sd, 0);
  while (!pq.empty()) {
    auto [v, y, x, d] = pq.top();
    pq.pop();

    if (mat[y][x] == 'S') {
      cout << v;
      return 0;
    }

    Push(y, x, (d + 1) & 3, v + t);
    for (int e : {1, 3}) {
      auto [dy, dx] = kDelta[(d + e) & 3];
      Push(y + dy, x + dx, d, v + 1);
    }
  }
  cout << "-1";

  return 0;
}