// Title : 스티커 뽑기
// Link  : https://www.acmicpc.net/problem/34856 
// Time  : 448 ms
// Memory: 27776 KB

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
  Node() : nxt{0, 1}, cnt{} {}
  Node(int x) : nxt{}, cnt{} {
    for (int i = 0; i < 2; i++) {
      nxt[i] = (i == x ? i : i ^ 1);
      cnt[i][0] = (x == 0 && i == 0);
      cnt[i][1] = (x == 1 && i == 1);
    }
  }

  int nxt[2];
  int cnt[2][2];
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    for (int i = 0; i < 2; i++) {
      int x = a.nxt[i];
      res.nxt[i] = b.nxt[x];
      res.cnt[i][0] = a.cnt[i][0] + b.cnt[x][0];
      res.cnt[i][1] = a.cnt[i][1] + b.cnt[x][1];
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
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    seg.Set(i, arr[i]);
  }
  seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int i, j;
    cin >> i >> j;
    swap(arr[i], arr[j]);
    seg.Update(i, arr[i]);
    seg.Update(j, arr[j]);
    auto res = seg.Query(1, n);
    swap(arr[i], arr[j]);
    seg.Update(i, arr[i]);
    seg.Update(j, arr[j]);
    cout << res.cnt[0][0] << " " << res.cnt[0][1] << "\n";
  }

  return 0;
}