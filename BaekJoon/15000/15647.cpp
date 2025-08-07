// Title : 로스팅하는 엠마도 바리스타입니다
// Link  : https://www.acmicpc.net/problem/15647 
// Time  : 356 ms
// Memory: 72276 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 3e5;

vector<pair<int, int>> edges[kMax + 1];
vector<pair<int64_t, int64_t>> memo[kMax + 1];
pair<int64_t, int64_t> msum[kMax + 1];

pair<int64_t, int64_t> DFS1(int cur, int par) {
  int64_t cnt = 1, val = 0;
  int sz = edges[cur].size();
  memo[cur].resize(sz);
  for (int i = 0; i < sz; i++) {
    auto [nxt, dist] = edges[cur][i];
    if (nxt == par) continue;
    auto [ncnt, nval] = DFS1(nxt, cur);
    int64_t cval = nval + ncnt * dist;
    memo[cur][i] = {ncnt, cval};
    cnt += ncnt, val += cval;
  }
  return msum[cur] = {cnt, val};
}

void DFS2(int cur, int par) {
  int sz = edges[cur].size();
  auto [scnt, sval] = msum[cur];
  for (int i = 0; i < sz; i++) {
    auto [nxt, dist] = edges[cur][i];
    if (nxt == par) continue;

    auto [ccnt, cval] = memo[cur][i];
    int64_t cnt = scnt - ccnt;
    int64_t val = sval - cval;
    msum[nxt].first += cnt;
    msum[nxt].second += val + cnt * dist;
    DFS2(nxt, cur);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  DFS1(1, 0);
  DFS2(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << msum[i].second << "\n";
  }

  return 0;
}
