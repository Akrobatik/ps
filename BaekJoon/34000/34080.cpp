// Title : 일천광년
// Link  : https://www.acmicpc.net/problem/34080 
// Time  : 272 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n, x, y;
    cin >> n >> x >> y;

    int64_t sum = x + y;
    __int128_t z = (__int128_t)n * min<int64_t>(x, y);
    int64_t p = z / sum, q = z % sum;

    if (q == 0) {
      if (x < y) p = n - p;
      cout << "1\n"
           << p << " " << sum << "\n";
      continue;
    }

    int64_t l = p, r = p + 1;
    int64_t lv = sum - q, rv = q;
    if (x < y) l = n - l - 1, r = n - r + 1, swap(lv, rv);
    cout << "2\n"
         << l << " " << lv << "\n"
         << r << " " << rv << "\n";
  }

  return 0;
}
