// Title : 트리와 XOR 쿼리
// Link  : https://www.acmicpc.net/problem/24532 
// Time  : 344 ms
// Memory: 44940 KB

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
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

struct Node {
  Node() : bits{} {}
  Node(int v) : bits{} {
    while (v) {
      int lsb = v & (-v);
      v ^= lsb;
      int crz = countr_zero((uint32_t)lsb);
      ++bits[crz];
    }
  }

  int bits[20];
};

using Lazy = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    for (int i = 0; i < 20; i++) {
      res.bits[i] = a.bits[i] + b.bits[i];
    }
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    Node res = a;
    int lzy = b;
    while (lzy) {
      int lsb = lzy & (-lzy);
      lzy ^= lsb;
      int crz = countr_zero((uint32_t)lsb);
      res.bits[crz] = sz - res.bits[crz];
    }
    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return a ^ b;
  }
};

constexpr int kMax = 1e5;

LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
vector<pair<int, int>> edges[kMax + 1];
int in[kMax + 1], out[kMax + 1], pkey[kMax + 1];
int nidx;

void Traverse(int cur, int par, int val) {
  in[cur] = ++nidx;
  seg.Set(nidx, val);
  for (auto [nxt, key] : edges[cur]) {
    if (nxt == par) continue;
    pkey[nxt] = key;
    Traverse(nxt, cur, val ^ key);
  }
  out[cur] = nidx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  seg.Init(n + 1, Node(), 0);
  Traverse(1, 0, 0);
  seg.Build();

  int table[20];
  for (int i = 0; i < 20; i++) {
    table[i] = 1 << i;
  }

  int m;
  cin >> m;
  while (m--) {
    int cmd, a, b;
    cin >> cmd >> a >> b;
    if (cmd == 1) {
      int old = pkey[a];
      pkey[a] = b;
      seg.Update(in[a], out[a], old ^ b);
    } else {
      int64_t na = out[a] - in[a] + 1;
      int64_t nb = out[b] - in[b] + 1;
      auto ra = seg.Query(in[a], out[a]);
      auto rb = seg.Query(in[b], out[b]);

      int64_t res = 0;
      for (int i = 0; i < 20; i++) {
        int64_t ca = ra.bits[i], cb = rb.bits[i];
        int64_t cnt = ca * (nb - cb) + cb * (na - ca);
        res += cnt * table[i];
      }
      cout << res << "\n";
    }
  }

  return 0;
}
