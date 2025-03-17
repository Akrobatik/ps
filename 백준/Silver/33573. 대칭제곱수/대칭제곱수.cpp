#include <bits/stdc++.h>

using namespace std;

bool Sqr(int64_t n) {
  long double ld = n;
  int64_t x = (int64_t)sqrtl(ld);
  return x * x == n;
}

bool RevSqr(int64_t n) {
  int64_t r = 0;
  while (n) r = r * 10 + n % 10, n /= 10;
  return Sqr(r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    cout << (Sqr(n) && RevSqr(n) ? "YES\n" : "NO\n");
  }

  return 0;
}
