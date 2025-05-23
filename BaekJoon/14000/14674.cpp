// Title : STOP USING MONEY
// Link  : https://www.acmicpc.net/problem/14674 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<tup> arr(n);
  for (auto& [i, c, h] : arr) cin >> i >> c >> h;

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    auto [li, lc, lh] = lhs;
    auto [ri, rc, rh] = rhs;
    int64_t lv = (int64_t)lh * rc, rv = (int64_t)rh * lc;
    if (lv != rv) return lv > rv;
    if (lc != rc) return lc < rc;
    return li < ri;
  });

  for (int i = 0; i < k; i++) cout << get<0>(arr[i]) << "\n";

  return 0;
}
