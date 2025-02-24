#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
  }

  void Update(int idx, int value) {
    int node = idx + nmax;
    int delta = value - tree[node];
    tree[node] = value;
    while ((node >>= 1)) tree[node] += delta;
  }

  int Query(int l, int r) {
    int res = 0;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += tree[l++];
      if (r & 1) res += tree[--r];
    }
    return res;
  }

  int nmax;
  vector<int> tree;
};
