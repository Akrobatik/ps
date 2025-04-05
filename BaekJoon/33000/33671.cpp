// Title : 루미의 생일파티장 꾸미기 （EX）
// Link  : https://www.acmicpc.net/problem/33671
// Time  : 276 ms
// Memory: 18680 KB

#include <bits/stdc++.h>

using namespace std;

struct Factorization {
  Factorization() : cyr(kMaxCyrene + 1, true) {
    vector<int> primes;
    cyr[0] = cyr[1] = false;
    for (int64_t i = 2; i <= kMaxCyrene; i++) {
      if (cyr[i]) primes.push_back(i);
      for (auto p : primes) {
        if (i * p > kMaxCyrene) break;
        cyr[i * p] = false;
        if (i % p == 0) break;
      }
    }
  }

  bool IsPrime(uint64_t n) {
    if (n <= kMaxCyrene) return cyr[n];
    if (!(n & 1)) return false;
    for (auto p : {3, 5, 7, 11, 13, 17, 19, 23, 29}) {
      if (n % p == 0) return false;
    }

    int cnt = countr_zero(n - 1);
    uint64_t d = n >> cnt;
    for (auto a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
      if (IsComposite(n, a, d, cnt)) return false;
    }
    return true;
  }

  vector<int64_t> Factorize(int64_t n) {
    vector<int64_t> vec;
    while (!(n & 1)) n >>= 1, vec.push_back(2);
    while (n != 1 && !IsPrime(n)) {
      int64_t f = Rho(n);
      while (n % f == 0) n /= f, vec.push_back(f);
    }
    if (n != 1) vec.push_back(n);
    return vec;
  }

  static constexpr int kMaxCyrene = 1000000;

  vector<bool> cyr;

 private:
  static uint64_t Power(uint64_t n, uint64_t exp, uint64_t mod) {
    uint64_t res = 1;
    while (exp) {
      if (exp & 1) res = (__uint128_t)res * n % mod;
      n = (__uint128_t)n * n % mod;
      exp >>= 1;
    }
    return res;
  }

  static bool IsComposite(uint64_t n, uint64_t a, uint64_t d, int cnt) {
    if (a % n == 0) return false;
    uint64_t x = Power(a, d, n);
    if (x == 1 || x == n - 1) return false;
    while (cnt--) {
      x = (__uint128_t)x * x % n;
      if (x == n - 1) return false;
    }
    return true;
  }

  int64_t Rho(int64_t n) {
    static mt19937_64 gen((uint64_t)time(nullptr));

    for (;;) {
      int64_t x, y, c, d;
      x = y = gen() % (n - 2) + 2;
      c = gen() % (n - 1) + 1;
      for (;;) {
        x = ((__uint128_t)x * x + c) % n;
        y = ((__uint128_t)y * y + c) % n;
        y = ((__uint128_t)y * y + c) % n;
        d = gcd(abs(x - y), n);
        if (d == 1) continue;
        if (IsPrime(d)) return d;
        n = d;
        break;
      }
    }
  }
};

constexpr int kMax = 2e6;
constexpr int64_t kMod = 998244353;

int64_t phi[kMax + 1];
unordered_map<int64_t, int64_t> memo;

int64_t PrefixSum(int64_t n) {
  if (n <= kMax) return phi[n];
  if (auto it = memo.find(n); it != memo.end()) return it->second;

  int64_t res = n * (n + 1) / 2;
  for (int i = 2, j; i <= n; i = j + 1) {
    int x = n / i;
    j = n / x;
    res -= PrefixSum(x) * (j - i + 1);
  }
  return memo[n] = res;
}

int64_t Calc(int64_t n, int64_t x, const vector<int64_t>& facts, int fidx) {
  if (n < x) return 0;

  int64_t res = PrefixSum(n / x) % kMod;
  int nf = facts.size();
  for (int i = fidx; i < nf; i++) {
    res = (res + Calc(n, x * facts[i], facts, i)) % kMod;
  }
  return res;
}

int64_t Phi(int64_t n, const vector<int64_t>& facts) {
  int64_t res = n;
  for (auto f : facts) {
    res -= res / f;
  }
  return res % kMod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  iota(phi, phi + kMax + 1, 0);
  for (int i = 2; i <= kMax; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= kMax; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
  partial_sum(phi, phi + kMax + 1, phi);

  int64_t a, b;
  cin >> a >> b;

  Factorization f;
  auto facts = f.Factorize(b);
  facts.erase(unique(facts.begin(), facts.end()), facts.end());
  cout << Calc(a, 1, facts, 0) * Phi(b, facts) % kMod;

  return 0;
}
