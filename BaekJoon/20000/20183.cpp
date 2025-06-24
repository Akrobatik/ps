// Title : 골목 대장 호석 - 효율성 2
// Link  : https://www.acmicpc.net/problem/20183 
// Time  : 1108 ms
// Memory: 23668 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, st, en;
  int64_t c;
  cin >> n >> m >> st >> en >> c;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  vector<int64_t> memo;

  auto Check = [&](int x) {
    memo.assign(n + 1, INT64_MAX);

    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;

    auto Push = [&](int u, int64_t w) {
      if (memo[u] <= w || w > c) return;
      memo[u] = w;
      pq.push({w, u});
    };

    Push(st, 0);
    while (!pq.empty()) {
      auto [w, cur] = pq.top();
      pq.pop();

      if (memo[cur] != w) continue;
      if (cur == en) return true;

      for (auto [nxt, ww] : edges[cur]) {
        if (ww <= x) Push(nxt, w + ww);
      }
    }
    return false;
  };

  int lo = 0, hi = 1e9 + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (!Check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  cout << (hi == 1e9 + 1 ? -1 : hi);

  return 0;
}
