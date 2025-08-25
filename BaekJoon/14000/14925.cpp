// Title : 목장 건설하기
// Link  : https://www.acmicpc.net/problem/14925 
// Time  : 16 ms
// Memory: 5996 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int maxx = 0;
  vector<vector<int>> memo(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c != '0') continue;
      memo[i][j] = min<int>({memo[i][j - 1], memo[i - 1][j], memo[i - 1][j - 1]}) + 1;
      maxx = max<int>(maxx, memo[i][j]);
    }
  }
  cout << maxx;

  return 0;
}
