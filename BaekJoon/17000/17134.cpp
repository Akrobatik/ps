// Title : 르모앙의 추측
// Link  : https://www.acmicpc.net/problem/17134 
// Time  : 452 ms
// Memory: 91364 KB

#include <bits/stdc++.h>

using namespace std;

struct FFT {
  vector<int> Mul(const vector<int>& u, const vector<int>& v) {
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

    vector<int> w(u.size());
    for (int i = 0; i < u.size(); i++) w[i] = round(uc[i].real());
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

constexpr int kMax = 1e6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr(kMax + 1, 1), brr(kMax + 1);

  vector<int> primes;
  primes.reserve(78498);
  arr[0] = arr[1] = 0;
  for (int i = 2; i <= kMax; i++) {
    if (arr[i]) {
      primes.push_back(i);
      if ((i << 1) <= kMax) {
        brr[i << 1] = 1;
      }
    }
    for (auto p : primes) {
      if (i * p > kMax) break;
      arr[i * p] = 0;
      if (i % p == 0) break;
    }
  }
  arr[2] = 0;

  FFT fft;
  auto crr = fft.Mul(arr, brr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << crr[n] << "\n";
  }

  return 0;
}
