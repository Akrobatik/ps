#include <bits/stdc++.h>

using namespace std;

struct NTT {
  vector<int64_t> Mul(vector<int64_t> u, vector<int64_t> v, int64_t mod) {
    int nmods = sizeof(kModData) / sizeof(kModData[0]);
    vector<vector<int64_t>> convs(nmods);
    for (int i = 0; i < convs.size(); i++) {
      convs[i] = Mul(u, v, kModData[i]);
    }

    vector<vector<int64_t>> crt_data(nmods, vector<int64_t>(nmods));
    for (int i = 0; i < nmods; i++) {
      for (int j = 0; j < nmods; j++) {
        if (i == j) {
          crt_data[i][j] = kModData[i].first;
        } else {
          crt_data[i][j] = Power(kModData[i].first, kModData[j].first - 2, kModData[j].first);
        }
      }
    }

    int n = convs[0].size();
    vector<int64_t> res(n), crt_convs(nmods);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < nmods; j++) crt_convs[j] = convs[j][i];
      res[i] = CRT(crt_convs, crt_data, mod);
    }
    return res;
  }

 private:
  static constexpr pair<int64_t, int64_t> kModData[] = {
      {469762049, 3},
      {998244353, 3},
      {1004535809, 3}};

  int64_t CRT(const vector<int64_t>& convs, const vector<vector<int64_t>>& crt_data, int64_t mod) {
    int64_t res = 0, mul = 1;
    int nmods = convs.size();
    vector<int64_t> x(nmods);
    for (int i = 0; i < nmods; i++) {
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

constexpr int64_t kMod = 1e9 + 7;

int64_t Power(int64_t n, int exp, int64_t mod) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = (res * n) % mod;
    n = (n * n) % mod;
    exp >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int64_t> table(n);
  table[0] = 1;
  for (int i = 1; i < n; i++) {
    table[i] = table[i - 1] * k % kMod;
  }

  vector<int64_t> fact(n), inv(n);
  fact[0] = 1;
  for (int i = 1; i < n; i++) fact[i] = (fact[i - 1] * i) % kMod;
  inv[n - 1] = Power(fact[n - 1], kMod - 2, kMod);
  for (int i = n - 1; i > 0; i--) inv[i - 1] = (inv[i] * i) % kMod;

  vector<int64_t> brr(n), crr(n);
  for (int i = 0; i < n; i++) {
    brr[i] = arr[i] * inv[i] % kMod;
    crr[i] = table[i] * inv[i] % kMod;
  }

  NTT ntt;
  auto conv = ntt.Mul(brr, crr, kMod);
  for (int i = 0; i < n; i++) {
    cout << conv[i] * fact[i] % kMod << " ";
  }

  return 0;
}