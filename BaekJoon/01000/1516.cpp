// Title : 게임 개발
// Link  : https://www.acmicpc.net/problem/1516 
// Time  : 4 ms
// Memory: 2420 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> edges(n + 1);
  vector<int> deg(n + 1), time(n + 1), memo(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> time[i];
    int x;
    while (cin >> x && x != -1) {
      edges[x].push_back(i);
      ++deg[i];
    }
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) pq.push({time[i], i});
  }

  while (!pq.empty()) {
    auto [t, cur] = pq.top();
    pq.pop();

    memo[cur] = t;
    for (auto nxt : edges[cur]) {
      if (--deg[nxt] == 0) {
        pq.push({t + time[nxt], nxt});
      }
    }
  }

  for (int i = 1; i <= n; i++) cout << memo[i] << "\n";

  return 0;
}
