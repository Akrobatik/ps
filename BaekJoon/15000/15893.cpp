// Title : 가장 긴 공통부분 팰린드롬
// Link  : https://www.acmicpc.net/problem/15893 
// Time  : 316 ms
// Memory: 63464 KB

#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

struct Manacher {
  void Init(string_view sv) {
    int n = (sv.size() << 1) + 1;
    table.clear(), table.resize(n);

    string s(n, '\0');
    auto ptr = s.data() + 1;
    for (char c : sv) *ptr = c, ptr += 2;

    int p, r = 0;
    for (int i = 1; i < n - 1; i++) {
      if (i > r) {
        p = r = i;
        while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
        table[i] = --r - p;
      } else {
        if (table[(p << 1) - i] < r - i) {
          table[i] = table[(p << 1) - i];
        } else if (table[(p << 1) - i] > r - i) {
          table[i] = r - i;
        } else {
          p = i;
          while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
          table[i] = --r - p;
        }
      }
    }
  }

  vector<int> table;
};

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

template <int32_t MOD1, int32_t BASE1, int32_t MOD2, int32_t BASE2>
struct PolyHash {
  using M1 = ModInt32<MOD1>;
  using M2 = ModInt32<MOD2>;

  PolyHash() : b1(BASE1), b2(BASE2), p1{1}, p2{1}, h1{0}, h2{0} {}

  void Init(string_view sv) {
    n = sv.size();
    int old = p1.size();
    p1.resize(n + 1), p2.resize(n + 1);
    for (int i = old; i <= n; i++) {
      p1[i] = p1[i - 1] * b1;
      p2[i] = p2[i - 1] * b2;
    }

    r1.resize(n + 1), r2.resize(n + 1);
    r1[n] = p1[n].Inv(), r2[n] = p2[n].Inv();
    for (int i = n - 1; i >= 0; i--) {
      r1[i] = r1[i + 1] * b1;
      r2[i] = r2[i + 1] * b2;
    }

    h1.resize(n + 1), h2.resize(n + 1);
    for (int i = 0; i < n; i++) {
      int x = (int)sv[i] + 1;
      h1[i + 1] = h1[i] + p1[i] * x;
      h2[i + 1] = h2[i] + p2[i] * x;
    }
  }

  bool Match(int i, int j, int len) {
    if (i + len > n || j + len > n) return false;
    return GetHash(i, len) == GetHash(j, len);
  }

  int64_t GetHash(int i, int len) {
    if (i + len > n) return -1;
    M1 x1 = h1[i + len] - h1[i];
    M2 x2 = h2[i + len] - h2[i];
    x1 *= r1[i];
    x2 *= r2[i];
    return (((int64_t)x1.val) << 32) | x2.val;
  }

 private:
  int n;
  M1 b1;
  M2 b2;
  vector<M1> p1, h1, r1;
  vector<M2> p2, h2, r2;
};

constexpr int kMod1 = 1e9 + 7;
constexpr int kBase1 = 337;
constexpr int kMod2 = 1e9 + 9;
constexpr int kBase2 = 331;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Manacher mnchr;
  vector<int> ids;

  PolyHash<kMod1, kBase1, kMod2, kBase2> ph;

  int n;
  cin >> n;
  vector<unordered_map<int64_t, int>> subs(n);
  for (auto& sub : subs) {
    string s;
    cin >> s;
    ph.Init(s);
    mnchr.Init(s);

    auto& table = mnchr.table;
    int ns = table.size();
    ids.resize(ns);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
      return table[lhs] > table[rhs];
    });

    for (auto i : ids) {
      int len = table[i];
      int st = (i >> 1) - (len >> 1);
      while (len > 0) {
        int64_t key = ph.GetHash(st++, len);
        if (sub.contains(key)) break;
        sub[key] = len;
        len -= 2;
      }
    }
  }

  unordered_map<int64_t, int> memo = move(subs[0]);
  for (int i = 1; i < n; i++) {
    if (memo.size() < subs[i].size()) swap(memo, subs[i]);
    unordered_map<int64_t, int> mnxt;
    for (auto [key, len] : subs[i]) {
      if (auto it = memo.find(key); it != memo.end()) mnxt[key] = len;
    }
    memo = move(mnxt);
  }

  int ans = 0;
  for (auto [key, len] : memo) {
    ans = max<int>(ans, len);
  }
  cout << ans;

  return 0;
}
