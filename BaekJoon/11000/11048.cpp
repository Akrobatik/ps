// Title : 이동하기
// Link  : https://www.acmicpc.net/problem/11048 
// Time  : 60 ms
// Memory: 5936 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      memo[i][j] = max<int>(memo[i - 1][j], memo[i][j - 1]) + x;
    }
  }
  cout << memo[n][m];

  return 0;
}
