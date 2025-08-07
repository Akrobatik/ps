// Title : 불꽃놀이의 아름다움
// Link  : https://www.acmicpc.net/problem/31839 
// Time  : 212 ms
// Memory: 27264 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 2e5;

vector<int> edges[kMax + 1];
int weights[kMax + 1];
pair<int64_t, int64_t> memo[kMax + 1];

void DFS1(int cur, int par) {
  auto& [ccnt, csum] = memo[cur];
  ccnt = weights[cur];
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    DFS1(nxt, cur);
    auto [ncnt, nsum] = memo[nxt];
    ccnt += ncnt;
    csum += ncnt + nsum;
  }
}

void DFS2(int cur, int par) {
  auto [ccnt, csum] = memo[cur];
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    auto& [ncnt, nsum] = memo[nxt];
    int64_t cnt = ccnt - ncnt;
    int64_t sum = csum - (ncnt + nsum);
    ncnt += cnt;
    nsum += cnt + sum;
    DFS2(nxt, cur);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> weights[i];
  }
  DFS1(1, 0);
  DFS2(1, 0);

  int64_t maxx = 0;
  for (int i = 1; i <= n; i++) {
    maxx = max<int64_t>(maxx, memo[i].second);
  }
  cout << maxx;

  return 0;
}
