#include <bits/stdc++.h>

using namespace std;

int memo[10001];
vector<pair<int, int>> edges[10001], r_edges[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    r_edges[v].push_back({u, w});
  }
  int src, dst;
  cin >> src >> dst;

  queue<pair<int, int>> q;
  q.push({src, 0});
  while (!q.empty()) {
    auto [cur, sum] = q.front();
    q.pop();

    for (auto [nxt, w] : edges[cur]) {
      if (memo[nxt] >= sum + w) continue;
      memo[nxt] = sum + w;
      q.push({nxt, sum + w});
    }
  }

  int cnt = 0;
  q.push({dst, memo[dst]});
  while (!q.empty()) {
    auto [cur, sum] = q.front();
    q.pop();

    for (auto& [prv, w] : r_edges[cur]) {
      if (sum == memo[prv] + w) {
        ++cnt;
        q.push({prv, sum - w});
        w = 0;
      }
    }
  }

  cout << memo[dst] << "\n"
       << cnt;

  return 0;
}
