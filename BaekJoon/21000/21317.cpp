// Title : 징검다리 건너기
// Link  : https://www.acmicpc.net/problem/21317
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  int arr[20][2];
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
  cin >> k;

  int memo[21][2];
  memset(memo, 0, sizeof(memo));
  for (int i = 2; i <= n; i++) {
    memo[i][0] = memo[i - 1][0] + arr[i - 1][0];
    if (i > 2 && memo[i][0] > memo[i - 2][0] + arr[i - 2][1]) memo[i][0] = memo[i - 2][0] + arr[i - 2][1];
    memo[i][1] = memo[i - 1][1] + arr[i - 1][0];
    if (i > 2 && memo[i][1] > memo[i - 2][1] + arr[i - 2][1]) memo[i][1] = memo[i - 2][1] + arr[i - 2][1];
    if (i > 3 && memo[i][1] > memo[i - 3][0] + k) memo[i][1] = memo[i - 3][0] + k;
  }
  cout << min<int>(memo[n][0], memo[n][1]);

  return 0;
}
