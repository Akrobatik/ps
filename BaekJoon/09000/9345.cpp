// Title : 디지털 비디오 디스크(DVDs)
// Link  : https://www.acmicpc.net/problem/9345 
// Time  : 152 ms
// Memory: 4864 KB

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

  vector<int> arr;
  SegTree<Node, FOp> seg;

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    arr.resize(n);

    seg.Init(n, Node());
    for (int i = 0; i < n; i++) {
      arr[i] = i;
      seg.Set(i, i);
    }
    seg.Build();

    while (k--) {
      int cmd, a, b;
      cin >> cmd >> a >> b;
      if (cmd == 0) {
        swap(arr[a], arr[b]);
        seg.Update(a, arr[a]);
        seg.Update(b, arr[b]);
      } else {
        auto [minn, maxx] = seg.Query(a, b);
        cout << (minn == a && maxx == b ? "YES\n" : "NO\n");
      }
    }
  }

  return 0;
}