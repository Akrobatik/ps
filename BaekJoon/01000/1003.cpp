// Title : 피보나치 함수
// Link  : https://www.acmicpc.net/problem/1003 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

struct Matrix {
  friend constexpr Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Matrix m;
    m.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0];
    m.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1];
    m.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0];
    m.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1];
    return m;
  }

  int64_t m[2][2];
};

constexpr Matrix Exp(int64_t n, const Matrix& m) {
  if (n == 1) return m;

  auto exp = Exp(n / 2, m);
  auto mp = exp * exp;
  if (n % 2) mp = mp * m;
  return mp;
}

template <int N>
struct Array {
  constexpr Array() {
    arr[0][0] = 1;
    arr[0][1] = arr[1][0] = 0;
    for (int i = 1; i < N; i++) {
      int v = Exp(i, {{{1, 1}, {1, 0}}}).m[0][1];
      arr[i][1] = v;
      arr[i + 1][0] = v;
    }
    arr[40][1] = Exp(N, {{{1, 1}, {1, 0}}}).m[0][1];
  }

  int arr[N + 1][2];
};

constexpr Array<40> ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    cout << ans.arr[m][0] << " " << ans.arr[m][1] << "\n";
  }

  return 0;
}
