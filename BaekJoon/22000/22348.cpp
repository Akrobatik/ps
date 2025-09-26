// Title : 헬기 착륙장
// Link  : https://www.acmicpc.net/problem/22348 
// Time  : 168 ms
// Memory: 89960 KB

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

constexpr int kMod = 1e9 + 7;
using ModInt = ModInt32<kMod>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a = 50000, b = 50000, s = a + b, r = 1;
  while ((r + 1) * (r + 2) / 2 <= s) ++r;

  vector<vector<ModInt>> memo(r + 1, vector<ModInt>(a + 1));
  memo[0][0] = 1;
  for (int i = 1; i <= r; i++) {
    int ub = min<int>(a, i * (i + 1) / 2);
    for (int j = 0; j <= ub; j++) {
      memo[i][j] = memo[i - 1][j];
      if (i <= j) memo[i][j] += memo[i - 1][j - i];
    }
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= a; j++) {
      memo[i][j] += memo[i][j - 1];
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    int s = a + b, r = 1;
    while ((r + 1) * (r + 2) / 2 <= s) ++r;

    ModInt ans = 0;
    for (int i = 1; i <= r; i++) {
      int is = i * (i + 1) / 2;
      int lb = max<int>(is - b, 0);
      int ub = min<int>(a, is);
      ans += memo[i][ub] - (lb ? memo[i][lb - 1] : 0);
    }
    cout << ans << "\n";
  }

  return 0;
}