// Title : 트리와 뽀미
// Link  : https://www.acmicpc.net/problem/33580
// Time  : 64 ms
// Memory: 21956 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1001][5001];
vector<int> edges[5001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector<int> coords(t);
  for (auto& e : coords) cin >> e;

  for (int i = 1; i <= t; i++) {
    for (int j = 0; j <= n; j++) {
      memo[i][j] = INT_MIN;
    }
  }

  for (int i = 1; i <= t; ++i) {
    for (int j = 1; j <= n; j++) {
      if (memo[i - 1][j] == INT_MIN) continue;

      memo[i][j] = max<int>(memo[i][j], memo[i - 1][j] + (j == coords[i - 1]));
      for (auto nxt : edges[j]) {
        memo[i][nxt] = max<int>(memo[i][nxt], memo[i - 1][j] + (nxt == coords[i - 1]));
      }
    }
  }

  int maxx = INT_MIN;
  for (int i = 1; i <= n; i++) {
    maxx = max<int>(maxx, memo[t][i]);
  }
  cout << maxx;

  return 0;
}
