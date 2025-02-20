#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
  using T = int64_t;
  FenwickTree(int n) : tree(n + 1) {}

  // Inverse element required
  void Update(int idx, T delta) {
    int n = tree.size();
    while (idx < n) tree[idx] += delta, idx += (idx & -idx);
  }

  T Query(int idx) {
    T res = 0;
    while (idx) res += tree[idx], idx -= (idx & -idx);
    return res;
  }

  T Query(int l, int r) {
    T res = 0;
    --l;
    while (l) res -= tree[l], l -= (l & -l);
    while (r) res += tree[r], r -= (r & -r);
    return res;
  }

  vector<T> tree;
};