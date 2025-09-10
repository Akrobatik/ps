// Title : 1, 3, 모 나누기
// Link  : https://www.acmicpc.net/problem/25188 
// Time  : 240 ms
// Memory: 2152 KB

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
  Node() : val(0), fwd(0), bwd(0), sum(0) {}
  Node(int64_t v) : val(v), fwd(v), bwd(v), sum(v) {}

  int64_t val, fwd, bwd, sum;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.val = max<int64_t>({a.val, b.val, a.bwd + b.fwd});
    res.fwd = max<int64_t>(a.fwd, a.sum + b.fwd);
    res.bwd = max<int64_t>(b.bwd, b.sum + a.bwd);
    res.sum = a.sum + b.sum;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  SegTree<Node, FOp> seg;
  seg.Init(n, Node());
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    seg.Set(i, x);
  }
  seg.Build();

  int64_t maxx = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int64_t l = seg.Query(0, i - 1).fwd;
      int64_t m = seg.Query(i, j - 1).val;
      int64_t r = seg.Query(j, n - 1).val;
      maxx = max<int64_t>(maxx, l + m + r);
    }
  }
  cout << maxx;

  return 0;
}
