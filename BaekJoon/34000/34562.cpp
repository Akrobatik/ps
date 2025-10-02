// Title : 터치 앤 리턴
// Link  : https://www.acmicpc.net/problem/34562 
// Time  : 228 ms
// Memory: 88124 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> mat(n, vector<int>(n, k + 1));
  for (int i = 0; i < n; i++) mat[i][i] = 0;
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

  int64_t mb = 1LL << n;
  vector<int> incl, excl;
  vector<vector<int>> dist(n, vector<int>(mb, k + 1));
  dist[0][1] = 0;
  for (int i = 0; i < mb; i++) {
    if (~i & 1) continue;

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
        dist[l][i | (1 << l)] = min<int>(dist[l][i | (1 << l)], dist[j][i] + mat[j][l]);
      }
    }
  }

  vector<int> mind(n, k + 1);
  for (int i = 0; i < mb; i++) {
    if (~i & 1) continue;

    int pc = popcount((uint32_t)i) - 1;
    for (int j = 0; j < n; j++) {
      if (~i & (1 << j)) continue;
      mind[pc] = min<int>(mind[pc], dist[j][i] + mat[j][0]);
    }
  }

  vector<pair<int, int>> arr;
  for (int i = 1; i < n; i++) {
    if (mind[i] > k) continue;
    while (!arr.empty() && arr.back().second >= mind[i]) arr.pop_back();
    arr.push_back({i * i, mind[i]});
  }

  int na = arr.size(), limit = 0;
  vector<int> memo(k + 1);
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