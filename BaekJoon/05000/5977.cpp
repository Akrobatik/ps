// Title : Mowing the Lawn
// Link  : https://www.acmicpc.net/problem/5977 
// Time  : 20 ms
// Memory: 5640 KB

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

using Node = int64_t;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return max<int64_t>(a, b);
  }
};

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int64_t> fwd(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    fwd[i + 1] = fwd[i] + x;
  }

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, -kInf);
  seg.Set(0, 0);
  seg.Build();

  vector<int64_t> memo(n + 1);
  for (int i = 1; i <= n; i++) {
    Node best = seg.Query(max<int>(0, i - k), i - 1);
    memo[i] = max<int64_t>(memo[i - 1], fwd[i] + best);
    seg.Update(i, memo[i - 1] - fwd[i]);
  }
  cout << memo[n] << '\n';

  return 0;
}