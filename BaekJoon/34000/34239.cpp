// Title : 플러스 마이너스 합 최대
// Link  : https://www.acmicpc.net/problem/34239 
// Time  : 64 ms
// Memory: 19192 KB

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

constexpr int64_t kInf = 1e18;

struct Node {
  Node() : sz(0), minn(kInf), maxx(-kInf), sum(0) {}
  Node(int64_t v) : sz(1), minn(v), maxx(v), sum(v) {}

  int sz;
  int64_t minn, maxx, sum;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    if (a.sz == 0) return b;
    if (b.sz == 0) return a;

    int64_t rmin, rmax, rsum;
    if (a.sz & 1) {
      rmin = -b.maxx, rmax = -b.minn, rsum = -b.sum;
    } else {
      rmin = b.minn, rmax = b.maxx, rsum = b.sum;
    }

    Node res;
    res.sz = a.sz + b.sz;
    res.minn = min<int64_t>(a.minn, a.sum + rmin);
    res.maxx = max<int64_t>(a.maxx, a.sum + rmax);
    res.sum = a.sum + rsum;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  SegTree<Node, FOp> seg;
  seg.Init(n, Node());
  for (int i = 0; i < n; i++) {
    seg.Set(i, arr[i]);
  }
  seg.Build();

  int64_t maxx = -kInf;
  for (int i = 0; i < n; i++) {
    int64_t cur = seg.Query(i, n - 1).maxx;
    maxx = max<int64_t>(maxx, cur);
  }
  cout << maxx;

  return 0;
}