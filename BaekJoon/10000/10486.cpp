// Title : Trapezoid Walkway
// Link  : https://www.acmicpc.net/problem/10486 
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e3;
constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n && n) {
    vector<vector<pair<int, int>>> g(kMax + 1);
    for (int i = 0; i < n; i++) {
      int a, b, h;
      cin >> a >> b >> h;
      int w = (a + b) * h;
      g[a].push_back({b, w});
      g[b].push_back({a, w});
    }

    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
    vector<int64_t> dist(kMax + 1, kInf);

    auto Push = [&](int u, int64_t d) {
      if (dist[u] <= d) return;
      dist[u] = d;
      pq.push({d, u});
    };

    int st, en;
    cin >> st >> en;

    Push(st, 0);
    while (!pq.empty()) {
      auto [d, cur] = pq.top();
      pq.pop();

      if (dist[cur] != d) continue;
      if (cur == en) break;

      for (auto [nxt, w] : g[cur]) {
        Push(nxt, d + w);
      }
    }

    int64_t d = dist[en];
    cout << (d / 100) << "." << setw(2) << setfill('0') << (d % 100) << "\n";
  }

  return 0;
}