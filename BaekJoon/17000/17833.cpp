// Title : 홍익대학교 지하캠퍼스
// Link  : https://www.acmicpc.net/problem/17833 
// Time  : 68 ms
// Memory: 50100 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r, d, m;
  cin >> n >> r >> d >> m;

  vector<vector<int>> mat(n + 1, vector<int>(n + 1, INT_MAX));
  while (m--) {
    int h, t, e1, e2;
    cin >> h >> t >> e1 >> e2;
    if (e1 > e2) swap(e1, e2);
    int dt = e2 - e1;
    int mg = h - e2;

    for (int u = e1; u + dt + mg <= n; u++) {
      int v = u + dt;
      mat[u][v] = min<int>(mat[u][v], t);
    }
  }

  vector<vector<pair<int, int>>> g(n + 1);
  for (int u = 1; u <= n; u++) {
    for (int v = u + 1; v <= n; v++) {
      if (mat[u][v] == INT_MAX) continue;
      g[u].push_back({v, mat[u][v]});
      g[v].push_back({u, mat[u][v]});
    }
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(n + 1, INT_MAX);

  auto Push = [&](int x, int ds) {
    if (dist[x] <= ds) return;
    dist[x] = ds;
    pq.push({ds, x});
  };

  Push(r, 0);
  while (!pq.empty()) {
    auto [ds, cur] = pq.top();
    pq.pop();

    if (dist[cur] != ds) continue;
    if (cur == d) break;

    for (auto [nxt, w] : g[cur]) {
      Push(nxt, ds + w);
    }
  }
  cout << (dist[d] != INT_MAX ? dist[d] : -1);

  return 0;
}