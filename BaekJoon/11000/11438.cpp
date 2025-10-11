// Title : LCA 2
// Link  : https://www.acmicpc.net/problem/11438 
// Time  : 64 ms
// Memory: 15816 KB

#include <bits/stdc++.h>

using namespace std;

struct LCA {
  void Init(const vector<vector<int>>& g, int rt) {
    int n = g.size();
    ord.resize(n + 1);
    par.resize(n + 1);
    asc.resize(n + 1);
    dep.resize(n + 1);
    in.resize(n + 1);
    head.resize(n + 1);

    int idx = 0;
    auto DFS = [&](auto&& self, int u) -> void {
      int cur = ++idx;
      ord[idx] = u;
      in[u] = cur;
      for (auto v : g[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        self(self, v);
        head[in[v]] = u;
        if ((in[u] & -in[u]) < (in[v] & -in[v])) in[u] = in[v];
      }
    };

    par[rt] = asc[rt] = dep[rt] = head[rt] = 0;
    DFS(DFS, rt);

    for (int i = 1; i <= idx; i++) {
      int u = ord[i], p = par[u];
      asc[u] = asc[p] | (in[u] & -in[u]);
    }
  }

  int Query(int u, int v) {
    if (in[u] ^ in[v]) {
      int x = asc[u] & asc[v] & -bit_floor((uint32_t)(in[u] ^ in[v]));
      if (asc[u] ^ x) {
        int k = bit_floor((uint32_t)(asc[u] ^ x));
        u = head[(in[u] & -k) | k];
      }
      if (asc[v] ^ x) {
        int k = bit_floor((uint32_t)(asc[v] ^ x));
        v = head[(in[v] & -k) | k];
      }
    }
    return dep[u] < dep[v] ? u : v;
  }

 private:
  vector<int> ord, par, asc, dep, in, head;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  LCA lca;
  lca.Init(g, 1);

  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    cout << lca.Query(u, v) << "\n";
  }

  return 0;
}