// Title : 일하는 세포
// Link  : https://www.acmicpc.net/problem/17401
// Time  : 4 ms
// Memory: 2420 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e9 + 7;

struct Matrix {
  Matrix(int _n) : n(_n), m(_n * _n) {}

  int64_t* operator[](int r) { return m.data() + r * n; }
  const int64_t* operator[](int r) const { return m.data() + r * n; }

  friend Matrix operator*(const Matrix& m1, const Matrix& m2) {
    int n = m1.n;
    Matrix m(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          m[i][j] = (m[i][j] + m1[i][k] * m2[k][j]) % kMod;
        }
      }
    }
    return m;
  }

  int n;
  vector<int64_t> m;
};

Matrix Power(const Matrix& m, int exp) {
  if (exp == 1) return m;
  auto res = Power(m, exp >> 1);
  res = res * res;
  if (exp & 1) res = res * m;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n, d;
  cin >> t >> n >> d;
  vector<Matrix> mats(t, Matrix(n));
  for (int i = 0; i < t; i++) {
    int m;
    cin >> m;
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      mats[i][a - 1][b - 1] = c;
    }
  }

  for (int i = 1; i < t; i++) {
    mats[i] = mats[i - 1] * mats[i];
  }

  Matrix ans(n);
  for (int i = 0; i < n; i++) ans[i][i] = 1;
  int quot = d / t;
  int rem = d % t;
  if (quot) ans = ans * Power(mats.back(), quot);
  if (rem) ans = ans * mats[rem - 1];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
