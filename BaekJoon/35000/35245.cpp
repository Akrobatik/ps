// Title : Get Good
// Link  : https://www.acmicpc.net/problem/35245 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;

    int64_t cut = min<int64_t>(n, x);
    int64_t ans = a * cut;
    n -= cut;

    int64_t cyc = x + y;
    int64_t cv = max<int64_t>(a * x, b * cyc);

    ans += (n / cyc) * cv;
    n %= cyc;

    int64_t add = max<int64_t>(a * max<int>(n - y, 0), b * n);
    cout << ans + add << "\n";
  }

  return 0;
}