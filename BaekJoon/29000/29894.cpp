// Title : 별자리
// Link  : https://www.acmicpc.net/problem/29894 
// Time  : 156 ms
// Memory: 10176 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int cnt[2] = {};
  vector<bool> visited(n + 1);
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;

    queue<int> q;
    int minn = INT_MAX, maxx = 0;

    auto Push = [&](int x) {
      if (visited[x]) return;
      visited[x] = true;
      minn = min<int>(minn, edges[x].size());
      maxx = max<int>(maxx, edges[x].size());
      q.push(x);
    };

    Push(i);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      for (auto nxt : edges[cur]) {
        Push(nxt);
      }
    }

    if (maxx <= 2) ++cnt[minn - 1];
  }

  cout << "1 " << abs(cnt[0] - cnt[1]);

  return 0;
}
