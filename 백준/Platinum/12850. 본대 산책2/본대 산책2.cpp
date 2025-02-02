#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kDiv = 1000000007ll;

template <int N>
struct Matrix {
  Matrix() { memset(m, 0, sizeof(m)); }

  constexpr Matrix(const int64_t (&init)[N][N]) : m{} {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        m[i][j] = init[i][j];
  }

  int64_t* operator[](int row) { return m[row]; }
  const int64_t* operator[](int row) const { return m[row]; }

  Matrix<N>& operator%=(int64_t n) {
    for (auto& v : m) v %= n;
    return *this;
  }

  friend Matrix<N> operator*(const Matrix<N>& m1, const Matrix<N>& m2) {
    Matrix<N> m;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          m[i][j] += m1[i][k] * m2[k][j];
        }
        m[i][j] %= kDiv;
      }
    }
    return m;
  }

  int64_t m[N][N];
};

template <int N>
Matrix<N> Exp(const Matrix<N>& m, int64_t n) {
  if (n == 1) return m;

  Matrix<N> tmp = Exp(m, n / 2);
  if (n & 1) return tmp * tmp * m;
  return tmp * tmp;
}

constexpr Matrix<8> mat({{0, 1, 1, 0, 0, 0, 0, 0},
                         {1, 0, 1, 1, 0, 0, 0, 0},
                         {1, 1, 0, 1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 1, 1, 0, 0},
                         {0, 0, 1, 1, 0, 1, 0, 1},
                         {0, 0, 0, 1, 1, 0, 1, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1},
                         {0, 0, 0, 0, 1, 0, 1, 0}});

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int d;
  cin >> d;

  cout << Exp(mat, d)[0][0];

  return 0;
}
