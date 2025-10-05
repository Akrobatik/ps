// Title : 골목길
// Link  : https://www.acmicpc.net/problem/1738 
// Time  : 4 ms
// Memory: 2288 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int64_t>> mat(n + 1, vector<int64_t>(n + 1, kInf));
  for (int i = 1; i <= n; i++) mat[i][i] = 0;

  while (m--) {
    int64_t u, v, w;
    cin >> u >> v >> w;
    mat[u][v] = min<int64_t>(mat[u][v], -w);
  }

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j || mat[i][j] == kInf) continue;
      g[j].push_back({i, mat[i][j]});
    }
  }

  for (int k = 1; k < n; k++) {
    for (int i = 1; i <= n; i++) {
      if (mat[i][k] == kInf) continue;
      for (int j = 1; j <= n; j++) {
        if (mat[k][j] == kInf) continue;
        mat[i][j] = min<int64_t>(mat[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }

  if (mat[1][n] == kInf) {
    cout << "-1";
    return 0;
  }

  for (int i = 1; i < n; i++) {
    if (mat[i][i] < 0 && mat[1][i] != kInf && mat[i][n] != kInf) {
      cout << "-1";
      return 0;
    }
  }

  vector<bool> used(n + 1);

  int cur = n;
  vector<int> ans;
  while (cur != 1) {
    used[cur] = true;
    ans.push_back(cur);
    for (auto [nxt, w] : g[cur]) {
      if (used[nxt] || mat[1][cur] != mat[1][nxt] + w) continue;
      cur = nxt;
      break;
    }
  }
  ans.push_back(1);

  for (auto e : views::reverse(ans)) cout << e << " ";

  return 0;
}