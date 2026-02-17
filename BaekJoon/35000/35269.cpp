// Title : 벽력일섬
// Link  : https://www.acmicpc.net/problem/35269 
// Time  : 776 ms
// Memory: 64464 KB

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

  int WalkL(int x) {
    int node = 1;
    Push(node);
    while (node < nmax) {
      int lnode = node << 1, rnode = lnode + 1;
      Push(lnode), Push(rnode);
      if (x <= tree[lnode].maxx) {
        node = lnode;
      } else {
        node = rnode;
      }
    }
    return node - nmax;
  }

  int WalkR(int x) {
    int node = 1;
    Push(node);
    while (node < nmax) {
      int lnode = node << 1, rnode = lnode + 1;
      Push(lnode), Push(rnode);
      if (tree[rnode].minn <= x) {
        node = rnode;
      } else {
        node = lnode;
      }
    }
    return node - nmax;
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

struct Node {
  Node() : minn(INT_MAX), maxx(INT_MIN) {}
  Node(int x) : minn(x), maxx(x) {}

  int minn, maxx;
};

using Lazy = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.minn = min<int>(a.minn, b.minn);
    res.maxx = max<int>(a.maxx, b.maxx);
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    Node res;
    res.minn = max<int>(a.minn - b, 0);
    res.maxx = max<int>(a.maxx - b, 0);
    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return a + b;
  }
};

// https://github.com/Akrobatik/ps/blob/main/template/segment_tree.cpp
template <typename V, typename OP>
  requires requires(V a, V b) {
    { OP{}(a, b) } -> convertible_to<V>;
  }
struct SegTree {
  void Init(int n, const V& ival) {
    nmax = bit_ceil((uint32_t)n);
    iv = ival;
    tree.assign(nmax << 1, iv);
  }

  void Set(int idx, const V& val) {
    tree[idx + nmax] = val;
  }

  void Build() {
    for (int i = nmax - 1; i > 0; i--) {
      tree[i] = OP{}(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  void Update(int idx, const V& val) {
    int node = idx + nmax;
    tree[node] = val;
    while (node >>= 1) {
      tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
    }
  }

  V Query(int idx) const {
    return tree[idx + nmax];
  }

  V Query(int l, int r) const {
    V lv = iv, rv = iv;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lv = OP{}(lv, tree[l++]);
      if (r & 1) rv = OP{}(tree[--r], rv);
    }
    return OP{}(lv, rv);
  }

 private:
  int nmax;
  V iv;
  vector<V> tree;
};

constexpr pair<int, int> kDelta[] = {
    {1, 0}, {0, 1}};

constexpr int kMax = 3e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 2>> arr(n);
  for (auto& e : arr) cin >> e[0];
  for (auto& e : arr) cin >> e[1];

  vector<int> cnt(kMax + 1);
  for (auto& e : arr) ++cnt[e[0]], ++cnt[e[1]];

  vector<vector<pair<int, int>>> qry(kMax + 1), upd(kMax + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (auto [dy, dx] : kDelta) {
        int y = i + dy, x = j + dx;
        if (!(0 <= y && y < n && 0 <= x && x < 2)) continue;

        int u = arr[i][j], v = arr[y][x];
        if (u > v) swap(u, v);
        upd[v].push_back({u, -1});
      }
    }
  }

  for (int i = 1; i < n; i++) {
    int minn = min<int>({arr[i - 1][0], arr[i - 1][1], arr[i][0], arr[i][1]});
    int maxx = max<int>({arr[i - 1][0], arr[i - 1][1], arr[i][0], arr[i][1]});
    upd[maxx].push_back({minn, 1});
  }

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(kMax + 1, Node(), 0);
  for (int i = 0; i <= kMax; i++) {
    seg.Set(i, Node(i));
  }
  seg.Build();

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l = seg.WalkL(l), r = seg.WalkR(r);
    if (l > r) continue;
    seg.Update(l, r, 1);
    qry[r].push_back({l, i});
  }

  SegTree<int, plus<int>> sg;
  sg.Init(kMax + 1, 0);
  for (int i = 0; i <= kMax; i++) {
    sg.Set(i, cnt[i]);
  }
  sg.Build();

  vector<int> ans(m);
  for (int i = 0; i <= kMax; i++) {
    for (auto [a, b] : upd[i]) {
      sg.Update(a, sg.Query(a) + b);
    }
    for (auto [a, b] : qry[i]) {
      ans[b] = sg.Query(a, i);
    }
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}