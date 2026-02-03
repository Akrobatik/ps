// Title : Fell Walking
// Link  : https://www.acmicpc.net/problem/35244 
// Time  : 608 ms
// Memory: 2700 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 1);
  sort(ord.begin(), ord.end(),
       [&](int lhs, int rhs) { return arr[lhs] < arr[rhs]; });

  vector<vector<int>> g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int8_t> vis;

  auto Check = [&](int l, int r) {
    vis.assign(n + 1, 0);

    int lv = arr[ord[l]], rv = arr[ord[r]];
    queue<int> q;

    auto Push = [&](int x) {
      if (!(lv <= arr[x] && arr[x] <= rv) || vis[x]) return;
      vis[x] = 1;
      q.push(x);
    };

    Push(1);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto nxt : g[cur]) {
        Push(nxt);
      }
    }
    return vis[2];
  };

  int minn = INT_MAX;
  for (int l = 0, r = 0; l < n; l++) {
    while (r < n && !Check(l, r)) ++r;
    if (r == n) break;
    minn = min<int>(minn, arr[ord[r]] - arr[ord[l]]);
  }
  cout << minn;

  return 0;
}