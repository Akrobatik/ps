// Title : 2차원 배열의 합
// Link  : https://www.acmicpc.net/problem/2167 
// Time  : 12 ms
// Memory: 2416 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> memo(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      memo[i][j] = memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1] + x;
    }
  }

  int k;
  cin >> k;
  while (k--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    --y1, --x1;
    cout << memo[y2][x2] - memo[y2][x1] - memo[y1][x2] + memo[y1][x1] << "\n";
  }

  return 0;
}
