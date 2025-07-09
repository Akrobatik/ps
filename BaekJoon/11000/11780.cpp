// Title : 플로이드 2
// Link  : https://www.acmicpc.net/problem/11780 
// Time  : 28 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = INT_MAX >> 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> dist(n + 1, vector<int>(n + 1, kInf));
  vector<vector<int>> memo(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    dist[u][v] = min<int>(dist[u][v], w);
    memo[u][v] = v;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      if (dist[i][k] == kInf) continue;
      for (int j = 1; j <= n; j++) {
        if (dist[k][j] == kInf) continue;
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          memo[i][j] = memo[i][k];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << (dist[i][j] != kInf ? dist[i][j] : 0) << " ";
    }
    cout << "\n";
  }

  vector<int> path;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (memo[i][j] == 0) {
        cout << "0\n";
        continue;
      }

      int cur = i;
      while (cur != j) {
        path.push_back(cur);
        cur = memo[cur][j];
      }
      path.push_back(cur);

      cout << path.size() << " ";
      for (auto e : path) cout << e << " ";
      cout << "\n";
      path.clear();
    }
  }

  return 0;
}
