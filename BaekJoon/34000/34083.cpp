// Title : 결계 배치하기
// Link  : https://www.acmicpc.net/problem/34083 
// Time  : 0 ms
// Memory: 2192 KB

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

constexpr int kMod = 998244353;

using ModInt = ModInt32<kMod>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  int d = n / m;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<pair<int, int>> axr(m);
  for (int i = 0; i < m; i++) {
    int l = arr[i * d], r = arr[(i + 1) * d - 1];
    axr[i] = {l, r};
  }

  vector<ModInt> memo(k + 1, 1), mnxt(k + 1);
  for (int i = 1; i < m; i++) {
    auto [ll, lr] = axr[i - 1];
    auto [rl, rr] = axr[i];
    mnxt.assign(k + 1, 0);

    int l = (i == 1 ? 1 : axr[i - 2].second + 1);
    int r = (i + 1 == m ? k : axr[i + 1].first - 1);
    for (int j = l; j < rl; j++) {
      auto cur = memo[j];
      if (!cur) continue;

      int lo = max<int>(j + 1, lr + lr - j);
      int hi = rl + rl - j;
      if (lo <= k) mnxt[lo] += cur;
      if (hi <= k) mnxt[hi] -= cur;
    }
    for (int j = l + 1; j <= r; j++) mnxt[j] += mnxt[j - 1];
    swap(memo, mnxt);
  }

  ModInt sum = 0;
  for (int i = 1; i <= k; i++) sum += memo[i];
  cout << sum;

  return 0;
}
