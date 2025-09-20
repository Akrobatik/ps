// Title : 단조수열 만들기
// Link  : https://www.acmicpc.net/problem/1209 
// Time  : 40 ms
// Memory: 32476 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  auto axr = arr;
  sort(axr.begin(), axr.end());
  axr.erase(unique(axr.begin(), axr.end()), axr.end());
  int m = axr.size();

  for (auto& e : arr) e = lower_bound(axr.begin(), axr.end(), e) - axr.begin();

  vector<vector<int64_t>> memo(n + 1, vector<int64_t>(m, kInf));
  for (auto& e : memo[0]) e = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto& val = memo[i + 1][j];
      int64_t av = axr[arr[i]], bv = axr[j];
      val = abs(av - bv) + memo[i][j];
      if (j) val = min<int64_t>(val, memo[i + 1][j - 1]);
    }
  }
  int64_t inc = memo[n][m - 1];

  memo.assign(n + 1, vector<int64_t>(m, kInf));
  for (auto& e : memo[0]) e = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto& val = memo[i + 1][j];
      int64_t av = axr[arr[n - i - 1]], bv = axr[j];
      val = abs(av - bv) + memo[i][j];
      if (j) val = min<int64_t>(val, memo[i + 1][j - 1]);
    }
  }
  int64_t dec = memo[n][m - 1];

  cout << min<int64_t>(inc, dec);

  return 0;
}
