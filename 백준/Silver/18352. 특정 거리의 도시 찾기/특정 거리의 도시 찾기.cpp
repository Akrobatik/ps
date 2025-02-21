#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, x;
  cin >> n >> m >> k >> x;
  vector<int> memo(n + 1, INT_MAX);
  vector<vector<int>> edges(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, x});
  while (!pq.empty()) {
    auto [w, i] = pq.top();
    pq.pop();

    if (memo[i] <= w) continue;
    memo[i] = w;

    for (auto t : edges[i]) {
      if (memo[t] <= w + 1) continue;
      pq.push({w + 1, t});
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (memo[i] != k) continue;
    cout << i << "\n";
    ++cnt;
  }

  if (!cnt) cout << "-1";

  return 0;
}
