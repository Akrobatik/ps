// Title : Unravel the Graph
// Link  : https://www.acmicpc.net/problem/34153 
// Time  : 144 ms
// Memory: 4004 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int64_t>> dist(n + 1, vector<int64_t>(n + 1, INT64_MAX >> 1));
  for (int i = 1; i <= n; i++) dist[i][i] = 0;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    int64_t ww = min<int64_t>(dist[u][v], w);
    dist[u][v] = dist[v][u] = ww;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min<int64_t>(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int64_t maxx = 0;
  int base;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (maxx <= dist[i][j]) {
        maxx = dist[i][j];
        base = i;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[base][i] << " ";
  }

  return 0;
}