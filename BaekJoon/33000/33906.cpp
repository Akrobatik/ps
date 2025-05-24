// Title : 점심 나가서 먹기
// Link  : https://www.acmicpc.net/problem/33906 
// Time  : 164 ms
// Memory: 14452 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> xrr(n), yrr(n);
  for (auto& e : xrr) cin >> e;
  for (auto& e : yrr) cin >> e;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  vector<int64_t> dist(n + 1, INT64_MAX >> 1);
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;

  auto Push = [&](int x, int64_t w) {
    if (dist[x] <= w) return;
    dist[x] = w;
    pq.push({w, x});
  };

  Push(1, 0);

  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();

    if (w != dist[cur]) continue;

    for (auto [nxt, ww] : edges[cur]) {
      Push(nxt, w + ww);
    }
  }

  int r, c;
  int br = INT_MAX, bc = INT_MAX;
  for (int i = 2; i <= n; i++) {
    if (dist[i] < (INT64_MAX >> 1)) {
      if (xrr[i - 1] != 0 && xrr[i - 1] < br) br = xrr[i - 1], r = i;
      if (yrr[i - 1] != 0 && yrr[i - 1] < bc) bc = yrr[i - 1], c = i;
    }
  }

  vector<int64_t> dr(n + 1, INT64_MAX >> 1);
  dr[r] = 0;
  pq.push({0, r});
  int64_t dst = -1;
  while (!pq.empty()) {
    auto [w, cur] = pq.top();
    pq.pop();

    if (w != dr[cur]) continue;

    if (cur == c) {
      dst = w;
      break;
    }

    for (auto [nxt, ww] : edges[cur]) {
      if (dr[nxt] <= w + ww) continue;
      dr[nxt] = w + ww;
      pq.push({w + ww, nxt});
    }
  }

  if (dst == -1) dst = dr[c];

  cout << dist[r] + dist[c] + dst;

  return 0;
}