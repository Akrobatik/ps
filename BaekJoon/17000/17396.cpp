// Title : 백도어
// Link  : https://www.acmicpc.net/problem/17396 
// Time  : 132 ms
// Memory: 15972 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> check(n);
  for (auto& e : check) cin >> e;
  check[n - 1] = 0;

  vector<vector<pair<int, int>>> edges(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  vector<int64_t> memo(n, INT64_MAX >> 1);
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;

  auto Push = [&](int v, int64_t d) {
    if (check[v] || memo[v] <= d) return;
    memo[v] = d;
    pq.push({d, v});
  };

  Push(0, 0);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (memo[u] != d) continue;

    if (u == n - 1) {
      cout << d;
      return 0;
    }

    for (auto [v, w] : edges[u]) {
      Push(v, d + w);
    }
  }
  cout << "-1";

  return 0;
}
