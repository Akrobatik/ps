// Title : 더치페이
// Link  : https://www.acmicpc.net/problem/21725 
// Time  : 132 ms
// Memory: 19228 KB

#include <bits/stdc++.h>

using namespace std;

// https://github.com/Akrobatik/ps/blob/main/template/lazy_segment_tree.cpp
template <typename V, typename L, typename OP, typename APPLY, typename COMPO>
  requires requires(V va, V vb, L la, L lb, int sz) {
    { OP{}(va, vb) } -> convertible_to<V>;
    { APPLY{}(va, la, sz) } -> convertible_to<V>;
    { COMPO{}(la, lb) } -> convertible_to<L>;
    { la == lb } -> convertible_to<bool>;
  }
struct LazySegTree {
  void Init(int n, const V& ival, const L& ilzy) {
    nmax = bit_ceil((uint32_t)n);
    nlog = countr_zero((uint32_t)nmax);
    iv = ival, il = ilzy;
    tree.assign(nmax << 1, iv);
    lazy.assign(nmax << 1, il);
    sz.resize(nmax << 1);
    sz[1] = nmax;
    for (int i = 1; i < nmax; i++) {
      sz[i << 1] = sz[i << 1 | 1] = sz[i] >> 1;
    }
  }

  void Set(int idx, const V& val) {
    tree[idx + nmax] = val;
  }

  void Build() {
    for (int i = nmax - 1; i > 0; i--) {
      tree[i] = OP{}(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  void Update(int l, int r, const L& lzy) {
    l += nmax, r += nmax + 1;
    for (int i = nlog; i > 0; i--) {
      if (Check(l, i)) Push(l >> i);
      if (Check(r, i)) Push((r - 1) >> i);
    }

    for (int ll = l, rr = r; ll < rr; ll >>= 1, rr >>= 1) {
      if (ll & 1) Apply(ll++, lzy);
      if (rr & 1) Apply(--rr, lzy);
    }

    for (int i = 1; i <= nlog; i++) {
      if (Check(l, i)) Pull(l >> i);
      if (Check(r, i)) Pull((r - 1) >> i);
    }
  }

  V Query(int idx) {
    int node = idx + nmax;
    for (int i = nlog; i > 0; i--) Push(node >> i);
    return tree[node];
  }

  V Query(int l, int r) {
    V lv = iv, rv = iv;

    l += nmax, r += nmax + 1;
    for (int i = nlog; i > 0; i--) {
      if (Check(l, i)) Push(l >> i);
      if (Check(r, i)) Push((r - 1) >> i);
    }

    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lv = OP{}(lv, tree[l++]);
      if (r & 1) rv = OP{}(tree[--r], rv);
    }
    return OP{}(lv, rv);
  }

  vector<int64_t> PushAll(int l, int r) {
    for (int i = 1; i < nmax; i++) {
      Push(i);
    }

    vector<int64_t> res(r - l + 1);
    for (int i = l; i <= r; i++) {
      res[i - l] = tree[i + nmax];
    }
    return res;
  }

 private:
  int nmax, nlog;
  V iv;
  L il;
  vector<V> tree;
  vector<L> lazy;
  vector<int> sz;

  bool Check(int x, int shift) {
    int y = (x >> shift) << shift;
    return x != y;
  }

  void Apply(int node, const L& lzy) {
    tree[node] = APPLY{}(tree[node], lzy, sz[node]);
    if (node < nmax) lazy[node] = COMPO{}(lazy[node], lzy);
  }

  void Push(int node) {
    if (lazy[node] == il) return;
    Apply(node << 1, lazy[node]);
    Apply(node << 1 | 1, lazy[node]);
    lazy[node] = il;
  }

  void Pull(int node) {
    tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
  }
};

using Node = int64_t;
using Lazy = int64_t;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return a + b;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    return a + b * sz;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return a + b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<tuple<int, int, int>> qr(q);
  for (auto& [cmd, a, b] : qr) cin >> cmd >> a >> b;

  vector<int> ord = [&]() {
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
      g[i].push_back(i);
    }

    vector<int> memo(n + 1);
    iota(memo.begin(), memo.end(), 0);

    auto Find = [&](int id) {
      while (id != memo[id]) {
        int par = memo[id];
        id = memo[id] = memo[par];
      }
      return id;
    };

    auto Union = [&](int a, int b) {
      a = Find(a), b = Find(b);
      if (a == b) return;
      if (g[a].size() < g[b].size()) swap(a, b);
      memo[b] = a;
      int old = g[a].size();
      g[a].resize(old + g[b].size());
      copy(g[b].begin(), g[b].end(), g[a].begin() + old);
      g[b] = vector<int>();
    };

    for (auto [cmd, a, b] : qr) {
      if (cmd == 1) Union(a, b);
    }

    int rep = Find(1);
    vector<int> res(n + 1);
    for (int i = 0; i < n; i++) {
      res[g[rep][i]] = i;
    }
    return res;
  }();

  vector<int> memo(n + 1);
  iota(memo.begin(), memo.end(), 0);

  vector<int> minn(n + 1), maxx(n + 1);
  for (int i = 1; i <= n; i++) {
    minn[i] = maxx[i] = ord[i];
  }

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    memo[b] = a;
    minn[a] = min<int>(minn[a], minn[b]);
    maxx[a] = max<int>(maxx[a], maxx[b]);
  };

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(n, 0, 0);

  for (auto [cmd, a, b] : qr) {
    if (cmd == 1) {
      Union(a, b);
    } else {
      int id = Find(a);
      int mn = minn[id], mx = maxx[id];
      int sz = mx - mn + 1;
      seg.Update(ord[a], ord[a], -b);
      seg.Update(mn, mx, b / sz);
    }
  }

  auto res = seg.PushAll(0, n - 1);
  vector<pair<int, int64_t>> axr, bxr;
  for (int i = 1; i <= n; i++) {
    int o = ord[i];
    if (res[o] > 0) {
      axr.push_back({i, res[o]});
    } else if (res[o] < 0) {
      bxr.push_back({i, -res[o]});
    }
  }

  vector<tuple<int, int, int64_t>> ans;
  while (!axr.empty() && !bxr.empty()) {
    auto [ai, av] = axr.back();
    axr.pop_back();

    auto [bi, bv] = bxr.back();
    bxr.pop_back();

    int64_t cut = min<int64_t>(av, bv);
    ans.push_back({ai, bi, cut});
    if ((av -= cut) > 0) axr.push_back({ai, av});
    if ((bv -= cut) > 0) bxr.push_back({bi, bv});
  }

  cout << ans.size() << "\n";
  for (auto [a, b, c] : ans) cout << a << " " << b << " " << c << "\n";

  return 0;
}