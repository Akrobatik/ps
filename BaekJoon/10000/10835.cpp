// Title : 카드게임
// Link  : https://www.acmicpc.net/problem/10835 
// Time  : 36 ms
// Memory: 33500 KB

#include <bits/stdc++.h>

using namespace std;

int memo[2001][2001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), brr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
  memo[0][0] = 0;

  int ans = 0, limit = (n << 1) - 1;
  for (int i = 0; i < limit; i++) {
    int minn = max<int>(i - n + 1, 0);
    int maxx = min<int>(i, n - 1);
    for (int j = minn; j <= maxx; j++) {
      int l = j, r = i - j;
      if (memo[l][r] == -1) continue;
      memo[l + 1][r + 1] = max<int>(memo[l + 1][r + 1], memo[l][r]);
      memo[l + 1][r] = max<int>(memo[l + 1][r], memo[l][r]);
      if (arr[l] > brr[r]) {
        memo[l][r + 1] = max<int>(memo[l][r + 1], memo[l][r] + brr[r]);
        ans = max<int>(ans, memo[l][r + 1]);
      }
    }
  }
  cout << ans;

  return 0;
}
