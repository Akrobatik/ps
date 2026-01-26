// Title : PriorityQueue가 아니에요
// Link  : https://www.acmicpc.net/problem/35155 
// Time  : 204 ms
// Memory: 13744 KB

#include <bits/stdc++.h>

using namespace std;

// https://github.com/Akrobatik/ps/blob/main/template/modint.cpp
template <int32_t MOD>
struct ModInt32 {
  using CT = conditional_t<MOD <= numeric_limits<int32_t>::max() / 2, int32_t, int64_t>;

  constexpr ModInt32() : val(0) {}
  constexpr ModInt32(int32_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}
  constexpr ModInt32(int64_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}
  constexpr ModInt32(__int128_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}

  constexpr ModInt32 Pow(int64_t exp) const {
    int64_t n = val, x = 1;
    while (exp) {
      if (exp & 1) x = x * n % MOD;
      n = n * n % MOD;
      exp >>= 1;
    }

    ModInt32 res;
    res.val = x;
    return res;
  }

  constexpr ModInt32 Inv() const {
    return Pow(MOD - 2);
  }

  constexpr ModInt32& operator++() {
    if (++val == MOD) val = 0;
    return *this;
  }

  constexpr ModInt32 operator++(int) {
    ModInt32 tmp(*this);
    operator++();
    return tmp;
  }

  constexpr ModInt32& operator+=(const ModInt32& other) {
    CT x = (CT)val + other.val;
    if (x >= MOD) x -= MOD;
    val = x;
    return *this;
  }

  constexpr ModInt32& operator-=(const ModInt32& other) {
    CT x = (CT)val + (MOD - other.val);
    if (x >= MOD) x -= MOD;
    val = x;
    return *this;
  }

  constexpr ModInt32& operator*=(const ModInt32& other) {
    val = (int64_t)val * other.val % MOD;
    return *this;
  }

  constexpr ModInt32& operator/=(const ModInt32& other) {
    *this *= other.Inv();
    return *this;
  }

  constexpr ModInt32 operator-() const {
    ModInt32 res;
    if (val) res.val = MOD - val;
    return res;
  }

  constexpr ModInt32 operator+(const ModInt32& rhs) const {
    return ModInt32(*this) += rhs;
  }

  constexpr ModInt32 operator-(const ModInt32& rhs) const {
    return ModInt32(*this) -= rhs;
  }

  constexpr ModInt32 operator*(const ModInt32& rhs) const {
    return ModInt32(*this) *= rhs;
  }

  constexpr ModInt32 operator/(const ModInt32& rhs) const {
    return ModInt32(*this) /= rhs;
  }

  constexpr bool operator!() const {
    return val == 0;
  }

  friend istream& operator>>(istream& is, ModInt32& num) {
    is >> num.val;
    if ((num.val %= MOD) < 0) num.val += MOD;
    return is;
  }

  friend ostream& operator<<(ostream& os, const ModInt32& num) {
    os << num.val;
    return os;
  }

  int32_t val;
};

constexpr int kMod = 998244353;
using ModInt = ModInt32<kMod>;

constexpr int kMax = 1e6;
ModInt memo[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ModInt> fact(kMax + 1), ifac(kMax + 1);
  fact[0] = 1;
  for (int i = 1; i <= kMax; i++) fact[i] = fact[i - 1] * i;
  ifac[kMax] = fact[kMax].Inv();
  for (int i = kMax; i > 0; i--) ifac[i - 1] = ifac[i] * i;

  auto Comb = [&](int a, int b) {
    if (b < 0 || a < b) return ModInt();
    return fact[a] * ifac[b] * ifac[a - b];
  };

  memo[0] = 1;
  for (int i = 0; i < kMax; i++) {
    if (i + 2 <= kMax) memo[i + 2] += memo[i];
    memo[i + 1] += memo[i];
    if (i % 3 == 0) {
      int x = i / 3;
      memo[i + 1] -= Comb(x + x, x) - Comb(x + x, x - 1);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n == 1 ? -1 : memo[n].val) << "\n";
  }

  return 0;
}