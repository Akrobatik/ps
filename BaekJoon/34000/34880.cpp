// Title : 두 번째로 큰 수
// Link  : https://www.acmicpc.net/problem/34880 
// Time  : 10744 ms
// Memory: 14004 KB

#include <bits/stdc++.h>

using namespace std;

// #define DEBUG

struct Intr {
#ifdef DEBUG
  Intr() : gen(random_device{}()) {}
#endif

  void Init(int _n, int _q) {
#ifdef DEBUG
    assert(2 <= _n && _n <= 50000);
    assert(2 <= _q && _q <= 50000);

    n = _n, q = _q, qc = n * 2 + q;
    arr.resize(n + 1);
    iota(arr.begin(), arr.end(), 0);
    shuffle(arr.begin() + 1, arr.end(), gen);
#endif
  }

  pair<int, int> Range() {
#ifdef DEBUG
    assert(--q >= 0);
    l = gen() % n + 1, r = gen() % n + 1;
    while (l == r) r = gen() % n + 1;
    if (l > r) swap(l, r);
    return {l, r};
#else
    int ll, rr;
    cin >> ll >> rr;
    return {ll, rr};
#endif
  }

  char Query(int i, int j) {
#ifdef DEBUG
    assert(i != j);
    assert(1 <= i && i <= n);
    assert(1 <= j && j <= n);
    assert(--qc >= 0);
    return arr[i] < arr[j] ? '<' : '>';
#else
    cout << "? " << i << " " << j << endl;
    char res;
    cin >> res;
    return res;
#endif
  }

  void Submit(int x) {
#ifdef DEBUG
    assert(l <= x && x <= r);
    int cnt = 0;
    for (int i = l; i <= r; i++) {
      cnt += (arr[x] < arr[i]);
    }
    assert(cnt == 1);
#else
    cout << "! " << x << endl;
#endif
  }

#ifdef DEBUG
  mt19937 gen;
  int n, q, l, r, qc;
  vector<int> arr;
#endif
};

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

    par[rt] = asc[rt] = dep[rt] = head[1] = 0;
    DFS(DFS, rt);

    for (int i = 1; i <= idx; i++) {
      int u = ord[i], p = par[u];
      asc[u] = asc[p] | (in[u] & -in[u]);
    }
  }

  uint32_t Query(uint32_t u, uint32_t v) {
    if (in[u] ^ in[v]) {
      uint32_t x = asc[u] & asc[v] & -BitFloor((uint32_t)(in[u] ^ in[v]));
      if (asc[u] ^ x) {
        uint32_t k = BitFloor((uint32_t)(asc[u] ^ x));
        u = head[(in[u] & -k) | k];
      }
      if (asc[v] ^ x) {
        uint32_t k = BitFloor((uint32_t)(asc[v] ^ x));
        v = head[(in[v] & -k) | k];
      }
    }
    return dep[u] < dep[v] ? u : v;
  }

  uint32_t BitFloor(uint32_t x) {
    int bw = 32 - __builtin_clz(x);
    return (1u << bw) >> 1;
  }

 private:
  vector<int> ord, par, asc, dep, in, head;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  Intr intr;
  intr.Init(n, q);

  auto [l, r] = intr.Range();

  vector<array<int, 2>> child(n + 1, {0, 0});
  vector<int> stk;
  for (int i = 1; i <= n; i++) {
    int out = 0;
    while (!stk.empty() && intr.Query(stk.back(), i) == '<') {
      out = stk.back();
      stk.pop_back();
    }

    if (!stk.empty()) child[stk.back()][1] = i;
    if (out) child[i][0] = out;
    stk.push_back(i);
  }

  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    for (auto c : child[i]) {
      if (c) g[i].push_back(c);
    }
  }

  LCA lca;
  lca.Init(g, stk[0]);
  while (q--) {
    int m = lca.Query(l, r);
    int u = (l <= m - 1 ? lca.Query(l, m - 1) : 0);
    int v = (m + 1 <= r ? lca.Query(m + 1, r) : 0);
    int x = (u && v ? (intr.Query(u, v) == '>' ? u : v) : max<int>(u, v));
    intr.Submit(x);

    if (q > 0) tie(l, r) = intr.Range();
  }

  return 0;
}