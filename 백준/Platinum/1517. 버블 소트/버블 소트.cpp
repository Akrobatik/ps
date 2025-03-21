#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
  }

  void Update(int idx, int delta) {
    int node = idx + nmax;
    while (node) tree[node] += delta, node >>= 1;
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

  int n;
  cin >> n;
  vector<int> arr(n), table(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = table[i] = x;
  }
  sort(table.begin(), table.end());
  auto tb = table.begin(), te = unique(table.begin(), table.end());
  for (auto& e : arr) {
    e = lower_bound(tb, te, e) - tb;
  }

  SegmentTree tree;
  tree.Init(n);

  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int x = arr[i];
    ans += i - tree.Query(0, x);
    tree.Update(x, 1);
  }
  cout << ans;

  return 0;
}
