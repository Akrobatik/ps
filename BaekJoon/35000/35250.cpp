// Title : Last Orders
// Link  : https://www.acmicpc.net/problem/35250 
// Time  : 40 ms
// Memory: 2552 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int bnd;
  cin >> bnd;

  vector<int> arr(bnd);
  for (auto& e : arr) cin >> e;

  int n;
  cin >> n;

  vector<int> out(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> out[i];
  }

  int m;
  cin >> m;

  vector<vector<int>> dist(n + 1, vector<int>(n + 1, kInf));
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    dist[u][v] = dist[v][u] = min<int>(dist[u][v], w);
  }
  for (int i = 0; i <= n; i++) dist[i][i] = 0;
  dist[0][1] = 0;

  for (int k = 0; k <= n; k++) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  vector<vector<int>> memo(bnd + 1, vector<int>(n + 1, kInf));
  memo[0][0] = 0;

  for (int i = 0; i < bnd; i++) {
    for (int j = 0; j <= n; j++) {
      int cur = memo[i][j];
      if (cur == kInf) continue;
      cur += arr[i];
      for (int k = 0; k <= n; k++) {
        if (j == k) continue;
        int dst = cur + dist[j][k];
        if (dst > out[k]) continue;
        memo[i + 1][k] = min<int>(memo[i + 1][k], dst);
      }
    }
  }

  auto Check = [&](int x) {
    return any_of(memo[x].begin(), memo[x].end(),
                  [](int v) { return v != kInf; });
  };

  int ans = bnd;
  while (ans && !Check(ans)) --ans;
  cout << ans;

  return 0;
}