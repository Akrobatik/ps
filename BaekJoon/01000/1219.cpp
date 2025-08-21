// Title : 오민식의 고민
// Link  : https://www.acmicpc.net/problem/1219 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr int64_t kInf = 1LL << 60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, st, en, m;
  cin >> n >> st >> en >> m;

  vector<tup> edges(m);
  vector<vector<int>> g(n);
  for (auto& [u, v, w] : edges) {
    cin >> u >> v >> w;
    g[u].push_back(v);
  }

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  for (auto& [u, v, w] : edges) w -= arr[v];

  vector<int64_t> dist(n, kInf);
  dist[st] = -arr[st];

  for (int i = 1; i < n; i++) {
    bool pass = true;
    for (auto [u, v, w] : edges) {
      if (dist[u] == kInf || dist[v] <= dist[u] + w) continue;
      dist[v] = dist[u] + w;
      pass = false;
    }
    if (pass) break;
  }

  queue<int> q;
  vector<bool> visited(n);

  auto Push = [&](int x) {
    if (visited[x]) return;
    visited[x] = true;
    q.push(x);
  };

  for (auto [u, v, w] : edges) {
    if (dist[u] == kInf || dist[v] <= dist[u] + w) continue;
    Push(v);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto nxt : g[cur]) {
      Push(nxt);
    }
  }

  if (dist[en] == kInf) {
    cout << "gg";
  } else if (visited[en]) {
    cout << "Gee";
  } else {
    cout << -dist[en];
  }

  return 0;
}