// Title : Circular Shortcut
// Link  : https://www.acmicpc.net/problem/35071 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr long double kPI = 3.14159265358979L;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long double x;
  cin >> x;
  cout << setprecision(9) << fixed << (kPI / 2.0L - 1.0L) * x;

  return 0;
}