// Title : 별자리
// Link  : https://www.acmicpc.net/problem/29894 
// Time  : 132 ms
// Memory: 8672 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<tup> edges(m);
  for (auto& [w, u, v] : edges) cin >> u >> v >> w;
  sort(edges.begin(), edges.end(), greater<tup>());

  int sum[2] = {};
  vector<int> memo(n + 1), deg(n + 1), minn(n + 1), maxx(n + 1);
  vector<array<int, 4>> cnt(n + 1, {1, 0, 0, 0});
  iota(memo.begin(), memo.end(), 0);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Dec = [&](int i) {
    if (1 <= minn[i] && maxx[i] <= 2) --sum[minn[i] - 1];
  };

  auto Inc = [&](int i) {
    if (1 <= minn[i] && maxx[i] <= 2) ++sum[minn[i] - 1];
  };

  auto Update = [&](int x, int p) {
    int o = deg[x];
    if (o <= 2) {
      --cnt[p][o];
      ++cnt[p][o + 1];

      int mn = INT_MAX, mx = 0;
      for (int i = 0; i < 4; i++) {
        if (cnt[p][i] == 0) continue;
        mn = min<int>(mn, i);
        mx = i;
      }
      minn[p] = mn, maxx[p] = mx;
    }
    ++deg[x];
  };

  auto Union = [&](int a, int b) {
    int pa = Find(a), pb = Find(b);
    if (pa == pb) {
      Dec(pa);
      Update(a, pa);
      Update(b, pb);
      Inc(pa);
    } else {
      Dec(pa);
      Dec(pb);
      memo[pb] = pa;
      for (int i = 0; i < 4; i++) {
        cnt[pa][i] += cnt[pb][i];
      }
      Update(a, pa);
      Update(b, pa);
      Inc(pa);
    }
  };

  int mn = INT_MAX, mw;
  int idx = 0;
  while (idx < m) {
    int w = get<0>(edges[idx]);
    while (idx < m && get<0>(edges[idx]) == w) {
      auto [_, u, v] = edges[idx++];
      Union(u, v);
    }
    int d = abs(sum[0] - sum[1]);
    if (mn >= d) mn = d, mw = w;
  }
  cout << mw << " " << mn;

  return 0;
}
