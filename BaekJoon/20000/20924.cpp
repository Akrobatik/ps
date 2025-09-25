// Title : 트리의 기둥과 가지
// Link  : https://www.acmicpc.net/problem/20924 
// Time  : 160 ms
// Memory: 48880 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r;
  cin >> n >> r;

  vector<vector<pair<int, int>>> und(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    und[u].push_back({v, w});
    und[v].push_back({u, w});
  }

  vector<vector<pair<int, int>>> dir(n + 1);
  [&](this auto&& self, int cur, int par) -> void {
    for (auto [nxt, w] : und[cur]) {
      if (nxt == par) continue;
      dir[cur].push_back({nxt, w});
      self(nxt, cur);
    }
  }(r, 0);

  int st = r, da = 0;
  while (dir[st].size() == 1) {
    auto [nxt, w] = dir[st][0];
    da += w;
    st = nxt;
  }

  int db = 0;
  [&](this auto&& self, int cur, int sum) -> void {
    db = max<int>(db, sum);
    for (auto [nxt, w] : dir[cur]) {
      self(nxt, sum + w);
    }
  }(st, 0);

  cout << da << " " << db;

  return 0;
}
