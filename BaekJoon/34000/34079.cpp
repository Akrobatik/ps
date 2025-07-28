// Title : 좋아하는 다이아몬드가 안경을 깜빡했다
// Link  : https://www.acmicpc.net/problem/34079 
// Time  : 252 ms
// Memory: 14756 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector<int> dist(n + 1);
  vector<bool> visited(n + 1);
  queue<int> q;

  auto Push = [&](int x) {
    if (visited[x]) return;
    visited[x] = true;
    q.push(x);
  };

  Push(1);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      dist[cur] = i;
      for (auto nxt : edges[cur]) {
        Push(nxt);
      }
    }
  }

  visited.assign(n + 1, false);

  auto PushQ = [&](int x, int d) {
    if (dist[x] != d) return;
    if (visited[x]) return;
    visited[x] = true;
    q.push(x);
  };

  int ans = 0;
  PushQ(n, dist[n]);
  for (int i = 1; !q.empty() && ans == 0; i++) {
    int nq = q.size(), all = nq;
    while (nq--) {
      int cur = q.front();
      q.pop();

      for (auto nxt : edges[cur]) {
        PushQ(nxt, dist[n] - i);
      }
    }

    if (q.size() == 1) {
      ans = q.front();
    }
  }
  cout << ans;

  return 0;
}
