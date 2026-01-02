// Title : 백설공주와 난쟁이
// Link  : https://www.acmicpc.net/problem/2912 
// Time  : 44 ms
// Memory: 12792 KB

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
  Node() : val(0), cnt(0) {}
  Node(int v, int c) : val(v), cnt(c) {}

  int val, cnt;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    if (a.val == b.val) {
      res = {a.val, a.cnt + b.cnt};
    } else if (a.cnt > b.cnt) {
      res = {a.val, a.cnt - b.cnt};
    } else if (a.cnt < b.cnt) {
      res = {b.val, b.cnt - a.cnt};
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, Node());
  vector<vector<int>> memo(c + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    seg.Set(i, {x, 1});
    memo[x].push_back(i);
  }
  seg.Build();

  auto Count = [&](int l, int r, int x) {
    return upper_bound(memo[x].begin(), memo[x].end(), r) - lower_bound(memo[x].begin(), memo[x].end(), l);
  };

  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    int x = seg.Query(l, r).val;
    if (x && ((r - l + 1) >> 1) < Count(l, r, x)) {
      cout << "yes " << x << "\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}