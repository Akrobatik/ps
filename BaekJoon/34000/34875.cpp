// Title : 자벌레 세기
// Link  : https://www.acmicpc.net/problem/34875 
// Time  : 60 ms
// Memory: 5536 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> cnt(n + 1);
  vector<pair<int, int>> adj(n - 1);
  for (auto& [u, v] : adj) {
    cin >> u >> v;
    ++cnt[u], ++cnt[v];
  }

  int64_t ans = 0;
  for (auto [u, v] : adj) {
    int64_t uc = cnt[u], vc = cnt[v];
    if (min<int64_t>(uc, vc) < 3) continue;

    int64_t ux = (uc - 1) * (uc - 2) / 2;
    int64_t vx = (vc - 1) * (vc - 2) / 2;
    ans += ux * vx;
  }
  cout << ans;

  return 0;
}