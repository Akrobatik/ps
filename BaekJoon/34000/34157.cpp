// Title : Split the SSHS 5
// Link  : https://www.acmicpc.net/problem/34157 
// Time  : 76 ms
// Memory: 15524 KB

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

constexpr int kMax = 1e5;

constexpr int kMod = 998244353;
using ModInt = ModInt32<kMod>;

vector<int> edges[kMax + 1];
vector<int> bombs[kMax + 1];
int in[kMax + 1], out[kMax + 1], nidx;
ModInt prob[kMax + 1], fact[kMax + 1], ifac[kMax + 1], inv[kMax + 1];
vector<int> stk;

void Build(int cur, int par) {
  in[cur] = ++nidx;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    Build(nxt, cur);
  }
  out[cur] = nidx;
}

void Traverse(int cur, int par) {
  prob[cur] *= prob[par];
  stk.clear();
  int bsz = bombs[cur].size();
  for (auto u : bombs[cur]) {
    if (!(in[cur] < in[u] && in[u] <= out[cur])) continue;
    while (!stk.empty() && out[stk.back()] < in[u]) stk.pop_back();
    stk.push_back(u);

    int sz = stk.size();
    int x = bsz - sz;
    prob[u] *= ModInt(x) * inv[x + 1];
  }

  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    Traverse(nxt, cur);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int sz;
    cin >> sz;

    auto& vec = bombs[i];
    vec.resize(sz);
    for (auto& e : vec) cin >> e;
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  Build(1, 0);
  for (int i = 1; i <= n; i++) {
    auto& vec = bombs[i];
    sort(vec.begin(), vec.end(), [&](int lhs, int rhs) {
      return in[lhs] < in[rhs];
    });
  }

  ModInt one = 1;
  prob[0] = fact[0] = ifac[0] = inv[0] = one;
  for (int i = 1; i <= n; i++) {
    prob[i] = one;
    fact[i] = fact[i - 1] * i;
  }
  ifac[n] = fact[n].Inv();
  for (int i = n; i > 0; i--) {
    ifac[i - 1] = ifac[i] * i;
    inv[i] = fact[i - 1] * ifac[i];
  }
  Traverse(1, 0);

  for (int i = 2; i <= n; i++) {
    cout << prob[i] << "\n";
  }

  return 0;
}
