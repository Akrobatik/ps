// Title : 파스칼 삼각형
// Link  : https://www.acmicpc.net/problem/33874 
// Time  : 64 ms
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
const Combination<4000000, kMod> kComb;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 2) {
    cout << "0 3";
    return 0;
  }

  int cnt = 2;
  if (n & 1) cnt = 4;
  if (n == 4) cnt = 4;
  if (n == 5) cnt = 6;

  cout << kComb(n - 2, (n - 1) >> 1) << " " << cnt;

  return 0;
}
