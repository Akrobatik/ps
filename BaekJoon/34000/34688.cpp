// Title : A Graph of Fire and Ice (Easy)
// Link  : https://www.acmicpc.net/problem/34688 
// Time  : 0 ms
// Memory: 2088 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> adj(m);
  for (auto& [w, u, v] : adj) cin >> u >> v >> w;
  sort(adj.begin(), adj.end(), greater<tuple<int, int, int>>());

  int ng;
  vector<int> memo, color;

  auto Find = [&](this auto&& self, int id) -> pair<int, int> {
    if (memo[id] == id) return {id, 0};
    auto [par, col] = self(memo[id]);
    return {memo[id] = par, color[id] ^= col};
  };

  auto Union = [&](int a, int b, int t) -> bool {
    auto [pa, ca] = Find(a);
    auto [pb, cb] = Find(b);
    if (pa == pb) return (ca ^ cb ^ t) == 0;
    memo[pb] = pa;
    color[pb] = ca ^ cb ^ t;
    --ng;
    return true;
  };

  int minn = INT_MAX;
  for (int mask = 0; mask <= m; mask++) {
    ng = n;
    memo.resize(n + 1);
    iota(memo.begin(), memo.end(), 0);
    color.assign(n + 1, 0);

    int cnt = 0;
    for (int i = 0; i < m; i++) {
      auto [w, u, v] = adj[i];
      if (Union(u, v, i != mask)) continue;
      cnt = m - i;
      break;
    }
    if (ng == 1) minn = min<int>(minn, cnt);
  }
  cout << (minn != INT_MAX ? minn : -1);

  return 0;
}