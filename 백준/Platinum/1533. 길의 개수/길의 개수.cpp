#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e6 + 3;

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

  int n, s, e, t;
  cin >> n >> s >> e >> t;
  int n5 = n * 5;
  Matrix mat(n5);
  for (int i = 0; i < n5; i += 5) {
    for (int j = 0; j < 4; j++) {
      mat[i + j + 1][i + j] = 1;
    }
    for (int j = 0; j < n5; j += 5) {
      char c;
      cin >> c;
      if (c == '0') continue;
      mat[i][j + c - '1'] = 1;
    }
  }

  mat = Power(mat, t);
  cout << mat[(s - 1) * 5][(e - 1) * 5];

  return 0;
}
