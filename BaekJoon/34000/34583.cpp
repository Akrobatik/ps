// Title : Zečevi
// Link  : https://www.acmicpc.net/problem/34583 
// Time  : 532 ms
// Memory: 11968 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<pair<int64_t, int64_t>> arr(n), bxr(m);
  for (auto& [a, b] : arr) cin >> a >> b;
  for (auto& [a, b] : bxr) cin >> a >> b;
  sort(arr.begin(), arr.end());
  sort(bxr.begin(), bxr.end());

  int idx = 0;
  vector<pair<int64_t, int64_t>> brr;
  while (idx < m) {
    int pos = bxr[idx].first, nxt = idx;
    int64_t sum = 0;
    while (nxt < m && bxr[nxt].first == pos) sum += bxr[nxt++].second;
    brr.push_back({pos, sum});
    idx = nxt;
  }

  auto Check = [&](int64_t x) -> bool {
    map<int64_t, int64_t> mp;
    auto hint = mp.end();
    for (auto [a, b] : brr) hint = mp.emplace_hint(hint, a, b);

    for (auto [a, b] : views::reverse(arr)) {
      if (b >= x) continue;

      int64_t limit = a + b, goal = a + x;
      auto it = mp.lower_bound(goal);
      while (limit < goal && it != mp.begin()) {
        auto& [pos, rem] = *--it;
        if (pos < a) break;
        int64_t cut = min<int64_t>(goal - limit, rem);
        limit += cut;
        if ((it->second -= cut) == 0) it = mp.erase(it);
      }
      if (limit < goal) return false;
    }
    return true;
  };

  int64_t s = 0;
  for (auto [a, b] : arr) s += b;
  for (auto [a, b] : brr) s += b;

  int64_t lo = 0, hi = s / n + 1;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (Check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo;

  return 0;
}