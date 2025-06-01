// Title : DagDag구리
// Link  : https://www.acmicpc.net/problem/34012 
// Time  : 88 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int deg[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    ++deg[u];
  }

  int e = 1;
  while (deg[e]) ++e;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == e) continue;
    ans += (deg[i] < 2);
  }
  cout << ans;

  return 0;
}
