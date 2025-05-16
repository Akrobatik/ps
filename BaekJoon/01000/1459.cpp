// Title : 걷기
// Link  : https://www.acmicpc.net/problem/1459 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t x, y, w, s;
  cin >> x >> y >> w >> s;
  int64_t minn = min<int64_t>(x, y);
  int64_t maxx = x ^ y ^ minn;
  int64_t ans = min<int64_t>((x + y) * w, minn * s + (maxx - minn) * w);
  if ((maxx - minn) & 1) {
    ans = min<int64_t>(ans, maxx * s + w - s);
  } else {
    ans = min<int64_t>(ans, maxx * s);
  }
  cout << ans;

  return 0;
}
