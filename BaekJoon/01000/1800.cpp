// Title : 인터넷 설치
// Link  : https://www.acmicpc.net/problem/1800 
// Time  : 76 ms
// Memory: 3108 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

vector<pair<int, int>> edges[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p, k;
  cin >> n >> p >> k;

  while (p--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  auto GetId = [&](int i, int r) {
    return r * (n + 1) + i;
  };

  int nd = (k + 1) * (n + 1);
  vector<int> dist(nd);
  priority_queue<tup, vector<tup>, greater<tup>> pq;

  auto Push = [&](int i, int r, int w, int ww, int x) {
    if (ww > x && ++r > k) return;
    int id = GetId(i, r);
    w += ww;
    if (dist[id] <= w) return;
    dist[id] = w;
    pq.push({w, i, r});
  };

  auto Check = [&](int x) {
    dist.assign(nd, INT_MAX);

    Push(1, 0, 0, 0, x);
    while (!pq.empty()) {
      auto [w, i, r] = pq.top();
      pq.pop();

      if (dist[GetId(i, r)] != w) continue;
      if (i == n) return true;

      for (auto [nxt, ww] : edges[i]) {
        Push(nxt, r, w, ww, x);
      }
    }

    return false;
  };

  int lo = -1, hi = 1e6 + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  cout << (hi != 1e6 + 1 ? hi : -1);

  return 0;
}
