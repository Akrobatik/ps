// Title : 블록 정리
// Link  : https://www.acmicpc.net/problem/2937 
// Time  : 0 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> memo(n + 1, vector<int>(n + 1));
  for (int i = 0; i < m; i++) {
    int y, x;
    cin >> y >> x;
    memo[y][x] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      memo[i][j] += memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1];
    }
  }

  auto Count = [&](int r, int c) {
    int maxx = 0;
    for (int i = 0; i + r <= n; i++) {
      for (int j = 0; j + c <= n; j++) {
        int cur = memo[i + r][j + c] - memo[i + r][j] - memo[i][j + c] + memo[i][j];
        maxx = max<int>(maxx, cur);
      }
    }
    return maxx;
  };

  int maxx = 0;
  for (int i = m / n + (m % n != 0); i * i <= m; i++) {
    if (m % i) continue;
    int r = i, c = m / i;
    maxx = max<int>(maxx, Count(r, c));
    if (r != c) maxx = max<int>(maxx, Count(c, r));
  }
  cout << m - maxx;

  return 0;
}
