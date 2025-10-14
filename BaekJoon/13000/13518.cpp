// Title : 트리와 쿼리 9
// Link  : https://www.acmicpc.net/problem/13518 
// Time  : 324 ms
// Memory: 23920 KB

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

using tup = tuple<int, int, int, int>;

constexpr int kMax = 1e6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> val(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  LCA lca;
  lca.Init(g, 1);

  int m = n << 1;
  vector<int> in(n + 1), out(n + 1), arr(m + 1);

  int idx = 0;
  [&](this auto&& self, int cur, int par) -> void {
    arr[in[cur] = ++idx] = cur;
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur);
    }
    arr[out[cur] = ++idx] = cur;
  }(1, 0);

  int q;
  cin >> q;
  vector<tup> qr(q);
  idx = 0;
  for (auto& [l, r, x, i] : qr) {
    int u, v;
    cin >> u >> v;
    if (in[u] > in[v]) swap(u, v);

    x = lca.Query(u, v);
    if (u == x) {
      l = in[u];
      r = in[v];
      x = 0;
    } else {
      l = out[u];
      r = in[v];
    }
    i = idx++;
  }

  int s = sqrt(m) + 1;
  sort(qr.begin(), qr.end(), [&](const tup& lhs, const tup& rhs) {
    auto [ll, lr, lx, lq] = lhs;
    auto [rl, rr, rx, rq] = rhs;
    int ls = ll / s, rs = rl / s;
    return ls < rs || (ls == rs && lr < rr);
  });

  int dup = 0;
  vector<int> tg(n + 1), cnt(kMax + 1);
  cnt[0] = 1;

  auto Push = [&](int i) {
    int x = arr[i], v = val[x];
    if (tg[x] ^= 1) {
      if (cnt[v]++ == 0) ++dup;
    } else {
      if (--cnt[v] == 0) --dup;
    }
  };

  auto Ans = [&](int i) {
    return dup + (cnt[val[i]] == 0);
  };

  vector<int> ans(q);

  auto [l, r, x, qi] = qr[0];
  for (int i = l; i <= r; i++) {
    Push(i);
  }
  ans[qi] = Ans(x);

  for (int i = 1; i < q; i++) {
    auto [ll, rr, xx, qq] = qr[i];
    while (ll < l) Push(--l);
    while (rr > r) Push(++r);
    while (ll > l) Push(l++);
    while (rr < r) Push(r--);
    ans[qq] = Ans(xx);
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}