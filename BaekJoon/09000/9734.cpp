// Title : 순환 소수
// Link  : https://www.acmicpc.net/problem/9734 
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

tuple<string, string, string> Split(const string& s) {
  string a, b, c;
  auto p1 = s.find_first_of('.');
  if (p1 != string::npos) {
    a = s.substr(0, p1);
    auto p2 = s.find_first_of('(', p1 + 1);
    if (p2 != string::npos) {
      b = s.substr(p1 + 1, p2 - p1 - 1);
      auto p3 = s.find_first_of(')', p2 + 1);
      if (p3 != string::npos) {
        c = s.substr(p2 + 1, p3 - p2 - 1);
      } else {
        c = s.substr(p2 + 1);
      }
    } else {
      b = s.substr(p1 + 1);
    }
  } else {
    a = s;
  }
  return {a, b, c};
}

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  while (cin >> s) {
    auto [a, b, c] = Split(s);
    if (b.empty() && c.empty()) {
      cout << s << " = " << stoi(s) << " / 1\n";
    } else if (c.empty()) {
      int sz = b.size();
      int64_t q = 1;
      for (int i = 0; i < sz; i++) q *= 10;
      int64_t p = q * stoi(a) + stoi(b);
      int64_t g = GCD(p, q);
      cout << s << " = " << p / g << " / " << q / g << "\n";
    } else {
      int sz = b.size();
      int64_t q = 1;
      for (int i = 0; i < sz; i++) q *= 10;
      if (b.empty()) b = "0";
      int64_t p = q * stoi(a) + stoi(b);

      string tmp(c.size(), '9');
      int64_t q2 = stoi(tmp);

      p = p * q2 + stoi(c);
      q *= q2;

      int64_t g = GCD(p, q);
      cout << s << " = " << p / g << " / " << q / g << "\n";
    }
  }

  return 0;
}
