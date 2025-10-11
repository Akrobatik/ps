// Title : 수상 택시
// Link  : https://www.acmicpc.net/problem/2836 
// Time  : 100 ms
// Memory: 8296 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> arr;
  while (n--) {
    int u, v;
    cin >> u >> v;
    if (u > v) arr.push_back({v, u});
  }
  sort(arr.begin(), arr.end());

  int64_t ans = m, x = 0;
  for (auto [u, v] : arr) {
    if (x < v) ans += (v - max<int>(u, x)) << 1;
    x = max<int>(x, v);
  }
  cout << ans;

  return 0;
}