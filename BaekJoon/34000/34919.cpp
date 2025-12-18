// Title : Marbles
// Link  : https://www.acmicpc.net/problem/34919 
// Time  : 36 ms
// Memory: 10320 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<char> vis, mask, color;
  vector<int> memo;
  vector<vector<int>> g;

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    memo[b] = a;
    return true;
  };

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    memo.resize(n + 1);
    iota(memo.begin(), memo.end(), 0);
    vis.assign(n + 1, 0);
    mask.assign(n + 1, 0);
    g.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (Union(i, x)) {
        g[i].push_back(x);
        g[x].push_back(i);
      } else {
        mask[i] = 1;
      }
    }

    color.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;

      [&](this auto&& self, int cur, int col) -> void {
        vis[cur] = 1;
        color[cur] = col;
        for (auto nxt : g[cur]) {
          if (vis[nxt]) continue;
          self(nxt, col ^ 1);
        }
      }(i, 0);
    }

    for (int i = 1; i <= n; i++) {
      cout << (mask[i] ? 'R' : (color[i] ? 'G' : 'B'));
    }
    cout << "\n";
  }

  return 0;
}