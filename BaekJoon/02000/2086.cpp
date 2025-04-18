// Title : 피보나치 수의 합
// Link  : https://www.acmicpc.net/problem/2086 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9;

struct Matrix {
  friend Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Matrix m;
    m.m[0][0] = ((int64_t)m1.m[0][0] * m2.m[0][0] + (int64_t)m1.m[0][1] * m2.m[1][0]) % kMod;
    m.m[0][1] = ((int64_t)m1.m[0][0] * m2.m[0][1] + (int64_t)m1.m[0][1] * m2.m[1][1]) % kMod;
    m.m[1][0] = ((int64_t)m1.m[1][0] * m2.m[0][0] + (int64_t)m1.m[1][1] * m2.m[1][0]) % kMod;
    m.m[1][1] = ((int64_t)m1.m[1][0] * m2.m[0][1] + (int64_t)m1.m[1][1] * m2.m[1][1]) % kMod;
    return m;
  }

  int m[2][2];
};

Matrix Power(const Matrix& m, int64_t exp) {
  if (exp == 1) return m;

  auto res = Power(m, exp >> 1);
  res = res * res;
  if (exp & 1) res = res * m;
  return res;
}

int Calc(int64_t n) {
  auto m = Power({{{1, 1}, {1, 0}}}, n);
  return m.m[0][1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;
  cout << (Calc(b + 2) + kMod - Calc(a + 1)) % kMod;

  return 0;
}
