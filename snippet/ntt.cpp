#include <bits/stdc++.h>

using namespace std;

struct NTT {
  vector<int64_t> Mul(vector<int64_t> u, vector<int64_t> v, int64_t mod) {
    vector<vector<int64_t>> convs(kNMods);
    for (int i = 0; i < convs.size(); i++) {
      convs[i] = Mul(u, v, kModData[i]);
    }

    array<array<int64_t, kNMods>, kNMods> crt_data;
    for (int i = 0; i < kNMods; i++) {
      for (int j = 0; j < kNMods; j++) {
        if (i == j) {
          crt_data[i][j] = kModData[i].first;
        } else {
          crt_data[i][j] = Power(kModData[i].first, kModData[j].first - 2, kModData[j].first);
        }
      }
    }

    int n = convs[0].size();
    vector<int64_t> res(n), crt_convs(kNMods);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < kNMods; j++) crt_convs[j] = convs[j][i];
      res[i] = CRT(crt_convs, crt_data, mod);
    }
    return res;
  }

 private:
  static constexpr pair<int64_t, int64_t> kModData[] = {
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