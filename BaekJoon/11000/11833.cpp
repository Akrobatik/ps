// Title : 돌 무게 재기
// Link  : https://www.acmicpc.net/problem/11833 
// Time  : 28 ms
// Memory: 5096 KB

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
    for (int i = nmax - 1; i > 0; --i) {
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

constexpr int kInf = INT_MAX >> 1;

struct Node {
  Node() : minn(kInf), maxx(-kInf), sum(0) {}
  Node(int v) : minn(v), maxx(v), sum(v) {}

  int minn, maxx, sum;
};

struct FOp {
  Node operator()(const Node& lhs, const Node& rhs) const {
    Node res;
    res.minn = min<int>(rhs.minn, rhs.sum + lhs.minn);
    res.maxx = max<int>(rhs.maxx, rhs.sum + lhs.maxx);
    res.sum = lhs.sum + rhs.sum;
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

  int minn = n + 1, maxx = 0;
  for (int i = 0; i < n; i++) {
    int r, s;
    cin >> r >> s;
    minn = min<int>(minn, r);
    maxx = max<int>(maxx, r);

    seg.Update(r, s == 1 ? 1 : -1);
    auto res = seg.Query(minn, maxx);
    cout << (res.minn >= 0 ? ">\n" : (res.maxx <= 0 ? "<\n" : "?\n"));
  }

  return 0;
}