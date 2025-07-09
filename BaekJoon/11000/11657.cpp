// Title : 타임머신
// Link  : https://www.acmicpc.net/problem/11657 
// Time  : 88 ms
// Memory: 3080 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = INT_MAX >> 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> dist(n + 1, vector<int>(n + 1, kInf));
  for (int i = 1; i <= n; i++) dist[i][i] = 0;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    dist[u][v] = min<int>(dist[u][v], w);
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      if (dist[i][k] == kInf) continue;
      for (int j = 1; j <= n; j++) {
        if (dist[k][j] == kInf) continue;
        dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dist[i][i] < 0 && dist[1][i] < kInf) {
      cout << "-1";
      return 0;
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << (dist[1][i] != kInf ? dist[1][i] : -1) << "\n";
  }

  return 0;
}
