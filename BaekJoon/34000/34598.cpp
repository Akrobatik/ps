// Title : Rim
// Link  : https://www.acmicpc.net/problem/34598 
// Time  : 3044 ms
// Memory: 38120 KB

#pragma GCC optimize("O3")

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

using tup = tuple<int, int, int, int, int>;

constexpr int kInf = 2e9 + 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> val(n << 1), memo;
  vector<vector<int>> g(n << 1);
  for (int i = 1; i < n; i++) {
    int u, v, w, x = n + i;
    cin >> u >> v >> w;
    val[x] = w;
    memo.push_back(w);
    g[u].push_back(x);
    g[v].push_back(x);
    g[x].push_back(u);
    g[x].push_back(v);
  }
  sort(memo.begin(), memo.end());
  memo.erase(unique(memo.begin(), memo.end()), memo.end());

  int nm = memo.size();
  for (int i = 0; i <= n; i++) {
    val[i] = nm;
  }
  for (int i = 1; i < n; i++) {
    val[n + i] = lower_bound(memo.begin(), memo.end(), val[n + i]) - memo.begin();
  }
  memo.push_back(kInf);

  vector<int> in(n << 1), out(n << 1), arr(n << 2);
  int idx = 0;
  [&](this auto&& self, int cur, int par) -> void {
    arr[in[cur] = ++idx] = cur;
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur);
    }
    arr[out[cur] = ++idx] = cur;
  }(1, 0);

  int s = sqrt(nm) + 1;
  vector<int> tg(n << 1), ucnt(nm + 1), bcnt(s + 1), bnxt(s + 1);
  vector<int64_t> usum(nm + 1), bsum(s + 1);

  for (int i = 0; i <= s; i++) {
    bnxt[i] = memo[min<int>((i + 1) * s, nm)];
  }

  auto Push = [&](int i) {
    int x = arr[i], v = val[x], b = v / s;
    if (tg[x] ^= 1) {
      ++ucnt[v], usum[v] += memo[v];
      ++bcnt[b], bsum[b] += memo[v];
    } else {
      --ucnt[v], usum[v] -= memo[v];
      --bcnt[b], bsum[b] -= memo[v];
    }
  };

  auto Ans = [&](int spc, int add) {
    int res = 0;
    int64_t cnt = 0, sum = add;

    int sv = val[spc], sb = sv / s;
    ++ucnt[sv], usum[sv] += memo[sv];
    ++bcnt[sb], bsum[sb] += memo[sv];
    for (int b = 0; b <= s; b++) {
      if (sum + bsum[b] >= (cnt + bcnt[b]) * bnxt[b]) {
        cnt += bcnt[b], sum += bsum[b];
        continue;
      }

      int i = b * s;
      while (i <= nm && sum + usum[i] >= (cnt + ucnt[i]) * memo[i]) cnt += ucnt[i], sum += usum[i], ++i;

      int64_t v = memo[i - 1];
      int64_t rem = sum - v * cnt;
      res = v + rem / cnt;
      break;
    }
    --ucnt[sv], usum[sv] -= memo[sv];
    --bcnt[sb], bsum[sb] -= memo[sv];
    return res;
  };

  LCA lca;
  lca.Init(g, 1);

  vector<tup> qr(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (in[u] > in[v]) swap(u, v);

    int l, r, x = lca.Query(u, v);
    if (u == x) {
      l = in[u];
      r = in[v];
      x = 0;
    } else {
      l = out[u];
      r = in[v];
    }
    qr[i] = {l, r, w, x, i};
  }

  int sq = sqrt(n << 2) + 1;
  sort(qr.begin(), qr.end(), [&](const tup& lhs, const tup& rhs) {
    auto [ll, lr, lw, lx, lq] = lhs;
    auto [rl, rr, rw, rx, rq] = rhs;
    int ls = ll / sq, rs = rl / sq;
    return ls < rs || (ls == rs && lr < rr);
  });

  vector<int> ans(m);

  auto [l, r, w, x, q] = qr[0];
  for (int i = l; i <= r; i++) {
    Push(i);
  }
  ans[q] = Ans(x, w);

  for (int i = 1; i < m; i++) {
    auto [ll, rr, ww, xx, qq] = qr[i];
    while (ll < l) Push(--l);
    while (rr > r) Push(++r);
    while (ll > l) Push(l++);
    while (rr < r) Push(r--);
    ans[qq] = Ans(xx, ww);
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}