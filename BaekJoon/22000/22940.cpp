// Title : 선형 연립 방정식
// Link  : https://www.acmicpc.net/problem/22940 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

struct Expr {
  Expr(int n) : l(n), r(0) {}

  friend Expr operator*(const Expr& lhs, int64_t rhs) {
    int n = lhs.l.size();
    Expr expr(n);
    for (int i = 0; i < n; i++) {
      expr.l[i] = lhs.l[i] * rhs;
    }
    expr.r = lhs.r * rhs;
    return expr;
  }

  friend Expr operator-(const Expr& lhs, const Expr& rhs) {
    int n = lhs.l.size();
    Expr expr(n);
    for (int i = 0; i < n; i++) {
      expr.l[i] = lhs.l[i] - rhs.l[i];
    }
    expr.r = lhs.r - rhs.r;
    return expr;
  }

  vector<int64_t> l;
  int64_t r;
};

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Expr> exprs(n, Expr(n));
  for (auto& expr : exprs) {
    for (auto& x : expr.l) cin >> x;
    cin >> expr.r;
  }

  for (int i = 0; i < n; i++) {
    int64_t li = exprs[i].l[i];
    for (int j = i + 1; j < n; j++) {
      int64_t lj = exprs[j].l[i];
      int64_t lcm = li * lj / GCD(li, lj);
      exprs[j] = exprs[i] * (lcm / li) - exprs[j] * (lcm / lj);
    }
  }

  vector<int64_t> ans(n);
  for (int i = n - 1; i >= 0; i--) {
    int64_t l = 0, r = exprs[i].r;
    for (int j = i + 1; j < n; j++) {
      r -= exprs[i].l[j] * ans[j];
    }
    ans[i] = r / exprs[i].l[i];
  }

  for (auto e : ans) cout << e << " ";

  return 0;
}
