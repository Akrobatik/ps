// Title : 1， 2， 3 더하기 3
// Link  : https://www.acmicpc.net/problem/15988
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1000000009;

struct Matrix {
  Matrix() : m({}) {}
  Matrix(const int64_t _m[3][3]) { memcpy(m, _m, sizeof(m)); }

  int64_t* operator[](int i) { return m + i * 3; }
  const int64_t* operator[](int i) const { return m + i * 3; }

  int64_t m[9];
};

Matrix operator*(const Matrix& m1, const Matrix& m2) {
  Matrix m;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        m[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  for (auto& v : m.m) v %= kMod;
  return m;
}

Matrix Power(const Matrix& m, int exp) {
  if (exp == 1) return m;

  Matrix tmp = Power(m, exp >> 1);
  tmp = tmp * tmp;
  if (exp & 1) tmp = tmp * m;
  return tmp;
}

constexpr int64_t kTrans[3][3] = {
    {1, 1, 1},
    {1, 0, 0},
    {0, 1, 0}};

constexpr int kInitV[3] = {2, 1, 1};

int64_t Calc(int nth) {
  static const Matrix kBase(kTrans);
  if (nth <= 2) return kInitV[2 - nth];
  auto m = Power(kBase, nth - 2);
  int64_t sum = 0;
  for (int j = 0; j < 3; j++) sum += m[0][j] * kInitV[j];
  return sum % kMod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << Calc(n) << "\n";
  }

  return 0;
}
