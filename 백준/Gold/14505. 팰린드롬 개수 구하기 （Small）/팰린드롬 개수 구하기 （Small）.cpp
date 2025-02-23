#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
  }

  void Update(int idx, int delta) {
    int node = idx + nmax;
    tree[node] += delta;
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

  static int GetMaxN(int n) {
    if (has_single_bit((uint32_t)n)) return n;
    return 1 << (32 - countl_zero((uint32_t)n));
  }

  int nmax;
  vector<int> tree;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  SegmentTree tree;

  string s;
  cin >> s;
  int n = s.size();
  tree.Init(n);

  vector<int> memo[26];

  for (int i = 0; i < n; i++) {
    tree.Update(i, 1);
    int v = s[i] - 'a';
    for (auto j : memo[v]) {
      int delta = 1;
      if (j + 1 != i) delta += tree.Query(j + 1, i - 1);
      tree.Update(j, delta);
    }
    memo[v].push_back(i);
  }

  cout << tree.tree[1];

  return 0;
}
