#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 10007;

struct Matrix {
  friend Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Matrix m;
    m.m[0][0] = (m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0]) % kMod;
    m.m[0][1] = (m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1]) % kMod;
    m.m[1][0] = (m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0]) % kMod;
    m.m[1][1] = (m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1]) % kMod;
    return m;
  }

  int m[2][2];
};

// fn

Matrix Exp(int n, const Matrix& m) {
  if (n == 1) return m;
  auto exp = Exp(n / 2, m);
  auto mp = exp * exp;
  if (n & 1) mp = mp * m;
  return mp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  auto m = Exp(n, {{{1, 2}, {1, 0}}});
  cout << m.m[0][0] << endl;

  return 0;
}
