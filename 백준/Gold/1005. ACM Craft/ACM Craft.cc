#include <bits/stdc++.h>

using namespace std;

int cost[1001];
vector<int> cond[1001];
bool visited[1001];

void Solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> cost[i];
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    cond[y].push_back(x);
  }
  int w;
  cin >> w;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 1; i <= n; i++) {
    if (cond[i].empty()) pq.push({cost[i], i});
  }

  while (!pq.empty()) {
    auto [sec, id] = pq.top();
    pq.pop();

    if (id == w) {
      cout << sec << "\n";

      memset(visited + 1, 0, n);
      for (int i = 1; i <= n; i++) cond[i].clear();
      return;
    }

    if (visited[id]) continue;
    visited[id] = true;

    for (int i = 1; i <= n; i++) {
      auto pred = [](int _id) {
        return !visited[_id];
      };

      if (visited[i]) continue;
      auto& vec = cond[i];
      if (auto it = find_if(vec.begin(), vec.end(), pred); it != vec.end()) continue;
      pq.push({sec + cost[i], i});
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
