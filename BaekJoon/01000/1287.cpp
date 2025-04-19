// Title : 할 수 있다
// Link  : https://www.acmicpc.net/problem/1287 
// Time  : 0 ms
// Memory: 2204 KB

#include <bits/stdc++.h>

using namespace std;

struct BigInt {
  BigInt() : sign(false), digits{} {}

  BigInt(int64_t n) : BigInt() {
    if (n < 0) sign = true, n = -n;
    while (n) digits.push_back(n % 10), n /= 10;
  }

  BigInt(string_view sv) : BigInt() {
    if (sv[0] == '-') {
      sign = true;
      sv = sv.substr(1);
    }

    digits.reserve(sv.size());
    for (auto digit : views::reverse(sv)) digits.push_back(digit - '0');
    Normalize();
  }

  void Normalize() const {
    while (!digits.empty() && digits.back() == 0) digits.pop_back();
    if (digits.empty()) sign = false;
  }

  bool IsZero() const {
    Normalize();
    return digits.empty();
  }

  BigInt& operator+=(const BigInt& other) {
    *this = operator+(*this, other);
    return *this;
  }

  BigInt& operator-=(const BigInt& other) {
    *this = operator-(*this, other);
    return *this;
  }

  BigInt& operator*=(const BigInt& other) {
    *this = operator*(*this, other);
    return *this;
  }

  BigInt& operator/=(const BigInt& other) {
    *this = operator/(*this, other);
    return *this;
  }

  friend BigInt operator+(const BigInt& lhs, const BigInt& rhs) {
    if (lhs.sign != rhs.sign) {
      rhs.sign = !rhs.sign;
      BigInt tmp = operator-(lhs, rhs);
      rhs.sign = !rhs.sign;
      return tmp;
    }

    vector<int8_t> digits(max<int>(lhs.digits.size(), rhs.digits.size()));
    for (int i = 0; i < lhs.digits.size(); i++) digits[i] += lhs.digits[i];
    for (int i = 0; i < rhs.digits.size(); i++) digits[i] += rhs.digits[i];

    int carry = 0;
    for (auto& digit : digits) {
      digit += carry;
      if (digit >= 10) {
        digit -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
    }
    if (carry) digits.push_back(1);

    BigInt tmp;
    tmp.sign = lhs.sign;
    tmp.digits.swap(digits);
    return tmp;
  }

  friend BigInt operator-(const BigInt& lhs, const BigInt& rhs) {
    if (lhs.sign != rhs.sign) {
      rhs.sign = !rhs.sign;
      BigInt tmp = operator+(lhs, rhs);
      rhs.sign = !rhs.sign;
      return tmp;
    }

    bool rev = lhs.digits.size() < rhs.digits.size();
    if (!rev && lhs.digits.size() == rhs.digits.size()) {
      for (int i = lhs.digits.size() - 1; i >= 0; i--) {
        if (lhs.digits[i] == rhs.digits[i]) continue;
        rev = lhs.digits[i] < rhs.digits[i];
        break;
      }
    }

    auto& a = (rev ? rhs.digits : lhs.digits);
    auto& b = (rev ? lhs.digits : rhs.digits);

    vector<int8_t> digits(max<int>(a.size(), b.size()));
    for (int i = 0; i < a.size(); i++) digits[i] += a[i];

    int carry = 0;
    for (int i = 0; i < digits.size(); i++) {
      digits[i] -= (i < b.size() ? b[i] : 0) + carry;
      if (digits[i] < 0) {
        digits[i] += 10;
        carry = 1;
      } else {
        carry = 0;
      }
    }

    BigInt tmp;
    tmp.sign = (lhs.sign != rev);
    tmp.digits.swap(digits);
    tmp.Normalize();
    return tmp;
  }

  friend BigInt operator*(const BigInt& lhs, const BigInt& rhs) {
    BigInt acc;
    for (int i = 0; i < lhs.digits.size(); i++) {
      int carry = 0;
      BigInt tmp;
      tmp.digits.reserve(rhs.digits.size() + i + 1);
      tmp.digits.resize(rhs.digits.size() + i, 0);
      for (int j = 0; j < rhs.digits.size(); j++) {
        tmp.digits[i + j] = lhs.digits[i] * rhs.digits[j] + carry;
        carry = tmp.digits[i + j] / 10;
        tmp.digits[i + j] %= 10;
      }
      if (carry) tmp.digits.push_back(carry);
      acc += tmp;
    }
    acc.sign = (lhs.sign != rhs.sign);
    acc.Normalize();
    return acc;
  }

  friend BigInt operator/(const BigInt& lhs, const BigInt& rhs) {
    if (rhs.IsZero()) throw runtime_error("Divide by zero");

    bool ls = lhs.sign, rs = rhs.sign;
    bool sign = ls != rs;
    lhs.sign = rhs.sign = false;

    BigInt qout, cur;
    qout.digits.resize(lhs.digits.size());

    for (int i = lhs.digits.size() - 1; i >= 0; --i) {
      cur.digits.insert(cur.digits.begin(), lhs.digits[i]);
      cur.Normalize();

      int lo = 0, hi = 10;
      while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        BigInt x = rhs * BigInt(mid);
        if (x <= cur) {
          lo = mid;
        } else {
          hi = mid;
        }
      }
      qout.digits[i] = lo;
      cur = cur - rhs * BigInt(lo);
    }

    lhs.sign = ls, rhs.sign = rs;

    qout.sign = sign;
    qout.Normalize();
    return qout;
  }

  friend bool operator==(const BigInt& lhs, const BigInt& rhs) {
    lhs.Normalize(), rhs.Normalize();
    return lhs.sign == rhs.sign && lhs.digits == rhs.digits;
  }

  friend bool operator<(const BigInt& lhs, const BigInt& rhs) {
    lhs.Normalize(), rhs.Normalize();
    if (lhs.sign != rhs.sign) return lhs.sign;
    if (lhs.digits.size() != rhs.digits.size())
      return lhs.sign ? lhs.digits.size() > rhs.digits.size()
                      : lhs.digits.size() < rhs.digits.size();
    for (int i = lhs.digits.size() - 1; i >= 0; --i) {
      if (lhs.digits[i] != rhs.digits[i])
        return lhs.sign ? lhs.digits[i] > rhs.digits[i]
                        : lhs.digits[i] < rhs.digits[i];
    }
    return false;
  }

  friend bool operator<=(const BigInt& lhs, const BigInt& rhs) {
    return lhs == rhs || lhs < rhs;
  }

  friend ostream& operator<<(ostream& os, const BigInt& num) {
    if (num.IsZero()) return os << '0';
    if (num.sign) os << '-';
    for (auto digit : views::reverse(num.digits)) os << (char)('0' + digit);
    return os;
  }

  mutable bool sign;
  mutable vector<int8_t> digits;
};

struct Expr;

struct Factor {
  Factor(string_view& sv);

  BigInt Eval();

  BigInt var;
  Expr* expr;
};

struct Term {
  Term(string_view& sv);

  BigInt Eval();

  vector<Factor> factors;
  vector<char> ops;
};

struct Expr {
  Expr(string_view& sv);

  BigInt Eval();

  vector<Term> terms;
  vector<char> ops;
};

Factor::Factor(string_view& sv) : var(), expr(nullptr) {
  if (sv.empty()) {
    cout << "ROCK";
    exit(0);
  }

  if (sv.front() == '(') {
    sv = sv.substr(1);
    expr = new Expr(sv);
    if (sv.empty() || sv.front() != ')') {
      cout << "ROCK";
      exit(0);
    }
    sv = sv.substr(1);
  } else if ('0' <= sv.front() && sv.front() <= '9') {
    int n = 0;
    while (n < sv.size() && '0' <= sv[n] && sv[n] <= '9') ++n;
    var = BigInt(sv.substr(0, n));
    sv = sv.substr(n);
  } else {
    cout << "ROCK";
    exit(0);
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

Expr::Expr(string_view& sv) {
  terms.push_back(Term(sv));
  while (!sv.empty() && (sv.front() == '+' || sv.front() == '-')) {
    ops.push_back(sv.front());
    sv = sv.substr(1);
    terms.push_back(Term(sv));
  }
}

BigInt Factor::Eval() {
  if (expr) return expr->Eval();
  return var;
}

BigInt Term::Eval() {
  BigInt res = factors[0].Eval();
  for (int i = 0; i < ops.size(); i++) {
    BigInt x = factors[i + 1].Eval();
    if (ops[i] == '*') {
      res *= x;
    } else {
      if (x.IsZero()) {
        cout << "ROCK";
        exit(0);
      }
      res /= x;
    }
  }
  return res;
}

BigInt Expr::Eval() {
  BigInt res = terms[0].Eval();
  for (int i = 0; i < ops.size(); i++) {
    BigInt x = terms[i + 1].Eval();
    if (ops[i] == '+') {
      res += x;
    } else {
      res -= x;
    }
  }
  return res;
}

bool Check(int ch) {
  return ('0' <= ch && ch <= '9') || (ch == '(') || (ch == ')') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  while (!Check(s.back())) s.pop_back();
  string_view sv = s;
  Expr expr(sv);
  if (!sv.empty()) {
    cout << "ROCK";
  } else {
    cout << expr.Eval();
  }

  return 0;
}
