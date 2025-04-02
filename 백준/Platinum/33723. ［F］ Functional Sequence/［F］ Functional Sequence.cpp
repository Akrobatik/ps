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
constexpr Combination<5000, kMod> kComb;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int64_t> table(n + 1);
  table[0] = 1;
  for (int i = 1; i <= n; i++) {
    table[i] = table[i - 1] * k % kMod;
  }

  vector<int64_t> ans(n);
  for (int i = 0; i < n; i++) {
    int64_t& x = ans[i];
    for (int j = 0; j <= i; j++) {
      x = (x + (kComb(i, j) * table[i - j]) % kMod * arr[j]) % kMod;
    }
  }

  for (auto e : ans) cout << e << " ";

  return 0;
}
