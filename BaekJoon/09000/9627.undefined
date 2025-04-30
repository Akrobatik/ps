// Title : 문장
// Link  : https://www.acmicpc.net/problem/9627 
// Time  : 0 ms
// Memory: 2460 KB

#include <bits/stdc++.h>

using namespace std;

const string kStr[] = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};

const string kStr2[] = {
    "",
    "",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
};

const string kStr3[] = {
    "",
    "onehundred",
    "twohundred",
    "threehundred",
    "fourhundred",
    "fivehundred",
    "sixhundred",
    "sevenhundred",
    "eighthundred",
    "ninehundred",
};

string Get(int n) {
  if (n >= 100) return kStr3[n / 100] + Get(n % 100);
  if (n < 20) return kStr[n];
  return kStr2[n / 10] + kStr[n % 10];
}

string Calc(int sum) {
  int n = sum;
  while (n++) {
    string s = Get(n);
    if (sum + s.size() == n) return s;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int sum = 0;
  ostringstream oss;
  while (n--) {
    string s;
    cin >> s;
    if (s == "$") {
      oss << "{} ";
    } else {
      sum += s.size();
      oss << s << " ";
    }
  }

  string fmt = oss.str();
  string args = Calc(sum);
  vformat_to(ostream_iterator<char>{cout}, fmt, make_format_args(args));

  return 0;
}
