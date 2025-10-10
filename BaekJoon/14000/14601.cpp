// Title : 샤워실 바닥 깔기 (Large)
// Link  : https://www.acmicpc.net/problem/14601 
// Time  : 0 ms
// Memory: 2216 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, x, y;
  cin >> k >> x >> y;
  int n = 1 << k;
  y = n - y, --x;

  vector<vector<int>> mat(n, vector<int>(n));
  mat[y][x] = -1;

  int idx = 0;
  [&](this auto&& self, int sy, int sx, int ty, int tx, int sz) -> void {
    if (sz == 1) return;
    sz >>= 1;

    int cur = ++idx;
    int cy = sy + sz - 1, cx = sx + sz - 1;
    if (ty >= sz && tx >= sz) {
      mat[cy][cx] = mat[cy][cx + 1] = mat[cy + 1][cx] = cur;
      self(sy, sx, sz - 1, sz - 1, sz);
      self(sy, sx + sz, sz - 1, 0, sz);
      self(sy + sz, sx, 0, sz - 1, sz);
      self(sy + sz, sx + sz, ty % sz, tx % sz, sz);
    } else if (ty >= sz) {
      mat[cy][cx] = mat[cy][cx + 1] = mat[cy + 1][cx + 1] = cur;
      self(sy, sx, sz - 1, sz - 1, sz);
      self(sy, sx + sz, sz - 1, 0, sz);
      self(sy + sz, sx + sz, 0, 0, sz);
      self(sy + sz, sx, ty % sz, tx % sz, sz);
    } else if (tx >= sz) {
      mat[cy][cx] = mat[cy + 1][cx] = mat[cy + 1][cx + 1] = cur;
      self(sy, sx, sz - 1, sz - 1, sz);
      self(sy, sx + sz, ty % sz, tx % sz, sz);
      self(sy + sz, sx, 0, sz - 1, sz);
      self(sy + sz, sx + sz, 0, 0, sz);
    } else {
      mat[cy][cx + 1] = mat[cy + 1][cx] = mat[cy + 1][cx + 1] = cur;
      self(sy, sx, ty % sz, tx % sz, sz);
      self(sy, sx + sz, sz - 1, 0, sz);
      self(sy + sz, sx, 0, sz - 1, sz);
      self(sy + sz, sx + sz, 0, 0, sz);
    }
  }(0, 0, y, x, n);

  for (auto& vec : mat) {
    for (auto e : vec) cout << e << " ";
    cout << "\n";
  }

  return 0;
}