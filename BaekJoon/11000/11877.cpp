// Title : 홍수
// Link  : https://www.acmicpc.net/problem/11877 
// Time  : 148 ms
// Memory: 14124 KB

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

  int kth(int k) {
    int node = 1;
    while (node < nmax) {
      node <<= 1;
      if (tree[node] < k) k -= tree[node++];
    }
    int res = node - nmax;
    while (node > 0) --tree[node], node >>= 1;
    return res;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, x;
  cin >> n >> x;

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    seg.Set(i, 1);
  }
  seg.Build();

  vector<int> arr(n);
  arr.back() = n;
  for (int i = 1; i < n; i++) {
    int64_t cut = min<int64_t>(x, n - i - 1);
    x -= cut;
    int x = seg.kth(cut);
    arr[x] = i;
  }

  if (x > 0) {
    cout << "-1";
    return 0;
  }

  for (auto e : arr) cout << e << " ";

  return 0;
}