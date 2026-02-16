// Title : 벽력일섬
// Link  : https://www.acmicpc.net/problem/35269 
// Time  : 1800 ms
// Memory: 208640 KB

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

  int WalkL(int x) {
    int node = 1;
    Push(node);
    while (node < nmax) {
      int lnode = node << 1, rnode = lnode + 1;
      Push(lnode), Push(rnode);
      if (x <= tree[lnode].maxx) {
        node = lnode;
      } else {
        node = rnode;
      }
    }
    return node - nmax;
  }

  int WalkR(int x) {
    int node = 1;
    Push(node);
    while (node < nmax) {
      int lnode = node << 1, rnode = lnode + 1;
      Push(lnode), Push(rnode);
      if (tree[rnode].minn <= x) {
        node = rnode;
      } else {
        node = lnode;
      }
    }
    return node - nmax;
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
  Node() : minn(INT_MAX), maxx(INT_MIN) {}
  Node(int x) : minn(x), maxx(x) {}

  int minn, maxx;
};

using Lazy = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.minn = min<int>(a.minn, b.minn);
    res.maxx = max<int>(a.maxx, b.maxx);
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    Node res;
    res.minn = max<int>(a.minn - b, 0);
    res.maxx = max<int>(a.maxx - b, 0);
    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return a + b;
  }
};

struct MergeSortTree {
 public:
  void Init(const vector<vector<int>>& v) {
    int n = v.size();
    nmax = bit_ceil((uint32_t)n);
    tree.assign(nmax << 1, vector<int>());

    for (int i = 0; i < n; i++) {
      tree[i + nmax] = v[i];
      sort(tree[i + nmax].begin(), tree[i + nmax].end());
    }

    for (int i = nmax - 1; i > 0; i--) {
      auto& node = tree[i];
      auto& lnode = tree[i << 1];
      auto& rnode = tree[i << 1 | 1];
      node.resize(lnode.size() + rnode.size());
      merge(lnode.begin(), lnode.end(), rnode.begin(), rnode.end(), node.begin());
    }
  }

  int Query(int l, int r) {
    int bnd = r;

    auto Q = [&](int i) {
      return upper_bound(tree[i].begin(), tree[i].end(), bnd) - tree[i].begin();
    };

    int res = 0;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += Q(l++);
      if (r & 1) res += Q(--r);
    }
    return res;
  }

 private:
  int nmax;
  vector<vector<int>> tree;
};

constexpr pair<int, int> kDelta[] = {
    {1, 0}, {0, 1}};

constexpr int kMax = 3e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 2>> arr(n);
  for (auto& e : arr) cin >> e[0];
  for (auto& e : arr) cin >> e[1];

  vector<int> fwd(kMax + 1);
  for (auto& e : arr) ++fwd[e[0]], ++fwd[e[1]];

  for (int i = 0, x = 0; i <= kMax; i++) {
    fwd[i] += x;
    x = fwd[i];
  }

  vector<vector<int>> adj(kMax + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (auto [dy, dx] : kDelta) {
        int y = i + dy, x = j + dx;
        if (!(0 <= y && y < n && 0 <= x && x < 2)) continue;

        int u = arr[i][j], v = arr[y][x];
        if (u > v) swap(u, v);
        adj[u].push_back(v);
      }
    }
  }

  vector<vector<int>> cube(kMax + 1);
  for (int i = 1; i < n; i++) {
    int minn = min<int>({arr[i - 1][0], arr[i - 1][1], arr[i][0], arr[i][1]});
    int maxx = max<int>({arr[i - 1][0], arr[i - 1][1], arr[i][0], arr[i][1]});
    cube[minn].push_back(maxx);
  }

  MergeSortTree atr, ctr;
  atr.Init(adj);
  ctr.Init(cube);

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(kMax + 1, Node(), 0);
  for (int i = 0; i <= kMax; i++) {
    seg.Set(i, Node(i));
  }
  seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    l = seg.WalkL(l), r = seg.WalkR(r);
    if (l > r) {
      cout << "0\n";
      continue;
    }

    seg.Update(l, r, 1);
    cout << fwd[r] - (l > 0 ? fwd[l - 1] : 0) - atr.Query(l, r) + ctr.Query(l, r) << "\n";
  }

  return 0;
}