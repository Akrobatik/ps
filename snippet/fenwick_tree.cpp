#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
  void Init(int n) {
    tree.clear(), tree.resize(n + 1);
  }

  // Inverse element required
  void Update(int idx, int delta) {
    int n = tree.size();
    while (idx < n) tree[idx] += delta, idx += (idx & -idx);
  }

  int Query(int idx) {
    int res = 0;
    while (idx) res += tree[idx], idx -= (idx & -idx);
    return res;
  }

  int Query(int l, int r) {
    int res = 0;
    --l;
    while (l) res -= tree[l], l -= (l & -l);
    while (r) res += tree[r], r -= (r & -r);
    return res;
  }

  vector<int> tree;
};