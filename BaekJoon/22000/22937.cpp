// Title : 교수님 계산기가 고장났어요!
// Link  : https://www.acmicpc.net/problem/22937 
// Time  : 4 ms
// Memory: 2028 KB

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
    // while (!digits.empty() && digits.back() == 0) digits.pop_back();
    // if (digits.empty()) sign = false;
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

  friend istream& operator>>(istream& is, BigInt& num) {
    string s;
    is >> s;
    num = BigInt(s);
    return is;
  }

  mutable bool sign;
  mutable vector<int8_t> digits;
};

pair<BigInt, int> ReadInt() {
  string s;
  cin >> s;
  s.erase(s.find('.'), 1);
  return {BigInt(s), s[0] - '0'};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    auto [a, ah] = ReadInt();
    auto [b, bh] = ReadInt();
    BigInt c = a * b;
    string s(c.digits.rbegin(), c.digits.rend());
    for (auto& ch : s) ch += '0';
    string head(s.begin(), s.end() - 18);
    string tail(s.end() - 18, s.end());
    if (c.sign) cout << "-";
    cout << head << "." << tail << "\n";
  }

  return 0;
}
