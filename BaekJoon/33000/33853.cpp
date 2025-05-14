// Title : 행렬과 쿼리
// Link  : https://www.acmicpc.net/problem/33853 
// Time  : 168 ms
// Memory: 24552 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 9;

struct Matrix {
  Matrix() : r(0), c(0), mat{} {}

  bool IsValid() const {
    return r != 0 && c != 0;
  }

  int* operator[](int r) { return mat[r]; }
  const int* operator[](int r) const { return mat[r]; }

  friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    Matrix res;
    if (!lhs.IsValid() || !rhs.IsValid() || lhs.c != rhs.r) return res;

    res.r = lhs.r, res.c = rhs.c;
    for (int i = 0; i < lhs.r; i++) {
      for (int k = 0; k < lhs.c; k++) {
        for (int j = 0; j < rhs.c; j++) {
          res[i][j] = ((int64_t)lhs[i][k] * rhs[k][j] + res[i][j]) % kMod;
        }
      }
    }
    return res;
  }

  int r, c;
  int mat[3][3];
};

constexpr int kMax = 1 << 18;
Matrix tree[kMax << 1], invalid;

void Update(int idx) {
  int node = idx + kMax;
  node >>= 1;
  while (node) tree[node] = tree[node << 1] * tree[(node << 1) + 1], node >>= 1;
}

optional<Matrix> Query(int node, int b, int e, int l, int r) {
  if (l > e || b > r) return nullopt;
  if (l <= b && e <= r) return tree[node];

  int mid = (b + e) >> 1;
  auto lhs = Query(node << 1, b, mid, l, r);
  auto rhs = Query((node << 1) + 1, mid + 1, e, l, r);
  if (lhs.has_value() && rhs.has_value()) return lhs.value() * rhs.value();
  if (lhs.has_value()) return lhs.value();
  if (rhs.has_value()) return rhs.value();
  return invalid;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int node = i + kMax;
    while (node && !tree[node].IsValid()) tree[node].r = tree[node].c = 2, node >>= 1;
  }

  while (q--) {
    int cmd;
    cin >> cmd;
    switch (cmd) {
      case 1: {
        int l, r, i, j;
        cin >> l >> r >> i >> j;
        auto res = Query(1, 0, kMax - 1, l, r).value_or(invalid);
        if (res.IsValid()) {
          cout << res[i - 1][j - 1] << "\n";
        } else {
          cout << "-1\n";
        }
      } break;

      case 2: {
        int i;
        cin >> i;
        auto& tnode = tree[i + kMax];
        auto& r = tnode.r;
        for (int c = 0; c < tnode.c; c++) tnode[r][c] = 0;
        ++r;
        Update(i);
      } break;

      case 3: {
        int i;
        cin >> i;
        auto& tnode = tree[i + kMax];
        auto& r = tnode.r;
        --r;
        Update(i);
      } break;

      case 4: {
        int i;
        cin >> i;
        auto& tnode = tree[i + kMax];
        auto& c = tnode.c;
        for (int r = 0; r < tnode.r; r++) tnode[r][c] = 0;
        ++c;
        Update(i);
      } break;

      case 5: {
        int i;
        cin >> i;
        auto& tnode = tree[i + kMax];
        auto& c = tnode.c;
        --c;
        Update(i);
      } break;

      case 6: {
        int i, j, k, v;
        cin >> i >> j >> k >> v;
        tree[i + kMax][j - 1][k - 1] = v;
        Update(i);
      } break;
    }
  }

  return 0;
}
