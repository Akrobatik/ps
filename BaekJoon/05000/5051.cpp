// Title : 피타고라스의 정리
// Link  : https://www.acmicpc.net/problem/5051
// Time  : 152 ms
// Memory: 30560 KB

#include <bits/stdc++.h>

using namespace std;

const double kPI = acos(-1);

int nmod[500000], smod[500000];

void FFT(vector<complex<double>>& v, bool inv) {
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

vector<int64_t> Mul(span<int> u) {
  int n = 1;
  int nu = u.size();
  int nuv = nu << 1;
  while (n < nuv) n <<= 1;

  vector<complex<double>> uc(u.begin(), u.end());
  uc.resize(n);
  FFT(uc, false);
  for (int i = 0; i < n; i++) uc[i] *= uc[i];
  FFT(uc, true);

  vector<int64_t> w(n);
  for (int i = 0; i < n; i++) w[i] = round(uc[i].real());
  return w;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int64_t i = 1; i < n; i++) {
    int r1 = (i * i) % n;
    int r2 = r1 << 1;
    if (r2 >= n) r2 -= n;
    ++nmod[r1];
    ++smod[r2];
  }

  auto sp = span<int>(nmod, nmod + n);
  auto vec = Mul(sp);
  int64_t ans = 0;
  for (int64_t i = 1; i < n; i++) {
    int r = (i * i) % n;
    ans += ((vec[r] + vec[n + r] + smod[r]) >> 1);
  }
  cout << ans;

  return 0;
}
