// Title : 보석 가게
// Link  : https://www.acmicpc.net/problem/13575
// Time  : 624 ms
// Memory: 64984 KB

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

FFT fft;

vector<int64_t> Mul(const vector<int64_t>& u, const vector<int64_t>& v) {
  auto res = fft.Mul(u, v);
  for (auto& e : res) e = (e != 0);
  return res;
}

vector<int64_t> Sqr(const vector<int64_t>& u) {
  auto res = fft.Sqr(u);
  for (auto& e : res) e = (e != 0);
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int64_t> arr(1001);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[x] = 1;
  }

  vector<int64_t> ans(arr);
  --k;
  while (k) {
    if (k & 1) ans = Mul(ans, arr);
    arr = Sqr(arr);
    k >>= 1;
  }

  for (int i = 1; i < ans.size(); i++) {
    if (ans[i] == 0) continue;
    cout << i << " ";
  }

  return 0;
}
