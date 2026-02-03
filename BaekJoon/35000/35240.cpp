// Title : Brickwork
// Link  : https://www.acmicpc.net/problem/35240 
// Time  : 532 ms
// Memory: 20344 KB

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

using Node = int;
using Lazy = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return max<int>(a, b);
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    return max<int>(a, b);
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return max<int>(a, b);
  }
};

using tup = tuple<int, int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tup> arr(n);
  vector<int> yrr, xrr;
  int64_t sum = 0;
  int64_t miny = INT_MAX, maxy = 0;
  int64_t minx = INT_MAX, maxx = 0;
  for (int i = 0; i < n; i++) {
    int y1, x1, h, w;
    cin >> x1 >> y1 >> w >> h;
    int y2 = y1 + h, x2 = x1 + w;
    arr[i] = {y1, x1, y2, x2};
    yrr.push_back(y1), yrr.push_back(y2);
    xrr.push_back(x1), xrr.push_back(x2);
    miny = min<int64_t>(miny, y1), maxy = max<int64_t>(maxy, y2);
    minx = min<int64_t>(minx, x1), maxx = max<int64_t>(maxx, x2);
    sum += (int64_t)w * h;
  }

  if (sum != (maxy - miny) * (maxx - minx)) {
    cout << "no";
    return 0;
  }

  sort(yrr.begin(), yrr.end());
  sort(xrr.begin(), xrr.end());
  yrr.erase(unique(yrr.begin(), yrr.end()), yrr.end());
  xrr.erase(unique(xrr.begin(), xrr.end()), xrr.end());

  auto Y = [&](int y) {
    return lower_bound(yrr.begin(), yrr.end(), y) - yrr.begin();
  };

  auto X = [&](int x) {
    return lower_bound(xrr.begin(), xrr.end(), x) - xrr.begin();
  };

  for (auto& [y1, x1, y2, x2] : arr) {
    y1 = Y(y1), y2 = Y(y2);
    x1 = X(x1), x2 = X(x2);
  }
  sort(arr.begin(), arr.end());

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(xrr.size(), 0, 0);
  for (auto [y1, x1, y2, x2] : arr) {
    if (seg.Query(x1, x2 - 1) > y1) {
      cout << "no";
      return 0;
    }
    seg.Update(x1, x2 - 1, y2);
  }
  cout << "yes";

  return 0;
}