// Title : 격자 경로의 가중치
// Link  : https://www.acmicpc.net/problem/33966 
// Time  : 1200 ms
// Memory: 24944 KB

#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

struct NTT {
  vector<int64_t> Mul(const vector<int64_t>& u, const vector<int64_t>& v, int64_t mod) {
    return Mul(u, v, kModData[0]);
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
const Combination<400000, kMod> kComb;

NTT ntt;
vector<int> arr, cat, sum, memo;
vector<int64_t> axr, bxr;

void CDQ(int l, int r, int k) {
  if (r - l <= 1) return;

  int mid = (l + r) >> 1;
  CDQ(l, mid, k);

  int len = mid - l, limit = r - k - l;
  if (len > 0 && limit > 0) {
    axr.resize(len);
    copy_n(memo.begin() + l, len, axr.begin());
    bxr.resize(limit);
    copy_n(cat.begin(), limit, bxr.begin());

    vector<int64_t> cxr = ntt.Mul(axr, bxr, kMod);
    for (int i = max<int>(mid, k + l); i < r; i++) {
      sum[i] = (sum[i] + cxr[i - k - l]) % kMod;
      memo[i] = (int64_t)arr[i] * sum[i] % kMod;
    }
  }
  CDQ(mid, r, k);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  arr.resize(n + 1);
  for (auto& e : arr) cin >> e;

  cat.resize(n - k + 1);
  for (int i = 0; i < cat.size(); i++) {
    cat[i] = kComb(i << 1, i) * kComb.Power(i + 1, kMod - 2) % kMod;
  }

  sum.resize(n + 1), memo.resize(n + 1);
  memo[0] = arr[0];
  CDQ(0, n + 1, k);

  for (int i = k; i <= n; i++) cout << memo[i] << " ";

  return 0;
}
