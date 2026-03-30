// Title : 고속 프리렌 변환
// Link  : https://www.acmicpc.net/problem/35433 
// Time  : 0 ms
// Memory: 2268 KB

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

constexpr int64_t kBnd = 1e6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  FFT fft;

  int64_t n, x;
  cin >> n >> x;

  int64_t ox = x, cnt = 1;
  while (x * ox <= kBnd) x *= ox, ++cnt;

  vector<vector<int64_t>> arr(n);
  for (auto& vec : arr) {
    int64_t a, l;
    cin >> a >> l;

    int64_t sz = l / cnt, rem = l % cnt;
    if (sz > 0) {
      int64_t val = 0;
      for (int64_t i = 0, pw = 1; i < cnt; i++, pw *= ox) {
        val += a * pw;
      }
      vec.assign(sz, val);
    }
    if (rem > 0) {
      int64_t val = 0;
      for (int64_t i = 0, pw = 1; i < rem; i++, pw *= ox) {
        val += a * pw;
      }
      vec.push_back(val);
    }
  }

  auto vec = [&](this auto&& self, int l, int r) -> vector<int64_t> {
    if (r - l == 1) return arr[l];

    int m = (l + r) >> 1;
    auto v1 = self(l, m);
    auto v2 = self(m, r);

    auto res = fft.Mul(v1, v2);

    vector<int64_t> v3;
    for (int i = 0; i < res.size(); i++) {
      v3.push_back(res[i] % x);
      int64_t nxt = res[i] / x;
      if (nxt) {
        if (i + 1 == res.size()) {
          res.push_back(nxt);
        } else {
          res[i + 1] += nxt;
        }
      }
    }
    while (!v3.empty() && v3.back() == 0) v3.pop_back();

    return v3;
  }(0, n);

  int64_t pw = 1;
  for (int i = 1; i < cnt; i++) {
    pw *= ox;
  }

  int ok = 0;
  string ans;
  for (auto e : views::reverse(vec)) {
    int64_t p = pw;
    while (p) {
      int64_t v = e / p;
      e -= v * p;
      p /= ox;

      if (v || ok) {
        ans.push_back('0' + v);
        ok = 1;
      }
    }
  }
  cout << ans;

  return 0;
}