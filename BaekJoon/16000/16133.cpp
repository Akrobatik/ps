// Title : 공학용 계산기 (Calculator)
// Link  : https://www.acmicpc.net/problem/16133 
// Time  : 0 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

struct Expr;
struct Term;
struct Factor;
struct Power;
struct Root;

struct Expr {
  Expr(string_view& sv);
  int64_t Eval();

  vector<Term> terms;
  vector<char> ops;
};

struct Term {
  Term(string_view& sv);
  int64_t Eval();

  vector<Factor> factors;
  vector<char> ops;
};

struct Factor {
  Factor(string_view& sv);
  int64_t Eval();

  vector<Power> powers;
  vector<char> ops;
};

struct Power {
  Power(string_view& sv);
  int64_t Eval();

  Power* power;
  Root* root;
};

struct Root {
  Root(string_view& sv);
  int64_t Eval();

  int64_t num;
  Expr* expr;
};

Expr::Expr(string_view& sv) {
  terms.push_back(Term(sv));
  while (!sv.empty() && (sv.front() == '+' || sv.front() == '-')) {
    ops.push_back(sv.front());
    sv = sv.substr(1);
    terms.push_back(Term(sv));
  }
}

Term::Term(string_view& sv) {
  factors.push_back(Factor(sv));
  while (!sv.empty() && (sv.front() == '*' || sv.front() == '/')) {
    ops.push_back(sv.front());
    sv = sv.substr(1);
    factors.push_back(Factor(sv));
  }
}

Factor::Factor(string_view& sv) {
  powers.push_back(Power(sv));
  while (!sv.empty() && sv.front() == '^') {
    ops.push_back(sv.front());
    sv = sv.substr(1);
    powers.push_back(Power(sv));
  }
}

Power::Power(string_view& sv) : power(nullptr), root(nullptr) {
  if (sv.front() == '#') {
    sv = sv.substr(1);
    power = new Power(sv);
  } else {
    root = new Root(sv);
  }
}

Root::Root(string_view& sv) : num(0), expr(nullptr) {
  if (sv.front() == '(') {
    sv = sv.substr(1);
    expr = new Expr(sv);
    sv = sv.substr(1);
  } else {
    int64_t x = 0;
    int n = 0;
    while (n < sv.size() && '0' <= sv[n] && sv[n] <= '9') x = x * 10 + (sv[n++] - '0');
    num = x;
    sv = sv.substr(n);
  }
}

int64_t Expr::Eval() {
  int64_t res = terms[0].Eval();
  for (int i = 0; i < ops.size(); i++) {
    int64_t x = terms[i + 1].Eval();
    if (ops[i] == '+') {
      res += x;
    } else {
      res -= x;
    }
  }
  return res;
}

int64_t Term::Eval() {
  int64_t res = factors[0].Eval();
  for (int i = 0; i < ops.size(); i++) {
    int64_t x = factors[i + 1].Eval();
    if (ops[i] == '*') {
      res *= x;
    } else {
      res /= x;
    }
  }
  return res;
}

int64_t Factor::Eval() {
  int64_t res = powers.back().Eval();
  for (int i = ops.size() - 1; i >= 0; i--) {
    int64_t x = powers[i].Eval();
    int64_t nxt = 1;
    while (res) {
      if (res & 1) nxt *= x;
      x *= x;
      res >>= 1;
    }
    res = nxt;
  }
  return res;
}

int64_t Power::Eval() {
  if (power) {
    int64_t x = power->Eval();
    if (x == 0 || x == 1) return x;
    int64_t lo = 0, hi = x;
    while (lo + 1 < hi) {
      int64_t mid = (lo + hi) >> 1;
      if (x / mid >= mid) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
  return root->Eval();
}

int64_t Root::Eval() {
  if (expr) return expr->Eval();
  return num;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  s.pop_back();
  string_view sv(s);
  auto expr = Expr(sv);
  cout << expr.Eval();

  return 0;
}
