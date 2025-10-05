// Title : 경비행기
// Link  : https://www.acmicpc.net/problem/2585 
// Time  : 88 ms
// Memory: 10340 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> arr{{0, 0}, {10000, 10000}};
  while (n--) {
    int y, x;
    cin >> y >> x;
    arr.push_back({y, x});
  }
  n = arr.size();

  vector<int> dist;
  for (int i = 0; i * i <= (int)2e7; i++) {
    dist.push_back(i * i * 100);
  }

  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n; i++) {
    auto [y1, x1] = arr[i];
    for (int j = i + 1; j < n; j++) {
      auto [y2, x2] = arr[j];
      int dy = y1 - y2, dx = x1 - x2;
      int r = dy * dy + dx * dx;
      int d = lower_bound(dist.begin(), dist.end(), r) - dist.begin();
      g[i].push_back({j, d});
      g[j].push_back({i, d});
    }
  }

  for (int i = 0; i < n; i++) {
    sort(g[i].begin(), g[i].end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.second < rhs.second;
    });
  }

  auto Check = [&](int lim) -> bool {
    vector<bool> vis(n);
    queue<int> q;

    q.push(0);
    vis[0] = true;
    for (int i = 0; !q.empty() && i <= k; i++) {
      int nq = q.size();
      while (nq--) {
        int cur = q.front();
        q.pop();

        for (auto [nxt, w] : g[cur]) {
          if (w > lim) break;
          if (vis[nxt]) continue;
          vis[nxt] = true;
          q.push(nxt);
        }
      }
    }
    return vis[1];
  };

  int lo = 0, hi = 1415;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << hi;

  return 0;
}