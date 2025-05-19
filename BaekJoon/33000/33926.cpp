// Title : 인덕이와 보드게임
// Link  : https://www.acmicpc.net/problem/33926 
// Time  : 208 ms
// Memory: 25664 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> val(n, vector<int>(m)), col(n, vector<int>(m));
  for (auto& vec : val) {
    for (auto& e : vec) cin >> e;
  }
  for (auto& vec : col) {
    for (auto& e : vec) cin >> e;
  }

  vector<vector<int64_t>> maxx(n, vector<int64_t>(m, INT64_MIN));
  vector<vector<int64_t>> minn(n, vector<int64_t>(m, INT64_MAX));

  maxx[0][0] = minn[0][0] = val[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) continue;

      int64_t cmax = INT64_MIN, cmin = INT64_MAX;
      if (i != 0) {
        for (auto prv : {maxx[i - 1][j], minn[i - 1][j]}) {
          if (prv == INT64_MIN || prv == INT64_MAX) continue;
          int64_t cur = (prv + val[i][j]) * (1 - (col[i][j] << 1));
          cmax = max<int64_t>(cmax, cur);
          cmin = min<int64_t>(cmin, cur);
        }
      }
      if (j != 0) {
        for (auto prv : {maxx[i][j - 1], minn[i][j - 1]}) {
          if (prv == INT64_MIN || prv == INT64_MAX) continue;
          int64_t cur = (prv + val[i][j]) * (1 - (col[i][j] << 1));
          cmax = max<int64_t>(cmax, cur);
          cmin = min<int64_t>(cmin, cur);
        }
      }

      maxx[i][j] = cmax, minn[i][j] = cmin;
    }
  }

  cout << maxx[n - 1][m - 1];

  return 0;
}