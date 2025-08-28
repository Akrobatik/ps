// Title : 수열과 쿼리 39
// Link  : https://www.acmicpc.net/problem/19651 
// Time  : 68 ms
// Memory: 7300 KB

#include <bits/stdc++.h>

using namespace std;

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
  Node() : maxx(0), fwd(0), bwd(0), sz(0) {}
  Node(int v) : maxx(v), fwd(v), bwd(v), sz(1) {}

  int maxx, fwd, bwd, sz;
};

struct FOp {
  Node operator()(const Node& lhs, const Node& rhs) const {
    Node res;
    res.maxx = max<int>({lhs.maxx, rhs.maxx, lhs.bwd + rhs.fwd});
    res.fwd = (lhs.fwd == lhs.sz ? lhs.fwd + rhs.fwd : lhs.fwd);
    res.bwd = (rhs.bwd == rhs.sz ? rhs.bwd + lhs.bwd : rhs.bwd);
    res.sz = lhs.sz + rhs.sz;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int64_t> axr(n + 2);
  for (int i = 1; i <= n; i++) {
    axr[i] = (arr[i] << 1) - arr[i - 1] - arr[i + 1];
  }

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, Node());
  seg.Set(1, 1), seg.Set(n, 1);
  for (int i = 2; i < n; i++) {
    seg.Set(i, axr[i] == 0);
  }
  seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int64_t i, j, x, y;
      cin >> i >> j >> x >> y;
      int64_t z = x + y * (j - i);

      axr[i - 1] -= x;
      axr[i] += x - y;
      axr[j] += z + y;
      axr[j + 1] -= z;
      for (auto idx : {i - 1, i, j, j + 1}) {
        if (1 < idx && idx < n) seg.Update(idx, axr[idx] == 0);
      }
    } else {
      int l, r;
      cin >> l >> r;
      if (l + 1 >= r) {
        cout << r - l + 1 << "\n";
      } else {
        cout << seg.Query(l + 1, r - 1).maxx + 2 << "\n";
      }
    }
  }

  return 0;
}
