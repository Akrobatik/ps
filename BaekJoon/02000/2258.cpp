// Title : 정육점
// Link  : https://www.acmicpc.net/problem/2258 
// Time  : 24 ms
// Memory: 2808 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> arr(n);
  for (auto& [w, p] : arr) cin >> w >> p;
  sort(arr.begin(), arr.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    auto [lw, lp] = lhs;
    auto [rw, rp] = rhs;
    return lp < rp || (lp == rp && lw > rw);
  });

  int64_t sum = 0, prv = -1, cost = 0, minn = INT64_MAX;
  for (auto [w, p] : arr) {
    sum += w;
    cost = (prv == p ? cost + p : p);
    prv = p;
    if (sum >= m) minn = min<int64_t>(minn, cost);
  }
  cout << (minn != INT64_MAX ? minn : -1);

  return 0;
}