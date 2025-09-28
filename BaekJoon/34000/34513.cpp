// Title : 룩의 이동
// Link  : https://www.acmicpc.net/problem/34513 
// Time  : 188 ms
// Memory: 72268 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

using tup = tuple<int, int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> board(n);
  for (auto& s : board) cin >> s;

  int sy, sx, ey, ex;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'R') sy = i, sx = j;
      if (board[i][j] == 'K') ey = i, ex = j;
    }
  }

  vector<vector<array<int, 5>>> dist(n, vector<array<int, 5>>(n, {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}));
  deque<tup> dq;

  auto Push = [&](int d, int y, int x, int dir, bool add) {
    if (!(0 <= y && y < n && 0 <= x && x < n)) return;
    if (board[y][x] == 'B') return;

    if (add) ++d;
    if (board[y][x] == 'W') dir = 4;
    if (dist[y][x][dir] <= d) return;
    dist[y][x][dir] = d;
    if (add) {
      dq.push_back({d, y, x, dir});
    } else {
      dq.push_front({d, y, x, dir});
    }
  };

  Push(0, sy, sx, 4, false);
  while (!dq.empty()) {
    auto [d, y, x, dir] = dq.front();
    dq.pop_front();

    if (dist[y][x][dir] != d) continue;
    if (board[y][x] == 'K') break;

    for (int i = 0; i < 4; i++) {
      auto [dy, dx] = kDelta[i];
      Push(d, y + dy, x + dx, i, (dir != i));
    }
  }

  int d = *min_element(dist[ey][ex].begin(), dist[ey][ex].end());
  cout << (d != INT_MAX ? d : -1);

  return 0;
}