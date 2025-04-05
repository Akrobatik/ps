// Title : 결혼식
// Link  : https://www.acmicpc.net/problem/5567
// Time  : 0 ms
// Memory: 2288 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> edges[501];
  bool memo[501] = {};

  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int ans = 0;
  queue<int> q;
  memo[1] = true;
  q.push(1);
  for (int i = 0; !q.empty() && i < 2; i++) {
    int nq = q.size();
    while (nq--) {
      int x = q.front();
      q.pop();

      for (auto nxt : edges[x]) {
        if (memo[nxt]) continue;
        ++ans;
        memo[nxt] = true;
        q.push(nxt);
      }
    }
  }
  cout << ans;

  return 0;
}
