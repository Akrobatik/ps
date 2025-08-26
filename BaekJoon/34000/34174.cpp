// Title : 동우가 눈을 뜨면 해가 떠있는 이유는?
// Link  : https://www.acmicpc.net/problem/34174 
// Time  : 108 ms
// Memory: 2184 KB

#include <bits/stdc++.h>

using namespace std;

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

constexpr int kMax = 1e4;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ModInt> fact(kMax + 1), ifac(kMax + 1), inv(kMax + 1);
  fact[0] = 1;
  for (int i = 1; i <= kMax; i++) fact[i] = fact[i - 1] * i;
  ifac[kMax] = fact[kMax].Inv();
  for (int i = kMax; i > 0; i--) ifac[i - 1] = ifac[i] * i;
  inv[0] = 1;
  for (int i = kMax; i > 0; i--) inv[i] = ifac[i] * fact[i - 1];

  auto Comb = [&](int n, int r) {
    return fact[n] * ifac[n - r] * ifac[r];
  };

  auto A3 = [&](int n) {
    ModInt res = 0;
    if (n % 2 == 0) res += ModInt(5 * n * n - 48 * n + 76) * inv[48];
    if (n % 4 == 0) res += ModInt(3) * inv[4];
    if (n % 6 == 0) res += ModInt(7 * n - 38) * inv[6];
    if (n % 12 == 0) res -= 8;
    if (n % 18 == 0) res -= 20;
    if (n % 24 == 0) res -= 16;
    if (n % 30 == 0) res -= 19;
    if (n % 42 == 0) res += 8;
    if (n % 60 == 0) res += 68;
    if (n % 84 == 0) res += 60;
    if (n % 90 == 0) res += 48;
    if (n % 120 == 0) res += 60;
    if (n % 210 == 0) res += 48;
    return res * n;
  };

  auto A4 = [&](int n) {
    ModInt res = 0;
    if (n % 6 == 0) res += ModInt(7 * n - 42) * inv[12];
    if (n % 12 == 0) res -= ModInt(5) * inv[2];
    if (n % 18 == 0) res -= 4;
    if (n % 24 == 0) res += 3;
    if (n % 42 == 0) res += 6;
    if (n % 60 == 0) res += 34;
    if (n % 84 == 0) res -= 6;
    if (n % 120 == 0) res -= 6;
    return res * n;
  };

  auto A5 = [&](int n) {
    ModInt res = 0;
    if (n % 6 == 0) res += ModInt(n - 6) * inv[4];
    if (n % 12 == 0) res -= ModInt(3) * inv[2];
    if (n % 24 == 0) res -= 2;
    if (n % 42 == 0) res += 4;
    if (n % 84 == 0) res += 6;
    if (n % 120 == 0) res += 6;
    return res * n;
  };

  auto A6 = [&](int n) {
    ModInt res = 0;
    if (n % 30 == 0) res += 4;
    if (n % 60 == 0) res -= 4;
    return res * n;
  };

  auto A7 = [&](int n) {
    ModInt res = 0;
    if (n % 30 == 0) res += 1;
    if (n % 60 == 0) res += 4;
    return res * n;
  };

  auto A = [&](int n, int m) {
    if (m == 3) return A3(n);
    if (m == 4) return A4(n);
    if (m == 5) return A5(n);
    if (m == 6) return A6(n);
    if (m == 7) return A7(n);
    assert(0);
  };

  auto B = [&](int n, int m) {
    ModInt res = 0, x = 1, y = 1;
    for (int i = 1, s = 1; i <= m; i++, s *= -1) {
      x *= ModInt(m - i + 1) * inv[i];
      y *= (n <= i ? 0 : ModInt(2) * inv[n - i]);
      if (i >= 3) res += x * y * s;
    }
    return res;
  };

  auto C = [&](int n) {
    ModInt res = 0, x = 1, y = 1;
    int m = n >> 1;
    res = ModInt(2 * m * (m - 1)) * inv[n - 1] * inv[n - 2] - ModInt(2 * m) * inv[n - 1];
    for (int i = 1, s = 1; i <= m; i++, s *= -1) {
      x *= ModInt(m - i + 1) * inv[i];
      y *= ModInt(2) * inv[n - i];
      res += x * y * s;
    }
    return res;
  };

  cout << "-1\n"
       << "-1\n"
       << "1\n";
  for (int i = 4; i <= kMax; i++) {
    ModInt n = i;
    ModInt ex = n - (n + n) * inv[i - 1] + Comb(i, 4) * 4 * inv[i - 1] * inv[i - 2] + 1;
    for (int j = 3; j <= 7; j++) ex -= A(i, j) * B(i, j);
    if (~i & 1) ex -= C(i);
    cout << ex << "\n";
  }
  
  return 0;
}
