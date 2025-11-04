// Title : Don't Fight The Music
// Link  : https://www.acmicpc.net/problem/34651 
// Time  : 444 ms
// Memory: 98588 KB

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
  Node() : type{}, sum{} {}
  Node(int cv, int rv, int bv) : type{}, sum{} {
    type[0] = cv;
    for (int t = 0; t < 4; t++) {
      sum[0][t] = (t & cv) ? bv : rv;
    }

    for (int t = 0; t < 4; t++) {
      int ncv = (t & cv) ? 2 : 1;
      type[t + 1] = ncv;
      for (int nt = 0; nt < 4; nt++) {
        sum[t + 1][nt] = (nt & ncv) ? bv : rv;
      }
    }
  }

  int type[5];
  int64_t sum[5][4];
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.type[0] = a.type[0] ^ b.type[0];
    for (int t = 0; t < 4; t++) {
      res.sum[0][t] = a.sum[0][t] + b.sum[0][t ^ a.type[0]];
    }

    for (int t = 0; t < 4; t++) {
      int ncv = t ^ a.type[0];
      res.type[t + 1] = a.type[t + 1] ^ b.type[ncv + 1];
      for (int nt = 0; nt < 4; nt++) {
        res.sum[t + 1][nt] = a.sum[t + 1][nt] + b.sum[ncv + 1][nt ^ a.type[t + 1]];
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> color(n + 1);
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    color[i] = (c == 'R' ? 1 : 2);
  }

  vector<array<int, 2>> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i][0];
  for (int i = 1; i <= n; i++) cin >> arr[i][1];

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, Node());
  for (int i = 1; i <= n; i++) {
    seg.Set(i, Node(color[i], arr[i][0], arr[i][1]));
  }
  seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    switch (cmd) {
      case 1: {
        int i;
        cin >> i;
        color[i] ^= 3;
        seg.Update(i, Node(color[i], arr[i][0], arr[i][1]));
      } break;
      case 2: {
        int i, k;
        cin >> i >> k;
        arr[i][0] = k;
        seg.Update(i, Node(color[i], arr[i][0], arr[i][1]));
      } break;
      case 3: {
        int i, k;
        cin >> i >> k;
        arr[i][1] = k;
        seg.Update(i, Node(color[i], arr[i][0], arr[i][1]));
      } break;
      case 4: {
        int l, r, t;
        cin >> l >> r >> t;

        auto res = seg.Query(l, r);
        cout << res.sum[~t & 1][0] << "\n";
      } break;
    }
  }

  return 0;
}