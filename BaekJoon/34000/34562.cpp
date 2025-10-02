// Title : 터치 앤 리턴
// Link  : https://www.acmicpc.net/problem/34562 
// Time  : 180 ms
// Memory: 84340 KB

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dist[1 << 20][20];
int mat[20][20];
int mind[20], memo[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  int mb = 1 << n;

  for (int i = 0; i < mb; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = k + 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = (i != j ? k + 1 : 0);
    }
  }

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    mat[u][v] = min<int>(mat[u][v], w);
    mat[v][u] = min<int>(mat[v][u], w);
  }

  for (int l = 1; l < n; l++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        mat[i][j] = min<int>(mat[i][j], mat[i][l] + mat[l][j]);
      }
    }
  }

  vector<int> incl, excl;
  dist[1][0] = 0;
  for (int i = 1; i < mb; i += 2) {
    incl.clear(), excl.clear();
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        incl.push_back(j);
      } else {
        excl.push_back(j);
      }
    }

    for (auto j : incl) {
      for (auto l : excl) {
        int nb = i | (1 << l);
        dist[nb][l] = min<int>(dist[nb][l], dist[i][j] + mat[j][l]);
      }
    }
  }

  for (int i = 0; i < n; i++) mind[i] = k + 1;

  for (int i = 1; i < mb; i += 2) {
    int pc = popcount((uint32_t)i) - 1;
    for (int j = 0; j < n; j++) {
      mind[pc] = min<int>(mind[pc], dist[i][j] + mat[j][0]);
    }
  }

  vector<pair<int, int>> arr;
  for (int i = 1; i < n; i++) {
    if (mind[i] > k) continue;
    while (!arr.empty() && arr.back().second >= mind[i]) arr.pop_back();
    arr.push_back({i * i, mind[i]});
  }

  int na = arr.size(), limit = 0;
  for (int i = 1; i <= k; i++) {
    memo[i] = max<int>(memo[i], memo[i - 1]);
    while (limit < na && arr[limit].second <= i) ++limit;
    for (int j = 0; j < limit; j++) {
      auto [r, w] = arr[j];
      memo[i] = max<int>(memo[i], memo[i - w] + r);
    }
  }
  cout << memo[k];

  return 0;
}