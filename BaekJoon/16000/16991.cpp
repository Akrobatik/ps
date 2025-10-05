// Title : 외판원 순회 3
// Link  : https://www.acmicpc.net/problem/16991 
// Time  : 40 ms
// Memory: 19512 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> yx(n);
  for (auto& [y, x] : yx) cin >> y >> x;

  vector<vector<long double>> mat(n, vector<long double>(n));
  for (int i = 0; i < n; i++) {
    auto [y1, x1] = yx[i];
    for (int j = i + 1; j < n; j++) {
      auto [y2, x2] = yx[j];
      long double dy = abs(y1 - y2), dx = abs(x1 - x2);
      mat[i][j] = mat[j][i] = hypot(dy, dx);
    }
  }

  int m = 1 << n;
  vector<vector<long double>> dist(n, vector<long double>(m, 1e18));
  dist[0][1] = 0.0;

  vector<int> incl, excl;
  for (int i = 0; i < m; i++) {
    incl.clear(), excl.clear();
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        incl.push_back(j);
      } else {
        excl.push_back(j);
      }
    }

    for (auto j : incl) {
      for (auto l : excl) {
        dist[l][i | (1 << l)] = min<long double>(dist[l][i | (1 << l)], dist[j][i] + mat[j][l]);
      }
    }
  }

  long double minn = 1e18;
  for (int i = 0; i < n; i++) {
    minn = min<long double>(minn, dist[i][m - 1] + mat[i][0]);
  }
  cout << setprecision(6) << fixed << minn;

  return 0;
}