#include <bits/stdc++.h>

using namespace std;

struct LazySegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
    lazy.clear(), lazy.resize(nmax << 1);
  }

  void Update(int idx, int64_t delta) {
    int node = nmax + idx;
    while (node) tree[node] += delta, node >>= 1;
  }

  void Update(int l, int r, int64_t delta) {
    UpdateRange(1, 0, nmax - 1, l, r, delta);
  }

  int64_t Query(int l, int r) {
    return QueryRange(1, 0, nmax - 1, l, r);
  }

  int nmax;
  vector<int64_t> tree, lazy;

 private:
  void UpdateLazy(int node, int b, int e) {
    int64_t& ldelta = lazy[node];
    if (ldelta) {
      tree[node] += ldelta * (e - b + 1);
      if (b != e) {
        lazy[node << 1] += ldelta;
        lazy[(node << 1) + 1] += ldelta;
      }
      ldelta = 0;
    }
  }

  void UpdateRange(int node, int b, int e, int l, int r, int64_t delta) {
    UpdateLazy(node, b, e);
    if (l > e || b > r) return;
    if (l <= b && e <= r) {
      tree[node] += delta * (e - b + 1);
      if (b != e) {
        lazy[node << 1] += delta;
        lazy[(node << 1) + 1] += delta;
      }
      return;
    }
    int mid = (b + e) >> 1;
    UpdateRange(node << 1, b, mid, l, r, delta);
    UpdateRange((node << 1) + 1, mid + 1, e, l, r, delta);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
  }

  int64_t QueryRange(int node, int b, int e, int l, int r) {
    UpdateLazy(node, b, e);
    if (l > e || b > r) return 0;
    if (l <= b && e <= r) return tree[node];
    int mid = (b + e) >> 1;
    return QueryRange(node << 1, b, mid, l, r) + QueryRange((node << 1) + 1, mid + 1, e, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  LazySegmentTree tree;

  int n, m, k;
  cin >> n >> m >> k;
  tree.Init(n + 1);
  for (int i = 1; i <= n; i++) {
    int64_t x;
    cin >> x;
    tree.Update(i, x);
  }

  while (k) {
    int a, b, c;
    int64_t d;
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      tree.Update(b, c, d);
    } else {
      cin >> b >> c;
      cout << tree.Query(b, c) << "\n";
      --k;
    }
  }

  return 0;
}
