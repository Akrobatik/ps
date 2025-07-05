// Title : 마라톤 2
// Link  : https://www.acmicpc.net/problem/10653 
// Time  : 20 ms
// Memory: 2552 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  k = min<int>(k, n - 2);
  vector<pair<int, int>> yx(n);
  for (auto& [y, x] : yx) cin >> y >> x;

  vector<vector<int>> memo(n, vector<int>(k + 1, INT_MAX >> 1));
  memo[0][0] = 0;
  for (int i = 1; i < n; i++) {
    auto [iy, ix] = yx[i];
    int limit = min<int>(i - 1, k);
    for (int j = 0; j <= limit; j++) {
      for (int l = 0; l <= j; l++) {
        auto [ly, lx] = yx[i - l - 1];
        memo[i][j] = min<int>(memo[i][j], memo[i - l - 1][j - l] + abs(iy - ly) + abs(ix - lx));
      }
    }
  }

  int minn = INT_MAX;
  for (int i = 0; i <= k; i++) minn = min<int>(minn, memo[n - 1][i]);
  cout << minn;

  return 0;
}
