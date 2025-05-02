// Title : Astromeeting
// Link  : https://www.acmicpc.net/problem/3075 
// Time  : 24 ms
// Memory: 2060 KB

#include <bits/stdc++.h>

using namespace std;

int coord[100];
int memo[100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, p, q;
    cin >> n >> p >> q;
    for (int i = 0; i < n; i++) cin >> coord[i], --coord[i];

    for (int i = 0; i < p; i++) {
      for (int j = 0; j < p; j++) {
        memo[i][j] = INT_MAX >> 1;
      }
    }
    for (int i = 0; i < p; i++) memo[i][i] = 0;

    while (q--) {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      memo[u][v] = min<int>(memo[u][v], w);
      memo[v][u] = min<int>(memo[v][u], w);
    }

    for (int k = 0; k < p; k++) {
      for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
          memo[i][j] = min<int>(memo[i][j], memo[i][k] + memo[k][j]);
        }
      }
    }

    int idx;
    int64_t minn = INT64_MAX;
    for (int i = 0; i < p; i++) {
      bool ok = true;
      int64_t sum = 0;
      for (int j = 0; ok && j < n; j++) {
        int64_t dist = (int64_t)memo[coord[j]][i];
        ok = (dist < (INT_MAX >> 1));
        sum += dist * dist;
      }
      if (ok && minn > sum) minn = sum, idx = i + 1;
    }
    cout << idx << " " << minn << "\n";
  }

  return 0;
}
