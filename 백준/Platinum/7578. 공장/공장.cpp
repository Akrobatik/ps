#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
  void Init(int n) {
    tree.clear(), tree.resize(n);
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

  vector<int> tree;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  unordered_map<int, int> hm;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    hm[x] = i;
  }

  FenwickTree tree;
  tree.Init(n + 1);
  int64_t cnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x = hm[x];
    cnt += i - tree.Query(x);
    tree.Update(x, 1);
  }
  cout << cnt;

  return 0;
}
