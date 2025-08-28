// Title : 수열과 쿼리 24
// Link  : https://www.acmicpc.net/problem/17408 
// Time  : 52 ms
// Memory: 4072 KB

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
  Node() : val(0), maxx(0) {}
  Node(int v) : val(v), maxx(v) {}

  int val, maxx;
};

struct FOp {
  Node operator()(const Node& lhs, const Node& rhs) const {
    Node res;
    res.val = max<int>({lhs.val, rhs.val, lhs.maxx + rhs.maxx});
    res.maxx = max<int>(lhs.maxx, rhs.maxx);
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
    int cmd, a, b;
    cin >> cmd >> a >> b;
    if (cmd == 1) {
      seg.Update(a, b);
    } else {
      cout << seg.Query(a, b).val << "\n";
    }
  }

  return 0;
}
