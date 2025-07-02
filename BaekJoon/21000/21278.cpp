// Title : 호석이 두 마리 치킨
// Link  : https://www.acmicpc.net/problem/21278 
// Time  : 0 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX >> 1));
  for (int i = 1; i <= n; i++) dist[i][i] = 0;
  while (m--) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = dist[b][a] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int minn = INT_MAX, a, b;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int cur = 0;
      for (int k = 1; k <= n; k++) {
        cur += min<int>(dist[i][k], dist[j][k]);
      }
      if (minn > cur) minn = cur, a = i, b = j;
    }
  }
  cout << a << " " << b << " " << (minn << 1);

  return 0;
}
