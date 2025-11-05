// Title : KSA 수열과 쿼리
// Link  : https://www.acmicpc.net/problem/33494 
// Time  : 8 ms
// Memory: 5396 KB

#include <bits/stdc++.h>

using namespace std;

namespace s1 {
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

int kMod;

// using Node = int64_t;
struct Node {
  Node() : cnt{} {}
  Node(int x) : cnt{} { ++cnt[x]; }

  int cnt[100];
};

using Lazy = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    for (int i = 0; i < kMod; i++) {
      res.cnt[i] = a.cnt[i] + b.cnt[i];
    }
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    Node res;
    for (int i = 0; i < kMod; i++) {
      int j = (i + b) % kMod;
      res.cnt[j] = a.cnt[i];
    }
    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return a + b;
  }
};

void Solve(int n, int k) {
  kMod = k;

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(n + 1, Node(), 0);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    seg.Set(i, x % kMod);
  }
  seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int cmd, l, r;
    cin >> cmd >> l >> r;
    if (cmd == 1) {
      seg.Update(l, r, 1);
    } else {
      auto res = seg.Query(l, r);
      int64_t sum = 0;
      for (int i = 1; i < kMod; i++) {
        sum += (int64_t)i * res.cnt[i];
      }
      cout << sum << "\n";
    }
  }
}
};  // namespace s1

namespace s2 {
// https://github.com/Akrobatik/ps/blob/main/template/lazy_segment_tree.cpp
template <typename V, typename L, typename OP, typename APPLY, typename COMPO>
  requires requires(V va, V vb, L la, L lb, int sz) {
    { OP{}(va, vb) } -> convertible_to<V>;
    { APPLY{}(va, la, sz) } -> convertible_to<V>;
    { COMPO{}(la, lb) } -> convertible_to<L>;
    { la == lb } -> convertible_to<bool>;
    { va.fail } -> convertible_to<bool>;
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
    if (node < nmax) {
      lazy[node] = COMPO{}(lazy[node], lzy);
      if (tree[node].fail) Push(node), Pull(node);
    }
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

int kMod;

struct Node {
  Node() : minn(0), maxx(0), sum(0), fail(false) {}
  Node(int64_t x) : minn(x), maxx(x), sum(x), fail(false) {}

  int64_t minn, maxx, sum;
  bool fail;
};

using Lazy = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.minn = min<int64_t>(a.minn, b.minn);
    res.maxx = max<int64_t>(a.maxx, b.maxx);
    res.sum = a.sum + b.sum;
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    Node res = a;
    if (res.minn == res.maxx) {
      int64_t val = (a.minn + b) % kMod;
      res.minn = res.maxx = val;
      res.sum = val * sz;
    } else if (res.maxx + b < kMod) {
      res.minn += b;
      res.maxx += b;
      res.sum += (int64_t)b * sz;
    } else {
      res.fail = true;
    }
    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return a + b;
  }
};

void Solve(int n, int k) {
  kMod = k;

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(n + 1, Node(), 0);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    seg.Set(i, x % kMod);
  }
  seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int cmd, l, r;
    cin >> cmd >> l >> r;
    if (cmd == 1) {
      seg.Update(l, r, 1);
    } else {
      cout << seg.Query(l, r).sum << "\n";
    }
  }
}
};  // namespace s2

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  if (k <= 100) {
    s1::Solve(n, k);
  } else {
    s2::Solve(n, k);
  }

  return 0;
}