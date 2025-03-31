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

constexpr int64_t kMod = 1e9 + 7;
const Combination<15000, kMod> kComb;

int64_t Calc(int64_t n) {
  int64_t x = kComb(n * 3, n);
  int64_t y = kComb(n * 2, n);
  return x * y % kMod;
}

int64_t comb[5001];
int64_t memo[5001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    memo[i] = comb[i] = Calc(i);
    for (int j = 1; j < i; j++) {
      memo[i] = (memo[i] + kMod - (memo[j] * comb[i - j] % kMod)) % kMod;
    }
  }
  cout << memo[n];

  return 0;
}
