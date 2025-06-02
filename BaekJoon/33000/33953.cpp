// Title : PPC와 CPP 2
// Link  : https://www.acmicpc.net/problem/33953 
// Time  : 3448 ms
// Memory: 157008 KB

#include <bits/stdc++.h>

using namespace std;

struct NTT {
  vector<int64_t> Mul(const vector<int64_t>& u, const vector<int64_t>& v) {
    return Mul(u, v, kModData[0]);

    // vector<vector<int64_t>> convs(kNMods);
    // for (int i = 0; i < convs.size(); i++) {
    //   convs[i] = Mul(u, v, kModData[i]);
    // }

    // array<array<int64_t, kNMods>, kNMods> crt_data;
    // for (int i = 0; i < kNMods; i++) {
    //   for (int j = 0; j < kNMods; j++) {
    //     if (i == j) {
    //       crt_data[i][j] = kModData[i].first;
    //     } else {
    //       crt_data[i][j] = Power(kModData[i].first, kModData[j].first - 2, kModData[j].first);
    //     }
    //   }
    // }

    // int n = convs[0].size();
    // vector<int64_t> res(n), crt_convs(kNMods);
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < kNMods; j++) crt_convs[j] = convs[j][i];
    //   res[i] = CRT(crt_convs, crt_data, mod);
    // }
    // return res;
  }

 private:
  static constexpr pair<int64_t, int64_t> kModData[] = {
      {998244353, 3},
      {7340033, 3},
      {415236097, 5},
      {463470593, 3}};

  static constexpr int kNMods = sizeof(kModData) / sizeof(kModData[0]);

  int64_t CRT(const vector<int64_t>& convs, const array<array<int64_t, kNMods>, kNMods>& crt_data, int64_t mod) {
    int64_t res = 0, mul = 1;
    array<int64_t, kNMods> x{};
    for (int i = 0; i < kNMods; i++) {
      x[i] = convs[i];
      for (int j = 0; j < i; j++) {
        x[i] = (x[i] - x[j]) * crt_data[j][i] % crt_data[i][i];
        if (x[i] < 0) x[i] += crt_data[i][i];
      }
      res = (res + mul * x[i]) % mod;
      mul = mul * crt_data[i][i] % mod;
    }
    return res;
  }

  void Conv(vector<int64_t>& v, bool inv, int64_t mod, int64_t g) {
    int n = v.size();
    for (int i = 1, j = 0; i < n; i++) {
      int b = n >> 1;
      while (j & b) j ^= b, b >>= 1;
      j |= b;
      if (i < j) swap(v[i], v[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      int64_t w = Power(g, (mod - 1) / (i << 1), mod);
      if (inv) w = Power(w, mod - 2, mod);
      for (int j = 0; j < n; j += (i << 1)) {
        int64_t z = 1;
        for (int k = 0; k < i; k++) {
          int64_t e = v[j + k];
          int64_t o = v[i + j + k] * z % mod;
          v[j + k] = (e + o) % mod;
          v[i + j + k] = (e - o + mod) % mod;
          z = z * w % mod;
        }
      }
    }

    if (inv) {
      int64_t inv_n = Power(n, mod - 2, mod);
      for (auto& x : v) x = x * inv_n % mod;
    }
  }

  vector<int64_t> Mul(vector<int64_t> u, vector<int64_t> v, pair<int64_t, int64_t> mod_data) {
    int nuv = u.size() + v.size();
    int n = 1;
    while (n < nuv) n <<= 1;
    u.resize(n), v.resize(n);

    auto [mod, g] = mod_data;

    Conv(u, false, mod, g);
    Conv(v, false, mod, g);
    for (int i = 0; i < n; i++) u[i] = u[i] * v[i] % mod;
    Conv(u, true, mod, g);

    return u;
  }

  int64_t Power(int64_t n, int exp, int64_t mod) {
    int64_t res = 1;
    while (exp) {
      if (exp & 1) res = (res * n) % mod;
      n = (n * n) % mod;
      exp >>= 1;
    }
    return res;
  }
};

template <int MAXN, int64_t MOD>
  requires(MAXN >= 0, MOD >= 3)
struct Combination {
  constexpr Combination() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
    inv[MAXN] = Power(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) inv[i - 1] = (inv[i] * i) % MOD;
  }

  int64_t operator()(int n, int r) const {
    return (((fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
  }

  static constexpr int64_t Power(int64_t n, int exp) {
    int64_t res = 1;
    while (exp) {
      if (exp & 1) res = (res * n) % MOD;
      n = (n * n) % MOD;
      exp >>= 1;
    }
    return res;
  }

  int64_t fact[MAXN + 1], inv[MAXN + 1];
};

constexpr int kMod = 998244353;

const Combination<8400000, kMod> kComb;

NTT ntt;

vector<int64_t> Inverse(const vector<int64_t>& poly) {
  int n = poly.size();
  vector<int64_t> arr{1};

  int cur = 1;
  while (cur < n) {
    int nxt = min<int>(cur << 1, n);
    vector<int64_t> brr(nxt);
    for (int i = 0; i < nxt; i++) brr[i] = poly[i];

    auto crr = ntt.Mul(arr, brr);
    crr.resize(nxt);

    vector<int64_t> drr(nxt);
    drr[0] = (2 - crr[0]);
    if (drr[0] < 0) drr[0] += kMod;
    for (int i = 1; i < nxt; i++) {
      if (crr[i] == 0) continue;
      drr[i] = kMod - crr[i];
    }

    arr = ntt.Mul(arr, drr);
    arr.resize(nxt);
    cur = nxt;
  }
  return arr;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int64_t> one(n + 1), two(n + 1);
  one[1] = 1, two[1] = 0;
  int len = k + 1;
  for (int i = 2; i <= n; i++) {
    len += k + 1;
    one[i] = kComb(len - 2, i - 1);
    two[i] = kComb(len - 2, i - 2);
  }

  int64_t ans = (one[n] << 1) + two[n];

  two[0] = 1;
  auto inv = Inverse(two);
  auto arr = ntt.Mul(one, inv);
  arr.resize(n + 1);
  arr = ntt.Mul(arr, one);

  cout << (ans + arr[n]) % kMod;

  return 0;
}
