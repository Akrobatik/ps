#include <bits/stdc++.h>

using namespace std;

struct LazySegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
    lazy.clear(), lazy.resize(nmax << 1);
  }

  void Update(int l, int r, int delta) {
    Update(1, 0, nmax - 1, l, r, delta);
  }

  int Query(int l, int r) {
    return Query(1, 0, nmax - 1, l, r);
  }

  int nmax;
  vector<int> tree, lazy;

 private:
  void Push(int node, int b, int e) {
    if (!lazy[node]) return;
    tree[node] += lazy[node] * (e - b + 1);
    if (b != e) {
      lazy[node << 1] += lazy[node];
      lazy[(node << 1) + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  void Update(int node, int b, int e, int l, int r, int delta) {
    bool fit = (l <= b && e <= r);
    if (fit) lazy[node] += delta;
    Push(node, b, e);
    if (l > e || b > r || fit) return;
    int mid = (b + e) >> 1;
    Update(node << 1, b, mid, l, r, delta);
    Update((node << 1) + 1, mid + 1, e, l, r, delta);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
  }

  int Query(int node, int b, int e, int l, int r) {
    Push(node, b, e);
    if (l > e || b > r) return 0;
    if (l <= b && e <= r) return tree[node];
    int mid = (b + e) >> 1;
    return Query(node << 1, b, mid, l, r) + Query((node << 1) + 1, mid + 1, e, l, r);
  }
};
