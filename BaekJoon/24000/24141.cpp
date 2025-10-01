// Title : インフルエンザ (Flu)
// Link  : https://www.acmicpc.net/problem/24141 
// Time  : 84 ms
// Memory: 13952 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e3;

int ids[kMax][kMax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, d, k;
  cin >> n >> m >> d >> k;
  int d2 = d * d;

  for (int i = 1; i <= n; i++) {
    int y, x;
    cin >> x >> y;
    ids[y][x] = i;
  }

  vector<vector<int>> g(n + 1);
  for (int y = 0; y < kMax; y++) {
    for (int x = 0; x < kMax; x++) {
      int i1 = ids[y][x];
      if (!i1) continue;

      for (int dy = -d; dy <= d; dy++) {
        int y2 = y + dy;
        if (!(0 <= y2 && y2 < kMax)) continue;

        int rem = d2 - dy * dy;
        int md = 0;
        while ((md + 1) * (md + 1) <= rem) ++md;
        for (int dx = -md; dx <= md; dx++) {
          int x2 = x + dx;
          if (!(0 <= x2 && x2 < kMax)) continue;

          int i2 = ids[y2][x2];
          if (!i2 || i1 == i2) continue;

          g[i1].push_back(i2);
        }
      }
    }
  }

  int cnt = 0;
  vector<bool> vis(n + 1);
  queue<int> q;

  auto Push = [&](int x, int st) {
    if (vis[x]) return;
    vis[x] = true;
    cnt += (st + m > k);
    q.push(x);
  };

  Push(1, 0);
  for (int i = 1; i <= k && !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      for (auto nxt : g[cur]) {
        Push(nxt, i);
      }
    }
  }
  cout << cnt;

  return 0;
}