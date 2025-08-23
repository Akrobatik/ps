// Title : 화려한 마을
// Link  : https://www.acmicpc.net/problem/12895 
// Time  : 76 ms
// Memory: 4084 KB

#include <bits/stdc++.h>

using namespace std;

struct LazySegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
    lazy.clear(), lazy.resize(nmax << 1);
  }

  void Update(int l, int r, int x) {
    Update(1, 0, nmax - 1, l, r, x);
  }

  int Query(int l, int r) {
    return __builtin_popcount(Query(1, 0, nmax - 1, l, r));
  }

  int nmax;
  vector<int> tree, lazy;

 private:
  void Push(int node, int b, int e) {
    if (!lazy[node]) return;
    tree[node] = 1 << lazy[node];
    if (b != e) {
      lazy[node << 1] = lazy[node];
      lazy[(node << 1) + 1] = lazy[node];
    }
    lazy[node] = 0;
  }

  void Update(int node, int b, int e, int l, int r, int x) {
    bool fit = (l <= b && e <= r);
    if (fit) lazy[node] = x;
    Push(node, b, e);
    if (l > e || b > r || fit) return;
    int mid = (b + e) >> 1;
    Update(node << 1, b, mid, l, r, x);
    Update((node << 1) + 1, mid + 1, e, l, r, x);
    tree[node] = tree[node << 1] | tree[(node << 1) + 1];
  }

  int Query(int node, int b, int e, int l, int r) {
    Push(node, b, e);
    if (l > e || b > r) return 0;
    if (l <= b && e <= r) return tree[node];
    int mid = (b + e) >> 1;
    return Query(node << 1, b, mid, l, r) | Query((node << 1) + 1, mid + 1, e, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t, q;
  cin >> n >> t >> q;

  LazySegmentTree seg;
  seg.Init(n + 1);
  seg.Update(1, n, 1);

  while (q--) {
    char cmd;
    int x, y;
    cin >> cmd >> x >> y;
    if (x > y) swap(x, y);
    if (cmd == 'C') {
      int z;
      cin >> z;
      seg.Update(x, y, z);
    } else {
      cout << seg.Query(x, y) << "\n";
    }
  }

  return 0;
}