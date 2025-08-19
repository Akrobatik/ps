// Title : 고통받는 난쟁이들
// Link  : https://www.acmicpc.net/problem/5817 
// Time  : 116 ms
// Memory: 8960 KB

#include <bits/stdc++.h>

using namespace std;

template <typename V>
  requires requires(V a, V b) {
    { a + b } -> convertible_to<V>;
    { a = b } -> convertible_to<V>;
    { V{} };
  }
struct SegmentTree {
  void Init(int n) {
    nmax = bit_ceil((unsigned)n);
    tree.assign(nmax << 1, V{});
  }

  void Set(int idx, const V& val) {
    tree[idx + nmax] = val;
  }

  void Swap(int i, int j) {
    V iv = tree[i + nmax];
    V jv = tree[j + nmax];
    Update(i, jv);
    Update(j, iv);
  }

  void Build() {
    for (int i = nmax - 1; i > 0; i--) {
      tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
  }

  void Update(int idx, V val) {
    int node = idx + nmax;
    tree[node] = val;
    while (node >>= 1) tree[node] = tree[node << 1] + tree[node << 1 | 1];
  }

  V Query(int l, int r) {
    V lv{}, rv{};
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lv = lv + tree[l++];
      if (r & 1) rv = tree[--r] + rv;
    }
    return lv + rv;
  }

  int nmax;
  vector<V> tree;
};

struct Node {
  Node() : minn(INT_MAX), maxx(INT_MIN) {}
  Node(int v) : minn(v), maxx(v) {}

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res{};
    res.minn = min<int>(lhs.minn, rhs.minn);
    res.maxx = max<int>(lhs.maxx, rhs.maxx);
    return res;
  }

  int minn, maxx;
};

struct Pos {
  Pos() : pos(INT_MAX) {}
  Pos(int p) : pos(p) {}

  friend Pos operator+(const Pos& lhs, const Pos& rhs) {
    Pos res{};
    res.pos = min<int>(lhs.pos, rhs.pos);
    return res;
  }

  int pos;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  SegmentTree<Node> seg1;
  SegmentTree<Pos> seg2;
  seg1.Init(n + 1);
  seg2.Init(n + 1);
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    seg1.Set(i, x);
    seg2.Set(x, i);
    arr[i] = x;
  }
  seg1.Build();
  seg2.Build();

  while (m--) {
    int cmd, a, b;
    cin >> cmd >> a >> b;
    if (cmd == 1) {
      seg1.Swap(a, b);
      seg2.Swap(arr[a], arr[b]);
      swap(arr[a], arr[b]);
    } else {
      int p = seg2.Query(a, b).pos;
      auto res = seg1.Query(p, p - a + b);
      cout << (res.minn == a && res.maxx == b ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
