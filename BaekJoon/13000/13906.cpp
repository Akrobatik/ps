// Title : 대문자
// Link  : https://www.acmicpc.net/problem/13906 
// Time  : 0 ms
// Memory: 2156 KB

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

constexpr int kMod = 1e9 + 7;
using ModInt = ModInt32<kMod>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size();
  vector<int> ids[26];
  for (int i = 0; i < n; i++) {
    int x = s[i] - 'a';
    ids[x].push_back(i);
  }

  int pos[26] = {};
  vector<ModInt> memo(n + 1, 1);
  for (int i = 0; i < n; i++) {
    int x = s[i] - 'a';
    ++pos[x];
    for (int j = 0; j < 26; j++) {
      int p = pos[j];
      if (p < 3) continue;
      memo[i + 1] += memo[ids[j][p - 3]];
    }
  }
  cout << memo[n] - 1;

  return 0;
}