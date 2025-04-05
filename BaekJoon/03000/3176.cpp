// Title : 도로 네트워크
// Link  : https://www.acmicpc.net/problem/3176
// Time  : 132 ms
// Memory: 28640 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[100001];
int parents[100001][17], minn[100001][17], maxx[100001][17];
int heights[100001];

pair<int, int> Query(int a, int b) {
  int rmin = INT_MAX, rmax = 0;

  if (heights[a] > heights[b]) swap(a, b);
  uint32_t delta = heights[b] - heights[a];
  while (delta) {
    int lsb = countr_zero(delta);
    rmin = min<int>(rmin, minn[b][lsb]);
    rmax = max<int>(rmax, maxx[b][lsb]);
    b = parents[b][lsb];
    delta ^= (1 << lsb);
  }
  if (a == b) return {rmin, rmax};

  int maxh = 31 - countl_zero((uint32_t)heights[a]);
  for (int h = maxh; h >= 0; h--) {
    if (parents[a][h] != parents[b][h]) {
      rmin = min<int>({rmin, minn[a][h], minn[b][h]});
      rmax = max<int>({rmax, maxx[a][h], maxx[b][h]});
      a = parents[a][h], b = parents[b][h];
    }
  }
  rmin = min<int>({rmin, minn[a][0], minn[b][0]});
  rmax = max<int>({rmax, maxx[a][0], maxx[b][0]});

  return {rmin, rmax};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    edges[u].push_back({v, l});
    edges[v].push_back({u, l});
  }

  queue<tuple<int, int, int>> q;
  q.push({1, 0, 0});
  while (!q.empty()) {
    auto [cur, par, h] = q.front();
    q.pop();

    heights[cur] = h;
    int limit = 32 - countl_zero((uint32_t)h);
    for (int i = 1; i < limit; i++) {
      int p = parents[cur][i - 1];
      parents[cur][i] = parents[p][i - 1];
      minn[cur][i] = min<int>(minn[cur][i - 1], minn[p][i - 1]);
      maxx[cur][i] = max<int>(maxx[cur][i - 1], maxx[p][i - 1]);
    }

    for (auto [nxt, l] : edges[cur]) {
      if (nxt == par) continue;
      parents[nxt][0] = cur;
      minn[nxt][0] = maxx[nxt][0] = l;
      q.push({nxt, cur, h + 1});
    }
  }

  int k;
  cin >> k;
  while (k--) {
    int d, e;
    cin >> d >> e;
    auto [rmin, rmax] = Query(d, e);
    cout << rmin << " " << rmax << "\n";
  }

  return 0;
}
