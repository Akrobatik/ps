// Title : 점 세 개 돌리기
// Link  : https://www.acmicpc.net/problem/35157 
// Time  : 104 ms
// Memory: 5100 KB

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

// using Node = int64_t;
struct Node {
  Node() : op{0, 2, 4} {}
  Node(int x, int y, int z) : op{x, y, z} {}

  int op[3];
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    for (int i = 0; i < 3; i++) {
      int apos = a.op[i] >> 1, asign = a.op[i] & 1;
      int bpos = b.op[apos] >> 1, bsign = b.op[apos] & 1;
      res.op[i] = (bpos << 1) | (asign ^ bsign);
    }
    return res;
  }
};

constexpr int kQr[3][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, Node());
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "X") {
      seg.Set(i, Node(0, 4, 3));
    } else if (s == "Y") {
      seg.Set(i, Node(5, 2, 0));
    } else if (s == "Z") {
      seg.Set(i, Node(2, 1, 4));
    } else if (s == "XX") {
      seg.Set(i, Node(0, 3, 5));
    } else if (s == "YY") {
      seg.Set(i, Node(1, 2, 5));
    } else if (s == "ZZ") {
      seg.Set(i, Node(1, 3, 4));
    } else if (s == "XY" || s == "YX") {
      seg.Set(i, Node(0, 2, 5));
    } else if (s == "YZ" || s == "ZY") {
      seg.Set(i, Node(1, 2, 4));
    } else if (s == "ZX" || s == "XZ") {
      seg.Set(i, Node(0, 3, 4));
    }
  }
  seg.Build();

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    auto res = seg.Query(l, r);

    for (auto& qr : kQr) {
      int ans[3];
      for (int i = 0; i < 3; i++) {
        int pos = res.op[i] >> 1, sign = res.op[i] & 1;
        ans[pos] = qr[i] * (sign ? -1 : 1);
      }
      for (int i = 0; i < 3; i++) {
        cout << ans[i] << " \n"[i + 1 == 3];
      }
    }
  }

  return 0;
}