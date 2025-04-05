// Title : 후위 표기식
// Link  : https://www.acmicpc.net/problem/1918
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

struct Expr;

struct Factor {
  Factor(string_view& sv);

  void Print();

  char var;
  unique_ptr<Expr> expr;
};

struct Term {
  Term(string_view& sv);

  void Print();

  vector<Factor> factors;
  vector<char> ops;
};

struct Expr {
  Expr(string_view& sv);

  void Print();

  vector<Term> terms;
  vector<char> ops;
};

Factor::Factor(string_view& sv) : var(0), expr(nullptr) {
  if (sv.front() == '(') {
    sv = sv.substr(1);
    expr = make_unique<Expr>(sv);
    sv = sv.substr(1);
  } else {
    var = sv.front();
    sv = sv.substr(1);
  }
}

void Factor::Print() {
  if (expr)
    expr->Print();
  else
    cout << var;
}

Term::Term(string_view& sv) {
  factors.push_back(Factor(sv));
  while (!sv.empty() && (sv.front() == '*' || sv.front() == '/')) {
    ops.push_back(sv.front());
    sv = sv.substr(1);
    factors.push_back(Factor(sv));
  }
}

void Term::Print() {
  factors.front().Print();
  for (int i = 0; i < ops.size(); i++) {
    factors[i + 1].Print();
    cout << ops[i];
  }
}

Expr::Expr(string_view& sv) {
  terms.push_back(Term(sv));
  while (!sv.empty() && (sv.front() == '+' || sv.front() == '-')) {
    ops.push_back(sv.front());
    sv = sv.substr(1);
    terms.push_back(Term(sv));
  }
}

void Expr::Print() {
  terms.front().Print();
  for (int i = 0; i < ops.size(); i++) {
    terms[i + 1].Print();
    cout << ops[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  string_view sv = s;
  Expr expr(sv);
  expr.Print();

  return 0;
}
