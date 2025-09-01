// Title : 물고기와 쿼리
// Link  : https://www.acmicpc.net/problem/34195 
// Time  : 148 ms
// Memory: 14948 KB

#include <bits/stdc++.h>

using namespace std;

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

struct Node {
  Node() : cnt(0), fwd(0), bwd(0) {}
  Node(int v) : cnt(0), fwd(v), bwd(v) {}

  int cnt, fwd, bwd;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.cnt = a.cnt + b.cnt + (a.bwd && b.fwd);
    res.fwd = a.fwd;
    res.bwd = b.bwd;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s;
  cin >> n >> s >> m;

  SegTree<Node, FOp> seg;
  seg.Init(n, Node());
  for (int i = 1; i < n; i++) {
    seg.Set(i, Node(s[i - 1] != s[i]));
  }
  seg.Build();

  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int l, r;
      cin >> l >> r;
      if (l != 1) seg.Update(l - 1, seg.Query(l - 1).fwd ^ 1);
      if (r != n) seg.Update(r, seg.Query(r).fwd ^ 1);
    } else {
      cout << seg.Query(1, n - 1).cnt << "\n";
    }
  }

  return 0;
}
