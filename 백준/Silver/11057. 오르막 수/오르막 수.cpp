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
        memo[i][k] = (memo[i][k] + memo[i - 1][j]) % kMod;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= 9; i++) ans += memo[n][i];
  cout << ans % kMod;

  return 0;
}
