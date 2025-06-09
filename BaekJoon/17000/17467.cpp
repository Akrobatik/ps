// Title : N! mod P (2)
// Link  : https://www.acmicpc.net/problem/17467 
// Time  : 100 ms
// Memory: 13984 KB

#include <bits/stdc++.h>

using namespace std;

const double kPI = acos(-1);
constexpr int kMax = 16384 * 4 + 2;

int64_t fact[kMax + 1], inv[kMax + 1];

int64_t Power(int64_t x, int64_t exp, int64_t mod) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = res * x % mod;
    x = x * x % mod;
    exp >>= 1;
  }
  return res;
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

void Mul(vector<int64_t>& u, const vector<int64_t>& v, int mod) {
  int nuv = u.size() + v.size();
  int n = 1;
  while (n < nuv) n <<= 1;

  vector<complex<double>> uc(n), vc(n), ur(n), vr(n);

  for (int i = 0; i < u.size(); i++) uc[i] = complex<double>(u[i] >> 15, u[i] & 0x7FFF);
  for (int i = 0; i < v.size(); i++) vc[i] = complex<double>(v[i] >> 15, v[i] & 0x7FFF);

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
    auto x1 = llround(ur[i].real()) % mod;
    auto x2 = (llround(ur[i].imag()) + llround(vr[i].real())) % mod;
    auto x3 = llround(vr[i].imag()) % mod;
    u[i] = ((x1 << 30) + (x2 << 15) + x3) % mod;
  }
}

void Lagrange(vector<int64_t>& poly, int mod) {
  int n = poly.size(), sz = n * 4 - 2;
  vector<int64_t> arr(n), axr(sz), brr(sz);

  for (int i = 0; i < n; i++) {
    arr[i] = (poly[i] * inv[i] % mod) * inv[n - i - 1] % mod;
    if ((i & 1) && arr[i]) arr[i] = mod - arr[i];
  }

  for (int i = 1; i < sz; i++) axr[i] = fact[i - 1] * inv[i] % mod;

  brr[n] = fact[n];
  for (int i = n + 1; i < sz; i++) brr[i] = (brr[i - 1] * i % mod) * axr[i - n] % mod;

  Mul(arr, axr, mod);

  poly.resize(sz);
  for (int i = n; i < sz; i++) poly[i] = arr[i] * (brr[i] % mod) % mod;
}

void Square(vector<int64_t>& poly, int mod) {
  Lagrange(poly, mod);

  int sz = poly.size() >> 1;
  for (int i = 0; i < sz; i++) poly[i] = poly[i << 1] * poly[(i << 1) + 1] % mod;
  poly.resize(sz);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p;
  cin >> n >> p;

  fact[0] = 1;
  for (int i = 1; i <= kMax; i++) fact[i] = fact[i - 1] * i % p;
  inv[kMax] = Power(fact[kMax], p - 2, p);
  for (int i = kMax; i; i--) inv[i - 1] = inv[i] * i % p;

  if (n <= kMax) {
    cout << fact[n];
    return 0;
  }

  vector<int64_t> poly{1, 2};

  int d;
  for (d = 1; d * (d + 1) < n; d <<= 1) Square(poly, p);
  int limit = n / d;

  int64_t ans = 1;
  for (int i = 0; i < limit; i++) ans = ans * poly[i] % p;
  for (int i = limit * d + 1; i <= n; i++) ans = ans * i % p;
  cout << ans;

  return 0;
}