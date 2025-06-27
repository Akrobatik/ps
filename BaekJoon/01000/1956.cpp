// Title : 운동
// Link  : https://www.acmicpc.net/problem/1956 
// Time  : 84 ms
// Memory: 2680 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int v, e;
  cin >> v >> e;
  vector<vector<int>> dist(v + 1, vector<int>(v + 1, INT_MAX >> 1));
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
  }

  for (int k = 0; k < v; k++) {
    for (int i = 1; i <= v; i++) {
      for (int j = 1; j <= v; j++) {
        dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int minn = INT_MAX;
  for (int i = 1; i <= v; i++) minn = min<int>(minn, dist[i][i]);

  cout << (minn < (INT_MAX >> 1) ? minn : -1);

  return 0;
}
