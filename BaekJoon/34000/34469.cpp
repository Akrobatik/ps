// Title : Floor is Lava
// Link  : https://www.acmicpc.net/problem/34469 
// Time  : 188 ms
// Memory: 29584 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({w, i});
    g[v].push_back({w, i});
  }

  vector<vector<pair<int, int>>> ng(m + 1);
  for (int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
    for (int j = 1; j < g[i].size(); j++) {
      auto [w1, u] = g[i][j - 1];
      auto [w2, v] = g[i][j];
      int w = w2 - w1;
      ng[u].push_back({v, w});
      ng[v].push_back({u, w});
    }
  }
  for (auto [w, v] : g[n]) {
    ng[v].push_back({0, 0});
  }

  vector<int64_t> dist(m + 1, kInf);
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;

  auto Push = [&](int x, int64_t d) {
    if (dist[x] <= d) return;
    dist[x] = d;
    pq.push({d, x});
  };

  for (auto [w, v] : g[1]) {
    Push(v, w);
  }

  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();

    if (dist[cur] != d) continue;
    if (cur == 0) break;

    for (auto [nxt, w] : ng[cur]) {
      Push(nxt, d + w);
    }
  }
  cout << dist[0];

  return 0;
}