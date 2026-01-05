// Title : 움직이지 않고 여행하는 법
// Link  : https://www.acmicpc.net/problem/35065 
// Time  : 276 ms
// Memory: 34224 KB

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  unordered_set<int> idx;
  for (int i = 1; i <= n; i++) {
    idx.insert(i);
  }

  vector<int> cnt(n + 1, -1);
  vector<ModInt> val(n + 1);
  vector<int> deg(n + 1);
  vector<vector<int>> out(n);

  auto Push = [&](int x, int c, ModInt add) {
    if (cnt[x] != -1) return;

    cnt[x] = c;
    val[x] = add;
    out[c].push_back(x);
  };

  Push(1, 0, 1);
  vector<int> tmp;
  for (int i = 0; i < n; i++) {
    ModInt all = 0;
    int sz = out[i].size();
    for (auto v : out[i]) {
      idx.erase(v);
      all += val[v];
      for (auto u : g[v]) {
        if (++deg[u] == sz) {
          if (idx.erase(u)) {
            tmp.push_back(u);
          }
        }
      }
    }

    for (auto e : idx) {
      ModInt cut = 0;
      for (auto u : g[e]) {
        if (cnt[u] + 1 == i + 1) cut += val[u];
      }
      Push(e, i + 1, all - cut);
    }

    for (auto v : out[i]) {
      for (auto u : g[v]) --deg[u];
    }

    for (auto e : tmp) idx.insert(e);
    tmp.clear();
  }

  for (int i = 1; i <= n; i++) cout << cnt[i] << " " << val[i] << "\n";

  return 0;
}