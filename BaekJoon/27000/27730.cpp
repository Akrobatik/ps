// Title : 견우와 직녀
// Link  : https://www.acmicpc.net/problem/27730 
// Time  : 184 ms
// Memory: 25048 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5;

struct Graph {
  void Init(int n) {
    edges.assign(n + 1, vector<pair<int, int>>());
    memo.assign(n + 1, vector<pair<int64_t, int64_t>>());
    msum.assign(n + 1, {});
  }

  void AddEdge(int u, int v, int w) {
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  tuple<int, int64_t, int64_t> FindCentroid() {
    DFS1(1, 0);
    DFS2(1, 0);

    int n = edges.size() - 1;
    int64_t minn = INT64_MAX, mi;
    for (int i = 1; i <= n; i++) {
      if (minn > msum[i].second) minn = msum[i].second, mi = i;
    }
    auto [cnt, sum] = msum[mi];
    return {mi, cnt, sum};
  }

 private:
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

  vector<vector<pair<int, int>>> edges;
  vector<vector<pair<int64_t, int64_t>>> memo;
  vector<pair<int64_t, int64_t>> msum;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Graph g;

  int n;
  cin >> n;
  g.Init(n);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.AddEdge(u, v, w);
  }
  auto [ui, ucnt, usum] = g.FindCentroid();

  int m;
  cin >> m;
  g.Init(m);
  for (int i = 1; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.AddEdge(u, v, w);
  }
  auto [vi, vcnt, vsum] = g.FindCentroid();

  cout << ui << " " << vi << "\n"
       << ucnt * (vcnt + vsum) + vcnt * (ucnt + usum) - ucnt * vcnt;

  return 0;
}
