// Title : 두 수의 합
// Link  : https://www.acmicpc.net/problem/3273 
// Time  : 24 ms
// Memory: 6776 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  map<int, int> mp;

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    ++mp[x];
  }

  int m;
  cin >> m;

  int64_t sum = 0;
  for (auto lit = mp.begin(); lit != mp.end(); ++lit) {
    auto [lv, lc] = *lit;
    auto rit = mp.find(m - lv);
    if (rit == mp.end()) continue;
    auto [rv, rc] = *rit;

    if (lv + rv != m) continue;
    if (lv < rv) sum += (int64_t)lc * rc;
    if (lv == rv) sum += (int64_t)lc * (lc - 1) / 2;
  }
  cout << sum;

  return 0;
}
