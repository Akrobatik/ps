// Title : 개미
// Link  : https://www.acmicpc.net/problem/14942
// Time  : 88 ms
// Memory: 21472 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[100001];
int ants[100001];
int heights[100001];
pair<int, int> memo[100001][16];

void Traverse(int cur, int par, int h) {
  heights[cur] = h;
  for (auto [nxt, w] : edges[cur]) {
    if (nxt == par) continue;
    memo[nxt][0] = {cur, w};
    Traverse(nxt, cur, h + 1);
  }
}

int Find(int cur, int rem) {
  if (cur == 1) return 1;

  int h = heights[cur];
  int maxx = 31 - countl_zero((uint32_t)h);
  for (int j = maxx; j >= 0; j--) {
    auto [nxt, w] = memo[cur][j];
    if (rem >= w) return Find(nxt, rem - w);
  }
  return cur;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ants[i];
  }

  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  Traverse(1, 0, 0);
  for (int j = 1; j < 16; j++) {
    for (int i = 1; i <= n; i++) {
      if (heights[i] < (1 << j)) continue;
      int par = memo[i][j - 1].first;
      memo[i][j].first = memo[par][j - 1].first;
      memo[i][j].second = memo[i][j - 1].second + memo[par][j - 1].second;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << Find(i, ants[i]) << "\n";
  }

  return 0;
}
