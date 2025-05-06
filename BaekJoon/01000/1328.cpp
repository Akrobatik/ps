// Title : 고층 빌딩
// Link  : https://www.acmicpc.net/problem/1328 
// Time  : 0 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int memo[100][100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l, r;
  cin >> n >> l >> r;
  memo[0][0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= i; k++) {
        memo[i][j][k] = ((int64_t)(i - 1) * memo[i - 1][j][k] + memo[i - 1][j][k - 1] + memo[i - 1][j - 1][k]) % kMod;
      }
    }
  }
  cout << memo[n - 1][l - 1][r - 1];

  return 0;
}
