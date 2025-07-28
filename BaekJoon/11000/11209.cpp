// Title : Intercept
// Link  : https://www.acmicpc.net/problem/11209 
// Time  : 36 ms
// Memory: 7356 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  int st, en;
  cin >> st >> en;

  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
  vector<int64_t> dist(n, INT64_MAX >> 1);

  auto Push = [&](int x, int64_t d) {
    if (dist[x] <= d) return;
    dist[x] = d;
    pq.push({d, x});
  };

  Push(st, 0);
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();

    if (d != dist[cur]) continue;
    if (cur == en) break;

    for (auto [nxt, w] : edges[cur]) {
      Push(nxt, d + w);
    }
  }
  while (!pq.empty()) pq.pop();

  vector<bool> visited(n);

  auto PushQ = [&](int x, int64_t d) {
    if (dist[en] - dist[x] != d || visited[x]) return;
    visited[x] = true;
    pq.push({d, x});
  };

  vector<int> ans;

  PushQ(en, 0);
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();

    if (pq.empty()) ans.push_back(cur);

    for (auto [nxt, w] : edges[cur]) {
      PushQ(nxt, d + w);
    }
  }

  sort(ans.begin(), ans.end());
  for (auto e : ans) cout << e << " ";

  return 0;
}
