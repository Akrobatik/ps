// Title : Key
// Link  : https://www.acmicpc.net/problem/7501 
// Time  : 8 ms
// Memory: 2592 KB

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

  static constexpr int kMaxCyrene = 500000;

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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Factorization solver;

  int64_t a, b;
  cin >> a >> b;

  for (int64_t i = a; i <= b; i++) {
    if (i & 1) {
      if (i == 9 || solver.IsPrime(i)) {
        cout << i << " ";
      }
    }
  }

  return 0;
}
