// Title : snupc 문자열 (Easy)
// Link  : https://www.acmicpc.net/problem/34348 
// Time  : 76 ms
// Memory: 7400 KB

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

  int Kth(int v, int k) {
    int idx = 1;
    while (idx < nmax) {
      if (tree[idx << 1][v] >= k) {
        idx <<= 1;
      } else {
        k -= tree[idx << 1][v];
        idx = idx << 1 | 1;
      }
    }
    return idx - nmax;
  }

 private:
  int nmax;
  V iv;
  vector<V> tree;
};

using Node = array<int, 5>;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    for (int i = 0; i < 5; i++) res[i] = a[i] + b[i];
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  auto Get = [](char c) {
    if (c == 's') return 0;
    if (c == 'n') return 1;
    if (c == 'u') return 2;
    if (c == 'p') return 3;
    return 4;
  };

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, Node());
  for (int i = 0; i < n; i++) {
    Node node{};
    ++node[Get(s[i])];
    seg.Set(i + 1, node);
  }
  seg.Build();

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    int minn = INT_MAX;
    auto res = seg.Query(l, r);
    for (int i = 0; i < 5; i++) {
      minn = min<int>(minn, res[i]);
    }

    auto Check = [&](int k) {
      int idx = l;
      for (int i = 0; i < 5; i++) {
        int x = seg.Query(1, idx - 1)[i];
        int pos = seg.Kth(i, k + x);
        if (pos > r) return false;
        idx = pos + 1;
      }
      return true;
    };

    int lo = 0, hi = minn + 1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (Check(mid)) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    cout << lo << "\n";
  }

  return 0;
}
