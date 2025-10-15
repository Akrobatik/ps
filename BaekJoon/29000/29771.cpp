// Title : 트리 컴포넌트 찾기
// Link  : https://www.acmicpc.net/problem/29771 
// Time  : 332 ms
// Memory: 30596 KB

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

  uint32_t Query(uint32_t u, uint32_t v) {
    if (in[u] ^ in[v]) {
      uint32_t x = asc[u] & asc[v] & -bit_floor((uint32_t)(in[u] ^ in[v]));
      if (asc[u] ^ x) {
        uint32_t k = bit_floor((uint32_t)(asc[u] ^ x));
        u = head[(in[u] & -k) | k];
      }
      if (asc[v] ^ x) {
        uint32_t k = bit_floor((uint32_t)(asc[v] ^ x));
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

  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int idx = -1;
  vector<int> table(n), rev(n), depth(n);
  vector<int64_t> memo(n);
  vector<vector<int>> ng(n);
  [&](this auto&& self, int cur, int par, int d, int64_t s) -> int {
    int co = ++idx;
    s += cur;
    table[cur] = co;
    rev[co] = cur;
    depth[co] = d;
    memo[co] = s;
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      int no = self(nxt, cur, d + 1, s);
      ng[co].push_back(no);
    }
    return co;
  }(0, -1, 0, 0);

  LCA lca;
  lca.Init(ng, 0);

  vector<int> arr, stk, par(n), deg(n);

  int m;
  cin >> m;
  while (m--) {
    int k;
    cin >> k;
    arr.resize(k * 2);
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      arr[i] = table[x];
    }
    sort(arr.begin(), arr.begin() + k);
    arr.back() = lca.Query(arr[0], arr[k - 1]);
    for (int i = 0; i + 1 < k; i++) {
      int u = arr[i], v = arr[i + 1];
      arr[i + k] = lca.Query(u, v);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    stk.clear();
    for (auto e : arr) {
      while (!stk.empty() && stk.back() != lca.Query(stk.back(), e)) stk.pop_back();
      if (!stk.empty()) {
        int p = stk.back();
        par[e] = p, ++deg[p];
      } else {
        par[e] = -1;
      }
      stk.push_back(e);
    }

    int s1 = arr.size();
    int64_t s2 = 0;

    queue<int> q;
    for (auto e : arr) {
      s2 += rev[e];
      if (deg[e]) continue;
      q.push(e);
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      int p = par[cur];
      if (p == -1) continue;

      s1 += depth[cur] - depth[p] - 1;
      s2 += memo[cur] - memo[p] - rev[cur];
      if (--deg[p] == 0) q.push(p);
    }

    cout << s1 << " " << s2 << "\n";
  }

  return 0;
}