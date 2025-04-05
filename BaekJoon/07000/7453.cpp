// Title : 합이 0인 네 정수
// Link  : https://www.acmicpc.net/problem/7453
// Time  : 2260 ms
// Memory: 127312 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

  vector<int> ab(n * n);
  auto _ab = ab.data();
  for (int i = 0; i < n; i++) pq.emplace(a[0] + b[i], 0, i);
  while (!pq.empty()) {
    auto [v, i, j] = pq.top();
    pq.pop();

    *_ab++ = v;
    if (i + 1 < n) pq.emplace(a[i + 1] + b[j], i + 1, j);
  }

  vector<int> cd(n * n);
  auto _cd = cd.data();
  for (int i = 0; i < n; i++) pq.emplace(c[0] + d[i], 0, i);
  while (!pq.empty()) {
    auto [v, i, j] = pq.top();
    pq.pop();

    *_cd++ = v;
    if (i + 1 < n) pq.emplace(c[i + 1] + d[j], i + 1, j);
  }

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
