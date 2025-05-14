// Title : 사라져버릴 것 같아요
// Link  : https://www.acmicpc.net/problem/33838 
// Time  : 36 ms
// Memory: 3584 KB

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

constexpr Combination<100000, kMod> kComb;

void Solve() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  if (b & 1) {
    cout << "0\n";
    return;
  }

  int r = n - a - b - c;
  int bs = b >> 1;
  int ts = a + bs;
  if (r + 1 < ts) {
    cout << "0\n";
    return;
  }

  int64_t ans = kComb(ts, a) * kComb(r + 1, r - ts + 1) % kMod;
  ans = ans * kComb(c + bs - 1, bs - 1) % kMod;
  ans = ans * kComb.fact[a] % kMod;
  ans = ans * kComb.fact[b] % kMod;
  ans = ans * kComb.fact[c] % kMod;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
