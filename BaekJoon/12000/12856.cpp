// Title : 홍준이는 색칠을 좋아해
// Link  : https://www.acmicpc.net/problem/12856 
// Time  : 172 ms
// Memory: 15348 KB

#include <bits/stdc++.h>

using namespace std;

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

struct Node {
  Node() : color(0), sum(0), fail(false) {}
  Node(int x) : color(x), sum(0), fail(false) {}

  int64_t color, sum;
  bool fail;
};

struct Lazy {
  Lazy() : x(0), y(0), add(0) {}
  Lazy(int64_t v) : x(v), y(v), add(0) {}

  constexpr bool operator==(const Lazy& o) const {
    return x == o.x && y == o.y && add == o.add;
  }

  int64_t x, y, add;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.color = (a.color == b.color ? a.color : -1);
    res.sum = a.sum + b.sum;
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    Node res = a;
    if (res.color != -1) {
      res.sum += (b.add + abs(res.color - b.x)) * sz;
      res.color = b.y;
    } else {
      res.fail = true;
    }
    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    if (a == Lazy()) return b;
    if (b == Lazy()) return a;
    Lazy res;
    res.x = a.x;
    res.y = b.y;
    res.add = a.add + abs(a.y - b.x) + b.add;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(n + 1, Node(), Lazy());
  for (int i = 1; i <= n; i++) {
    seg.Set(i, i);
  }
  seg.Build();

  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      seg.Update(l, r, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.Query(l, r).sum << "\n";
    }
  }

  return 0;
}
