// Title : 제곱수의 합 (More Huge)
// Link  : https://www.acmicpc.net/problem/17633 
// Time  : 8 ms
// Memory: 2168 KB

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

  static constexpr int kMaxCyrene = 10000;

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

int64_t Sqrt(int64_t n) {
  int64_t lo = 1, hi = 1e9 + 1;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (mid * mid <= n) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

complex<int64_t> Pow(complex<int64_t> g, int64_t exp) {
  complex<int64_t> res{1, 0};
  while (exp) {
    if (exp & 1) res *= g;
    g *= g;
    exp >>= 1;
  }
  return res;
}

int64_t Pow(int64_t n, int64_t exp, int64_t mod) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = (__int128_t)res * n % mod;
    n = (__int128_t)n * n % mod;
    exp >>= 1;
  }
  return res;
}

vector<pair<int64_t, int>> Transform(const vector<int64_t>& facts) {
  vector<pair<int64_t, int>> res;
  auto it = facts.begin();
  while (it != facts.end()) {
    int64_t p = *it++;
    int cnt = 1;
    while (it != facts.end() && *it == p) ++it, ++cnt;
    res.push_back({p, cnt});
  }
  return res;
}

bool CheckTwo(vector<pair<int64_t, int>>& facts) {
  sort(facts.begin(), facts.end());
  for (auto [p, exp] : facts) {
    if (p % 4 == 3 && (exp & 1)) return false;
  }
  return true;
}

pair<int64_t, int64_t> Cornacchia(int64_t n) {
  static mt19937_64 gen((uint64_t)time(nullptr));

  int64_t t;
  do t = uniform_int_distribution<int64_t>(2, n - 2)(gen);
  while (Pow(t, (n - 1) >> 1, n) != n - 1);

  __int128_t x = n, y = Pow(t, (n - 1) >> 2, n);
  while (y * y > n) {
    __int128_t z = x % y;
    tie(x, y) = tie(y, z);
  }
  return {y, Sqrt(n - y * y)};
}

pair<int64_t, int64_t> FindTwo(const vector<pair<int64_t, int>>& facts) {
  complex<int64_t> g{1, 0};
  for (auto [p, exp] : facts) {
    if (p == 2) {
      g *= Pow({1, 1}, exp);
    } else if (p % 4 == 1) {
      auto [a, b] = Cornacchia(p);
      g *= Pow({a, b}, exp);
    } else {
      complex<int64_t> m{p, 0};
      for (int i = 0; i < exp; i += 2) g *= m;
    }
  }
  return {abs(g.real()), abs(g.imag())};
}

array<int64_t, 4> Find(int64_t n) {
  int cnt = 0;
  while (n % 4 == 0) n >>= 2, ++cnt;

  array<int64_t, 4> arr{};

  int64_t rt = Sqrt(n);
  if (rt * rt == n) {
    arr[0] = rt << cnt;
    return arr;
  }

  Factorization solver;
  auto facts = Transform(solver.Factorize(n));
  if (CheckTwo(facts)) {
    auto [a, b] = FindTwo(facts);
    arr[0] = a << cnt, arr[1] = b << cnt;
    return arr;
  }

  if (n % 8 != 7) {
    for (int64_t a = 1;; a++) {
      int64_t x = n - a * a;
      if (x < 0) break;

      facts = Transform(solver.Factorize(x));
      if (CheckTwo(facts)) {
        auto [b, c] = FindTwo(facts);
        arr[0] = a << cnt, arr[1] = b << cnt, arr[2] = c << cnt;
        return arr;
      }
    }
  }

  for (int64_t a = 1;; a++) {
    int64_t x = n - a * a;
    arr[0] = a << cnt;
    for (int64_t b = 0; b <= a; b++) {
      int64_t y = x - b * b;
      if (y < 0) break;
      facts = Transform(solver.Factorize(y));
      if (CheckTwo(facts)) {
        auto [c, d] = FindTwo(facts);
        arr[1] = b << cnt, arr[2] = c << cnt, arr[3] = d << cnt;
        return arr;
      }
    }
  }
  assert(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  auto arr = Find(n);
  sort(arr.begin(), arr.end());

  int i = 0;
  while (arr[i] == 0) ++i;
  cout << 4 - i;

  return 0;
}