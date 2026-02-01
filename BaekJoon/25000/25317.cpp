// Title : functionx
// Link  : https://www.acmicpc.net/problem/25317 
// Time  : 132 ms
// Memory: 16192 KB

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
    return a ^ b;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    return a ^ b;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return a ^ b;
  }
};

using tup = tuple<int64_t, int64_t, int64_t>;

constexpr int64_t kInf = 2e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tup> qr(n);
  vector<int64_t> memo{-kInf, kInf};
  for (auto& [cmd, a, b] : qr) {
    cin >> cmd;
    if (cmd == 1) {
      cin >> a >> b;
    } else {
      cin >> a;
      memo.push_back(a);
    }
  }

  sort(memo.begin(), memo.end());
  memo.erase(unique(memo.begin(), memo.end()), memo.end());

  int nm = memo.size();
  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(nm, 0, 0);
  set<int64_t> st;
  int base = 1;

  auto Push = [&](int64_t a, int64_t b) {
    if (a == 0) {
      base *= (b > 0) - (b < 0);
    } else {
      int zr = (b % a == 0);
      if (zr) st.insert(-b / a);

      int64_t x = -b / a;
      if (a > 0) {
        int64_t y;
        for (int i = -1; i <= 1; i++) {
          int64_t v = x + i;
          if (v * a + b < 0) y = v;
        }
        auto it = lower_bound(memo.begin(), memo.end(), y);
        if (*it != y) --it;
        int ub = it - memo.begin();
        seg.Update(0, ub, 1);
      } else {
        int64_t y;
        for (int i = -1; i <= 1; i++) {
          int64_t v = x - i;
          if (v * a + b < 0) y = v;
        }
        auto it = lower_bound(memo.begin(), memo.end(), y);
        int lb = it - memo.begin();
        seg.Update(lb, nm - 1, 1);
      }
    }
  };

  for (auto [cmd, a, b] : qr) {
    if (cmd == 1) {
      Push(a, b);
    } else {
      if (base == 0 || st.contains(a)) {
        cout << "0\n";
      } else {
        int x = (base < 0) ^ seg.Query(lower_bound(memo.begin(), memo.end(), a) - memo.begin());
        cout << (x ? "-\n" : "+\n");
      }
    }
  }

  return 0;
}