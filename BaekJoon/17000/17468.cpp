// Title : N! mod P (3)
// Link  : https://www.acmicpc.net/problem/17468 
// Time  : 556 ms
// Memory: 51364 KB

#include <bits/stdc++.h>

using namespace std;

const double kPI = acos(-1);
constexpr int kMax = (1 << 16) * 4 + 2;
constexpr int kScale = 17;
constexpr int kMask = (1 << kScale) - 1;

int64_t fact[kMax + 1], fact_inv[kMax + 1];
int64_t inv[kMax + 1];

int64_t Power(int64_t x, int64_t exp, int64_t mod) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = (__int128_t)res * x % mod;
    x = (__int128_t)x * x % mod;
    exp >>= 1;
  }
  return res;
}

int64_t Round(double x, int64_t mod) {
  __int128_t res = (__int128_t)(x + 0.5);
  return res % mod;
}

void Conv(vector<complex<double>>& v, bool inv) {
  int n = v.size();
  for (int i = 1, j = 0; i < n; i++) {
    int b = n >> 1;
    while (j & b) j ^= b, b >>= 1;
    j |= b;
    if (i < j) swap(v[i], v[j]);
  }

  vector<complex<double>> w(n >> 1);
  const double angle = (inv ? kPI : -kPI) * 2.0 / n;
  for (int i = 0; i < w.size(); i++) w[i] = complex<double>(cos(angle * i), sin(angle * i));

  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += (i << 1)) {
      for (int k = 0; k < i; k++) {
        complex<double> e = v[j + k];
        complex<double> o = v[i + j + k] * w[n / (i << 1) * k];
        v[j + k] = e + o;
        v[i + j + k] = e - o;
      }
    }
  }

  if (inv) {
    for (int i = 0; i < n; i++) v[i] /= n;
  }
}

void Mul(vector<int64_t>& u, const vector<int64_t>& v, int64_t mod) {
  int nuv = u.size() + v.size();
  int n = 1;
  while (n < nuv) n <<= 1;

  vector<complex<double>> uc(n), vc(n), ur(n), vr(n);
  for (int i = 0; i < u.size(); i++) {
    int64_t hi = u[i] >> kScale, lo = u[i] & kMask;
    uc[i] = complex<double>(hi, lo);
  }
  for (int i = 0; i < v.size(); i++) {
    int64_t hi = v[i] >> kScale, lo = v[i] & kMask;
    vc[i] = complex<double>(hi, lo);
  }

  Conv(uc, false);
  Conv(vc, false);

  for (int i = 0, j; i < n; i++) {
    j = i ? n - i : 0;
    auto x1 = (uc[i] + conj(uc[j])) * complex<double>(0.5, 0.0);
    auto x2 = (uc[i] - conj(uc[j])) * complex<double>(0.0, -0.5);
    auto x3 = (vc[i] + conj(vc[j])) * complex<double>(0.5, 0.0);
    auto x4 = (vc[i] - conj(vc[j])) * complex<double>(0.0, -0.5);
    ur[i] = (x1 * x3) + (x1 * x4) * complex<double>(0, 1.0);
    vr[i] = (x2 * x3) + (x2 * x4) * complex<double>(0, 1.0);
  }

  Conv(ur, true);
  Conv(vr, true);

  u.resize(n);
  for (int i = 0; i < n; i++) {
    auto x1 = (__int128_t)Round(ur[i].real(), mod);
    auto x2 = ((__int128_t)Round(ur[i].imag(), mod) + Round(vr[i].real(), mod)) % mod;
    auto x3 = (__int128_t)Round(vr[i].imag(), mod);
    u[i] = ((x1 << (kScale * 2)) + (x2 << kScale) + x3) % mod;
  }
}

void Lagrange(vector<int64_t>& poly, int64_t mod) {
  int n = poly.size(), sz = n * 4 - 2;
  vector<int64_t> arr(n), axr(sz), brr(sz);

  for (int i = 0; i < n; i++) {
    arr[i] = ((__int128_t)poly[i] * fact_inv[i] % mod) * fact_inv[n - i - 1] % mod;
    if ((i & 1) && arr[i]) arr[i] = mod - arr[i];
  }

  for (int i = 0; i < sz; i++) axr[i] = inv[i];

  brr[n] = fact[n];
  for (int i = n + 1; i < sz; i++) brr[i] = ((__int128_t)brr[i - 1] * i % mod) * inv[i - n] % mod;

  Mul(arr, axr, mod);

  poly.resize(sz);
  for (int i = n; i < sz; i++) poly[i] = (__int128_t)arr[i] * brr[i] % mod;
}

void Square(vector<int64_t>& poly, int64_t mod) {
  Lagrange(poly, mod);

  int sz = poly.size() >> 1;
  for (int i = 0; i < sz; i++) poly[i] = (__int128_t)poly[i << 1] * poly[(i << 1) + 1] % mod;
  poly.resize(sz);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, p;
  cin >> n >> p;

  fact[0] = 1;
  for (int i = 1; i <= kMax; i++) fact[i] = (__int128_t)fact[i - 1] * i % p;
  fact_inv[kMax] = Power(fact[kMax], p - 2, p);
  for (int i = kMax; i; i--) fact_inv[i - 1] = (__int128_t)fact_inv[i] * i % p;
  for (int i = 1; i <= kMax; i++) inv[i] = (__int128_t)fact[i - 1] * fact_inv[i] % p;

  if (n <= kMax) {
    cout << fact[n];
    return 0;
  }

  vector<int64_t> poly{1, 2};

  int64_t d;
  for (d = 1; d * (d + 1) < n; d <<= 1) Square(poly, p);
  int64_t limit = n / d;

  int64_t ans = 1;
  for (int64_t i = 0; i < limit; i++) ans = (__int128_t)ans * poly[i] % p;
  for (int64_t i = limit * d + 1; i <= n; i++) ans = (__int128_t)ans * i % p;
  cout << ans;

  return 0;
}