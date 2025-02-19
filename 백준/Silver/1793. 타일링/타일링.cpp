#include <bits/stdc++.h>

using namespace std;

struct BigInt {
  BigInt() : num() {}
  BigInt(int n) {
    while (n) num.push_back(n % 10), n /= 10;
  }
  BigInt(const BigInt& other) : num(other.num) {}

  BigInt& operator+=(const BigInt& rhs) {
    if (num.size() < rhs.num.size()) num.resize(rhs.num.size(), 0);
    int n = min<int>(num.size(), rhs.num.size());
    for (int i = 0; i < n; i++) num[i] += rhs.num[i];

    int carry = 0;
    for (auto& digit : num) {
      digit += carry;
      carry = (digit >= 10);
      if (carry) digit -= 10;
    }
    if (carry) num.push_back(1);
    return *this;
  }

  friend BigInt operator+(const BigInt& lhs, const BigInt& rhs) {
    BigInt tmp = lhs;
    tmp += rhs;
    return tmp;
  }

  friend BigInt operator*(const BigInt& lhs, const BigInt& rhs) {
    BigInt acc;
    for (int i = 0; i < lhs.num.size(); i++) {
      int carry = 0;
      BigInt tmp;
      tmp.num.reserve(rhs.num.size() + i + 1);
      tmp.num.resize(rhs.num.size() + i, 0);
      for (int j = 0; j < rhs.num.size(); j++) {
        tmp.num[i + j] = lhs.num[i] * rhs.num[j] + carry;
        carry = tmp.num[i + j] / 10;
        tmp.num[i + j] %= 10;
      }
      if (carry) tmp.num.push_back(carry);
      acc += tmp;
    }
    return acc;
  }

  BigInt& operator*=(const BigInt& rhs) {
    *this = operator*(*this, rhs);
    return *this;
  }

  void Print() {
    if (num.empty()) cout << '0';
    for (auto rit = num.rbegin(); rit != num.rend(); ++rit) cout << (char)(*rit + '0');
    cout << "\n";
  }

  vector<int8_t> num;
};

int main() {
  BigInt memo[251] = {1, 1, 3};
  BigInt b2 = 2;
  for (int i = 3; i <= 250; i++) {
    memo[i] += memo[i - 2];
    memo[i] += memo[i - 2];
    memo[i] += memo[i - 1];
  }

  for (;;) {
    int n;
    cin >> n;
    if (cin.fail()) break;
    memo[n].Print();
  }

  return 0;
}
