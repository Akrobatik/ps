#include <bits/stdc++.h>

using namespace std;

template <int MAXN, int MOD>
struct Combination {
  constexpr Combination() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = (int64_t)fact[i - 1] * i % MOD;
    inv[MAXN] = Power(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) inv[i - 1] = (int64_t)inv[i] * i % MOD;
  }

  constexpr int operator()(int n, int r) const {
    return ((int64_t)fact[n] * inv[r] % MOD) * inv[n - r] % MOD;
  }

  static constexpr int Power(int n, int exp) {
    int64_t res = 1;
    while (exp) {
      if (exp & 1) res = (res * n) % MOD;
      n = (n * n) % MOD;
      exp >>= 1;
    }
    return res;
  }

  int fact[MAXN + 1], inv[MAXN + 1];
};
