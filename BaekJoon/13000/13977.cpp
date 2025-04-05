// Title : 이항 계수와 쿼리
// Link  : https://www.acmicpc.net/problem/13977
// Time  : 104 ms
// Memory: 64520 KB

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
    if (exp == 1) return n;
    int64_t nn = Power(n, exp >> 1);
    nn = (nn * nn) % MOD;
    if (exp & 1) nn = (nn * n) % MOD;
    return nn;
  }

  int64_t fact[MAXN + 1], inv[MAXN + 1];
};

constexpr int kMax = 4000000;
constexpr int64_t kMod = 1000000007ll;

Combination<kMax, kMod> comb;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;
  while (m--) {
    int n, r;
    cin >> n >> r;
    cout << comb(n, r) << "\n";
  }

  return 0;
}
