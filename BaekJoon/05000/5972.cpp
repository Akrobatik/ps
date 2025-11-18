// Title : 택배 배송
// Link  : https://www.acmicpc.net/problem/5972 
// Time  : 24 ms
// Memory: 5536 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> g(n + 1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(n + 1, INT_MAX);

  auto Push = [&](int x, int d) {
    if (dist[x] <= d) return;
    dist[x] = d;
    pq.push({d, x});
  };

  Push(1, 0);
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();

    if (dist[cur] != d) continue;
    if (cur == n) break;

    for (auto [nxt, w] : g[cur]) {
      Push(nxt, d + w);
    }
  }
  cout << dist[n];

  return 0;
}