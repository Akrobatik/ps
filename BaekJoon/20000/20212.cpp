// Title : 나무는 쿼리를 싫어해~
// Link  : https://www.acmicpc.net/problem/20212 
// Time  : 76 ms
// Memory: 19580 KB

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
  Node() : val(0), sz(0) {}
  Node(int64_t v, int64_t s) : val(v), sz(s) {}

  int64_t val, sz;
};

using Lazy = int64_t;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return Node(a.val + b.val, a.sz + b.sz);
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    return Node(a.val + a.sz * b, a.sz);
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

  int n;
  cin >> n;

  vector<tuple<int, int, int, int>> qr(n);
  vector<int> memo;
  memo.reserve(n << 2);
  for (auto& [cmd, i, j, k] : qr) {
    cin >> cmd >> i >> j >> k;
    memo.push_back(i);
    memo.push_back(i - 1);
    memo.push_back(j);
    memo.push_back(j + 1);
  }
  sort(memo.begin(), memo.end());
  memo.erase(unique(memo.begin(), memo.end()), memo.end());

  for (auto& [cmd, i, j, k] : qr) {
    i = lower_bound(memo.begin(), memo.end(), i) - memo.begin();
    j = lower_bound(memo.begin(), memo.end(), j) - memo.begin();
  }

  int nm = memo.size();
  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(nm, Node(), 0);
  for (int i = 1; i + 1 < nm; i++) {
    int64_t sz = memo[i + 1] - memo[i];
    seg.Set(i, Node(0, sz));
  }
  seg.Build();

  vector<tuple<int, int, int>> arr, brr;
  for (auto [cmd, i, j, k] : qr) {
    if (cmd == 1) {
      arr.push_back({i, j, k});
    } else {
      brr.push_back({i, j, k});
    }
  }

  int nb = brr.size();
  vector<int> idxs(nb);
  iota(idxs.begin(), idxs.end(), 0);
  sort(idxs.begin(), idxs.end(), [&](int lhs, int rhs) {
    return get<2>(brr[lhs]) < get<2>(brr[rhs]);
  });

  int na = arr.size(), idx = 0;
  vector<int64_t> ans(nb);
  for (auto i : idxs) {
    auto [l, r, k] = brr[i];
    while (idx < k) {
      auto [ll, rr, kk] = arr[idx++];
      seg.Update(ll, rr, kk);
    }
    ans[i] = seg.Query(l, r).val;
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}