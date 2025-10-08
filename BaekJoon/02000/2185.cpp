// Title : 직사각형의 합집합
// Link  : https://www.acmicpc.net/problem/2185 
// Time  : 320 ms
// Memory: 4612 KB

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
  Node() : sz(0), sum(0), val(0), fwd(0), bwd(0), fail(false) {}

  int sz, sum, val, fwd, bwd;
  bool fail;
};

using Lazy = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.sz = a.sz + b.sz;
    res.sum = a.sum + b.sum - (a.bwd && b.fwd ? 2 : 0);
    res.val = 0;
    res.fwd = a.fwd;
    res.bwd = b.bwd;
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    if (b == 0) return a;

    Node res = a;
    res.val += b;
    if (res.val > 0) {
      res.sz = sz;
      res.sum = 2;
      res.fwd = res.bwd = 1;
    } else if (sz == 1) {
      res.sz = 0;
      res.sum = 0;
      res.fwd = res.bwd = 0;
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

constexpr int kPad = 10000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<array<int, 4>> qr[2];
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int minx = min<int>(x1, x2) + kPad, maxx = max<int>(x1, x2) + kPad;
    int miny = min<int>(y1, y2) + kPad, maxy = max<int>(y1, y2) + kPad;

    qr[0].push_back({minx, miny + 1, maxy, -1});
    qr[0].push_back({maxx, miny + 1, maxy, 1});
    qr[1].push_back({miny, minx + 1, maxx, -1});
    qr[1].push_back({maxy, minx + 1, maxx, 1});
  }

  int64_t ans = 0;
  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  for (int t = 0; t < 2; t++) {
    sort(qr[t].begin(), qr[t].end());

    seg.Init(20001, Node(), 0);

    int idx = 0, m = n << 1;
    while (idx < m) {
      int cx = get<0>(qr[t][idx]);
      while (idx < m && get<0>(qr[t][idx]) == cx) {
        auto [x, y1, y2, d] = qr[t][idx++];
        seg.Update(y1, y2, -d);
      }

      int dx = (idx < m ? get<0>(qr[t][idx]) - cx : 0);
      ans += dx * seg.Query(0, 20000).sum;
    }
  }
  cout << ans;

  return 0;
}