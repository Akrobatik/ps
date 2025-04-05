// Title : 공장
// Link  : https://www.acmicpc.net/problem/7578
// Time  : 152 ms
// Memory: 7884 KB

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

int memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    memo[x] = i;
  }

  FenwickTree tree;
  tree.Init(n + 1);
  int64_t cnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x = memo[x];
    cnt += i - tree.Query(x);
    tree.Update(x, 1);
  }
  cout << cnt;

  return 0;
}
