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

struct FenwickTree {
  FenwickTree(int _n) : n(_n), fwt(n + 1, 0) {}

  void Update(int i, ModInt x) {
    for (; i <= n; i += i & (-i)) fwt[i] += x;
  }

  ModInt Query(int i) {
    ModInt res = 0;
    for (; i > 0; i -= i & (-i)) res += fwt[i];
    return res;
  }

  ModInt Query(int l, int r) {
    return Query(r) - Query(l - 1);
  }

  int n;
  vector<ModInt> fwt;
};

vector<pair<int, int>> edges[5001];
int order[5001];
int in[5001], out[5001], sz[5001];
int oidx;

int Traverse(int cur, int par) {
  int sum = 1;
  for (auto [nxt, id] : edges[cur]) {
    if (nxt == par) continue;
    in[id] = ++oidx;
    sz[id] = Traverse(nxt, cur);
    out[id] = oidx;
    sum += sz[id];
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back({v, i});
    edges[v].push_back({u, i});
  }
  Traverse(1, 0);

  ModInt pc = n - 1;
  ModInt pl = (int64_t)n * (n - 1) / 2 - (n - 2);
  ModInt all = pc * pc * pl * pl;

  vector<int> ids(n - 1);
  iota(ids.begin(), ids.end(), 1);
  sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    return in[lhs] > in[rhs];
  });

  FenwickTree f1(n), f2(n), f3(n);
  ModInt s1 = 0, s2 = 0, s3 = 0;

  ModInt sum = 0;
  for (auto i : ids) {
    ModInt iu = sz[i], iv = n - sz[i];
    sum += iu * iv * iu * iv;

    ModInt x1 = f1.Query(in[i], out[i]);
    ModInt x2 = f2.Query(in[i], out[i]);
    ModInt x3 = f3.Query(in[i], out[i]);

    ModInt y = iu * 2 + iv * 3;
    sum += iv * (iu * y * x1 + (iu - y) * x2 - x3);

    ModInt z = iu * 3 + iv * 2;
    sum += iu * (iv * z * (s1 - x1) + (iv - z) * (s2 - x2) - (s3 - x3));

    ModInt w1 = iu, w2 = w1 * iu, w3 = w2 * iu;
    f1.Update(in[i], w1);
    f2.Update(in[i], w2);
    f3.Update(in[i], w3);
    s1 += w1, s2 += w2, s3 += w3;
  }
  cout << sum / all;

  return 0;
}
