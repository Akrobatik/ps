// Title : Even Three is Odd
// Link  : https://www.acmicpc.net/problem/19359 
// Time  : 84 ms
// Memory: 33420 KB

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

constexpr int kMod = 1e9 + 7;
using ModInt = ModInt32<kMod>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ModInt> arr, sum;
  vector<vector<array<ModInt, 2>>> memo;

  int n;
  while (cin >> n) {
    arr.resize(n + 1);
    memo.assign(n, vector<array<ModInt, 2>>(n + 1));
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) memo[1][i] = {i - 1, 1};
    for (int i = 1; i < n - 1; i++) {
      sum.assign(n + 2, 0);
      for (int j = n; j >= 1; j--) {
        sum[j] = sum[j + 1] + memo[i][j][1] * arr[j];
      }

      ModInt x = 0, y = 0;
      for (int j = 1; j <= n; j++) {
        x += memo[i][j - 1][0];
        y += memo[i][j - 1][1] * (j - 1);
        memo[i + 1][j][0] += arr[j] * (x + y + memo[i][j][1] * (j - 1)) + sum[j + 1] * (j - 1);
        memo[i + 1][j][1] += arr[j] * memo[i][j][0] + sum[j];
      }
    }

    ModInt ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += memo[n - 1][i][0] + memo[n - 1][i][1] * i;
    }
    cout << ans << "\n";
  }

  return 0;
}
