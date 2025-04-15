// Title : 쿨한 물건 구매
// Link  : https://www.acmicpc.net/problem/1214 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t d, p, q;
  cin >> d >> p >> q;
  if (p < q) swap(p, q);

  int64_t gcd = GCD(p, q);
  int64_t lcm = p * q / gcd;
  int64_t ans = (d / lcm) * lcm;
  if (ans) ans -= lcm;
  int64_t rem = d - ans;
  int limit = (rem + p - 1) / p;
  int64_t add = p * limit;
  for (int i = 0; i < limit; i++) {
    int j = ((rem - p * i) + q - 1) / q;
    add = min<int64_t>(add, p * i + q * j);
  }
  cout << ans + add;

  return 0;
}
