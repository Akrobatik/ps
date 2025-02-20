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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  FenwickTree tree(n);
  vector<int64_t> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) tree.Update(i, arr[i]);

  int q = m + k;
  while (q--) {
    char a;
    int64_t b, c;
    cin >> a >> b >> c;
    if (a & 1) {  // '1'
      int64_t delta = c - arr[b];
      arr[b] = c;
      tree.Update(b, delta);
    } else {  // '2'
      cout << tree.Query(b, c) << "\n";
    }
  }

  return 0;
}