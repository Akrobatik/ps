// Title : Attention
// Link  : https://www.acmicpc.net/problem/28020 
// Time  : 32 ms
// Memory: 6904 KB

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

struct Node {
  Node() : s1(0), s2(0) {}
  Node(int64_t _s1, int64_t _s2) : s1(_s1), s2(_s2) {}

  int64_t s1, s2;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.s1 = a.s1 + b.s1;
    res.s2 = a.s2 + b.s2;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n), table(n);
  for (auto& e : arr) cin >> e;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    table[x] = i;
  }

  SegTree<Node, FOp> seg;
  seg.Init(n, Node());
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int x = table[arr[i]];
    auto res = seg.Query(0, x);
    seg.Update(x, Node(1, res.s1));
    ans += res.s2;
  }

  if (ans == 0) {
    cout << "Attention is what I want";
  } else {
    cout << "My heart has gone to paradise\n"
         << ans;
  }

  return 0;
}