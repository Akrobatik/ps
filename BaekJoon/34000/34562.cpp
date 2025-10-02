// Title : 터치 앤 리턴
// Link  : https://www.acmicpc.net/problem/34562 
// Time  : 440 ms
// Memory: 174140 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, k;
  cin >> n >> m >> k;

  vector<vector<int64_t>> mat(n, vector<int64_t>(n, kInf));
  for (int i = 0; i < n; i++) mat[i][i] = 0;
  while (m--) {
    int64_t u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    mat[u][v] = min<int64_t>(mat[u][v], w);
    mat[v][u] = min<int64_t>(mat[v][u], w);
  }

  for (int l = 1; l < n; l++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        mat[i][j] = min<int64_t>(mat[i][j], mat[i][l] + mat[l][j]);
      }
    }
  }

  int64_t mb = 1LL << n;
  vector<vector<int64_t>> dist(n, vector<int64_t>(mb, kInf));
  dist[0][1] = 0;
  for (int i = 0; i < mb; i++) {
    if (~i & 1) continue;
    for (int j = 0; j < n; j++) {
      if (~i & (1 << j)) continue;

      int64_t cur = dist[j][i];
      if (cur == kInf) continue;

      for (int l = 0; l < n; l++) {
        if (i & (1 << l)) continue;
        if (mat[j][l] == kInf) continue;
        dist[l][i | (1 << l)] = min<int64_t>(dist[l][i | (1 << l)], cur + mat[j][l]);
      }
    }
  }

  vector<int64_t> mind(n, kInf);
  for (int i = 0; i < mb; i++) {
    if (~i & 1) continue;

    int pc = popcount((uint32_t)i) - 1;
    for (int j = 0; j < n; j++) {
      if (~i & (1 << j)) continue;

      int64_t d = dist[j][i], w = mat[j][0];
      if (d == kInf || w == kInf) continue;
      mind[pc] = min<int64_t>(mind[pc], d + w);
    }
  }

  vector<pair<int64_t, int64_t>> arr;
  for (int i = 1; i < n; i++) {
    if (mind[i] > k) continue;
    while (!arr.empty() && arr.back().second >= mind[i]) arr.pop_back();
    arr.push_back({i * i, mind[i]});
  }

  vector<int64_t> memo(k + 1);
  for (int i = 1; i <= k; i++) {
    memo[i] = max<int64_t>(memo[i], memo[i - 1]);
    for (auto [r, w] : arr) {
      if (w > i) break;
      memo[i] = max<int64_t>(memo[i], memo[i - w] + r);
    }
  }
  cout << memo[k];

  return 0;
}