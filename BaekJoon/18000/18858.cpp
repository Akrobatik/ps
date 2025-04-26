// Title : 훈련소로 가는 날
// Link  : https://www.acmicpc.net/problem/18858 
// Time  : 16 ms
// Memory: 2812 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 998244353;

int memo[1001][101][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) memo[1][i][0] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k < j; k++) {
        memo[i + 1][k][0] += memo[i][j][0];
        if (memo[i + 1][k][0] >= kMod) memo[i + 1][k][0] -= kMod;
      }
      memo[i + 1][j][0] = ((int64_t)memo[i + 1][j][0] + memo[i][j][0] + memo[i][j][1]) % kMod;
      for (int k = j + 1; k <= m; k++) {
        memo[i + 1][k][1] = ((int64_t)memo[i + 1][k][1] + memo[i][j][0] + memo[i][j][1]) % kMod;
      }
    }
  }

  int64_t ans = 0;
  for (int i = 1; i <= m; i++) ans += memo[n][i][0] + memo[n][i][1];
  cout << ans % kMod;

  return 0;
}
