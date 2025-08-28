// Title : 색종이와 쿼리
// Link  : https://www.acmicpc.net/problem/18246 
// Time  : 212 ms
// Memory: 76624 KB

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

  void Build(const SegTree& lhs, const SegTree& rhs) {
    for (int i = 1; i < (nmax << 1); i++) {
      tree[i] = OP{}(lhs.tree[i], rhs.tree[i]);
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

  //  private:
  int nmax;
  V iv;
  vector<V> tree;
};

template <typename V, typename OP>
  requires requires(V a, V b) {
    { OP{}(a, b) } -> convertible_to<V>;
  }
struct SegTree2D {
  void Init(int ny, int nx, const V& ival) {
    nmaxy = bit_ceil((uint32_t)ny);
    iv = ival;

    tree.assign(nmaxy << 1, SegTree<V, OP>());
    for (int i = 1; i < (nmaxy << 1); i++) {
      tree[i].Init(nx, iv);
    }
  }

  void Build() {
    for (int i = 0; i < nmaxy; i++) {
      tree[i + nmaxy].Build();
    }
    for (int i = nmaxy - 1; i > 0; i--) {
      tree[i].Build(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  void Set(int y, int x, int v) {
    tree[y + nmaxy].Set(x, v);
  }

  V Query(int y1, int x1, int y2, int x2) {
    V lv = iv, rv = iv;
    for (y1 += nmaxy, y2 += nmaxy + 1; y1 < y2; y1 >>= 1, y2 >>= 1) {
      if (y1 & 1) lv = OP{}(lv, tree[y1++].Query(x1, x2));
      if (y2 & 1) rv = OP{}(tree[--y2].Query(x1, x2), rv);
    }
    return OP{}(lv, rv);
  }

 private:
  int nmaxy;
  V iv;
  vector<SegTree<V, OP>> tree;
};

using Node = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return max<int>(a, b);
  }
};

constexpr int kMax = 1500;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> board(kMax + 1, vector<int>(kMax + 1, 0));

  int n, m;
  cin >> n >> m;

  while (n--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    ++board[y1][x1];
    --board[y1][x2];
    --board[y2][x1];
    ++board[y2][x2];
  }

  for (int i = 0; i <= kMax; i++) {
    for (int j = 0; j <= kMax; j++) {
      int val = 0;
      if (i) val += board[i - 1][j];
      if (j) val += board[i][j - 1];
      if (i && j) val -= board[i - 1][j - 1];
      board[i][j] += val;
    }
  }

  SegTree2D<Node, FOp> seg;
  seg.Init(kMax, kMax, 0);
  for (int i = 0; i < kMax; i++) {
    for (int j = 0; j < kMax; j++) {
      seg.Set(i, j, board[i][j]);
    }
  }
  seg.Build();

  while (m--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << seg.Query(y1, x1, y2 - 1, x2 - 1) << "\n";
  }

  return 0;
}
