// Title : 불의 군주 라그나로스 2
// Link  : https://www.acmicpc.net/problem/33688 
// Time  : 3516 ms
// Memory: 6136 KB

#include <bits/stdc++.h>

using namespace std;

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

constexpr int64_t kMod = 998244353;
constexpr int64_t kG = 3;
constexpr int kMax = 1 << 18;

int a[kMax], b[kMax];

int64_t Power(int64_t n, int exp, int64_t mod) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = (res * n) % mod;
    n = (n * n) % mod;
    exp >>= 1;
  }
  return res;
}

void Conv(int* v, bool inv, int n) {
  for (int i = 1, j = 0; i < n; i++) {
    int b = n >> 1;
    while (j & b) j ^= b, b >>= 1;
    j |= b;
    if (i < j) swap(v[i], v[j]);
  }

  for (int i = 1; i < n; i <<= 1) {
    int64_t w = Power(kG, (kMod - 1) / (i << 1), kMod);
    if (inv) w = Power(w, kMod - 2, kMod);
    for (int j = 0; j < n; j += (i << 1)) {
      int64_t z = 1;
      for (int k = 0; k < i; k++) {
        int64_t e = v[j + k];
        int64_t o = z * v[i + j + k] % kMod;
        v[j + k] = (e + o) % kMod;
        v[i + j + k] = (e - o + kMod) % kMod;
        z = z * w % kMod;
      }
    }
  }

  if (inv) {
    int64_t inv_n = Power(n, kMod - 2, kMod);
    for (int i = 0; i < kMax; i++) v[i] = inv_n * v[i] % kMod;
  }
}

vector<int> Mul(const vector<int>& u, const vector<int>& v, int maxx) {
  int nuv = u.size() + v.size();
  int n = 1;
  while (n < nuv) n <<= 1;

  memcpy(a, u.data(), u.size() << 2);
  memset(a + u.size(), 0, (n - u.size()) << 2);
  memcpy(b, v.data(), v.size() << 2);
  memset(b + v.size(), 0, (n - v.size()) << 2);

  Conv(a, false, n);
  Conv(b, false, n);
  for (int i = 0; i < n; i++) a[i] = (int64_t)a[i] * b[i] % kMod;
  Conv(a, true, n);

  vector<int> res(min<int>(u.size() + v.size() - 1, maxx));
  for (int i = 0; i < res.size(); i++) res[i] = a[i];
  return res;
}

vector<int> Sqr(const vector<int>& u, int maxx) {
  int nuv = u.size() << 1;
  int n = 1;
  while (n < nuv) n <<= 1;

  memcpy(a, u.data(), u.size() << 2);
  memset(a + u.size(), 0, (n - u.size()) << 2);

  Conv(a, false, n);
  for (int i = 0; i < n; i++) a[i] = (int64_t)a[i] * a[i] % kMod;
  Conv(a, true, n);

  vector<int> res(min<int>(u.size() + u.size() - 1, maxx));
  for (int i = 0; i < res.size(); i++) res[i] = a[i];
  return res;
}

const Combination<50000, kMod> kComb;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, x, y;
  cin >> n >> m >> x >> y;
  y = (y + x - 1) / x;
    
  if (n < y) {
    cout << "0";
    return 0;
  }

  vector<int> cnt(101);
  for (int i = 0; i < m; i++) {
    int64_t hp;
    cin >> hp;
    ++cnt[(hp + x - 1) / x];
  }

  vector<int> arr{1};
  for (int i = 0; i <= 100; i++) {
    if (cnt[i] == 0) continue;
    vector<int> brr(i + 1), crr(i + 1);
    for (int j = 0; j <= i; j++) {
      brr[j] = crr[j] = kComb.inv[j];
    }

    int exp = cnt[i] - 1;
    while (exp) {
      if (exp & 1) brr = Mul(brr, crr, n - y + 1);
      crr = Sqr(crr, n - y + 1);
      exp >>= 1;
    }
    arr = Mul(arr, brr, n - y + 1);
  }

  int64_t ans = 0;
  for (int i = 0; i < arr.size() && i <= n - y; i++) {
    if (arr[i] == 0) continue;
    int64_t add = (kComb(y + i - 1, i) * kComb.fact[i] % kMod) * arr[i] % kMod;
    ans += add;
  }
  cout << ans % kMod;

  return 0;
}
