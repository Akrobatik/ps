// Title : 오르막 수
// Link  : https://www.acmicpc.net/problem/11057
// Time  : 0 ms
// Memory: 2060 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 10007;

int memo[1001][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  memo[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = j; k <= 9; k++) {
        memo[i][k] += memo[i - 1][j];
      }
    }
    for (int j = 0; j <= 9; j++) memo[i][j] %= kMod;
  }

  int ans = 0;
  for (int i = 0; i <= 9; i++) ans += memo[n][i];
  cout << ans % kMod;

  return 0;
}
