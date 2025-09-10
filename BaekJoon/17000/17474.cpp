// Title : 수열과 쿼리 26
// Link  : https://www.acmicpc.net/problem/17474 
// Time  : 1668 ms
// Memory: 67580 KB

#include <bits/stdc++.h>

using namespace std;

template <typename V, typename L, typename OP, typename APPLY, typename COMPO>
  requires requires(V va, V vb, L la, L lb, int sz) {
    { OP{}(va, vb) } -> convertible_to<V>;
    { APPLY{}(va, la, sz) } -> convertible_to<V>;
    { COMPO{}(la, lb) } -> convertible_to<L>;
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
    Apply(node << 1, lazy[node]);
    Apply(node << 1 | 1, lazy[node]);
    lazy[node] = il;
  }

  void Pull(int node) {
    tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
  }
};

struct Node {
  Node() : sum(0), max1(-1), max2(-1), maxc(0), fail(false) {}
  Node(int v) : sum(v), max1(v), max2(-1), maxc(1), fail(false) {}

  int64_t sum;
  int max1, max2, maxc;
  bool fail;
};

using Lazy = int;

struct FOp {
  Node operator()(const Node& lhs, const Node& rhs) const {
    Node res;
    res.sum = lhs.sum + rhs.sum;
    if (lhs.max1 > rhs.max1) {
      res.max1 = lhs.max1;
      res.max2 = max<int>(lhs.max2, rhs.max1);
      res.maxc = lhs.maxc;
    } else if (lhs.max1 < rhs.max1) {
      res.max1 = rhs.max1;
      res.max2 = max<int>(rhs.max2, lhs.max1);
      res.maxc = rhs.maxc;
    } else {
      res.max1 = lhs.max1;
      res.max2 = max<int>(lhs.max2, rhs.max2);
      res.maxc = lhs.maxc + rhs.maxc;
    }
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    if (a.max1 <= b) return a;

    Node res = a;
    if (a.max2 < b) {
      res.sum -= (int64_t)(a.max1 - b) * a.maxc;
      res.max1 = b;
    } else {
      res.fail = true;
    }
    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return min<int>(a, b);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(n + 1, Node(), INT_MAX);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    seg.Set(i, x);
  }
  seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      seg.Update(l, r, v);
    } else if (cmd == 2) {
      int l, r;
      cin >> l >> r;
      cout << seg.Query(l, r).max1 << "\n";
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.Query(l, r).sum << "\n";
    }
  }

  return 0;
}
