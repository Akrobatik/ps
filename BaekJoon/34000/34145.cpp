// Title : 조화로운 사각형
// Link  : https://www.acmicpc.net/problem/34145 
// Time  : 1752 ms
// Memory: 4560 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, -1}, {-1, 0}, {0, -1}, {0, 0}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int8_t>> fwt(n + 2, vector<int8_t>(m + 2));

  auto UpdatePt = [&](int y, int x, int8_t v) {
    for (int i = y; i <= n; i += (i & -i)) {
      for (int j = x; j <= m; j += (j & -j)) {
        fwt[i][j] ^= v;
      }
    }
  };

  auto UpdateRc = [&](int y1, int x1, int y2, int x2, int8_t v) {
    UpdatePt(y1, x1, v);
    UpdatePt(y1, x2 + 1, v);
    UpdatePt(y2 + 1, x1, v);
    UpdatePt(y2 + 1, x2 + 1, v);
  };

  auto Calc = [&](int y, int x) -> int8_t {
    int8_t res = 0;
    for (int i = y; i > 0; i -= (i & -i)) {
      for (int j = x; j > 0; j -= (j & -j)) {
        res ^= fwt[i][j];
      }
    }
    return res;
  };

  auto Get = [&](char c) -> int8_t {
    if (c == 'E') return 0;
    if (c == 'F') return 1;
    if (c == 'W') return 2;
    if (c == 'A') return 3;
    assert(0);
  };

  vector<vector<int8_t>> board(n + 2, vector<int8_t>(m + 2, 4));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      board[i][j] = Get(c);
    }
  }

  auto Check = [&](int y, int x) {
    bool used[4] = {};
    for (int i = 0; i < 4; i++) {
      auto [dy, dx] = kDelta[i];
      int yy = y + dy, xx = x + dx;
      int v = board[yy][xx] ^ Calc(yy, xx);
      if (v >= 4 || used[v]) return false;
      used[v] = true;
    }
    return true;
  };

  int cnt = 0;
  vector<vector<bool>> check(n + 2, vector<bool>(m + 2));
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      check[i][j] = Check(i, j);
      cnt += check[i][j];
    }
  }
  cout << cnt << "\n";

  vector<pair<int, int>> cands;
  vector<vector<bool>> visited(n + 2, vector<bool>(m + 2));

  auto Push = [&](int y, int x) {
    if (visited[y][x]) return;
    visited[y][x] = true;
    cands.push_back({y, x});
  };

  while (q--) {
    int t, y1, x1, y2, x2;
    cin >> t >> y1 >> x1 >> y2 >> x2;

    cands.clear();
    for (int i = x1; i <= x2 + 1; i++) {
      Push(y1, i);
      Push(y2 + 1, i);
    }
    for (int i = y1 + 1; i <= y2; i++) {
      Push(i, x1);
      Push(i, x2 + 1);
    }

    for (auto [y, x] : cands) {
      cnt -= check[y][x];
      visited[y][x] = false;
    }

    UpdateRc(y1, x1, y2, x2, t);
    for (auto [y, x] : cands) {
      check[y][x] = Check(y, x);
      cnt += check[y][x];
    }

    cout << cnt << "\n";
  }

  return 0;
}