// Title : 너의 평점은
// Link  : https://www.acmicpc.net/problem/25206 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

double Calc(const string& s) {
  if (s == "A+") return 4.5;
  if (s == "A0") return 4.0;
  if (s == "B+") return 3.5;
  if (s == "B0") return 3.0;
  if (s == "C+") return 2.5;
  if (s == "C0") return 2.0;
  if (s == "D+") return 1.5;
  if (s == "D0") return 1.0;
  if (s == "F") return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double sum = 0, xsum = 0;

  string s, g;
  while (cin >> s >> s >> g) {
    if (g == "P") continue;
    double x = Calc(g);
    double y = stoi(s);
    xsum += x * y;
    sum += y;
  }
  cout << setprecision(4) << fixed << xsum / sum;

  return 0;
}
