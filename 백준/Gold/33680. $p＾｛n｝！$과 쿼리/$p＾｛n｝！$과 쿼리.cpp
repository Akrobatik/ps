#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e9 + 7;

int64_t Power(int64_t n, int exp) {
  if (exp == 1) return n;
  int64_t nn = Power(n, exp >> 1);
  nn = nn * nn % kMod;
  if (exp & 1) nn = nn * n % kMod;
  return nn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t p, n;
    cin >> p >> n;
    int64_t y = Power(p, n) + kMod - 1;
    int64_t x = Power(p - 1, kMod - 2);
    cout << (y * x % kMod) << "\n";
  }

  return 0;
}