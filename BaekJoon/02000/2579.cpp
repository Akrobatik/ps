// Title : 계단 오르기
// Link  : https://www.acmicpc.net/problem/2579
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _memo[302][2];
  auto memo = _memo + 1;
  memset(_memo, 0, sizeof(_memo));

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    memo[i][0] = max<int>(memo[i - 2][0], memo[i - 2][1]) + v;
    memo[i][1] = memo[i - 1][0] + v;
  }
  cout << max<int>(memo[n][0], memo[n][1]);

  return 0;
}
