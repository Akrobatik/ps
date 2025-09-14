// Title : 잡아라 벌레 벌레!
// Link  : https://www.acmicpc.net/problem/34339 
// Time  : 444 ms
// Memory: 6124 KB

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
  Node() : bits{} { bits.set(0); }
  Node(int x) : Node() { bits.set(x); }

  bitset<101> bits;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    bitset<101> av = a.bits, bv = b.bits;
    if (av.count() < bv.count()) swap(av, bv);

    Node res;
    int x = bv._Find_first();
    while (x <= 100) {
      res.bits |= (av << x);
      x = bv._Find_next(x);
    }
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

  auto Check = [&](int l, int r) -> bool {
    auto res = seg.Query(l, r);
    return res.bits[100];
  };

  int64_t sum = 0;
  int l = 0;
  for (int i = 1; i <= n; i++) {
    while (l + 1 < i && Check(l + 1, i)) ++l;
    sum += l;
  }
  cout << sum;

  return 0;
}
