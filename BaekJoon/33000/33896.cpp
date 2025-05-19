// Title : 아깝게 놓친 COSS 장학금
// Link  : https://www.acmicpc.net/problem/33896 
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int, string>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n);
  for (auto& [s, c, r, na] : arr) cin >> na >> s >> r >> c;

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    auto& [ls, lc, lr, ln] = lhs;
    auto& [rs, rc, rr, rn] = rhs;
    int64_t lv = (int64_t)ls * ls * ls / (lc * (lr + 1)); 
    int64_t rv = (int64_t)rs * rs * rs / (rc * (rr + 1));
    if (lv != rv) return lv > rv;
    return lc < rc || (lc == rc && ln.compare(rn) < 0);
  });

  cout << get<3>(arr[1]);

  return 0;
}