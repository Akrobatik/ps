// Title : 영화 수집
// Link  : https://www.acmicpc.net/problem/3653
// Time  : 92 ms
// Memory: 4584 KB

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  SegmentTree tree;

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    tree.Init(n + m + 1);
    for (int i = 1; i <= n; i++) tree.Update(i, 1);
    int maxx = tree.nmax - 1;
    vector<int> memo(n + 1);
    iota(memo.rbegin(), memo.rend() - 1, 1);
    for (int i = 1; i <= m; i++) {
      int idx;
      cin >> idx;
      auto& tidx = memo[idx];
      cout << tree.Query(tidx + 1, maxx) << " ";
      tree.Update(tidx, 0);
      tidx = n + i;
      tree.Update(tidx, 1);
    }
    cout << "\n";
  }

  return 0;
}
