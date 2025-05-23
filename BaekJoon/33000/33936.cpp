// Title : 두 괄호 문자열
// Link  : https://www.acmicpc.net/problem/33936 
// Time  : 12 ms
// Memory: 2192 KB

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
constexpr int kInv2 = 5e8 + 4;
constexpr Combination<2000, kMod> kComb;
constexpr auto Power = kComb.Power;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  int half = n >> 1;

  int cur = 0, mul = 0;
  vector<int> ccur(n + 2), cnxt(n + 2), scur(n + 2), snxt(n + 2);
  ccur[0] = 1;
  for (int i = 1; i <= n; i++) {
    fill(cnxt.begin(), cnxt.end(), 0);
    fill(snxt.begin(), snxt.end(), 0);

    cur += (s[i - 1] == '(' ? 1 : -1);
    mul += cur;

    for (int j = cur; j <= i; j++) {
      int cnt = 0, sum = 0;
      if (j) {
        cnt = (cnt + ccur[j - 1]) % kMod;
        sum = ((int64_t)ccur[j - 1] * j + scur[j - 1] + sum) % kMod;
      }
      cnt = (cnt + ccur[j + 1]) % kMod;
      sum = ((int64_t)ccur[j + 1] * j + scur[j + 1] + sum) % kMod;

      cnxt[j] = cnt, snxt[j] = sum;
    }

    swap(ccur, cnxt), swap(scur, snxt);
  }

  int sum = (((int64_t)scur[0] - (int64_t)ccur[0] * mul) % kMod + kMod) * kInv2 % kMod;
  int all = kComb(n, half) * Power(half + 1, kMod - 2) % kMod;
  cout << ((sum - all + ccur[0]) % kMod + kMod) % kMod << "\n";

  return 0;
}
