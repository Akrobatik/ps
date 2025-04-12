// Title : 동전 게임
// Link  : https://www.acmicpc.net/problem/6000 
// Time  : 28 ms
// Memory: 17668 KB

#include <bits/stdc++.h>

using namespace std;

int arr[2001];
int memo[2001][2001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = n; i >= 1; i--) cin >> arr[i];
  partial_sum(arr, arr + n + 1, arr);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      memo[i][j] = max<int>(memo[i][j], memo[i][j - 1]);
      for (auto step : {j * 2 - 1, j * 2}) {
        if (step <= i) {
          memo[i][j] = max<int>(memo[i][j], arr[i] - memo[i - step][step]);
        }
      }
    }
  }
  cout << memo[n][1];

  return 0;
}
