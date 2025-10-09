// Title : 구두 수선공
// Link  : https://www.acmicpc.net/problem/14908 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  for (auto& [p, q] : arr) cin >> p >> q;

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);

  sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    auto [lp, lq] = arr[lhs];
    auto [rp, rq] = arr[rhs];
    int lv = lp * rq, rv = rp * lq;
    return lv < rv || (lv == rv && lhs < rhs);
  });

  for (auto e : ids) cout << e + 1 << " ";

  return 0;
}