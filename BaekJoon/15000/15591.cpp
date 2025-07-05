// Title : MooTube (Silver)
// Link  : https://www.acmicpc.net/problem/15591 
// Time  : 172 ms
// Memory: 2420 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[5001];

int Count(int cur, int par, int limit) {
  int cnt = 1;
  for (auto [nxt, w] : edges[cur]) {
    if (w < limit) break;
    if (nxt == par) continue;
    cnt += Count(nxt, cur, limit);
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  for (int i = 1; i <= n; i++) {
    sort(edges[i].begin(), edges[i].end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.second > rhs.second;
    });
  }

  while (q--) {
    int k, v;
    cin >> k >> v;
    cout << Count(v, 0, k) - 1 << "\n";
  }

  return 0;
}
