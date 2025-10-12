// Title : Bombončići
// Link  : https://www.acmicpc.net/problem/34615 
// Time  : 1196 ms
// Memory: 111608 KB

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
  Node() : cnt{}, sum{} {}
  Node(uint32_t x) : Node() {
    int crz = countr_zero(x);
    ++cnt[crz];
    sum[crz] += x;
  }

  uint32_t cnt[26];
  uint64_t sum[26];
};

struct Lazy {
  Lazy() : cnt(0), val{} {}
  Lazy(uint32_t x) : cnt(1), val{1, x} {}

  constexpr bool operator==(const Lazy& other) const {
    return cnt == other.cnt;
  }

  uint32_t cnt;
  uint32_t val[27];
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    for (int i = 0; i <= 25; i++) {
      res.cnt[i] = a.cnt[i] + b.cnt[i];
      res.sum[i] = a.sum[i] + b.sum[i];
    }
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    int s = b.cnt;
    Node res;
    for (int i = s; i <= 25; i++) {
      if (a.cnt[i] == 0) continue;
      res.cnt[i - s] = a.cnt[i];
      res.sum[i - s] = (a.sum[i] >> s);
    }

    for (int i = 0; i < s; i++) {
      if (a.cnt[i] == 0) continue;
      uint64_t x = b.val[i + 1];
      uint32_t j = countr_zero(x);
      res.cnt[j] += a.cnt[i];
      res.sum[j] += x * a.cnt[i];
    }

    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    if (a.cnt == 0) return b;

    Lazy res;
    res.cnt = min<int>(a.cnt + b.cnt, 26);
    for (int i = 1; i <= a.cnt; i++) {
      int j = countr_zero(a.val[i]);
      res.val[i] = (b.cnt <= j ? (a.val[i] >> j) : b.val[j + 1]);
    }

    for (int i = a.cnt + 1; i <= res.cnt; i++) {
      res.val[i] = b.val[i - a.cnt];
    }

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
    uint32_t x;
    cin >> x;
    seg.Set(i, x);
  }
  seg.Build();

  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      uint32_t l, r, x;
      cin >> l >> r >> x;
      seg.Update(l, r, x);
    } else {
      uint32_t l, r;
      cin >> l >> r;

      auto res = seg.Query(l, r);
      uint64_t sum = 0;
      for (int i = 0; i <= 25; i++) sum += res.sum[i];
      cout << sum << "\n";
    }
  }

  return 0;
}