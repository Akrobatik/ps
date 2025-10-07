// Title : 어떤 우유의 배달목록 (Easy)
// Link  : https://www.acmicpc.net/problem/23835 
// Time  : 0 ms
// Memory: 2284 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1000;

vector<int> g[kMax + 1];
int parent[kMax + 1][10], depth[kMax + 1], cnt[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  [&](this auto&& self, int cur, int par, int d) -> void {
    parent[cur][0] = par;
    depth[cur] = d;
    for (int i = 1, p = par; i < 10 && parent[p][i - 1]; i++) {
      p = parent[cur][i] = parent[p][i - 1];
    }

    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur, d + 1);
    }
  }(1, 0, 0);

  auto LCA = [&](int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    uint32_t delta = depth[v] - depth[u];
    while (delta) {
      uint32_t lsb = delta & -delta;
      delta ^= lsb;
      v = parent[v][countr_zero(lsb)];
    }
    if (u == v) return u;

    int idx = bit_width((uint32_t)depth[u]);
    while (idx--) {
      int pu = parent[u][idx], pv = parent[v][idx];
      if (pu != pv) u = pu, v = pv;
    }
    return parent[u][0];
  };

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int u, v;
      cin >> u >> v;
      int lca = LCA(u, v);
      int add = 0;
      while (u != lca) cnt[u] += add++, u = parent[u][0];
      cnt[lca] += add;
      add += depth[v] - depth[lca];
      while (v != lca) cnt[v] += add--, v = parent[v][0];
    } else {
      int x;
      cin >> x;
      cout << cnt[x] << "\n";
    }
  }

  return 0;
}