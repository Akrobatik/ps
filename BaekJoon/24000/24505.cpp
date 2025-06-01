// Title : blobhyperthink
// Link  : https://www.acmicpc.net/problem/24505 
// Time  : 148 ms
// Memory: 6724 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> trees(11, vector<int>(n + 1));

  auto Update = [&](int t, int i, int d) {
    auto& tree = trees[t];
    for (; i <= n; i += i & (-i)) {
      tree[i] += d;
      if (tree[i] >= kMod) tree[i] -= kMod;
    }
  };

  auto Query = [&](int t, int i) {
    int64_t res = 0;
    auto& tree = trees[t];
    for (; i; i -= i & (-i)) res += tree[i];
    return res % kMod;
  };

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    Update(0, x, 1);
    for (int j = 1; j < 11; j++) {
      int v = Query(j - 1, x - 1);
      Update(j, x, v);
    }
  }
  cout << Query(10, n);

  return 0;
}
