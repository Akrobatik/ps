#include <bits/stdc++.h>

#include <span>

using namespace std;

struct Matrix {
  Matrix(int n) : m(n * n, 0), size(n) {}

  int* operator[](int i) { return m.data() + i * size; }
  const int* operator[](int i) const { return m.data() + i * size; }

  Matrix& operator%=(int n) {
    for (auto& v : m) v %= n;
    return *this;
  }

  vector<int> m;
  int size;
};

Matrix operator*(const Matrix& m1, const Matrix& m2) {
  int n = m1.size;
  Matrix m(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        m[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  for (auto& v : m.m) v %= 1000;
  return m;
}

Matrix Exp(const Matrix& m, int64_t n) {
  if (n == 1) return m;

  Matrix tmp = Exp(m, n / 2);
  if (n % 2 == 0) return tmp * tmp;
  return tmp * tmp * m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int64_t m;
  cin >> n >> m;
  Matrix mat(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }
  mat = Exp(mat, m);
  mat %= 1000;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
