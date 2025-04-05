// Title : 팬케익 먹기
// Link  : https://www.acmicpc.net/problem/2545
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    int64_t sum = a + b + c - d;
    a = min<int64_t>(a, sum / 3ll);
    sum -= a;
    b = min<int64_t>(b, sum / 2ll);
    c = sum - b;
    int64_t ans = a * b * c;
    cout << ans << "\n";
  }

  return 0;
}
