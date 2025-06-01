// Title : 증가 수열의 개수
// Link  : https://www.acmicpc.net/problem/17409 
// Time  : 52 ms
// Memory: 6332 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> trees(k, vector<int>(n + 1));

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
    for (int j = 1; j < k; j++) {
      int v = Query(j - 1, x - 1);
      Update(j, x, v);
    }
  }
  cout << Query(k - 1, n);

  return 0;
}
