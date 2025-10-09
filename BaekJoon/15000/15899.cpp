// Title : 트리와 색깔
// Link  : https://www.acmicpc.net/problem/15899 
// Time  : 168 ms
// Memory: 25888 KB

#include <bits/stdc++.h>

using namespace std;

// https://github.com/Akrobatik/ps/blob/main/template/segment_tree.cpp
template <typename V, typename OP>
  requires requires(V a, V b) {
    { OP{}(a, b) } -> convertible_to<V>;
  }
struct SegTree {
  void Init(int n, const V& ival) {
    nmax = bit_ceil((uint32_t)n);
    iv = ival;
    tree.assign(nmax << 1, iv);
  }

  void Set(int idx, const V& val) {
    tree[idx + nmax] = val;
  }

  void Build() {
    for (int i = nmax - 1; i > 0; i--) {
      tree[i] = OP{}(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  void Update(int idx, const V& val) {
    int node = idx + nmax;
    tree[node] = val;
    while (node >>= 1) {
      tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
    }
  }

  V Query(int idx) const {
    return tree[idx + nmax];
  }

  V Query(int l, int r) const {
    V lv = iv, rv = iv;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lv = OP{}(lv, tree[l++]);
      if (r & 1) rv = OP{}(tree[--r], rv);
    }
    return OP{}(lv, rv);
  }

 private:
  int nmax;
  V iv;
  vector<V> tree;
};

using Node = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return a + b;
  }
};

constexpr int kMod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, c;
  cin >> n >> m >> c;

  vector<vector<int>> groups(c + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    groups[x].push_back(i);
  }

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int idx = 0;
  vector<int> in(n + 1), out(n + 1);

  [&](this auto&& self, int cur, int par) -> void {
    in[cur] = ++idx;
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur);
    }
    out[cur] = idx;
  }(1, 0);

  vector<pair<int, int>> qr(m);
  for (auto& [c, v] : qr) cin >> v >> c;
  sort(qr.begin(), qr.end());

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, 0);

  int64_t old = 0, sum = 0;
  for (auto [c, v] : qr) {
    while (old <= c) {
      for (auto e : groups[old]) {
        seg.Update(in[e], 1);
      }
      ++old;
    }

    sum += seg.Query(in[v], out[v]);
  }
  cout << sum % kMod;

  return 0;
}