// Title : Bitonic Ordering
// Link  : https://www.acmicpc.net/problem/21136 
// Time  : 128 ms
// Memory: 8472 KB

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);
  stable_sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    return arr[lhs] < arr[rhs];
  });

  SegTree<Node, FOp> seg;
  seg.Init(n, 0);

  vector<int> axr;

  int64_t ans = 0;
  int idx = 0;
  while (idx < n) {
    int val = arr[ids[idx]];
    axr.clear();
    while (idx < n && arr[ids[idx]] == val) axr.push_back(ids[idx++]);

    int l = 0, r = axr.size() - 1;
    while (l <= r) {
      int fwd = axr[l], bwd = axr[r];
      int fcnt = fwd - seg.Query(0, fwd), bcnt = (n - bwd - 1) - seg.Query(bwd + 1, n - 1);
      if (fcnt < bcnt) {
        ans += fcnt, ++l;
        seg.Update(fwd, 1);
      } else {
        ans += bcnt, --r;
        seg.Update(bwd, 1);
      }
    }
  }
  cout << ans;

  return 0;
}