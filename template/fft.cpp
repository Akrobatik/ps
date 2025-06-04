#include <bits/stdc++.h>

using namespace std;

struct FFT {
  vector<int64_t> Mul(const vector<int64_t>& u, const vector<int64_t>& v) {
    int nuv = u.size() + v.size();
    int n = 1;
    while (n < nuv) n <<= 1;

    vector<complex<double>> uc(u.begin(), u.end());
    vector<complex<double>> vc(v.begin(), v.end());
    uc.resize(n), vc.resize(n);

    Conv(uc, false);
    Conv(vc, false);
    for (int i = 0; i < n; i++) uc[i] *= vc[i];
    Conv(uc, true);

    vector<int64_t> w(n);
    for (int i = 0; i < n; i++) w[i] = round(uc[i].real());
    return w;
  }

  vector<int64_t> Sqr(const vector<int64_t>& u) {
    int nuv = u.size() << 1;
    int n = 1;
    while (n < nuv) n <<= 1;

    vector<complex<double>> uc(u.begin(), u.end());
    uc.resize(n);

    Conv(uc, false);
    for (int i = 0; i < n; i++) uc[i] *= uc[i];
    Conv(uc, true);

    vector<int64_t> w(n);
    for (int i = 0; i < n; i++) w[i] = round(uc[i].real());
    return w;
  }

 private:
  const double kPI = acos(-1);

  void Conv(vector<complex<double>>& v, bool inv) {
    int n = v.size();
    for (int i = 1, j = 0; i < n; i++) {
      int b = n >> 1;
      while (j & b) j ^= b, b >>= 1;
      j |= b;
      if (i < j) swap(v[i], v[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      double x = (inv ? kPI / i : -kPI / i);
      complex<double> w(cos(x), sin(x));
      for (int j = 0; j < n; j += (i << 1)) {
        complex<double> z(1, 0);
        for (int k = 0; k < i; k++) {
          complex<double> e = v[j + k];
          complex<double> o = v[i + j + k];
          v[j + k] = e + o * z;
          v[i + j + k] = e - o * z;
          z *= w;
        }
      }
    }

    if (inv) {
      for (int i = 0; i < n; i++) v[i] /= n;
    }
  }
};
