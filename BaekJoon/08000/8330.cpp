// Title : 순열
// Link  : https://www.acmicpc.net/problem/8330 
// Time  : 228 ms
// Memory: 7688 KB

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

constexpr int kInf = INT_MAX >> 1;

struct Node {
  Node() : minn(kInf), sum(0) {}
  Node(int v) : minn(v), sum(v) {}

  int minn, sum;
};

struct FOp {
  Node operator()(const Node& lhs, const Node& rhs) const {
    Node res;
    res.minn = min<int>(rhs.minn, rhs.sum + lhs.minn);
    res.sum = lhs.sum + rhs.sum;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1), cnt(n + 1, -1);
  cnt[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x < 0) x = 0;
    if (x > n) x = n;
    arr[i] = x;
    ++cnt[x];
  }

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, Node());
  for (int i = 0; i <= n; i++) {
    seg.Set(i, cnt[i]);
  }
  seg.Build();

  cout << (seg.Query(1, n).minn >= 0 ? "TAK\n" : "NIE\n");

  int m;
  cin >> m;
  while (m--) {
    int i, x;
    cin >> i >> x;
    if (x < 0) x = 0;
    if (x > n) x = n;

    int old = arr[i];
    arr[i] = x;
    seg.Update(old, --cnt[old]);
    seg.Update(x, ++cnt[x]);

    cout << (seg.Query(1, n).minn >= 0 ? "TAK\n" : "NIE\n");
  }

  return 0;
}
