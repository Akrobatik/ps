#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> seq(n);
  for (int i = 0; i < n; i++) cin >> seq[i];
  vector<int> ans(seq);
  sort(ans.begin(), ans.end());
  int m;
  cin >> m;
  vector<tuple<int, int, int>> edges(m);
  for (int i = 0; i < m; i++) cin >> get<1>(edges[i]) >> get<2>(edges[i]) >> get<0>(edges[i]);
  set<vector<int>> memo;
  priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
  pq.push({0, seq});
  while (!pq.empty()) {
    auto [c, v] = pq.top();
    pq.pop();

    auto it = memo.find(v);
    if (it != memo.end()) continue;
    memo.insert(v);

    if (v == ans) {
      cout << c;
      return 0;
    }

    for (auto& edge : edges) {
      auto [w, a, b] = edge;
      auto vv = v;
      swap(vv[a - 1], vv[b - 1]);
      if (memo.find(vv) != memo.end()) continue;
      pq.push({c + w, vv});
    }
  }
  cout << -1;
  return 0;
}
