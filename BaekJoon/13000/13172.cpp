// Title : Σ
// Link  : https://www.acmicpc.net/problem/13172
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

static constexpr int64_t c = 1000000007;

int64_t Inverse(int64_t v, int n = c - 2) {
  if (n == 1) return v % c;

  int64_t tmp = Inverse(v, n / 2) % c;
  tmp = (tmp * tmp) % c;
  if (n % 2) return (tmp * v) % c;
  return tmp;
}

int64_t GCD(int64_t a, int64_t b) {
  int64_t c = a % b;
  if (c == 0) return b;
  return GCD(b, c);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;
  int64_t ans = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> b >> a;
    int64_t div = a > b ? GCD(a, b) : GCD(b, a);
    if (div > 1) {
      a /= div;
      b /= div;
    }
    ans += (Inverse(b) * a) % c;
    ans %= c;
  }

  cout << ans << endl;

  return 0;
}
