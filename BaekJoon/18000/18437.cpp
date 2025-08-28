// Title : 회사 문화 5
// Link  : https://www.acmicpc.net/problem/18437 
// Time  : 76 ms
// Memory: 13880 KB

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
    return a + b;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    if (b == 0) return a;
    if (b == 1) return sz;
    return 0;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return b ? b : a;
  }
};

constexpr int kMax = 1e5;

vector<int> edges[kMax + 1];
int in[kMax + 1], out[kMax + 1];
int nidx;

void Traverse(int cur) {
  in[cur] = ++nidx;
  for (auto nxt : edges[cur]) {
    Traverse(nxt);
  }
  out[cur] = nidx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    edges[x].push_back(i);
  }
  Traverse(1);

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(n + 1, 0, 0);
  seg.Update(1, n, 1);

  int m;
  cin >> m;
  while (m--) {
    int cmd, i;
    cin >> cmd >> i;
    if (cmd == 3) {
      cout << seg.Query(in[i] + 1, out[i]) << "\n";
    } else {
      seg.Update(in[i] + 1, out[i], cmd);
    }
  }

  return 0;
}
