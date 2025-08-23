// Title : 가계부 (Hard)
// Link  : https://www.acmicpc.net/problem/12837 
// Time  : 56 ms
// Memory: 18408 KB

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
    for (int i = nmax - 1; i > 0; --i) {
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

using Node = int64_t;

struct FOp {
  Node operator()(const Node& lhs, const Node& rhs) const {
    return lhs + rhs;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, 0);

  while (m--) {
    int64_t cmd, a, b;
    cin >> cmd >> a >> b;
    if (cmd == 1) {
      int64_t old = seg.Query(a);
      seg.Update(a, old + b);
    } else {
      cout << seg.Query(a, b) << "\n";
    }
  }

  return 0;
}