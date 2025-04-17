// Title : 이항 계수 6
// Link  : https://www.acmicpc.net/problem/14854 
// Time  : 76 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t Power(int64_t n, int64_t exp, int64_t mod) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = res * n % mod;
    n = n * n % mod;
    exp >>= 1;
  }
  return res;
}

template <int N>
constexpr array<array<int64_t, N>, N> BuildP() {
  array<array<int64_t, N>, N> arr{};
  array<int64_t, N> fact{}, inv{};
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % N;
  inv[N - 1] = Power(fact[N - 1], N - 2, N);
  for (int i = N - 1; i; i--) inv[i - 1] = inv[i] * i % N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      arr[i][j] = (fact[i] * inv[j] % N) * inv[i - j] % N;
    }
  }
  return arr;
}

template <int P, int E, int PE = Power(P, E, INT_MAX)>
constexpr array<int64_t, PE> BuildPE() {
  array<int64_t, PE> arr{};
  arr[0] = 1;
  for (int i = 1; i < PE; i++) arr[i] = (i % P == 0 ? arr[i - 1] : arr[i - 1] * i % PE);
  return arr;
}

constexpr int64_t kMod = 142857;

constexpr auto kComb11 = BuildP<11>();
constexpr auto kComb13 = BuildP<13>();
constexpr auto kComb37 = BuildP<37>();
constexpr auto kFact27 = BuildPE<3, 3>();

template <int P>
int64_t CalcP(int64_t n, int64_t k) {
  int64_t res = 1;
  while (n || k) {
    if constexpr (P == 11) {
      res = res * kComb11[n % P][k % P] % P;
    } else if constexpr (P == 13) {
      res = res * kComb13[n % P][k % P] % P;
    } else {
      res = res * kComb37[n % P][k % P] % P;
    }
    n /= P, k /= P;
  }
  return res;
}

int64_t Calc27(int64_t n, int64_t k) {
  auto Count = [](int64_t x) {
    int64_t cnt = 0;
    while (x) x /= 3, cnt += x;
    return cnt;
  };

  auto Calc = [](int64_t x) {
    int64_t res = 1;
    while (x) res = res * (((x / 27) & 1) ? 26 : 1) * kFact27[x % 27] % 27, x /= 3;
    return res;
  };

  int64_t exp = Count(n) - Count(k) - Count(n - k);
  if (exp >= 3) return 0;
  int64_t res = 1;
  for (int i = 0; i < exp; i++) res *= 3;
  return res * Calc(n) * Power(Calc(k) * Calc(n - k) % 27, 17, 27) % 27;
}


int64_t ExtGCD(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  x = 1, y = 0;
  int64_t x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int64_t q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}

pair<int64_t, int64_t> CRT(const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) {
  auto [ar, am] = a;
  auto [br, bm] = b;
  int64_t x, y;
  int64_t g = ExtGCD(am, bm, x, y);
  int64_t l = am * bm / g;
  int64_t t = ((br - ar) / g) * x % (bm / g);
  if (t < 0) t += bm / g;
  return {(ar + am * t) % l, l};
}

int64_t Calc(int64_t n, int64_t k) {
  array<pair<int64_t, int64_t>, 3> rems{{
      {CalcP<11>(n, k), 11},
      {CalcP<13>(n, k), 13},
      {CalcP<37>(n, k), 37},
  }};

  pair<int64_t, int64_t> res = {Calc27(n, k), 27};
  for (auto rem : rems) {
    res = CRT(res, rem);
  }
  return res.first;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n, k;
    cin >> n >> k;
    cout << Calc(n, k) << "\n";
  }

  return 0;
}