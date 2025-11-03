// Title : Grievous Lady
// Link  : https://www.acmicpc.net/problem/34654 
// Time  : 64 ms
// Memory: 28236 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

constexpr pair<int, int> kCDelta[] = {
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> mat, out;

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    mat.assign(n, vector<int>(m, 0));
    out.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int v;
        cin >> v;
        mat[i][j] = out[i][j] = v;
      }
    }

    auto Check = [&](int y, int x, int v) {
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < m && out[yy][xx] == v) return false;
      }
      return true;
    };

    auto Count = [&](int y, int x, int v) {
      int cnt = 0;
      for (auto [dy, dx] : kCDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < m && out[yy][xx] == v) ++cnt;
      }
      return cnt;
    };

    [&](this auto&& self, int idx) -> bool {
      if (idx == n * m) return true;
      int y = idx / m, x = idx % m;
      if (mat[y][x]) {
        return self(idx + 1);
      } else {
        int clr[4] = {1, 2, 3, 4};
        sort(clr, clr + 4, [&](int lhs, int rhs) {
          int lv = Count(y, x, lhs), rv = Count(y, x, rhs);
          return lv > rv;
        });

        for (int i : clr) {
          if (!Check(y, x, i)) continue;
          out[y][x] = i;
          if (self(idx + 1)) return true;
          out[y][x] = 0;
        }
      }
      return false;
    }(0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << out[i][j] << " \n"[j + 1 == m];
      }
    }
  }

  return 0;
}