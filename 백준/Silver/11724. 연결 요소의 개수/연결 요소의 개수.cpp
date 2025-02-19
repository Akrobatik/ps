#include <bits/stdc++.h>

using namespace std;

int memo[1001];

int Find(int id, int& height) {
  height = 0;
  while (id != memo[id]) {
    int parent = memo[id];
    memo[id] = memo[parent];
    id = parent;
    ++height;
  }
  return id;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  iota(memo + 1, memo + n + 1, 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    int hu, hv;
    int pu = Find(u, hu), pv = Find(v, hv);
    if (hu < hv) swap(pu, pv);
    memo[pu] = pv;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) ans += (i == memo[i]);
  cout << ans;

  return 0;
}
