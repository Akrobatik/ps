// Title : 01타일
// Link  : https://www.acmicpc.net/problem/1904 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

struct Matrix {
  friend Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Matrix m;
    m.m[0][0] = (m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0]) % 15746;
    m.m[0][1] = (m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1]) % 15746;
    m.m[1][0] = (m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0]) % 15746;
    m.m[1][1] = (m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1]) % 15746;
    return m;
  }

  int64_t m[2][2];
};

Matrix Exp(int64_t n, const Matrix& m) {
  if (n == 1) return m;

  auto exp = Exp(n / 2, m);
  auto mp = exp * exp;
  if (n % 2) mp = mp * m;
  return mp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  auto m = Exp(n + 1, {{{1, 1}, {1, 0}}});
  cout << m.m[0][1] << endl;

  return 0;
}
