// Title : 데이터 구조
// Link  : https://www.acmicpc.net/problem/12899 
// Time  : 636 ms
// Memory: 18408 KB

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

  int kth(int k) {
    int node = 1;
    while (node < nmax) {
      node <<= 1;
      if (tree[node] < k) k -= tree[node++];
    }
    return node - nmax;
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

constexpr int kMax = 2e6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  SegTree<Node, FOp> seg;
  seg.Init(kMax + 1, 0);

  int n;
  cin >> n;

  while (n--) {
    int cmd, x;
    cin >> cmd >> x;
    if (cmd == 1) {
      seg.Update(x, seg.Query(x) + 1);
    } else {
      int idx = seg.kth(x);
      seg.Update(idx, seg.Query(idx) - 1);
      cout << idx << "\n";
    }
  }

  return 0;
}
