#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
  }

  void Update(int idx, int64_t value) {
    int node = idx + nmax;
    tree[node] = value;
    while ((node >>= 1)) tree[node] = max<int64_t>(tree[node << 1], tree[(node << 1) + 1]);
  }

  int64_t Query(int l, int r) {
    int64_t res = 0;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = max<int64_t>(res, tree[l++]);
      if (r & 1) res = max<int64_t>(res, tree[--r]);
    }
    return res;
  }

  int nmax;
  vector<int64_t> tree;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  SegmentTree tree;

  int n, d;
  cin >> n >> d;
  tree.Init(n);

  int64_t ans = INT64_MIN;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    int64_t cur = tree.Query(max<int>(i - d, 0), i - 1) + x;
    tree.Update(i, cur);
    ans = max<int64_t>(ans, cur);
  }
  cout << ans;

  return 0;
}
