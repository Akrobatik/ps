#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

  vector<int> ab;
  ab.reserve(n * n);
  for (auto av : a) {
    for (auto bv : b) ab.push_back(av + bv);
  }
  sort(ab.begin(), ab.end());

  vector<int> cd;
  cd.reserve(n * n);
  for (auto cv : c) {
    for (auto dv : d) cd.push_back(cv + dv);
  }
  sort(cd.begin(), cd.end());

  int64_t sum = 0;
  auto ab_it = ab.begin(), ab_end = ab.end();
  auto cd_it = cd.rbegin(), cd_end = cd.rend();
  while (ab_it != ab_end && cd_it != cd_end) {
    int abv = *ab_it;
    int cdv = *cd_it;
    if (abv + cdv == 0) {
      int64_t ab_cnt = 1, cd_cnt = 1;
      while (++ab_it != ab_end && *ab_it == abv) ++ab_cnt;
      while (++cd_it != cd_end && *cd_it == cdv) ++cd_cnt;
      sum += ab_cnt * cd_cnt;
    } else if (abv + cdv < 0) {
      ab_it = lower_bound(ab_it + 1, ab_end, -cdv);
    } else {
      cd_it = lower_bound(cd_it + 1, cd_end, -abv, greater<int>());
    }
  }

  cout << sum;

  return 0;
}
