// Title : 수열과 쿼리 10
// Link  : https://www.acmicpc.net/problem/13557 
// Time  : 104 ms
// Memory: 10216 KB

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

constexpr int64_t kInf = INT64_MAX >> 2;

struct Node {
  Node() : val(-kInf), sum(0), fwd(-kInf), bwd(-kInf) {}
  Node(int64_t v) : val(v), sum(v), fwd(v), bwd(v) {}

  int64_t val, sum, fwd, bwd;
};

struct FOp {
  Node operator()(const Node& lhs, const Node& rhs) const {
    Node res;
    res.val = max<int64_t>({lhs.val, rhs.val, lhs.bwd + rhs.fwd});
    res.sum = lhs.sum + rhs.sum;
    res.fwd = max<int64_t>(lhs.fwd, lhs.sum + rhs.fwd);
    res.bwd = max<int64_t>(rhs.bwd, rhs.sum + lhs.bwd);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, Node());
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    seg.Set(i, x);
  }
  seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (y1 <= x2) {
      int64_t base = seg.Query(y1, x2).sum;
      int64_t fwd = max<int64_t>(seg.Query(x1, y1 - 1).bwd, 0);
      int64_t bwd = max<int64_t>(seg.Query(x2 + 1, y2).fwd, 0);
      cout << base + fwd + bwd << "\n";
    } else {
      auto base = seg.Query(x2, y1);
      int64_t fwd = max<int64_t>(seg.Query(x1, x2 - 1).bwd, 0);
      int64_t bwd = max<int64_t>(seg.Query(y1 + 1, y2).fwd, 0);
      cout << max<int64_t>({base.val, fwd + bwd + base.sum, fwd + base.fwd, bwd + base.bwd}) << "\n";
    }
  }

  return 0;
}
