// Title : Ignition
// Link  : https://www.acmicpc.net/problem/13141
// Time  : 44 ms
// Memory: 2416 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = 1 << 29;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n, kInf));
  vector<vector<int>> edges(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    g[i][i] = 0;
  }

  while (m--) {
    int s, e, l;
    cin >> s >> e >> l;
    --s, --e;
    if (g[s][e] > l) g[s][e] = g[e][s] = l;
    if (edges[s][e] < l) edges[s][e] = edges[e][s] = l;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = min<int>(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  int minn = INT_MAX;
  for (int k = 0; k < n; k++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (edges[i][j] == 0) continue;
        cur = max<int>(cur,
                       min<int>({(g[k][i] + edges[i][j]) << 1,
                                 (g[k][j] + edges[i][j]) << 1,
                                 g[k][i] + g[k][j] + edges[i][j]}));
      }
    }
    minn = min<int>(minn, cur);
  }
  cout << (minn >> 1) << ((minn & 1) ? ".5" : ".0");

  return 0;
}
