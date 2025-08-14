// Title : 팰린드롬의 개수
// Link  : https://www.acmicpc.net/problem/1204 
// Time  : 40 ms
// Memory: 5988 KB

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

constexpr int kMod = 835454957;
using ModInt = ModInt32<kMod>;

ModInt memo[101][50][201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<string> strs;
  strs.reserve(n);
  while (n--) {
    string s;
    cin >> s;
    if (s.size() <= k) strs.push_back(s);
  }
  n = strs.size();

  for (int i = 0; i < n; i++) {
    auto& is = strs[i];
    int ni = is.size();
    for (int j = 0; j < ni; j++) {
      int l = j, r = ni - j;
      int minn = min<int>(l, r);
      bool ok = true;
      for (int k = 0; ok && k < minn; k++) {
        ok = (is[j - k - 1] == is[j + k]);
      }
      if (ok) memo[ni][i][r - l + 100] += 1;
    }
    for (int j = 0; j < ni; j++) {
      int l = j, r = ni - j - 1;
      int minn = min<int>(l, r);
      bool ok = true;
      for (int k = 0; ok && k < minn; k++) {
        ok = (is[j - k - 1] == is[j + k + 1]);
      }
      if (ok) memo[ni][i][r - l + 100] += 1;
    }
  }

  for (int i = 1; i < k; i++) {
    for (int j = 0; j < n; j++) {
      auto& js = strs[j];
      int nj = js.size();
      for (int l = -nj; l <= nj; l++) {
        auto cur = memo[i][j][l + 100];
        if (!cur) continue;

        for (int m = 0; m < n; m++) {
          auto& ms = strs[m];
          int nm = ms.size();
          int nxt = i + nm + 1;
          if (nxt > k) continue;

          if (l < 0) {
            int minn = min<int>(-l, nm);
            bool ok = true;
            for (int o = 0; ok && o < minn; o++) {
              ok = (js[-l - o - 1] == ms[o]);
            }
            if (ok) memo[nxt][minn < nm ? m : j][l + nm + 100] += cur;
          } else {
            int minn = min<int>(l, nm);
            bool ok = true;
            for (int o = 0; ok && o < minn; o++) {
              ok = (js[nj - l + o] == ms[nm - o - 1]);
            }
            if (ok) memo[nxt][minn < nm ? m : j][l - nm + 100] += cur;
          }
        }
      }
    }
  }

  ModInt ans = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      ans += memo[i][j][100];
    }
  }
  cout << ans;

  return 0;
}
