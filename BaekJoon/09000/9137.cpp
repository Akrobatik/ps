// Title : Matematické cvičení
// Link  : https://www.acmicpc.net/problem/9137 
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

int GetValue(char c) {
  if (isalpha(c)) return c - 'A' + 10;
  return c - '0';
}

char ToChar(int x) {
  if (x < 10) return '0' + x;
  return 'A' + x - 10;
}

string Calc(const string& s1, const string& s2, int n) {
  vector<int8_t> digits(max<int>(s1.size(), s2.size()));
  for (int i = 0; i < s1.size(); i++) digits[i] += GetValue(s1[s1.size() - i - 1]);
  for (int i = 0; i < s2.size(); i++) digits[i] += GetValue(s2[s2.size() - i - 1]);

  int carry = 0;
  for (auto& digit : digits) {
    digit += carry;
    if (digit >= n) {
      digit -= n;
      carry = 1;
    } else {
      carry = 0;
    }
  }
  if (carry) digits.push_back(1);

  string res;
  res.resize(digits.size());
  auto it = res.begin();
  for (auto digit : views::reverse(digits)) *it++ = ToChar(digit);
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n && n) {
    string s1, s2;
    cin >> s1 >> s2;

    string ans;
    if (n == 1) {
      ans.resize(s1.size() + s2.size(), '1');
      if (s1[0] == '0') ans.pop_back();
      if (s2[0] == '0') ans.pop_back();
      if (ans.empty()) ans.push_back('0');
    } else {
      ans = Calc(s1, s2, n);
    }
    cout << s1 << " + " << s2 << " = " << ans << "\n";
  }

  return 0;
}
