// Title : 공중화장실 공리주의
// Link  : https://www.acmicpc.net/problem/33889 
// Time  : 0 ms
// Memory: 2052 KB

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

constexpr Combination<2001, 1000000007> kComb;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int x = (m << 1) - 1;

  if (n >= x) {
    int nn = m + 1;
    int rr = n - x;
    cout << kComb(nn + rr - 1, rr);
  } else {
    int nn = n - m + 1;
    int rr = m - nn;
    cout << kComb(nn + rr - 1, rr);
  }

  return 0;
}
