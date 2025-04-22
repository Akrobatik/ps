// Title : 사과나무
// Link  : https://www.acmicpc.net/problem/20002 
// Time  : 16 ms
// Memory: 2376 KB

#include <bits/stdc++.h>

using namespace std;

int memo[301][301];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      memo[i][j] = memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1] + x;
    }
  }

  int maxx = INT_MIN;
  for (int k = 1; k <= n; k++) {
    for (int i = k; i <= n; i++) {
      for (int j = k; j <= n; j++) {
        maxx = max<int>(maxx, memo[i][j] - memo[i - k][j] - memo[i][j - k] + memo[i - k][j - k]);
      }
    }
  }
  cout << maxx;

  return 0;
}
