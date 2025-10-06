// Title : 두 직사각형
// Link  : https://www.acmicpc.net/problem/9061 
// Time  : 104 ms
// Memory: 2768 KB

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
  Node() : minn(INT_MAX), maxx(INT_MIN) {}
  Node(int x) : minn(x), maxx(x) {}

  int minn, maxx;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.minn = min<int>(a.minn, b.minn);
    res.maxx = max<int>(a.maxx, b.maxx);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  SegTree<Node, FOp> seg;
  vector<pair<int, int>> arr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    arr.resize(n);
    for (auto& [x, y] : arr) cin >> x >> y;

    if (n <= 2) {
      cout << "0\n";
      continue;
    }

    int64_t minn = INT64_MAX;
    for (int o = 0; o < 2; o++) {
      sort(arr.begin(), arr.end());

      seg.Init(n, Node());
      for (int i = 0; i < n; i++) {
        seg.Set(i, arr[i].second);
      }
      seg.Build();

      int lx = arr[0].first, rx = arr[n - 1].first;
      for (int i = 1; i < n; i++) {
        auto [x1, y1] = arr[i - 1];
        auto [x2, y2] = arr[i];
        auto [lmin, lmax] = seg.Query(0, i - 1);
        auto [rmin, rmax] = seg.Query(i, n - 1);

        int64_t lw = x1 - lx, rw = rx - x2;
        int64_t lh = lmax - lmin, rh = rmax - rmin;
        int64_t lv = lw * lh, rv = rw * rh;
        minn = min<int64_t>(minn, max<int64_t>(lv, rv));
      }

      for (auto& [x, y] : arr) swap(x, y);
    }
    cout << minn << "\n";
  }

  return 0;
}