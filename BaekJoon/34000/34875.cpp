// Title : 자벌레 세기
// Link  : https://www.acmicpc.net/problem/34875 
// Time  : 56 ms
// Memory: 6708 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> val(n + 1);
  vector<pair<int, int>> adj(n - 1);
  for (auto& [u, v] : adj) {
    cin >> u >> v;
    ++val[u], ++val[v];
  }
  for (int i = 1; i <= n; i++) {
    val[i] = ((val[i] - 1) * (val[i] - 2)) >> 1;
  }

  int64_t ans = 0;
  for (auto [u, v] : adj) {
    ans += val[u] * val[v];
  }
  cout << ans;

  return 0;
}