// Title : 과제 해결하기 2
// Link  : https://www.acmicpc.net/problem/35066 
// Time  : 32 ms
// Memory: 13808 KB

#include <bits/stdc++.h>

using namespace std;

struct Factorization {
  Factorization() : seive(kMaxN + 1, true) {
    vector<int> primes;
    seive[0] = seive[1] = false;
    for (int64_t i = 2; i <= kMaxN; i++) {
      if (seive[i]) primes.push_back(i);
      for (auto p : primes) {
        if (i * p > kMaxN) break;
        seive[i * p] = false;
        if (i % p == 0) break;
      }
    }
  }

  bool IsPrime(uint64_t n) {
    if (n <= kMaxN) return seive[n];
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

  static constexpr int kMaxN = 1e6;

  vector<bool> seive;

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

  int64_t all;
  map<pair<int64_t, int64_t>, int64_t> mp;

  auto Query = [&](int64_t m, int64_t r) -> int64_t {
    if (m == 1) return all;

    auto it = mp.find({m, r});
    if (it != mp.end()) return it->second;

    cout << "? " << m << " " << r << endl;

    int64_t res;
    cin >> res;
    return mp[{m, r}] = res;
  };

  auto Power = [](int64_t n, int64_t exp) {
    int64_t res = 1;
    while (exp) {
      if (exp & 1) res *= n;
      n *= n;
      exp >>= 1;
    }
    return res;
  };

  Factorization solver;
  all = Query(2, 0) + Query(2, 1);
  int64_t base = Power(2, all / (all - Query(2, 0)) - 1);
  while (Query(base, 0) > 1) {
    int64_t mask = 0, bnd = (int64_t)1e12 / base;
    for (int i = 0; (1LL << i) + mask <= bnd; i++) {
      int64_t m = 1LL << i;
      if (Query(base << (i + 1), base * (mask + m))) {
        mask += m;
      }
    }

    auto f = solver.Factorize(mask);
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());

    for (auto p : f) {
      base *= Power(p, all / (all - Query(p, 0)) - 1);
    }
  }
  cout << "! " << base << endl;

  return 0;
}