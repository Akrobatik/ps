// Title : 등산
// Link  : https://www.acmicpc.net/problem/1486 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Get = [](char c) {
    if (c <= 'Z') return c - 'A';
    return c - 'a' + 26;
  };

  int n, m, t, d;
  cin >> n >> m >> t >> d;

  vector<vector<int>> board(n, vector<int>(m));
  for (auto& vec : board) {
    for (auto& e : vec) {
      char c;
      cin >> c;
      e = Get(c);
    }
  }

  priority_queue<tup, vector<tup>, greater<tup>> pq;
  vector<vector<int>> rev(n, vector<int>(m, INT_MAX >> 1));

  auto PushR = [&](int y, int x, int z) {
    if (rev[y][x] <= z || z > d) return;
    rev[y][x] = z;
    pq.push({z, y, x});
  };

  PushR(0, 0, 0);
  while (!pq.empty()) {
    auto [z, y, x] = pq.top();
    pq.pop();

    if (rev[y][x] != z) continue;

    for (auto [dy, dx] : kDelta) {
      int yy = y + dy, xx = x + dx;
      if (0 <= yy && yy < n && 0 <= xx && xx < m) {
        int h = board[yy][xx] - board[y][x];
        int zd = (h < 0 ? h * h : 1);
        if (abs(h) <= t) PushR(yy, xx, z + zd);
      }
    }
  }

  vector<vector<int>> dist(n, vector<int>(m, INT_MAX >> 1));

  auto Push = [&](int y, int x, int z) {
    if (dist[y][x] <= z || rev[y][x] + z > d) return;
    dist[y][x] = z;
    pq.push({z, y, x});
  };

  int maxx = 0;

  Push(0, 0, 0);
  while (!pq.empty()) {
    auto [z, y, x] = pq.top();
    pq.pop();

    if (dist[y][x] != z) continue;
    maxx = max<int>(maxx, board[y][x]);

    for (auto [dy, dx] : kDelta) {
      int yy = y + dy, xx = x + dx;
      if (0 <= yy && yy < n && 0 <= xx && xx < m) {
        int h = board[y][x] - board[yy][xx];
        int zd = (h < 0 ? h * h : 1);
        if (abs(h) <= t) Push(yy, xx, z + zd);
      }
    }
  }

  cout << maxx;

  return 0;
}