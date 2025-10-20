// Title : 최소 공통 조상과 쿼리
// Link  : https://www.acmicpc.net/problem/20535 
// Time  : 644 ms
// Memory: 89196 KB

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

  int n, q;
  cin >> n >> q;

  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }

  LCA lca;
  lca.Init(g, 1);

  int idx = 0;
  vector<int> in(n + 1), out(n + 1), dep(n + 1);
  [&](this auto&& self, int cur) -> void {
    in[cur] = ++idx;
    for (auto nxt : g[cur]) {
      dep[nxt] = dep[cur] + 1;
      self(nxt);
    }
    out[cur] = idx;
  }(1);

  vector<int> arr, stk, par(n + 1), deg(n + 1), cnt(n + 1);

  while (q--) {
    int k;
    cin >> k;

    arr.resize(k << 1);
    for (int i = 0; i < k; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.begin() + k, [&](int lhs, int rhs) {
      return in[lhs] < in[rhs];
    });
    arr[k] = lca.Query(arr[0], arr[k - 1]);
    for (int i = 1; i < k; i++) {
      arr[i + k] = lca.Query(arr[i - 1], arr[i]);
    }
    for (int i = (k << 1) - 1; i >= 0; i--) {
      cnt[arr[i]] = (i < k);
    }
    sort(arr.begin(), arr.end(), [&](int lhs, int rhs) {
      return in[lhs] < in[rhs];
    });
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    auto Check = [&](int x, int y) {
      return in[x] <= in[y] && out[y] <= out[x];
    };

    stk.clear();
    for (auto e : arr) {
      while (!stk.empty() && !Check(stk.back(), e)) stk.pop_back();
      if (!stk.empty()) {
        int p = stk.back();
        par[e] = p, ++deg[p];
      } else {
        par[e] = 0;
      }
      stk.push_back(e);
    }

    queue<int> q;
    for (auto e : arr) {
      if (deg[e]) continue;
      q.push(e);
    }

    int64_t sum = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      int p = par[cur];
      if (p == 0) continue;

      sum += (int64_t)dep[p] * cnt[p] * cnt[cur];
      cnt[p] += cnt[cur];
      if (--deg[p] == 0) q.push(p);
    }
    cout << sum << "\n";
  }

  return 0;
}