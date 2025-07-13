// Title : 해안선
// Link  : https://www.acmicpc.net/problem/34059 
// Time  : 16 ms
// Memory: 17644 KB

#include <bits/stdc++.h>

using namespace std;

template <int MAXN, int64_t MOD>
  requires(MAXN >= 0, MOD >= 3)
struct Combination {
  constexpr Combination() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
    inv[MAXN] = Power(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) inv[i - 1] = (inv[i] * i) % MOD;
  }

  int64_t operator()(int n, int r) const {
    return (((fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
  }

  static constexpr int64_t Power(int64_t n, int exp) {
    int64_t res = 1;
    while (exp) {
      if (exp & 1) res = (res * n) % MOD;
      n = (n * n) % MOD;
      exp >>= 1;
    }
    return res;
  }

  int64_t fact[MAXN + 1], inv[MAXN + 1];
};

constexpr int kMax = 1e6;
constexpr int kMod = 1e9 + 7;
const Combination<kMax, kMod> kComb;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;
  if (a > b) swap(a, b);

  int x = a - 2, y = n - b, z = b - a - 1;
  int64_t ans = kComb(x + y, x) * kComb.Power(2, z) % kMod;
  if (b - a == 1) {
    if ((ans += kComb.Power(2, n - 3)) >= kMod) ans -= kMod; 
  }
  cout << ans;

  return 0;
}