// Title : K-지폐
// Link  : https://www.acmicpc.net/problem/28131 
// Time  : 308 ms
// Memory: 18092 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[10000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, s, t;
  cin >> n >> m >> k >> s >> t;
  --s, --t;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges[u].push_back({v, w});
  }

  vector<int> memo(n * k, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  auto Push = [&](int x, int w) {
    x = (w % k) * n + x;
    if (memo[x] <= w) return;
    memo[x] = w;
    pq.push({w, x});
  };

  Push(s, 0);
  while (!pq.empty()) {
    auto [cw, cx] = pq.top();
    pq.pop();

    if (memo[cx] < cw) continue;

    int x = cx % n;
    for (auto [nx, nw] : edges[x]) {
      Push(nx, cw + nw);
    }
  }

  if (memo[t] == INT_MAX) {
    cout << "IMPOSSIBLE";
  } else {
    cout << memo[t];
  }

  return 0;
}
