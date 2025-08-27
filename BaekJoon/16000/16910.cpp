// Title : mex와 쿼리
// Link  : https://www.acmicpc.net/problem/16910 
// Time  : 212 ms
// Memory: 21360 KB

#include <bits/stdc++.h>

using namespace std;

template <typename V, typename L, typename OP, typename APPLY, typename COMPO>
  requires requires(V va, V vb, L la, L lb, int sz) {
    { OP{}(va, vb) } -> convertible_to<V>;
    { APPLY{}(va, la, sz) } -> convertible_to<V>;
    { COMPO{}(la, lb) } -> convertible_to<L>;
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

  int FirstZero(int l, int r) {
    return FirstZero(1, 0, nmax - 1, l, r);
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
    if (node < nmax) {
      Apply(node << 1, lazy[node]);
      Apply(node << 1 | 1, lazy[node]);
    }
    lazy[node] = il;
  }

  void Pull(int node) {
    tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
  }

  int FirstZero(int node, int b, int e, int l, int r) {
    Push(node);
    if (l > e || b > r) return -1;
    if (tree[node] == e - b + 1) return -1;
    if (b == e) return b;
    int mid = (b + e) >> 1;
    int lres = FirstZero(node << 1, b, mid, l, r);
    if (lres != -1) return lres;
    return FirstZero(node << 1 | 1, mid + 1, e, l, r);
  }
};

using Node = int;
using Lazy = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return a + b;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    if (b == 0) return a;
    if (b == 1) return sz;
    if (b == 2) return 0;
    return sz - a;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    if (b == 0) return a;
    if (b == 1 || b == 2) return b;
    return a ^ 3;
  }
};

using tup = tuple<int, int64_t, int64_t>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> memo{1};
  memo.reserve(n * 6 + 1);

  auto Push = [&](int64_t x) {
    if (x) memo.push_back(x);
  };

  vector<tup> arr(n);
  for (auto& [t, l, r] : arr) {
    cin >> t >> l >> r;
    for (int i = -1; i <= 1; i++) {
      Push(l + i), Push(r + i);
    }
  }

  sort(memo.begin(), memo.end());
  memo.erase(unique(memo.begin(), memo.end()), memo.end());

  auto Get = [&](int64_t x) -> int {
    return lower_bound(memo.begin(), memo.end(), x) - memo.begin();
  };

  int nm = memo.size();
  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(nm, 0, 0);

  for (auto [t, l, r] : arr) {
    l = Get(l), r = Get(r);
    seg.Update(l, r, t);
    cout << memo[seg.FirstZero(0, nm - 1)] << "\n";
  }

  return 0;
}
