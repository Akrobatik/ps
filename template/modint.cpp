#include <bits/stdc++.h>

using namespace std;

template <int32_t MOD>
struct ModInt32 {
  using CT = typename std::conditional<
      (MOD <= std::numeric_limits<int32_t>::max() / 2),
      int32_t,
      int64_t>::type;

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
    if (x >= MOD) val -= MOD;
    val = x;
    return *this;
  }

  constexpr ModInt32& operator-=(const ModInt32& other) {
    CT x = (CT)val + (MOD - other.val);
    if (x >= MOD) val -= MOD;
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

template <int64_t MOD>
struct ModInt64 {
  using CT = typename std::conditional<
      (MOD <= std::numeric_limits<int64_t>::max() / 2),
      int64_t,
      __int128_t>::type;

  constexpr ModInt64() : val(0) {}
  constexpr ModInt64(int32_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}
  constexpr ModInt64(int64_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}
  constexpr ModInt64(__int128_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}

  constexpr ModInt64 Pow(int64_t exp) const {
    __int128_t n = val, x = 1;
    while (exp) {
      if (exp & 1) x = x * n % MOD;
      n = n * n % MOD;
      exp >>= 1;
    }

    ModInt64 res;
    res.val = x;
    return res;
  }

  constexpr ModInt64 Inv() const {
    return Pow(MOD - 2);
  }

  constexpr ModInt64& operator++() {
    if (++val == MOD) val = 0;
    return *this;
  }

  constexpr ModInt64 operator++(int) {
    ModInt64 tmp(*this);
    operator++();
    return tmp;
  }

  constexpr ModInt64& operator+=(const ModInt64& other) {
    CT x = (CT)val + other.val;
    if (x >= MOD) val -= MOD;
    val = x;
    return *this;
  }

  constexpr ModInt64& operator-=(const ModInt64& other) {
    CT x = (CT)val + (MOD - other.val);
    if (x >= MOD) val -= MOD;
    val = x;
    return *this;
  }

  constexpr ModInt64& operator*=(const ModInt64& other) {
    val = (__int128_t)val * other.val % MOD;
    return *this;
  }

  constexpr ModInt64& operator/=(const ModInt64& other) {
    *this *= other.Inv();
    return *this;
  }

  constexpr ModInt64 operator-() const {
    ModInt64 res;
    if (val) res.val = MOD - val;
    return res;
  }

  constexpr ModInt64 operator+(const ModInt64& rhs) const {
    return ModInt64(*this) += rhs;
  }

  constexpr ModInt64 operator-(const ModInt64& rhs) const {
    return ModInt64(*this) -= rhs;
  }

  constexpr ModInt64 operator*(const ModInt64& rhs) const {
    return ModInt64(*this) *= rhs;
  }

  constexpr ModInt64 operator/(const ModInt64& rhs) const {
    return ModInt64(*this) /= rhs;
  }

  constexpr bool operator!() const {
    return val == 0;
  }

  friend istream& operator>>(istream& is, ModInt64& num) {
    is >> num.val;
    if ((num.val %= MOD) < 0) num.val += MOD;
    return is;
  }

  friend ostream& operator<<(ostream& os, const ModInt64& num) {
    os << num.val;
    return os;
  }

  int64_t val;
};
