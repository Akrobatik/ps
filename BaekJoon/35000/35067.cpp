// Title : 메이플 월드 탐험하기
// Link  : https://www.acmicpc.net/problem/35067 
// Time  : 488 ms
// Memory: 46060 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<array<int, 2>> maxp(n + 1);
  for (int i = 1; i <= n; i++) {
    int mv1 = 0, mv2 = 0, mi1, mi2;
    for (auto u : g[i]) {
      int v = arr[u];
      if (mv1 < v) {
        mv2 = mv1, mi2 = mi1;
        mv1 = v, mi1 = u;
      } else if (mv2 < v) {
        mv2 = v, mi2 = u;
      }
    }
    maxp[i] = {mi1, mi2};
  }

  vector<array<int64_t, 2>> memo(n + 1, {-1, -1});
  for (int i = 1; i <= n; i++) {
    cout << [&](this auto&& self, int cur, int par) -> int64_t {
      int x = (par == maxp[cur][0]);
      if (memo[cur][x] != -1) return memo[cur][x];

      int64_t res = 0;
      if (g[cur].size() == 1) {
        int nxt = maxp[cur][0];
        res = (nxt == par ? cur : self(nxt, cur));
      } else {
        int nxt = maxp[cur][0];
        if (nxt == par) nxt = maxp[cur][1];
        res = self(nxt, cur);
      }

      return memo[cur][x] = res;
    }(i, 0) << "\n";
  }

  return 0;
}