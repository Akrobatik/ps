// Title : 팰린팰린드롬
// Link  : https://www.acmicpc.net/problem/34154 
// Time  : 12 ms
// Memory: 10480 KB

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

constexpr int kMod1 = 1e9 + 7;
constexpr int kBase1 = 337;
constexpr int kMod2 = 1e9 + 9;
constexpr int kBase2 = 331;

using M1 = ModInt32<kMod1>;
using M2 = ModInt32<kMod2>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size(), half = n >> 1;

  M1 b1 = kBase1;
  vector<M1> h1(n + 1), p1(n + 1);
  M2 b2 = kBase2;
  vector<M2> h2(n + 1), p2(n + 1);

  p1[0] = 1, p2[0] = 1;
  for (int i = 0; i < n; i++) {
    int x = s[i] - 'A' + 1;
    h1[i + 1] = h1[i] + p1[i] * x;
    h2[i + 1] = h2[i] + p2[i] * x;
    p1[i + 1] = p1[i] * b1;
    p2[i + 1] = p2[i] * b2;
  }

  auto Fwd = [&](int st, int len) {
    M1 x1 = h1[st + len] - h1[st];
    M2 x2 = h2[st + len] - h2[st];
    x1 *= p1[n - st];
    x2 *= p2[n - st];
    return (((int64_t)x1.val) << 32) | x2.val;
  };

  auto Bwd = [&](int st, int len) {
    return Fwd(n - st - len, len);
  };

  int idx = 0, maxx = 1;
  while (idx < half) {
    int len = 1;
    while (idx + len <= half && Fwd(idx, len) != Bwd(idx, len)) ++len;

    int cur = (idx + len <= half ? len : n - (idx << 1));
    maxx = max<int>(maxx, cur);
    idx += len;
  }
  cout << maxx;

  return 0;
}