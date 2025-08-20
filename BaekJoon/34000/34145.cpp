// Title : 조화로운 사각형
// Link  : https://www.acmicpc.net/problem/34145 
// Time  : 1260 ms
// Memory: 9192 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, -1}, {-1, 0}, {0, -1}, {0, 0}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Get = [&](char c) -> int8_t {
    if (c == 'E') return 0;
    if (c == 'F') return 1;
    if (c == 'W') return 2;
    if (c == 'A') return 3;
  };

  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int8_t>> board(n + 2, vector<int8_t>(m + 2, 4));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      board[i][j] = Get(c);
    }
  }

  vector<vector<array<int8_t, 4>>> keys(n + 2, vector<array<int8_t, 4>>(m + 2, {0, 0, 0, 0}));

  auto Check = [&](int y, int x) -> bool {
    bool used[4] = {};
    for (int z = 0; z < 4; ++z) {
      auto [dy, dx] = kDelta[z];
      int yy = y + dy, xx = x + dx;
      int v = board[yy][xx] ^ keys[yy][xx][z];
      if (v >= 4 || used[v]) return false;
      used[v] = true;
    }
    return true;
  };

  auto Apply = [&](int y, int x, int z, int8_t t) {
    auto [dy, dx] = kDelta[z];
    int yy = y + dy, xx = x + dx;
    keys[yy][xx][z] ^= t;
  };

  long long cnt = 0;
  vector<vector<char>> check(n + 2, vector<char>(m + 2, 0));
  for (int y = 2; y <= n; ++y) {
    for (int x = 2; x <= m; ++x) {
      check[y][x] = Check(y, x);
      cnt += check[y][x];
    }
  }
  cout << cnt << "\n";

  vector<pair<int, int>> cands;
  vector<vector<char>> vis(n + 2, vector<char>(m + 2, 0));
  auto Push = [&](int y, int x) {
    if (y < 1 || x < 1 || y > n || x > m) return;
    if (vis[y][x]) return;
    vis[y][x] = 1;
    cands.emplace_back(y, x);
  };

  while (q--) {
    int t, y1, x1, y2, x2;
    cin >> t >> y1 >> x1 >> y2 >> x2;

    cands.clear();

    for (int x = x1; x <= x2 + 1; ++x) {
      Push(y1, x);
      Push(y2 + 1, x);
    }

    for (int y = y1 + 1; y <= y2; ++y) {
      Push(y, x1);
      Push(y, x2 + 1);
    }

    for (auto [y, x] : cands) {
      cnt -= check[y][x];
      vis[y][x] = 0;
    }

    for (int x = x1 + 1; x <= x2; ++x) {
      Apply(y1, x, 2, t);
      Apply(y1, x, 3, t);
    }

    Apply(y1, x1, 3, t);
    Apply(y1, x2 + 1, 2, t);

    for (int x = x1 + 1; x <= x2; ++x) {
      Apply(y2 + 1, x, 0, t);
      Apply(y2 + 1, x, 1, t);
    }

    Apply(y2 + 1, x1, 1, t);
    Apply(y2 + 1, x2 + 1, 0, t);

    for (int y = y1 + 1; y <= y2; ++y) {
      Apply(y, x1, 1, t);
      Apply(y, x1, 3, t);
    }

    for (int y = y1 + 1; y <= y2; ++y) {
      Apply(y, x2 + 1, 0, t);
      Apply(y, x2 + 1, 2, t);
    }

    for (auto [y, x] : cands) {
      check[y][x] = Check(y, x);
      cnt += check[y][x];
    }

    cout << cnt << "\n";
  }

  return 0;
}