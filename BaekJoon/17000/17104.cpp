// Title : 골드바흐 파티션 2
// Link  : https://www.acmicpc.net/problem/17104 
// Time  : 308 ms
// Memory: 55012 KB

#include <bits/stdc++.h>

using namespace std;

struct FFT {
  vector<int> Sqr(const vector<int>& u) {
    int nuv = u.size() << 1;
    int n = 1;
    while (n < nuv) n <<= 1;

    vector<complex<double>> uc(u.begin(), u.end());
    uc.resize(n);

    Conv(uc, false);
    for (int i = 0; i < n; i++) uc[i] *= uc[i];
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

  vector<int> arr(kMax + 1, 1);

  vector<int> primes;
  arr[0] = arr[1] = 0;
  for (int i = 2; i <= kMax; i++) {
    if (arr[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > kMax) break;
      arr[i * p] = 0;
      if (i % p == 0) break;
    }
  }

  FFT fft;
  auto brr = fft.Sqr(arr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ((brr[n] + arr[n >> 1]) >> 1) << "\n";
  }

  return 0;
}
