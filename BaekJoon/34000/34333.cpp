// Title : @Override
// Link  : https://www.acmicpc.net/problem/34333 
// Time  : 1884 ms
// Memory: 176992 KB

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
  Node() : maxx(INT_MIN), sum(0) {}
  Node(int v) : maxx(v), sum(v) {}

  int maxx;
  int64_t sum;
};

using Lazy = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.maxx = max<int>(a.maxx, b.maxx);
    res.sum = a.sum + b.sum;
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    if (b == INT_MAX) return a;

    Node res;
    res.maxx = b;
    res.sum = (int64_t)b * sz;
    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    if (b == INT_MAX) return a;
    return b;
  }
};

struct TreeFlatten {
  // 1-Based
  void Init(int root, const vector<vector<int>>& g) {
    int n = g.size();
    par.assign(n, 0), depth.assign(n, 0);
    in.assign(n, 0), out.assign(n, 0);
    heavy.assign(n, 0), head.assign(n, 0);

    nidx = 0;
    DFS1(root, g);
    DFS2(root, root, g);
  }

  int GetIdx(int u) {
    return in[u];
  }

  int GetParent(int u) {
    return par[u];
  }

  int GetLCA(int u, int v) {
    while (head[u] != head[v]) {
      int hu = head[u], hv = head[v];
      if (depth[hu] > depth[hv]) {
        u = par[hu];
      } else {
        v = par[hv];
      }
    }
    return depth[u] < depth[v] ? u : v;
  }

  pair<int, int> GetSubtree(int u) {
    return {in[u], out[u]};
  }

  vector<pair<int, int>> GetPath(int u, int v) {
    vector<pair<int, int>> res;
    while (head[u] != head[v]) {
      int hu = head[u], hv = head[v];
      if (depth[hu] > depth[hv]) {
        res.push_back({in[hu], in[u]});
        u = par[hu];
      } else {
        res.push_back({in[hv], in[v]});
        v = par[hv];
      }
    }
    if (depth[u] > depth[v]) swap(u, v);
    res.push_back({in[u], in[v]});
    return res;
  }

 private:
  int DFS1(int cur, const vector<vector<int>>& g) {
    int sum = 1, maxx = 0;
    for (auto nxt : g[cur]) {
      if (nxt == par[cur]) continue;
      par[nxt] = cur, depth[nxt] = depth[cur] + 1;
      int cnt = DFS1(nxt, g);
      sum += cnt;
      if (maxx < cnt) maxx = cnt, heavy[cur] = nxt;
    }
    return sum;
  }

  void DFS2(int cur, int hv, const vector<vector<int>>& g) {
    head[cur] = hv, in[cur] = ++nidx;
    if (heavy[cur]) DFS2(heavy[cur], hv, g);
    for (auto nxt : g[cur]) {
      if (nxt == par[cur] || nxt == heavy[cur]) continue;
      DFS2(nxt, nxt, g);
    }
    out[cur] = nidx;
  }

  int nidx;
  vector<int> par, depth, in, out, heavy, head;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  vector<vector<int>> edges(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  TreeFlatten tf;
  tf.Init(1, edges);

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(n + 1, Node(), INT_MAX);
  for (int i = 1; i <= n; i++) {
    seg.Set(tf.GetIdx(i), arr[i]);
  }
  seg.Build();

  while (q--) {
    int cmd, i;
    cin >> cmd >> i;
    if (cmd == 1) {
      auto lr = tf.GetPath(1, tf.GetParent(i));
      int maxx = INT_MIN;
      for (auto [l, r] : lr) maxx = max<int>(maxx, seg.Query(l, r).maxx);
      auto [l, r] = tf.GetSubtree(i);
      seg.Update(l, r, maxx);
    } else {
      auto [l, r] = tf.GetSubtree(i);
      cout << seg.Query(l, r).sum << "\n";
    }
  }

  return 0;
}
