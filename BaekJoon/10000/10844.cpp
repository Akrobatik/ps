// Title : 쉬운 계단 수
// Link  : https://www.acmicpc.net/problem/10844 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9;

int memo[101][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= 9; i++) memo[1][i] = 1;
  for (int i = 1; i < n; i++) {
    memo[i + 1][1] = memo[i][0];
    memo[i + 1][8] = memo[i][9];
    for (int j = 1; j <= 8; j++) {
      memo[i + 1][j - 1] += memo[i][j];
      memo[i + 1][j + 1] += memo[i][j];
    }

    for (int j = 0; j <= 9; j++) memo[i + 1][j] %= kMod;
  }

  int64_t ans = 0;
  for (int i = 0; i <= 9; i++) ans += memo[n][i];
  cout << ans % kMod;

  return 0;
}
