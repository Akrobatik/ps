// Title : 괄호
// Link  : https://www.acmicpc.net/problem/10422 
// Time  : 0 ms
// Memory: 2240 KB

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

constexpr int kMod = 1e9 + 7;
constexpr Combination<5000, kMod> kComb;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> cat(5001);
  for (int i = 0; i < cat.size(); i++) {
    cat[i] = kComb(i << 1, i) * kComb.Power(i + 1, kMod - 2) % kMod;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n & 1) {
      cout << "0\n";
    } else {
      cout << cat[n >> 1] << "\n";
    }
  }

  return 0;
}
